abet = set("abcdefghijklmnnopqrstuvwxyz")

f = open("input.txt")
lines = f.read().split("\n\n")


total = 0
for l in lines:
	l = l.replace("\n", "")
	notansd = abet - set(l)
	total += (26 - len(notansd))

print(total)

f.close()
