#!/usr/bin/python3
#
# Advent of Code 2019
# Day 7 : Amplification Circuit
# 
# Author : Charlie Rose
# Language : Python3
# Date : 12/29/2019

###############################################################################

from itertools import permutations

prog = 0
programHC = []
programs = [ [], [], [], [], [] ]
ips = [0, 0, 0, 0, 0]

###############################################################################

def getOperand(op, mode):
    rv = -1
    if mode == 1:
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
    global programs

    while len(programs[prog]) <= mem:
        programs[prog].append(0)

def accessMemory(loc):
    if loc >= len(programs[prog]):
        increaseMemory(loc)
    return programs[prog][loc]

def editMemory(loc, val):
    global programs

    if loc >= len(programs[prog]):
        increaseMemory(loc)
    programs[prog][loc] = val


# Function : Run Program
# Parameters : 
#   none
# Returns :
#   Halt Code ( "HALT" )
def runProgram( in1, in2  ): 
    global ips
    if in1 == 0:
        inputMode = 2
    else:
        inputMode = 1
    
    ip = ips[prog]

    while ip < len(programs[prog]):
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

            editMemory(dest, val1 * val2) 
            
            ip += 4
    
        # Opcode 3 : Get Input
        if opcode == 3:
            operand1 = accessMemory(ip + 1)

            dest = operand1

            if inputMode == 1:
                value = in1
                inputMode = 2
            else:
                value = in2

            editMemory(dest, value)
    
            ip += 2 
    
        # Opcode 4 : Give Output
        if opcode == 4:
            operand1 = accessMemory(ip + 1)
  
            outVal = getOperand(operand1, param1mode)

            ip += 2
            
            ips[prog] = ip
            return outVal

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

            editMemory(dest, int( val1 == val2 ))

            ip += 4

        # Opcode 99 : Halt
        if opcode == 99:
            return "HALT"

###############################################################################


if __name__ == "__main__":
    f = open("day7input.txt")
    # Load programs
    programf = f.readlines()[0].split(",")
    for i in range(0, len(programf)):
        programHC.append( int(programf[i]) )
    
    # Actually run the day 7
    sequences = [''.join(p) for p in permutations("56789")]

    maxSeq = ""
    maxVal = 0
    
    for seq in sequences:
        ips = [0,0,0,0,0]
        programs = [ [], [], [], [], []]
        for p in range(5):
            for n in programHC:
                programs[p].append(n)

        carry = 0
        for v in seq:
            carry = runProgram(int(v), carry)
            prog += 1
            prog = prog % 5

        while True:
            cT = runProgram(0, carry)
            prog += 1
            prog = prog % 5
            if not(cT == "HALT"):
                carry = cT
            else:
                break


        if carry > maxVal:
            maxVal = carry
            maxSeq = seq

        print( seq, ":", carry)
            
    print("Sequence :", maxSeq, ", Value :", maxVal)

    f.close()

