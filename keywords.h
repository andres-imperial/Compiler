// ----------------------------------------------------------------------------
// Andres Imperial
// CPSC 323 MW 11:30am
// Assignment 1: Lexer
//
// File: keywords.h
// Header file for the declaration of keywords and has a helper function for
// checking for keywords.
// ----------------------------------------------------------------------------

#ifndef KEYWORDS_H
#define KEYWORDS_H
#include <string>
using namespace std;

// Declaration list of keywords in Rat16F.
const string keywords[] = {"function", "integer", "boolean", "real", "if",
                      "endif", "else", "return", "print", "read", "while",
                      "true", "false"};

// --- isKeyword --------------------------------------------------------------
// Function checks if a given string is apart of the keyword list.
//
// Input -- string sourceString - given string to check for in keyword list.
//
// Output -- bool - returns true if the string is a keyword, else it returns
// false.
// ----------------------------------------------------------------------------
bool isKeyword(string sourceString){

  // Loop through the keyword list and check if given string is apart of the
  // keyword list.
  for(int i = 0; i < sizeof(keywords)/sizeof(*keywords); ++i){
    if(sourceString == keywords[i]){
      return true;
    }
  }

  return false;

}// End of isKeyword()

#endif // End of keywords.h


