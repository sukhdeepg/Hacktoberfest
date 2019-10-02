# Hi I love Hello World snippet, because coding for me is more than just words it is a expression of freedom and power
# and saying Hello to the World in Assembly Mips is so loving nice that I really enjoy, so here is my hello world.

# to run this code go to http://courses.missouristate.edu/kenvollmar/mars/ 
# download mars program (it is written in java, but it's ok)


.text                       # in assembly there is a guy named program counter bellow .text is the code
.globl main                 # set main as a global value
j main                      # jump to main

exit:                       # fuction exit
      li $v0, 10            # prepare the program to end
       syscall              # execute instructions
       
main:                       # label main
      li $v0, 4             # prepare screen to a string
      la $a0, olah          # load the string olah to the register $a0
      syscall               # execute 
      j exit                # jump to exit
      
.data                       # in this part you write the variables to your code.

      olah: .asciiz " \n Hello World \n I love you\n Thanks Hacktoberfest 2019\n"
