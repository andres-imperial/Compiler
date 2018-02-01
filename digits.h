// ----------------------------------------------------------------------------
// Andres Imperial
// CPSC 323 MW 11:30am
// Assignment 1: Lexer
//
// File: digits.h
// Header file for recognizing reals and integers using a FSM. The following
// FSM is declared in this header file.
//
// Starting state is designated by a -> and all accepting states are designated
// by a prefix underscore(_).
// Accepting state 1 is for digits.
// Accepting state 3 is for reals.
// States 0, 2, 4 are none accepting states.
//
//   _|_(d)_(.)__
// ->0|  1   4
//  _1|  1   2
//   2|  3   4
//  _3|  3   4
//   4|  4   4
// ----------------------------------------------------------------------------

#ifndef DIGITS_H
#define DIGITS_H
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

// Inputs for digits_FSM       d  .
const int digits_FSM[5][2] = {{1, 4},
                              {1, 2},
		                      {3, 4},
		                      {3, 4},
		                      {4, 4}};

// --- getDigit ---------------------------------------------------------------
// This function utilizes the FSM for digits to recognize lexemes and declare
// their appropriate token type.
//
// Input -- ifstream& sourceFile - is a refrence variable to the source file.
//       -- string& token - is a refrence variable to token type for lexeme.
//
// Output -- string - this string contains the extracted lexeme.
// ----------------------------------------------------------------------------
string getDigit(ifstream& sourceFile, string& token){

  char sourceChar;
  string lexeme;
  // Set current state to starting state (0).
  int currState = 0;
  // Reset file stream pointer to original character.
  sourceFile.unget();

  // Start digits_FSM.
  while(true){
    sourceFile.get(sourceChar);
    // Input is a digit
    if(isdigit(sourceChar)){
      currState = digits_FSM[currState][0];
      lexeme += sourceChar;
    }
    // Input is a decimal
    else if(sourceChar == '.'){
      currState = digits_FSM[currState][1];
      lexeme += sourceChar;
    }
    // Input is not valid for integer or real, reverse file stream pointer one
    // step and break from loop.
    else{
      sourceFile.unget();
      break;
    }
  }

  // Check current state of FSM and return proper token.
  if(currState == 1){
    token = "integer";
  }
  else if(currState == 2 || currState == 4){
    token = "unknown";
  }
  else if(currState == 3){
    token = "real";
  }

  return lexeme;

}// End of getDigit

#endif // End of digits.h
