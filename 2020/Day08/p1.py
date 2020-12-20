
f = open("input.txt")

accu = 0
program = f.readlines()
run2 = [False] * len(program)

print(run2)

f.close()

i = 0
while i < len(program):
	if( run2[i] ):
		break

	line = program[i].split()
	run2[i] = True


	if line[0] == "acc":
		accu += int(line[1])
		i += 1
	elif line[0] == "nop":
		i += 1
	elif line[0] == "jmp":
		i += int(line[1])


print(accu)
