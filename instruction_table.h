// ----------------------------------------------------------------------------
// Andres Imperial
// CSCP 323 mw 11:30am
// Assignment 3: Generating Assembly Code
//
// file: instruction_table.h
// ----------------------------------------------------------------------------

#ifndef INSTRUCTION_TABLE_H
#define INSTRUCTION_TABLE_H

#include <cstring>
using namespace std;

// Instruction table structure
struct Instruction_Table
{
    public:
        int address = 0;
        string op;
        string oprnd;
}; // End of Instruction_Table struct

#endif // End of instruction_table.h


