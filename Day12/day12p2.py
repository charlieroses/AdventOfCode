#!/usr/bin/python3

# Advent of Code 2019
# Day 12 : The N-Body Problem
# 
# Author : Charlie Rose
# Language : Python3
# Date : 12/X/2019


if __name__ == "__main__":
    moonsP = [ [0,0,0], [0,0,0], [0,0,0], [0,0,0]]
    moonsV = [ [0,0,0], [0,0,0], [0,0,0], [0,0,0]]

    # Input and parse file
    f = open("day12stepinput.txt", "r")
    
    fin = f.readlines()
    fin = fin[0]
    fin = fin.split(",")

    moonsP[0][0] = int(fin[0])
    moonsV[0][0] = int(fin[1])
    moonsP[0][1] = int(fin[2])
    moonsV[0][1] = int(fin[3])
    moonsP[0][2] = int(fin[4])
    moonsV[0][2] = int(fin[5])
    moonsP[1][0] = int(fin[6])
    moonsV[1][0] = int(fin[7])
    moonsP[1][1] = int(fin[8])
    moonsV[1][1] = int(fin[9])
    moonsP[1][2] = int(fin[10])
    moonsV[1][2] = int(fin[11])
    moonsP[2][0] = int(fin[12])
    moonsV[2][0] = int(fin[13])
    moonsP[2][1] = int(fin[14])
    moonsV[2][1] = int(fin[15])
    moonsP[2][2] = int(fin[16])
    moonsV[2][2] = int(fin[17])
    moonsP[3][0] = int(fin[18])
    moonsV[3][0] = int(fin[19])
    moonsP[3][1] = int(fin[20])
    moonsV[3][1] = int(fin[21])
    moonsP[3][2] = int(fin[22])
    moonsV[3][2] = int(fin[23])

    f.close()

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
 
    fout = ""

    for m in range(4):
        for c in range(3):
            fout += str(moonsP[m][c]) + "," + str(moonsV[m][c]) + ","

    
    print(moonsV)
    f = open("day12stepinput.txt", "w")
    f.write(fout)
    f.close()
