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
    init_program = f.readlines()[0].split(",")
    for i in range(0, len(init_program)):
        init_program[i] = int(init_program[i])

      
    for noun in range(0, 99):
        for verb in range(0,99):

            # Prep program for runnning
            program = []
            for i in init_program:
                program.append(i)

            program[1] = noun
            program[2] = verb
            i = 0

            # run program with inputs
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
                    if program[0] == 19690720:
                        print("Noun : " + str(noun) + ", Verb : " + str(verb) + ", Output : " + str(program[0]))
                    
                    break


    f.close()
