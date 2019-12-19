def load_code():
    with open("Task 2-1.txt") as src:
        return list(map(int, src.read().split(",")))


def execute(program, noun, verb):
    pos = 0
    program[1] = noun
    program[2] = verb
    while pos < len(program):
        opcode = program[pos]
        if opcode == 1 or opcode == 2:
            op1 = program[pos + 1]
            op2 = program[pos + 2]
            dest = program[pos + 3]
            program[dest] = program[op1] + program[op2] if opcode == 1 else program[op1] * program[op2]
            pos += 4
        elif opcode == 99:
            break
        else:
            print("There has been a wrong input")
            break
    return program[0]


noun = 0
verb = -1
result = 0
while result != 19690720:
    verb += 1
    if verb == 100:
        verb = 0
        noun += 1
    intcode = load_code()
    result = execute(intcode, noun, verb)
print(100 * noun + verb)
