#!/usr/bin/python3
#
# Advent of Code 2019
# Day 7 : Amplification Circuit
# 
# Author : Charlie Rose
# Language : Python3
# Date : 12/8/2019

from itertools import permutations

def day7main(in1, in2):
    f = open("day7input.txt")

    # read the file and prep it for parsing
    program = f.readlines()[0].split(",")
    for i in range(0, len(program)):
        program[i] = int(program[i])

    inputOn = 1

    i = 0
    while i < len(program):
        if program[i] > 99:
            longopcode = str(program[i])

            while len(longopcode) < 5:
                longopcode = "0" + longopcode

            opcode = int(longopcode[3:5])
            param1mode = int(longopcode[2])
            param2mode = int(longopcode[1])
            param3mode = int(longopcode[0])


        else:
            opcode = program[i]
            param1mode = 0
            param2mode = 0
            param3mode = 0

        # Opcode 1 : Add
        if opcode == 1:
            operand1 = program[i + 1]
            operand2 = program[i + 2]
            dest = program[i + 3]

            if param1mode:
                # Immidiate Mode
                val1 = operand1
            else:
                # Destination Mode
                val1 = program[operand1]

            if param2mode:
                # Immidiate Mode
                val2 = operand2
            else:
                # Destination Mode
                val2 = program[operand2]

            program[dest] = val1 + val2 

            i += 4

        # Opcode 2 : Multiply
        if opcode == 2:
            operand1 = program[i + 1]
            operand2 = program[i + 2]
            dest = program[i + 3]
 
            if param1mode:
                # Immidiate Mode
                val1 = operand1
            else:
                # Destination Mode
                val1 = program[operand1]

            if param2mode:
                # Immidiate Mode
                val2 = operand2
            else:
                # Destination Mode
                val2 = program[operand2]

            program[dest] = val1 * val2 
            
            i += 4
    
        # Opcode 3 : Get Input
        if opcode == 3:
            dest = program[i + 1]

            if inputOn == 1:
                value = in1
                inputOn = 2
            elif inputOn == 2:
                value = in2

            program[dest] = value
    
            i += 2 
    
        # Opcode 4 : Give Output
        if opcode == 4:
            operand1 = program[i + 1]
  
            if param1mode:
                # Immidiate Mode
                outVal = operand1
            else:
                # Destination Mode
                outVal = program[operand1]

            return outVal 

            i += 2

        # Opcode 5 : Jump If True
        if opcode == 5:
            operand1 = program[i + 1]
            operand2 = program[i + 2]
 
            if param1mode:
                # Immidiate Mode
                test = operand1
            else:
                # Destination Mode
                test = program[operand1]

            if param2mode:
                # Immidiate Mode
                dest = operand2
            else:
                # Destination Mode
                dest = program[operand2]

            if test:
                i = dest
            else:
                i += 3

        # Opcode 6 : Jump If False
        if opcode == 6:
            operand1 = program[i + 1]
            operand2 = program[i + 2]

            if param1mode:
                # Immidiate Mode
                test = operand1
            else:
                # Destination Mode
                test = program[operand1]

            if param2mode:
                # Immidiate Mode
                dest = operand2
            else:
                # Destination Mode
                dest = program[operand2]
            
            if (not test):
                i = dest
            else:
                i += 3

        # Opcode 7 : Less Than
        if opcode == 7:
            operand1 = program[i + 1]
            operand2 = program[i + 2]
            operand3 = program[i + 3]

            if param1mode:
                # Immidiate Mode
                val1 = operand1
            else:
                # Destination Mode
                val1 = program[operand1]

            if param2mode:
                # Immidiate Mode
                val2 = operand2
            else:
                # Destination Mode
                val2 = program[operand2]

            program[operand3] = int( val1 < val2 )

            i += 4
            

        # Opcode 8 : Equals
        if opcode == 8:
            operand1 = program[i + 1]
            operand2 = program[i + 2]
            operand3 = program[i + 3]

            if param1mode:
                # Immidiate Mode
                val1 = operand1
            else:
                # Destination Mode
                val1 = program[operand1]

            if param2mode:
                # Immidiate Mode
                val2 = operand2
            else:
                # Destination Mode
                val2 = program[operand2]

            program[operand3] = int( val1 == val2 )

            i += 4
 
        # Opcode 99 : Halt
        if opcode == 99:
            break

    f.close()


if __name__ == "__main__":
    sequences = [''.join(p) for p in permutations("01234")]
    
    maxSeq = sequences[0]
    carry = 0
    for v in maxSeq:
        carry = day7main(int(v), carry)
    maxVal = carry
    
    for seq in sequences:
        carry = 0
        for v in seq:
            carry = day7main(int(v), carry)

        if carry > maxVal:
            maxVal = carry
            maxSeq = seq

    print("Sequence :", maxSeq, ", Value :", maxVal)
