firstList = []
secondList = []
with open("2024/day/01/input01.txt") as f:
    for line in f:
        firstList.append(line.split()[0])
        secondList.append(line.split()[1])

firstList.sort()
secondList.sort()

output = 0
for i in range(len(firstList)):
    output += abs(int(firstList[i]) - int(secondList[i]))
print(output)