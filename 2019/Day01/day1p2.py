#!/usr/bin/python3
#
# Advent of Code 2019
# Day 1 : The Tyranny of the Rocket Equation
# 
# Author : Charlie Rose
# Language : Python3
# Date : 12/4/2019

def fuelcount(mass):
    fuel = (mass // 3) - 2
    
    if fuel > 0:
        return fuel + fuelcount(fuel)
    else:
        return 0;


if __name__ == "__main__":
    f = open("day1input.txt")
    totalfuel = 0
    

    for line in f.readlines():
        mass = int(line)
        totalfuel += fuelcount(mass)

    print(totalfuel)

    f.close()
