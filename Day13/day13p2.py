#!/usr/bin/python3
#
# Advent of Code 2019
# Day 13 : Care Package
# 
# Author : Charlie Rose
# Language : Python3
# Date : 12/19/2019


################################# FUNCTIONS ###################################

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


def displayBoard(pieces):
    width = 42
    hieght = 24
    
    board = ["."] * (width * hieght)
    
    p = 2
    while p < len(pieces):
        x = pieces[p - 2]
        y = pieces[p - 1]
        g = pieces[p]
        c = "."
        
        if x == -1:
            if y == 0:
                print(g)

        if g == 1:
            c = "X"
        elif g == 2:
            c = "0"
        elif g == 3:
            c = "T"
        elif g == 4:
            c = "o"
        elif g == 0:
            c = "."
       
        i = (y * width) + x
        board[i] = c

        p += 3

    for i in range(len(board)):
        print(board[i], end="")
        if i%width == 0:
            print()

##################################### MAIN ####################################

gamePieces = []

relativeBase = 0

# read the file and prep it for parsing
f = open("day13input.txt")
program = f.readlines()[0].split(",")
for i in range(0, len(program)):
    program[i] = int(program[i])

program[0] = 2
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
    
###############################################################################
    # Opcode 3 : Get Input
    if opcode == 3:
        operand1 = accessMemory(i + 1)

        dest = operand1
        if param1mode == 2:
            dest += relativeBase


        displayBoard(gamePieces)
        print("\n -1 : L, 1 : R")

        value = 3
        while not( value == 0 or value == 1 or value == -1):
            try:
                value = int(input())
            except:
                continue


        editMemory(dest, value)

        i += 2 
    
    # Opcode 4 : Give Output
    if opcode == 4:
        operand1 = accessMemory(i + 1)
  
        outVal = getOperand(operand1, param1mode)

        gamePieces.append(outVal)

        i += 2

###############################################################################
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
###############################################################################

f.close()
