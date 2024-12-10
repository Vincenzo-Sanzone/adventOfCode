def getSafe(numbers) -> bool:
    isIncreasing = numbers[0] < numbers[1]
    prevNumber = numbers[0]
    hadARemovedNumber = False
    for i in range(1, len(numbers)):
        if abs(numbers[i] - prevNumber) > 3 or numbers[i] == prevNumber:
            if hadARemovedNumber:
                return False
            hadARemovedNumber = True
        elif isIncreasing and numbers[i] < prevNumber:
            if hadARemovedNumber:
                return False
            hadARemovedNumber = True
        elif not isIncreasing and numbers[i] > prevNumber:
            if hadARemovedNumber:
                return False
                
            hadARemovedNumber = True
        else:
            prevNumber = numbers[i]
    return True

output = 0
with open("2024/day/02/input02.txt") as f:
    for line in f:
        numbers = list(map(int, line.split()))
        if getSafe(numbers):
            output += 1
        elif getSafe(numbers[::-1]):      
            output += 1

print(output)
