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
		
		vpass = False
		if (cnt == 8) or (cnt == 7 and not ("cid" in passpt)):
			vpass = True
			for f in passpt.split():
				ff = f.split(":")
				if ff[0] == "byr" and (int(ff[1]) < 1920 or int(ff[1]) > 2002):
					vpass = False
				elif ff[0] == "iyr" and (int(ff[1]) < 2010 or int(ff[1]) > 2020):
					vpass = False
				elif ff[0] == "eyr" and (int(ff[1]) < 2020 or int(ff[1]) > 2030):
					vpass = False

				elif ff[0] == "hgt":
					if ff[1][-2] == "c" and ff[1][-1] == "m":
						if int(ff[1][0:-2]) < 150 or int(ff[1][0:-2]) > 193:
							vpass = False
					elif ff[1][-2] == "i" and ff[1][-1] == "n":
						if int(ff[1][0:-2]) < 59 or int(ff[1][0:-2]) > 76:
							vpass = False
					else:
						vpass = False

				elif (ff[0] == "hcl"):
					if ff[1][0] != "#" and len(ff[1]) != 7:
						vpass = False
					for z in ff[1][1::]:
						if not(z in "0123456789abcdef"):
							vpass = False

				elif ff[0] == "ecl" and not(ff[1] in ["amb", "blu", "brn", "gry", "grn", "hzl", "oth"]):
					vpass = False

				elif ff[0] == "pid":
					if len(ff[1]) != 9:
						vpass = False
					for z in ff[1]:
						if not(z in "0123456789"):
							vpass = False

		if vpass:
			valid += 1

		passpt = ""

print(valid)
