with open("Task 1-1.txt") as f:
	masses_list = []
	for line in f:
		masses_list.append(int(line.strip()))
fuel = 0
for mass in masses_list:
	fuel += mass//3-2
	
print(fuel)
