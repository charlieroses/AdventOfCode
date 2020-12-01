#!/usr/bin/python3

# Advent of Code 2019
# Day 12 : The N-Body Problem
# 
# Author : Charlie Rose
# Language : Python3
# Date : 12/31/2019

import math

def prime_factor(n):
    f = {}
    
    for i in range(2, n+1):
        while n % i == 0:
            if i in f.keys():
                f[i] += 1
            else:
                f[i] = 1
            n = n / i
    return f



if __name__ == "__main__":
    moonsP = []
    moonsPi = []
    moonsV = [ [0,0,0], [0,0,0], [0,0,0], [0,0,0]]

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

############# First find the lowest x repeat    
    x_rep = 0
    time = 0
    while True:
        time += 1
        for m1 in range(4):
            for m2 in range(4):
                if m1 == m2:
                    continue
                for xyz in range(3):
                    if moonsP[m1][xyz] > moonsP[m2][xyz]:
                        moonsV[m1][xyz] -= 1
                    elif moonsP[m1][xyz] < moonsP[m2][xyz]:
                        moonsV[m1][xyz] += 1

        for m in range(4):
            for xyz in range(3):
                moonsP[m][xyz] += moonsV[m][xyz]

        vel0 = True
        for m in range(4):
            if not(moonsV[m][0] == 0):
                vel0 = False

        repeat = False
        if vel0:
            repeat = True
            for m in range(4):
                if not(moonsP[m][0] == moonsPi[m][0]):
                    repeat = False

        if repeat:
            break

    x_rep = time
    print(x_rep)

############# Reset run again
    moonsP = []
    moonsV = [ [0,0,0], [0,0,0], [0,0,0], [0,0,0]]
    
    for m in range(4):
        pos = []
        for c in range(3):
            pos.append(moonsPi[m][c])
        moonsP.append(pos)

    time = 0
############# Find the lowest y repeat
    y_rep = 0
    while True:
        time += 1
        for m1 in range(4):
            for m2 in range(4):
                if m1 == m2:
                    continue
                for xyz in range(3):
                    if moonsP[m1][xyz] > moonsP[m2][xyz]:
                        moonsV[m1][xyz] -= 1
                    elif moonsP[m1][xyz] < moonsP[m2][xyz]:
                        moonsV[m1][xyz] += 1

        for m in range(4):
            for xyz in range(3):
                moonsP[m][xyz] += moonsV[m][xyz]

        vel0 = True
        for m in range(4):
            if not(moonsV[m][1] == 0):
                vel0 = False

        repeat = False
        if vel0:
            repeat = True
            for m in range(4):
                if not(moonsP[m][1] == moonsPi[m][1]):
                    repeat = False

        if repeat:
            break

    y_rep = time
    print(y_rep)
############# Reset run again
    moonsP = []
    moonsV = [ [0,0,0], [0,0,0], [0,0,0], [0,0,0]]
    
    for m in range(4):
        pos = []
        for c in range(3):
            pos.append(moonsPi[m][c])
        moonsP.append(pos)

    time = 0
############# Find the lowest z repeat
    z_rep = 0
    while True:
        time += 1
        for m1 in range(4):
            for m2 in range(4):
                if m1 == m2:
                    continue
                for xyz in range(3):
                    if moonsP[m1][xyz] > moonsP[m2][xyz]:
                        moonsV[m1][xyz] -= 1
                    elif moonsP[m1][xyz] < moonsP[m2][xyz]:
                        moonsV[m1][xyz] += 1

        for m in range(4):
            for xyz in range(3):
                moonsP[m][xyz] += moonsV[m][xyz]

        vel0 = True
        for m in range(4):
            if not(moonsV[m][2] == 0):
                vel0 = False

        repeat = False
        if vel0:
            repeat = True
            for m in range(4):
                if not(moonsP[m][2] == moonsPi[m][2]):
                    repeat = False

        if repeat:
            break

    z_rep = time
    print(z_rep)


############# Calc LCM

    x_fact = prime_factor(x_rep)
    y_fact = prime_factor(y_rep)
    z_fact = prime_factor(z_rep)

    print(x_fact)
    print(y_fact)
    print(z_fact)

    p_factors = list(set(x_fact.keys()) | set(y_fact.keys()) | set(z_fact.keys()))
    p_fact = {}


    for i in p_factors:
        p_fact[i] = 0
        if (i in x_fact.keys()) and (x_fact[i] > p_fact[i]):
           p_fact[i] = x_fact[i] 
        if (i in y_fact.keys()) and (y_fact[i] > p_fact[i]):
           p_fact[i] = y_fact[i] 
        if (i in z_fact.keys()) and (z_fact[i] > p_fact[i]):
           p_fact[i] = z_fact[i] 

    print(p_fact)
    ans = 1
    
    for i in p_fact.keys():
        ans = int(ans * math.pow(i, p_fact[i]))

    print(ans)
    
    f.close()
