#!/usr/bin/python3
#
# Advent of Code 2019
# Day 14 : Space Stoichiometry
# 
# Author : Charlie Rose
# Language : Python3
# Date : 12/26/2019

###############################################################################
import math


# Dicitonary of counts
#   ( product : count made )
productsCount = {}

# Dictionary of tuples
#   ( product : [list of reactant tuples] )
# reactant tuple
#   ( reactant, reactant count )
reactions = {}

# Dictionary of extra products made
#   ( product : leftover count )
extraProd = {}

# Total Ore needed
totalOre = 0

###############################################################################

def calcOre(chem, need):
    global productsCount
    global reactions
    global extraProd
    global totalOre


    mult = math.ceil( need / productsCount[chem])
    extraProd[chem] += (productsCount[chem] * mult) - need

    for r in reactions[chem]:
        if r[0] == "ORE":
            totalOre += (r[1] * mult)
        else:
            n2 = r[1] * mult
            if not (extraProd[r[0]] == 0):
                if extraProd[r[0]] >= n2:
                    extraProd[r[0]] = extraProd[r[0]] - n2
                    n2 = 0
                else:
                    n2 = n2 - extraProd[r[0]]
                    extraProd[r[0]] = 0
            if not (n2 == 0):
                calcOre( r[0], n2 )

###############################################################################

if __name__ == "__main__":
    fname = input("Input File Name : ")
    f = open(fname)
    for react in f.readlines():
        rsplit = react.split("=>")
        
        reactants = rsplit[0]
        rtsplit = reactants.split(",")
        rlist = []
        for r in rtsplit:
            rt = r
            if rt[0] == " ":
                rt = rt[1:]
            if rt[-1] == " ":
                rt = rt[:-1]
            rn = rt.split(" ")[1]
            rc = int(rt.split(" ")[0])
            rlist.append((rn, rc))

        fproduct = rsplit[1][1:-1]
        prodName = fproduct.split(" ")[1]
        prodAmount = fproduct.split(" ")[0]
    
        reactions[prodName] = rlist
        productsCount[prodName] = int(prodAmount)
        extraProd[prodName] = 0

    calcOre("FUEL", 1)

    print(totalOre)

    f.close()
