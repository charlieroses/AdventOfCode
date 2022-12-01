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
    imgRendered = ["x"] * layerLength

    currLayer = ""
    currRender = ""
    for v in imgSrc:
        currLayer += v
        currRender 
        if len(currLayer) % layerLength == 0:
            imgLayered.append(currLayer)
            currLayer = ""

    # Render the layers
    for l in imgLayered:
        for i in range(len(l)):
            if (l[i] == "0") and (imgRendered[i] == "x") :
                imgRendered[i] = "."
            elif (l[i] == "1") and (imgRendered[i] == "x") :
                imgRendered[i] = "#"

    # Pretty print the image
    prettyPrint = ""
    for i in range(len(imgRendered)):
        if i % imgW == 0:
            prettyPrint += "\n"
        prettyPrint += imgRendered[i]

    print(prettyPrint)

    f.close()
