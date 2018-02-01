// ----------------------------------------------------------------------------
// Andres Imperial
// CPSC 323 MW 11:30am
// Assignment 1: Lexer
//
// File: separators.h
// Header file to declare the separator symbols and some helper funtions for
// Rat16F language.
// ----------------------------------------------------------------------------

#ifndef SEPARATORS_H
#define SEPARATORS_H
#include <string>
#include <fstream>
using namespace std;

// Array of declared separators.
const string separators[] = {"$$", "[", "]", ",", ":", "{", "}", ";", "(",
                             ")"};

// --- isSeparator(char) ------------------------------------------------------
// Function checks a single character to see if it is apart of the separator
// list.
//
// Input -- char sourceChar - given character to check for in separator list.
//
// Output -- bool - returns true if character is apart of separator list, else
// false is returned.
// ----------------------------------------------------------------------------
bool isSeparator(char sourceChar){

  // Loop through separator list and compare sourceChar against first character
  // of separators.
  for(int i = 0; i < sizeof(separators)/sizeof(*separators); ++i){
    if(sourceChar == separators[i][0]){
      return true;
    }
  }

  return false;

}// End of isSeparator(char)

// --- isSeparator(string) ----------------------------------------------------
// Function checks if a string is apart of the separator list.
//
// Input -- string unknownSep - given string to check for in separator list.
//
// Output -- bool - returns true if string is apart of separator list, else
// false is returned.
// ----------------------------------------------------------------------------
bool isSeparator(string unknownSep){

  // Loop through separator list and compare given string against all
  // separators in the separator list.
  for(int i = 0; i < sizeof(separators)/sizeof(*separators); ++i){
    if(unknownSep == separators[i]){
      return true;
    }
  }

  return false;

}// End of isSeparator(string)

// ---- getSeparator ----------------------------------------------------------
// Function get a separator lexeme from the provided source file. This can
// only recognize separators of max length two characters.
//
// Input -- ifstream& sourceFile - a refrence variable to the source file.
//       -- string& token - a refrence variable to token type.
//
// Output -- string - this string contains the extracted lexeme.
// ----------------------------------------------------------------------------
string getSeparator(ifstream& sourceFile, string& token){

  char sourceChar;
  string lexeme;

  // Reset file stream pointer to orginal character.
  sourceFile.unget();

  // Get first character from source file and save it to the lexeme string.
  sourceFile.get(sourceChar);
  lexeme += sourceChar;
  sourceFile.get(sourceChar);

  // Check for two character separators.
  for(int i = 0; i < sizeof(separators)/sizeof(*separators); ++i){
    if(sourceChar == separators[i][1]){
      lexeme += sourceChar;
      break;
    }
    if((i + 1) == sizeof(separators)/sizeof(*separators)){
      // Move file pointer back one for a two character separator was not
      // found.
      sourceFile.unget();
    }
  }

  // Check if lexeme is apart of list else change token type to unknown.
  if(isSeparator(lexeme)){
    token = "separator";
  }
  else{
    token = "unknown";
  }

  return lexeme;

}// End of getSeparator()

#endif // End of separators.h
