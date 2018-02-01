// ----------------------------------------------------------------------------
// Andres Imperial
// CPSC 323 MW 11:30am
// Assignment 1: Lexer
//
// File: main.cpp
// Write a lexical analyzer for the Rat16F language using a FSM for identifier,
// integer, and real. Main() will take care of opening and closing source and
// destination files. Main() will also create a destination file name for 
// storing the tokens and related lexemes.
// ----------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <fstream>
#include "lexer.h"
#include "parser.h"
using namespace std;

// ---- main ------------------------------------------------------------------
// Main will be provided a source file through command line arguments. Main
// then will open the source file and create a destination file for storing
// results. Once open main will call the lexer function passing it the source
// file and destination file.
//
// Input -- int argc - is the count of given arguments, which should be two.
// The first is the executable name and the second should be the given source
// file.
//       -- char* argv[] - character array that contains the names of the
// given arguments. 
//
// Output -- int - exit code for main.
// ----------------------------------------------------------------------------
int main(int argc,char*argv[]){

  // Check if executable was called with proper format.
  if(argc < 2){
    cout << "Invalid format -- Not enough arguments provided." << endl;
    cout << "Please follow format -- ./Lexerfy filename.txt" << endl;
    return 0;
  }
  else if(argc > 2){
    cout << "Invalid format -- Too many arguments provided." << endl;
    cout << "Please follow format -- ./Lexerfy filename.txt" << endl;
    return 0;
  }

  ifstream sourceFile;
  ofstream lexerFile;
  // Create the destination file by prefixing the given source file with
  // lexer_. 
  string lexerFileName = string("lexer_") + argv[1];

  // Open given source file to read from and check for error.
  // Open destination file -- lexer_sourceFileName -- and check for error.
  sourceFile.open(argv[1]);
  lexerFile.open(lexerFileName.c_str());

  if(!sourceFile.is_open()){
    cout << "Error file -- " << argv[1] << " -- couldn't be opened!\n";
    return 0;
  }
  else if(!lexerFile.is_open()){
    cout << "Error file -- " << lexerFileName << " -- could not be opened!\n";
    return 0;
  }
  
  string token;
  string lexeme;
  int lineCount = 0;

  // Set up lexer files column names.
  lexerFile << left << setw(20) << "Token" << "Lexeme\n\n";
  ++lineCount;

  // Continue loop until end of file is reached.
  while(!sourceFile.eof()){
  // Call the lexer function and pass it the source file 
    lexeme = lexer(sourceFile, token);
    if(lexeme != "-1"){
      lexerFile << left << setw(20) << token << lexeme << endl;
	  ++lineCount;
    }
  }

  // Close filestreams.
  sourceFile.close();
  lexerFile.close();

  // Once the file has been lexically analyzed send it to be parsed.
  Parser(lexerFileName, argv[1], lineCount);

  return 0;

}// End of main()

// End of main.cpp
