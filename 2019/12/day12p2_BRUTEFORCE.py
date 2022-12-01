#!/usr/bin/python3

# Advent of Code 2019
# Day 12 : The N-Body Problem
# 
# Author : Charlie Rose
# Language : Python3
# Date : 12/19/2019


if __name__ == "__main__":
    moonsP = []
    moonsPi = []
    moonsV = [ [0,0,0], [0,0,0], [0,0,0], [0,0,0]]
    zerosArr = [[0,0,0]] * 4

    # Input and parse file
    print("Input File:")
    ifile = input()
    f = open(ifile)
    
    for l in f.readlines():
        ls = l.split(",")
        pos = [0,0,0]
        posi = [0,0,0]

        for i in range(len(ls)):
            isNeg = False
            for c in ls[i]:
                if c.isdigit():
                    pos[i] = (pos[i] * 10) + int(c)
                    posi[i] = (posi[i] * 10) + int(c)
                if c == "-":
                    isNeg = True
            if isNeg:
                pos[i] = -pos[i]
                posi[i] = -posi[i]

        moonsP.append(pos)
        moonsPi.append(posi)

    i = 0
    foundZ = False
    while True:
        i += 1
        if not foundZ:
            for m1 in range(4):
                for m2 in range(4):
                    if m1 == m2:
                        continue
                    for xyz in range(3):
                        if moonsP[m1][xyz] > moonsP[m2][xyz]:
                            moonsV[m1][xyz] -= 1
                        elif moonsP[m1][xyz] < moonsP[m2][xyz]:
                            moonsV[m1][xyz] += 1

            for m1 in range(4):
                for xyz in range(3):
                    moonsP[m1][xyz] += moonsV[m1][xyz]

            initState = False
        
            if moonsV == zerosArr:
                foundZ = True
                break
        if foundZ:
            initState = True
            for m1 in range(4):
                for xyz in range(3):
                    if not( moonsP[m1][xyz] == moonsPi[m1][xyz]):
                        initState = False




        print("Step :", i)
        
        if initState:
            break


    f.close()
