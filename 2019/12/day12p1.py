#!/usr/bin/python3

# Advent of Code 2019
# Day 12 : The N-Body Problem
# 
# Author : Charlie Rose
# Language : Python3
# Date : 12/19/2019


if __name__ == "__main__":
    moonsP = []
    moonsV = [ [0,0,0], [0,0,0], [0,0,0], [0,0,0]]
    moonsPE = [0,0,0,0]
    moonsKE = [0,0,0,0]
    moonsE = [0,0,0,0]

    # Input and parse file
    print("Input File:")
    ifile = input()
    f = open(ifile)
    
    for l in f.readlines():
        ls = l.split(",")
        pos = [0,0,0]

        for i in range(len(ls)):
            isNeg = False
            for c in ls[i]:
                if c.isdigit():
                    pos[i] = (pos[i] * 10) + int(c)
                if c == "-":
                    isNeg = True
            if isNeg:
                pos[i] = -pos[i]

        moonsP.append(pos)

    steps = 1000
    for i in range(steps):
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
            moonsPE[m1] = abs(moonsP[m1][0]) + abs(moonsP[m1][1]) + abs(moonsP[m1][2])
            moonsKE[m1] = abs(moonsV[m1][0]) + abs(moonsV[m1][1]) + abs(moonsV[m1][2])
            moonsE[m1] = moonsKE[m1] * moonsPE[m1]


    totalE = 0
    for m1 in range(4):
        totalE += moonsE[m1]

    print(totalE)
    f.close()
