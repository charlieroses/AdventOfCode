#!/usr/bin/python3
#
# Advent of Code 2019
# Day 1 : The Tyranny of the Rocket Equation
# 
# Author : Charlie Rose
# Language : Python3
# Date : 12/4/2019

if __name__ == "__main__":
    f = open("day1input.txt")
    totalfuel = 0
    

    for line in f.readlines():
        mass = int(line)
        fuel = (mass // 3) - 2
        totalfuel += fuel

    print(totalfuel)

    f.close()
