def solution(input):
    output = 0
    row = input.split("\n")
    for i in range(len(row)):
        for j in range(len(row[i])):
            if row[i][j] == "X":
                if i > 2 and row[i-1][j] == "M" and row[i-2][j] == "A" and row[i-3][j] == "S":
                    output += 1
                if j > 2 and row[i][j-1] == "M" and row[i][j-2] == "A" and row[i][j-3] == "S":
                    output += 1
                if i > 2 and j > 2 and row[i-1][j-1] == "M" and row[i-2][j-2] == "A" and row[i-3][j-3] == "S":
                    output += 1
                if i > 2 and j < len(row[i])-3 and row[i-1][j+1] == "M" and row[i-2][j+2] == "A" and row[i-3][j+3] == "S":
                    output += 1
                if i < len(row)-3 and row[i+1][j] == "M" and row[i+2][j] == "A" and row[i+3][j] == "S":
                    output += 1
                if j < len(row[i])-3 and row[i][j+1] == "M" and row[i][j+2] == "A" and row[i][j+3] == "S":
                    output += 1
                if i < len(row)-3 and j < len(row[i])-3 and row[i+1][j+1] == "M" and row[i+2][j+2] == "A" and row[i+3][j+3] == "S":
                    output += 1
                if i < len(row)-3 and j > 2 and row[i+1][j-1] == "M" and row[i+2][j-2] == "A" and row[i+3][j-3] == "S":
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
assert solution(test) == 18

with open("2024/day/04/input01.txt") as f:
    print(solution(f.read().strip()))