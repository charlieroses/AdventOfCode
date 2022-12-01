# format 
#  key = bag color
#  value = array of tuples of ("color", quantity)
bags = {}


def findGold(currKey):
	global bags

	if currKey == "shiny gold":
		return 1
	
	if bags[currKey] == []:
		return 0

	t = 0
	for i in bags[currKey]:
		t += findGold(i[0])

	return (t > 0)




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


total = 0


for i in bags:
	if findGold(i):
		total+= 1
	print("NEW BAG")

print(total - 1)

f.close()
