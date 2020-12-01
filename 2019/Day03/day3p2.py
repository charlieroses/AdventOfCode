#!/usr/bin/python3
#
# Advent of Code 2019
# Day 3 : Crossed Wires
# 
# Author : Charlie Rose
# Language : Python3
# Date : 12/6/2019

import sys

if __name__ == "__main__":
    f = open("day3input.txt")

    wires = f.readlines()
    centralPort = (0,0)
    #I could use a set here I guess, I'm more comfortable with lists however
    intersections = []
    points = []
    points2 = []
    pointsstep = {}
    pointsstep2 = {}
    steps = 0
    steps2 = 0

    currPos = (0,0)
    for d in wires[0].split(","):
        direction = d[0]
        value = int(d[1::])
  
        # Iterate for the number in each thing
        for i in range(value):
            # U - UP - Increase Y
            if direction == "U":
                currPos = (currPos[0], currPos[1] + 1)

            # D - DOWN - Decrease Y
            elif direction == "D": 
                currPos = (currPos[0], currPos[1] - 1)

            # L - LEFT - Decrease X
            elif direction == "L":
                currPos = (currPos[0] - 1, currPos[1])

            # R - RIGHT - Increase X
            elif direction == "R":
                currPos = (currPos[0] + 1, currPos[1])
            
            steps += 1
            points.append(currPos)
            pointsstep[currPos] = steps

    
    currPos = (0,0)
    for d in wires[1].split(","):
        direction = d[0]
        value = int(d[1::])

        # Iterate for the number in each thing
        for i in range(value):
            # U - UP - Increase Y
            if direction == "U":
                currPos = (currPos[0], currPos[1] + 1)

            # D - DOWN - Decrease Y
            elif direction == "D": 
                currPos = (currPos[0], currPos[1] - 1)

            # L - LEFT - Decrease X
            elif direction == "L":
                currPos = (currPos[0] - 1, currPos[1])

            # R - RIGHT - Increase X
            elif direction == "R":
                currPos = (currPos[0] + 1, currPos[1])

            steps2 += 1
            points2.append(currPos)
            pointsstep2[currPos] = steps2


    intersections = set(points) & set(points2)
    minsteps = sys.maxsize
    minpoint = (0,0)

    for i in intersections:
        s1 = pointsstep[i]
        s2 = pointsstep2[i]

        if (s1 + s2) < minsteps:
            minsteps = s1 + s2
            minpoint = i

    print( minsteps )
    print( minpoint )
    f.close()
