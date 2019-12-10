#!/usr/bin/python3
#
# Advent of Code 2019
# Day 9 : Sensor Boost
# 
# Author : Charlie Rose
# Language : Python3
# Date : 12/9/2019

def getOperand(op, mode):
    if mode == 2:
        # Relative Mode
        rv = accessMemory(op + relativeBase)
    elif mode == 1:
        # Immidiate Mode
        rv =  op
    elif mode == 0:
        # Destination Mode
        rv =  accessMemory(op)

    else:
        print( "Bad Mode" )
        return -1
    
    return rv

def increaseMemory(mem):
    global program
    while len(program) <= mem:
        program.append(0)

def accessMemory(loc):
    if loc >= len(program):
        increaseMemory(loc)
    return program[loc]

def editMemory(loc, val):
    global program
    if loc >= len(program):
        increaseMemory(loc)
    program[loc] = val


f = open("day9input.txt")

relativeBase = 0

# read the file and prep it for parsing
program = f.readlines()[0].split(",")
for i in range(0, len(program)):
    program[i] = int(program[i])

i = 0
while i < len(program):
    if accessMemory(i) > 99:
        longopcode = str(accessMemory(i))

        while len(longopcode) < 5:
            longopcode = "0" + longopcode

        opcode = int(longopcode[3:5])
        param1mode = int(longopcode[2])
        param2mode = int(longopcode[1])
        param3mode = int(longopcode[0])

    else:
        opcode = accessMemory(i)
        param1mode = 0
        param2mode = 0
        param3mode = 0

    # Opcode 1 : Add
    if opcode == 1:
        operand1 = accessMemory(i + 1)
        operand2 = accessMemory(i + 2)
        operand3 = accessMemory(i + 3)

        val1 = getOperand(operand1, param1mode)
        val2 = getOperand(operand2, param2mode)
        dest = operand3

        if param3mode == 2:
            dest += relativeBase

        editMemory(dest, val1 + val2)

        i += 4

    # Opcode 2 : Multiply
    if opcode == 2:
        operand1 = accessMemory(i + 1)
        operand2 = accessMemory(i + 2)
        operand3 = accessMemory(i + 3)
 
        val1 = getOperand(operand1, param1mode)
        val2 = getOperand(operand2, param2mode)
        dest = operand3

        if param3mode == 2:
            dest += relativeBase

        editMemory(dest, val1 * val2) 
            
        i += 4
    
    # Opcode 3 : Get Input
    if opcode == 3:
        operand1 = accessMemory(i + 1)

        dest = operand1
        if param1mode == 2:
            dest += relativeBase

        print("Enter an Int")
        value = int(input())

        editMemory(dest, value)
    
        i += 2 
    
    # Opcode 4 : Give Output
    if opcode == 4:
        operand1 = accessMemory(i + 1)
  
        outVal = getOperand(operand1, param1mode)

        print( outVal )

        i += 2

    # Opcode 5 : Jump If True
    if opcode == 5:
        operand1 = accessMemory(i + 1)
        operand2 = accessMemory(i + 2)
 
        test = getOperand(operand1, param1mode)
        dest = getOperand(operand2, param2mode)

        if test:
            i = dest
        else:
            i += 3

    # Opcode 6 : Jump If False
    if opcode == 6:
        operand1 = accessMemory(i + 1)
        operand2 = accessMemory(i + 2)
        
        test = getOperand(operand1, param1mode)
        dest = getOperand(operand2, param2mode)
            
        if (not test):
            i = dest
        else:
            i += 3

    # Opcode 7 : Less Than
    if opcode == 7:
        operand1 = accessMemory(i + 1)
        operand2 = accessMemory(i + 2)
        operand3 = accessMemory(i + 3)

        val1 = getOperand(operand1, param1mode)
        val2 = getOperand(operand2, param2mode)
        dest = operand3

        if param3mode == 2:
            dest += relativeBase

        editMemory(dest, int( val1 < val2 ))

        i += 4
            

    # Opcode 8 : Equals
    if opcode == 8:
        operand1 = accessMemory(i + 1)
        operand2 = accessMemory(i + 2)
        operand3 = accessMemory(i + 3)
        
        val1 = getOperand(operand1, param1mode)
        val2 = getOperand(operand2, param2mode)
        dest = operand3

        if param3mode == 2:
            dest += relativeBase

        editMemory(dest, int( val1 == val2 ))

        i += 4

    # Opcode 9 : Adjust Relative Base
    if opcode == 9:
        operand1 = accessMemory(i + 1)

        val1 = getOperand(operand1, param1mode)

        relativeBase += val1

        i += 2


    # Opcode 99 : Halt
    if opcode == 99:
        break

f.close()
