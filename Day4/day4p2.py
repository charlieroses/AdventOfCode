#!/usr/bin/python3
#
# Advent of Code 2019
# Day 4 : Secure Container
# 
# Author : Charlie Rose
# Language : Python3
# Date : 12/6/2019

if __name__ == "__main__":
    minPass = 178416
    maxPass = 676461
    possiblePasses = []

    for i in range(minPass, maxPass+1):
        increasing = False
        containsDouble = False
        counts = [0,0,0,0,0,0,0,0,0,0]
    
        stringPass = str(i)
        
        counts[int(stringPass[-1])] += 1
        
        for j in range(len(stringPass)-1):
            if int(stringPass[j]) > int(stringPass[j+1]):
                increasing = True

            counts[int(stringPass[j])] += 1
        

        if 2 in counts:
            containsDouble = True
        
        print(i)
        if (not increasing) and containsDouble:
            possiblePasses.append(stringPass)

    print(len(possiblePasses))
