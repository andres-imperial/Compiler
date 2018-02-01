// ----------------------------------------------------------------------------
// Andres Imperial
// CSCP 323 mw 11:30am
// Assignment 2: Parser
//
// file: parser_functs.h
// ----------------------------------------------------------------------------

#ifndef PARSER_FUNCTS_H
#define PARSER_FUNCTS_H
#include <cstring>
using namespace std;

// Function Declarations

bool Parser(string fileName, int lineCount);
bool lexeme_is(string target);
bool token_is(string target);
bool Rat16F(void);
bool Opt_Funct_Def(void);
bool Opt_Declar_List(void);
bool Statement_List(void);
bool Funct_Def(void);
bool Function(void);
bool Identifier(void);
bool Opt_Param_List(void);
bool Body(void);
bool Param_List(void);
bool Parameter(void);
bool IDs(void);
bool Qualifier(void);
bool Declar_List(void);
bool Declaration(void);
bool Statement(void);
bool Compound(void);
bool Assign(void);
bool If(void);
bool Return(void);
bool Write(void);
bool Read(void);
bool While(void);
bool Expression(void);
bool Condition(void);
bool Relop(void);
bool Expression_Prime(void);
bool Term(void);
bool Term_Prime(void);
bool Factor(void);
bool Primary(void);
void Print_Instructions(void);
void Back_Patch(int jump_addr);
void Gen_Instr(string op, string oprnd);

#endif // End of parser_functs.h
