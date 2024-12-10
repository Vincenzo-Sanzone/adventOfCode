def solution(input):
    output = 0
    for i in range(len(input)):
        if input[i:].startswith("mul("):
            try:
                firstNumber = int(input[i+4:input[i+4:].index(",")+i+4]) 
                secondNumber = int(input[input[i+4:].index(",")+i+5:input[i+4:].index(")")+i+4])
                if firstNumber / 100 < 10 and secondNumber / 100 < 10:
                    output += firstNumber * secondNumber
            except:
                pass
    return output

assert solution("xmul(2,4)%&mul[3,7]!@^do_not_mul(5,5)+mul(32,64]then(mul(11,8)mul(8,5))") == 161

with open("2024/day/03/input01.txt") as f:
    print(solution(f.read().strip()))