#!/usr/bin/python3

# Advent of Code 2019
# Day 10 : Monitoring Station
# 
# Author : Charlie Rose
# Language : Python3
# Date : 12/18/2019

import math

def contCollCheck(v, v1, dv):
    if dv > 0:
        return v >= v1
    elif dv < 0:
        return v <= v1
    else:
        return False



if __name__ == "__main__":
    print("Input File:")
    ifile = input()
    f = open(ifile)
    fileLines = f.readlines()
    asteroids = []
    detections = {}


    for r in range(len(fileLines)):
        row = fileLines[r]
        
        for c in range(len(row)):
            unit = row[c]

            if unit == "#":
                point = (c, r)
                asteroids.append( point )
                detections[point] = []

    for a in asteroids:
        for a2 in asteroids:
            if a == a2:
                continue
            detection = True

            c0 = a[0]
            r0 = a[1]
            c1 = a2[0]
            r1 = a2[1]

            dc = c1 - c0
            dr = r1 - r0

            slopegcd = math.gcd(dc, dr)

            dc = dc / slopegcd
            dr = dr / slopegcd

            c = c0 + dc
            r = r0 + dr

            while not( contCollCheck(c, c1, dc) or contCollCheck(r, r1, dr) ): 
                if (c,r) in asteroids:
                    detection = False
             
                c += dc
                r += dr
                

            if detection:
                detections[a].append(a2)

    bestA = asteroids[0]
    bestD = len(detections[bestA])
    for a in asteroids:
        if len(detections[a]) > bestD:
            bestA = a
            bestD = len(detections[a])

    print(bestA, bestD)
    f.close()
