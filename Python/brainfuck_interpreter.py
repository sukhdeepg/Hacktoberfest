#A Brainfuck interpreter in Python - Author: github.com/R4H33M

#https://en.wikipedia.org/wiki/Brainfuck

#This is my favorite code snippet as it is a showcase  of simple interpreter design patterns for a fun, crazy language

def brainfuck_interpreter(code, input):
    output = ""
    data = {0:0}
    data_pointer = 0
    instruction_pointer = 0
    input_data = [ord(i) for i in input]
    
    while True:
        instruction = code[instruction_pointer]
        if instruction == ",":
            data[data_pointer] = input_data[0]
            input_data.pop(0)
        elif instruction == ".":
            output += chr(data[data_pointer])
        elif instruction == "-":
            if data[data_pointer] == 0:
                data[data_pointer] = 255
            else:
                data[data_pointer] -= 1
        elif instruction == "+":
            if data[data_pointer] == 255:
                data[data_pointer] = 0
            else:
                data[data_pointer] += 1
        elif instruction == ">":
            data_pointer += 1
            if data_pointer in data:
                pass
            else:
                data[data_pointer] = 0
        elif instruction == "<":
            data_pointer -= 1
            if data_pointer in data:
                pass
            else:
                data[data_pointer] = 0
        elif instruction == "[": 
            if data[data_pointer] == 0:
                b_count, f_count = 0,0
                for i in range(instruction_pointer, len(code)):
                    if code[i] == "[":
                        f_count += 1
                    elif code[i] == "]":
                        b_count += 1
                        if f_count == b_count:
                            instruction_pointer = i
                            break
            else:
                pass
        elif instruction == "]":
            if data[data_pointer] != 0:
                b_count, f_count = 0,0
                for i in range(len(code[:instruction_pointer])-1, -1, -1):
                    if code[i] == "]":
                        b_count += 1
                    elif code[i] == "[":
                        f_count += 1
                        if b_count + 1 == f_count:
                            instruction_pointer = i
                            break
            else:
                pass
                
        if instruction_pointer == (len(code) - 1):
            break
        else:
            instruction_pointer += 1
                
    return output