f = open("input.txt")

r = f.readlines()
passpt = ""
valid = 0;

for l in r:
	if l != "\n":
		passpt += l
	else:
		cnt = 0
		for a in passpt:
			if a == ":":
				cnt += 1
		if (cnt == 8) or (cnt == 7 and not ("cid" in passpt)):
			valid += 1



		passpt = ""

print(valid)
