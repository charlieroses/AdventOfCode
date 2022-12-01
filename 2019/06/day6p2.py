#!/usr/bin/python3
#
# Advent of Code 2019
# Day 6 : Universal Orbit Map
# 
# Author : Charlie Rose
# Language : Python3
# Date : 12/8/2019


universeTree = {}
pathList = []

def countOrbits(parent, level):
    if universeTree[parent] == -1:
        return 0
    else:
        return level * len(universeTree[parent]) + countKidOrbits(universeTree[parent], level+1)

def countKidOrbits(children, level):
    t = 0
    for kid in children:
        t += countOrbits(kid, level)
    return t

def listOfPathsToLeaves(parent, inProgress):
    inProgress += parent + ","
    if universeTree[parent] == -1:
        return inProgress
    else:
        for child in universeTree[parent]:
            pathList.append( listOfPathsToLeaves(child, inProgress) )
        return "flag"



if __name__ == "__main__":
    f = open("day6input.txt")

    # Read the file and store the children
    for line in f.readlines():
        pair = line.split(")")
        parent = pair[0]
        child = pair[1][0:-1]

        if parent in universeTree:
            if universeTree[parent] == -1:
                universeTree[parent] = [child]
            else:
                universeTree[parent].append(child)
        else:
            universeTree[parent] = [child]

        if (not (child in universeTree)):
            # The child is a leaf
            universeTree[child] = -1


    listOfPathsToLeaves("COM", "")
    santaPath = []
    youPath = []

    for p in pathList:
        if p == "flag":
            continue
        
        pl = p.split(",")

        if "SAN" in pl:
            santaPath = pl[0:-2]

        if "YOU" in pl:
            youPath = pl[0:-2]


    matching = 0

    if len(santaPath) <= len(youPath):
        shorterPath = santaPath
    else:
        shorterPath = youPath

    for i in range(len(shorterPath)):
        if santaPath[i] == youPath[i]:
            matching += 1

    shortestOrbits = len(youPath) + len(santaPath) - (2 * matching)
   
    print(shortestOrbits)

    f.close()
