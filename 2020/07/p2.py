# format 
#  key = bag color
#  value = array of tuples of ("color", quantity)
bags = {}


def calcBags(currKey):
	t = 0

	print(currKey)
	if bags[currKey] == []:
		return 1

	for i in bags[currKey]:
		t += (i[1] * calcBags(i[0]))

	return (1 + t)

f = open("input.txt", "r")

for l in f.readlines():
	b = l.split("contain")
	bc = b[0].split()
	bc = bc[0] + " " + bc[1]
	
	barr = []
	
	if b[1] != " no other bags.\n":
		for p in b[1].split(","):
			ps = p.split()
			pcnt = int(ps[0])
			pcol = ps[1] + " " + ps[2]
			barr.append((pcol, pcnt))
	bags[bc] = barr

print(calcBags("shiny gold") - 1)

f.close()
