#!/usr/bin/python3
#
# Advent of Code 2019
# Day 8 : Space Image Format
# 
# Author : Charlie Rose
# Language : Python3
# Date : 12/8/2019

def calcValInLayer( v, l ):
    c = 0
    
    for i in l:
        if i == v:
            c += 1

    return c


if __name__ == "__main__":
    f = open("day8input.txt")
    imgH = 6
    imgW = 25
    layerLength = imgH * imgW

    # Read the file
    imgSrc = f.readlines()[0][0:-1]

    # Parse the image
    imgLayered = []
    currLayer = ""
    for v in imgSrc:
        currLayer += v
        if len(currLayer) % layerLength == 0:
            imgLayered.append(currLayer)
            currLayer = ""

    
    # Find least 0s
    minLayer0s = imgLayered[0]
    minCount0s = calcValInLayer( "0", minLayer0s )

    for l in imgLayered:
        if calcValInLayer("0", l) < minCount0s:
            minCount0s = calcValInLayer("0", l)
            minLayer0s = l

    minLayer1s = calcValInLayer( "1", minLayer0s )
    minLayer2s = calcValInLayer( "2", minLayer0s )

    print(minLayer1s, minLayer2s, minLayer1s * minLayer2s)


    f.close()
