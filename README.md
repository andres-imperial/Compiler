
# Compiler
The objective is to create a symbol table handling mechanism and generating an assembly code output for the 
simplified version of Rat16F.

### How to Compile:
Have all source code in one directory and run the following command to compile with 
g++(requires c++11 libraries):  
  `g++ -g -std=c++11 main.cpp -o Assembler`

### How to use this program
Assembler is the name of the executable file. In order to run a lexical analysis and parse a file for syntax 
analysis, while creating a symbol table and instruction set according to the simplified RAT16F language provide 
the file name as an argument in the command line when running Assembler. 

Proper format follows:  
  `./Assembler yourfile.txt`

After execution Assembler will create a multiple new files in the current directory labeled:
+ lexer_yourfile.txt: This file will hold all the tokens and lexemes extracted from your file.
+ parser_yourfile.txt: This file will then contain all production rules utilized when parsing yourfile.txt.
+ instr_yourfile.txt: This will hold the instruction set.
+ symbol_yourfile.txt: This file will contain the symbol table that represents your file.

### Design of program
I chose to create two header files, one being instruction_table.h that defines a stuct for a single instruction. 
I then declared this an array of this struct in my parser.h file with a size of 600. The other new header file is 
symbols.h which creates a class for the symbol table with a max size of 100 symbols. This file also contains helper 
functions such as print, get address, find, size, and insert. For the jump stack I implemented C++’s container 
template <stack> with type <int>.

### Some Semantics:
1. consider that  “true” has an integer value of 1 and “false” has an integer value of 0.
2. No arithmetic operations are allowed for booleans.
3. The types must match for arithmetic operations (no conversions)

### Limitations
Max amount of instruction is 600 and the max amount of symbols is 100.

### Contact
###### andres.imperial@live.com
