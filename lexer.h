// ----------------------------------------------------------------------------
// Andres Imperial
// CPSC 323 MW 11:30am
// Assignment 1: Lexer
//
// File: lexer.h
// Write a lexical analyzer for the Rat16F language using a FSM for identifier,
// integer, and real. This header file will include the lexer() function that
// will read from the source file provided, call the proper function to extract
// lexemes and assign proper token types, then write these results to a
// destination file.
// ----------------------------------------------------------------------------

#ifndef LEXER_H
#define LEXER_H
#include <fstream>
#include <string>
#include <cctype>
#include <iomanip>
#include "identifiers.h"
#include "operators.h"
#include "separators.h"
#include "digits.h"
#include "keywords.h"
using namespace std;

// --- lexer ------------------------------------------------------------------
// Function to read in from a source file and extract lexemes and token types
// using FSMs for identifiers/keywords, reals, and integers.
//
// Input -- ifstream& sourceFile - is a refrence variable to the source file.
//       -- ofstream& lexerFile - is a refrence variable to the destination
//       file.
//
// Output -- void
// ----------------------------------------------------------------------------
string lexer(ifstream& sourceFile, string& token){

  string lexeme;
  char sourceChar;

  // Get character from source file.
  sourceFile.get(sourceChar);
  lexeme = sourceChar;

  // If the character is a letter call the Identifier Lexer.
  if(isalpha(sourceChar)){
    // Get lexeme by calling getIdentifier funtion.
    lexeme = getIdentifier(sourceFile, token);
    // Check to see if identifier is actually a keyword, then print to
    // lexerFile.
    if(isKeyword(lexeme)){
      token = "keyword";
    }
  }
  else if(isdigit(sourceChar)){
    // Print token and lexeme to lexerFile.
    lexeme = getDigit(sourceFile, token);
  }
  else if(isOperator(sourceChar) && isSeparator(sourceChar)){
    // if character is found both in operator's and separator's list then get
    // both potential lexemes and compare which is longer. The longer one is
    // then chosen.
    string tempToken;
    string tempLexeme = getOperator(sourceFile, tempToken);
    lexeme = getSeparator(sourceFile, token);
    // Separator lexeme is longer
    if(lexeme.length() > tempLexeme.length()){
      // Don't do anything.
    }
    // Operator lexeme is longer
    else if(lexeme.length() < tempLexeme.length()){
      token = tempToken;
      lexeme = tempLexeme;
    }
    // Both are the same length check for it being in the separators list.
    else if(isSeparator(lexeme)){
      // Don't do anything.
    }
    // Both are same length but not found in separator list so print out as
    // operator or unknown if not found in operator's list.
    else{
      token = tempToken;
      lexeme = tempLexeme;
    }
  }
  else if(isOperator(sourceChar)){
    // Character found in operator's list.
    lexeme = getOperator(sourceFile, token);
  }
  else if(isSeparator(sourceChar)){
    // Character found in separator's list.
    lexeme = getSeparator(sourceFile, token);
  }
  else if(isspace(sourceChar)){
    // Do not print anything for space.
    return "-1";
  }
  else{
    // Token is unknown, print token as unknown and lexeme.
    token = "unknown";
  }

  return lexeme;

}// End of lexer()

#endif // End of lexer.h
