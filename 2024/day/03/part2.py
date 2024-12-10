def solution(input):
    output = 0
    enabled = True
    for i in range(len(input)):
        if enabled and input[i:].startswith("mul("):
            try:
                firstNumber = int(input[i+4:input[i+4:].index(",")+i+4]) 
                secondNumber = int(input[input[i+4:].index(",")+i+5:input[i+4:].index(")")+i+4])
                if firstNumber / 100 < 10 and secondNumber / 100 < 10:
                    output += firstNumber * secondNumber
            except:
                pass
        elif input[i:].startswith("don\'t()"):
            enabled = False
        elif input[i:].startswith("do()"):
            enabled = True
    return output

assert solution("xmul(2,4)&mul[3,7]!^don't()_mul(5,5)+mul(32,64](mul(11,8)undo()?mul(8,5))") == 48

with open("2024/day/03/input02.txt") as f:
    print(solution(f.read().strip()))