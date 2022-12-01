abet = set("abcdefghijklmnnopqrstuvwxyz")

f = open("input.txt")
lines = f.read().split("\n\n")


total = 0
for l in lines:
	cset = set("abcdefghijklmnnopqrstuvwxyz")
	for p in l.split("\n"):
		cset = cset.intersection(set(p))

	total += len(cset)

print(total)

f.close()
