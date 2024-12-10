def isValid(row, i, j):
    return ((row[i-1][j-1] == "M" and row[i+1][j+1] == "S") or (row[i-1][j-1] == "S" and row[i+1][j+1] == "M")) and ((row[i-1][j+1] == "M" and row[i+1][j-1] == "S") or (row[i-1][j+1] == "S" and row[i+1][j-1] == "M"))

def solution(input):
    output = 0
    row = input.split("\n")
    for i in range(1, len(row) - 1):
        for j in range(1, len(row[i])-1):
            if row[i][j] == "A":
                if isValid(row, i, j):
                    output += 1
                    
    return output

test = """MMMSXXMASM
MSAMXMSMSA
AMXSXMAAMM
MSAMASMSMX
XMASAMXAMM
XXAMMXXAMA
SMSMSASXSS
SAXAMASAAA
MAMMMXMMMM
MXMXAXMASX"""
assert solution(test) == 9

with open("2024/day/04/input02.txt") as f:
    print(solution(f.read().strip()))