// ----------------------------------------------------------------------------
// Andres Imperial
// CPSC 323 MW 11:30am
// Assignment 1: Lexer
//
// File: identifier.h
// Header file for recognizing identifiers using a id_FSM. The following FSM is
// declared in this header file.
//
// Starting state is designated by a -> and all accepting states are designated
// by a prefix underscore(_).
// States 1 and 3 are accepting states for type identifer.
// States 0, 2, and 4 are non-accepting states.
//
//   _|_(l)_(_)_(d)__
// ->0|  1   4   4
//  _1|  3   2   3
//   2|  3   2   3
//  _3|  3   2   3
//   4|  4   4   4
// ----------------------------------------------------------------------------

#ifndef IDENTIFIER_H
#define IDENTIFIER_H
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

// Inputs for id_FSM       l  _  d
const int id_FSM[5][3] = {{1, 4, 4},
                          {3, 2, 3},
                          {3, 2, 3},
                          {3, 2, 3},
                          {4, 4, 4}};

// --- getIdentifier ----------------------------------------------------------
// This function utilizes the FSM for identifiers to recognize lexemes and
// declare their proper token type.
//
// Input -- ifstream& sourceFile - is a refrence variable to the source file.
//       -- string& token - is a refrence variable to token type for lexeme.
//
// Output -- string - this string contains the extracted lexeme.
// ----------------------------------------------------------------------------
string getIdentifier(ifstream& sourceFile, string& token){

  char sourceChar;
  string lexeme;
  // Set current state to starting state of 0.
  int currState = 0;
  // Reset file stream pointer to original character.
  sourceFile.unget();

  // Start FSM.
  while(true){
    sourceFile.get(sourceChar);
    // Input is a letter.
    if(isalpha(sourceChar)){
      currState = id_FSM[currState][0];
      lexeme += sourceChar;
    }
    // Input is an underscore.
    else if(sourceChar == '_'){
      currState = id_FSM[currState][1];
      lexeme += sourceChar;
    }
    // Input is a digit.
    else if(isdigit(sourceChar)){
      currState = id_FSM[currState][2];
      lexeme += sourceChar;
    }
    // Input is not valid, reverse file stream pointer one step and break from
    // loop.
    else{
      sourceFile.unget();
      break;
    }
  }

  // Check current state of FSM and return proper token type.
  if(currState == 1 || currState == 3){
    token = "identifier";
  }
  else{
    token = "unknown";
  }

  return lexeme;

}// End of getIdentifier

#endif // End of identifier.h
