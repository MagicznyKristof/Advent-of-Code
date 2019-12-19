def crosses(x, y):
    return min(y[0][0], y[1][0]) < x[0][0] < max(y[0][0], y[1][0]) and min(x[0][1], x[1][1]) < y[0][1] < max(x[0][1], x[1][1])


def find_distance(x, y):
    return abs(x[0][0]) + abs(y[0][1])



moveset = []
with open("Task 3-1.txt") as f:
    line1 = f.readline()
    moveset.append(line1.strip().split(','))
    line2 = f.readline()
    moveset.append(line2.strip().split(','))

htable1 = []
htable2 = []
vtable1 = []
vtable2 = []
pos = [0, 0]

for move in moveset[0]:
    step = int(move[1:])
    if move[0] == 'U':
        vtable1.append([[pos[0], pos[1]], [pos[0] + step, pos[1]]])
        pos[0] += step
    elif move[0] == 'D':
        vtable1.append([[pos[0], pos[1]], [pos[0] - step, pos[1]]])
        pos[0] -= step
    elif move[0] == 'R':
        htable1.append([[pos[0], pos[1]], [pos[0], pos[1] + step]])
        pos[1] += step
    elif move[0] == 'L':
        htable1.append([[pos[0], pos[1]], [pos[0], pos[1] - step]])
        pos[1] -= step

pos = [0, 0]
for move in moveset[1]:
    step = int(move[1:])
    if move[0] == 'U':
        vtable2.append([[pos[0], pos[1]], [pos[0] + step, pos[1]]])
        pos[0] += step
    elif move[0] == 'D':
        vtable2.append([[pos[0], pos[1]], [pos[0] - step, pos[1]]])
        pos[0] -= step
    elif move[0] == 'R':
        htable2.append([[pos[0], pos[1]], [pos[0], pos[1] + step]])
        pos[1] += step
    elif move[0] == 'L':
        htable2.append([[pos[0], pos[1]], [pos[0], pos[1] - step]])
        pos[1] -= step

dist = 0

for x in htable1:
    for y in vtable2:
        if crosses(x, y):
            new_dist = find_distance(x, y)
            if dist == 0:
                dist = new_dist
            else:
                dist = min(dist, new_dist)

for x in htable2:
    for y in vtable1:
        if crosses(x, y):
            new_dist = find_distance(x, y)
            if dist == 0:
                dist = new_dist
            else:
                dist = min(dist, new_dist)

print(dist)