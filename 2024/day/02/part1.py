output = 0
with open("2024/day/02/input01.txt") as f:
    for line in f:
        numbers = list(map(int, line.split()))
        
        isIncreasing = numbers[0] < numbers[1]
        prevNumber = numbers[0]
        isSafe = True
        
        for i in range(1, len(numbers)):
            if abs(numbers[i] - prevNumber) > 3 or numbers[i] == prevNumber:
                isSafe = False
                break
            if isIncreasing and numbers[i] < prevNumber:
                isSafe = False
                break
            if not isIncreasing and numbers[i] > prevNumber:
                isSafe = False
                break
            prevNumber = numbers[i]
        
        if isSafe:
            output += 1

print(output)
