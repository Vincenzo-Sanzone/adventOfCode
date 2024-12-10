def solution(input):
    output = 0
    order = {}
    lines = input.split("\n")
    for line in lines:
        if "|" in line:
            after, first = list(map(int, line.split("|")))
            if first not in order:
                order[first] = [after]
            else:
                order[first].append(after)
        elif "," in line:
            toBePrinted = list(map(int, line.split(",")))
            cantPrint = []
            isPossible = True
            for page in toBePrinted:
                if page in cantPrint:
                    isPossible = False
                    break
                if page in order:
                    for after in order[page]:
                        if after not in cantPrint:
                            cantPrint.append(after)
            if isPossible:
                output += toBePrinted[int(len(toBePrinted)/2)]
    return output

test = """47|53
97|13
97|61
97|47
75|29
61|13
75|53
29|13
97|29
53|29
61|53
97|53
61|29
47|13
75|47
97|75
47|61
75|61
47|29
75|13
53|13

75,47,61,53,29
97,61,53,29,13
75,29,13
75,97,47,61,53
61,13,29
97,13,75,29,47"""
assert solution(test) == 143

with open("2024/day/05/input01.txt") as f:
    print(solution(f.read().strip()))