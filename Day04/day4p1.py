#!/usr/bin/python3
#
# Advent of Code 2019
# Day 4 : Secure Container
# 
# Author : Charlie Rose
# Language : Python3
# Date : 12/5/2019

if __name__ == "__main__":
    minPass = 178416
    maxPass = 676461
    possiblePasses = []

    for i in range(minPass, maxPass+1):
        increasing = False
        containsDouble = False

        stringPass = str(i)
        for j in range(len(stringPass)-1):
            if int(stringPass[j]) > int(stringPass[j+1]):
                increasing = True

            if stringPass[j] == stringPass[j+1]:
                containsDouble = True

        if (not increasing) and containsDouble:
            possiblePasses.append(stringPass)

    print(len(possiblePasses))
