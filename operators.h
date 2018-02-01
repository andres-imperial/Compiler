// ----------------------------------------------------------------------------
// Andres Imperial
// CPSC 323 MW 11:30am
// Assignment 1: Lexer
//
// File: operators.h
// Header file to declare the operator symbols and some helper funtions for
// Rat16F language.
// ----------------------------------------------------------------------------

#ifndef OPERATOR_H
#define OPERATOR_H
#include <string>
#include <fstream>
using namespace std;

// Declaration of operators list.
const string operators[] = {":=", "/=", "=>", "<=", "=", ">", "<", "+", "-",
                            "*", "/"};

// --- isOperator(char) -------------------------------------------------------
// Function checks a single character to see if it is apart of the operator
// list.
//
// Input -- char sourceChar - given character to check for in operator list.
//
// Output -- bool - returns true if character is apart of operator list, else
// false is returned.
// ----------------------------------------------------------------------------
bool isOperator(char sourceChar){

  // Loop through operator list and compare sourceChar against first character
  // of operators.
  for(int i = 0; i < sizeof(operators)/sizeof(*operators); ++i){
    if(sourceChar == operators[i][0]){
      return true;
    }
  }

  return false;

}// End of isOperator(char)

// --- isOperator(string) -----------------------------------------------------
// Function checks if a string is apart of the operator list.
//
// Input -- string unknownOp - given string to check for in operator list.
//
// Output -- returns true if string is apart of operator list, else false is
// returned.
// ----------------------------------------------------------------------------
bool isOperator(string unknownOp){

  // Loop through operator list and compare given string against all operators
  // in operator list.
  for(int i = 0; i < sizeof(operators)/sizeof(*operators); ++i){
    if(unknownOp == operators[i]){
      return true;
    }
  }

  return false;

}// End of isOperator(string)

// --- getOperator ------------------------------------------------------------
// Function gets an operator lexeme from the provided source file. This can
// only recognize operators of max length two characters.
//
// Input -- ifstream& sourceFile - a refrence variable to the source file.
//       -- string& token - a refrence variable to the token type.
//
// Output -- string - this string contains the extracted lexeme.
// ----------------------------------------------------------------------------
string getOperator(ifstream& sourceFile, string& token){

  char sourceChar;
  string lexeme;

  // Reset file stream pointer to original character.
  sourceFile.unget();

  // Get first character and save it in the lexeme string.
  sourceFile.get(sourceChar);
  lexeme += sourceChar;
  sourceFile.get(sourceChar);

  // Check for two character operators.
  for(int i = 0; i < sizeof(operators)/sizeof(*operators); ++i){
    if(sourceChar == operators[i][1]){
      lexeme += sourceChar;
      break;
    }
    if((i + 1) == sizeof(operators)/sizeof(*operators)){
      // Move file pointer back one for a two character operator was not
      // found.
      sourceFile.unget();
    }
  }

  // Check if lexeme is apart of list else change token type to unknown.
  if(isOperator(lexeme)){
    token = "operator";
  }
  else{
    token = "unknown";
  }

  return lexeme;

}// End of getOperator()

#endif // End of operator.h
