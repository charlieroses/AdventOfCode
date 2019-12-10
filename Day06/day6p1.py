#!/usr/bin/python3
#
# Advent of Code 2019
# Day 6 : Universal Orbit Map
# 
# Author : Charlie Rose
# Language : Python3
# Date : 12/7/2019


universeTree = {}

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


    print(countOrbits("COM", 1))

    f.close()
