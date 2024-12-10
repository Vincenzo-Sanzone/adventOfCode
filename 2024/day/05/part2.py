def createValidOrder(graph, toBePrinted):
    validOrder = []
    goodGraph = {}
    for page in toBePrinted:
        goodGraph[page] = []

    for toPrintAfter in graph:
        if toPrintAfter in toBePrinted:
            for toPrintFirst in graph[toPrintAfter]:
                if toPrintFirst in toBePrinted:
                    goodGraph[toPrintFirst].append(toPrintAfter)

    while len(validOrder) < len(toBePrinted):
        for page in goodGraph:
            if len(goodGraph[page]) == 0:
                validOrder.append(page)
                for otherPage in goodGraph:
                    if page in goodGraph[otherPage]:
                        goodGraph[otherPage].remove(page)
                goodGraph.pop(page)
                break

    return validOrder[int(len(validOrder) / 2)]

def solution(input):
    output = 0
    order = {}
    graph = {}
    lines = input.split("\n")
    for line in lines:
        if "|" in line:
            after, first = list(map(int, line.split("|")))
            if first not in order:
                order[first] = [after]
            else:
                order[first].append(after)
            if after not in graph:
                graph[after] = [first]
            else:
                graph[after].append(first)
        elif "," in line:
            toBePrinted = list(map(int, line.split(",")))
            cantPrint = []
            for page in toBePrinted:
                if page in cantPrint:
                    output += createValidOrder(order, toBePrinted)
                    break
                if page in order:
                    for after in order[page]:
                        if after not in cantPrint:
                            cantPrint.append(after)
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
result_test = solution(test)
print(f"SOLUTION OF THE TEST INPUT: {result_test}")
assert result_test == 123

with open("2024/day/05/input02.txt") as f:
    print(f"SOLUTION OF THE REAL INPUT: {solution(f.read().strip())}")