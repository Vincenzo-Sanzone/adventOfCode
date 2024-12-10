firstList = []
occurences = {}
with open("2024/day/01/input02.txt") as f:
    for line in f:
        firstList.append(int(line.split()[0]))
        secondNumber = int(line.split()[1])
        if secondNumber in occurences:
            occurences[secondNumber] += 1
        else:
            occurences[secondNumber] = 1

firstList.sort()

output = 0
for i in range(len(firstList)):
    value = firstList[i]
    if value in occurences:
        output += value * occurences[value]
print(output)