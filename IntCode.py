#!/usr/bin/python3
#
# Advent of Code 2019
# Run Program IntCode Computer
# 
# Author : Charlie Rose
# Language : Python3
# Date : 12/26/2019


################################## GLOBALS ####################################

relativeBase = 0
program = []

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


# Function : Run Program
# Parameters : 
#   none
# Returns :
#   Halt Code ( "HALT" )
def runProgram(  ): 
    ip = 0
    while ip < len(program):
        longopcode = str(accessMemory(ip))

        while len(longopcode) < 5:
            longopcode = "0" + longopcode

        opcode = int(longopcode[3:5])
        param1mode = int(longopcode[2])
        param2mode = int(longopcode[1])
        param3mode = int(longopcode[0])

        # Opcode 1 : Add
        if opcode == 1:
            operand1 = accessMemory(ip + 1)
            operand2 = accessMemory(ip + 2)
            operand3 = accessMemory(ip + 3)

            val1 = getOperand(operand1, param1mode)
            val2 = getOperand(operand2, param2mode)
            dest = operand3

            if param3mode == 2:
                dest += relativeBase

            editMemory(dest, val1 + val2)

            ip += 4

        # Opcode 2 : Multiply
        if opcode == 2:
            operand1 = accessMemory(ip + 1)
            operand2 = accessMemory(ip + 2)
            operand3 = accessMemory(ip + 3)
 
            val1 = getOperand(operand1, param1mode)
            val2 = getOperand(operand2, param2mode)
            dest = operand3

            if param3mode == 2:
                dest += relativeBase

            editMemory(dest, val1 * val2) 
            
            ip += 4
    
        # Opcode 3 : Get Input
        if opcode == 3:
            operand1 = accessMemory(ip + 1)

            dest = operand1
            if param1mode == 2:
                dest += relativeBase

            print("Enter an Int")
            value = int(input())

            editMemory(dest, value)
    
            ip += 2 
    
        # Opcode 4 : Give Output
        if opcode == 4:
            operand1 = accessMemory(ip + 1)
  
            outVal = getOperand(operand1, param1mode)

            print( outVal )

            ip += 2

        # Opcode 5 : Jump If True
        if opcode == 5:
            operand1 = accessMemory(ip + 1)
            operand2 = accessMemory(ip + 2)
 
            test = getOperand(operand1, param1mode)
            dest = getOperand(operand2, param2mode)

            if test:
                ip = dest
            else:
                ip += 3

        # Opcode 6 : Jump If False
        if opcode == 6:
            operand1 = accessMemory(ip + 1)
            operand2 = accessMemory(ip + 2)
        
            test = getOperand(operand1, param1mode)
            dest = getOperand(operand2, param2mode)
            
            if (not test):
                ip = dest
            else:
                ip += 3

        # Opcode 7 : Less Than
        if opcode == 7:
            operand1 = accessMemory(ip + 1)
            operand2 = accessMemory(ip + 2)
            operand3 = accessMemory(ip + 3)

            val1 = getOperand(operand1, param1mode)
            val2 = getOperand(operand2, param2mode)
            dest = operand3

            if param3mode == 2:
                dest += relativeBase
    
            editMemory(dest, int( val1 < val2 ))

            ip += 4
            

        # Opcode 8 : Equals
        if opcode == 8:
            operand1 = accessMemory(ip + 1)
            operand2 = accessMemory(ip + 2)
            operand3 = accessMemory(ip + 3)
        
            val1 = getOperand(operand1, param1mode)
            val2 = getOperand(operand2, param2mode)
            dest = operand3

            if param3mode == 2:
                dest += relativeBase

            editMemory(dest, int( val1 == val2 ))

            ip += 4

        # Opcode 9 : Adjust Relative Base
        if opcode == 9:
            operand1 = accessMemory(ip + 1)

            val1 = getOperand(operand1, param1mode)

            relativeBase += val1

            ip += 2


        # Opcode 99 : Halt
        if opcode == 99:
            return "HALT"

##################################### MAIN ####################################

if __name__ == "__main__":

    f = open("day9input.txt")


    # read the file and prep it for parsing
    program = f.readlines()[0].split(",")
    for i in range(0, len(program)):
        program[i] = int(program[i])
    
    runProgram()

    f.close()
