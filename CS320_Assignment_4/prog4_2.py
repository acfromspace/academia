import StackMachine
import sys

print("Assignment #4-2, Andrew Christopher De Leon, andrewchristopherdeleon@gmail.com")
fileName = open(sys.argv[1])
answer = StackMachine.StackMachine()
for line in fileName.readlines():
    draft = line.split(' ')
    tokens = []
    for i in draft:
        tokens.append(i.strip())
    token_count = len(tokens)
    if token_count == 2:
        if tokens[0] == 'push':
            if tokens[1].isdigit():
                answer.push(int(tokens[1]))
    elif token_count == 1:
        if tokens[0] == 'add':
            answer.add()
        if tokens[0] == 'sub':
            answer.sub()
        if tokens[0] == 'mul':
            answer.mul()
        if tokens[0] == 'div':
            answer.div()
        if tokens[0] == 'mod':
            answer.mod()
        if tokens[0] == 'pop':
            answer.pop()
    else:
        print("Incorrect input.")
print(answer.pop())
    

# fileName = file itself
# text = text within file
# line = line within file
