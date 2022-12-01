#!/usr/bin/python3
#
# Advent of Code 2019
# Day 2 : 1202 Program Alarm
# 
# Author : Charlie Rose
# Language : Python3
# Date : 12/4/2019

if __name__ == "__main__":
    f = open("day2input.txt")

    # read the file and prep it for parsing
    program = f.readlines()[0].split(",")
    for i in range(0, len(program)):
        program[i] = int(program[i])

    # parse code
    program[1] = 12
    program[2] = 2
   
    i = 0
    while i < len(program):
        # Opcode 1 : Add
        if program[i] == 1:
            operand1 = program[i + 1]
            operand2 = program[i + 2]
            dest = program[i + 3]
           
            program[dest] = program[operand1] + program[operand2]

            i += 4

        # Opcode 2 : Multiply
        if program[i] == 2:
            operand1 = program[i + 1]
            operand2 = program[i + 2]
            dest = program[i + 3]
 
            program[dest] = program[operand1] * program[operand2]
            
            i += 4


        # Opcode 99 : Halt
        if program[i] == 99:
            break


    print(program[0])
    f.close()
