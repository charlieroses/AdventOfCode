#!/usr/bin/python3

# Advent of Code 2019
# Day 10 : Monitoring Station
# 
# Author : Charlie Rose
# Language : Python3
# Date : 12/19/2019

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

    
    laser = bestA
    cl = laser[0]
    rl = laser[1]
    astangles = {}

    for a in asteroids:
        if a == laser:
            continue
        
        ca = a[0]
        ra = a[1]

        dc = ca - cl
        dr = ra - rl

        if ( dc == 0 ) and ( dr > 0 ) :
            angle = 90
        elif ( dc == 0 ) and ( dr < 0 ):
            angle = 270
        elif ( dr == 0 ) and ( dc > 0 ):
            angle = 0
        elif ( dr == 0 ) and ( dc < 0 ):
            angle = 180
        else:
            angle = math.atan( dr/dc )
            angle = angle * (180 / math.pi)
            if dc < 0:
                angle += 180
            if angle < 0:
                angle += 360

        angle = (angle + 90) % 360
        astangles[a] = angle

    orderedAngles = sorted(astangles.items(), key = lambda kv:(kv[1], kv[0]))
    destructOrder = [0] * len(orderedAngles)
    
    lp = 0
    d = 1
    while 0 in destructOrder:
        if destructOrder[lp] == 0:
            destructOrder[lp] = d
            d += 1

            n = (lp + 1) % len(orderedAngles)
            while orderedAngles[lp][1] == orderedAngles[n][1]:
                lp = n
                n = (lp + 1) % len(orderedAngles)
        else:
            n = (lp + 1) % len(orderedAngles)

        lp = n


    i200 = destructOrder.index(200)
    print(orderedAngles[i200])

    f.close()
