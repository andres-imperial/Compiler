// ----------------------------------------------------------------------------
// Andres Imperial
// CSCP 323 mw 11:30am
// Assignment 3: Generating Assembly Code
//
// file: symbols.h
// ----------------------------------------------------------------------------

#ifndef SYMBOLS_H
#define SYMBOLS_H

#include <cstring>
#include <iostream>
#include <iomanip>
using namespace std;
int const MAX_SYMBOLS = 100;

// Symbols class definition
class Symbols
{
    private:
        string ids[MAX_SYMBOLS];
        string type[MAX_SYMBOLS];
        int memory_address[MAX_SYMBOLS];
        int index = 0;

    public:
        bool insert(string lexeme, int address, string id_Type)
        {
            ids[index] = lexeme;
            type[index] = id_Type;
            memory_address[index] = address;
            ++index;
            return true;
        }
        int size(void){return index;}
        int find(string lexeme)
        {
            for(int i = 0; i < index; ++i)
            {
                if(ids[i] == lexeme){
                    return i;
                }
            }
            // Target lexeme was not found
            return -1;
        }
        int Get_Address(string target){return memory_address[find(target)];}
        void print(ofstream& symbolFile)
        {
            symbolFile << setw(20) << left << "Identifier" << setw(25)
                << "Memory Location" << setw(5) << "Type\n";
            for(int i = 0; i < index; ++i)
            {
                symbolFile << setw(20) << left << ids[i] << setw(25)
                    << memory_address[i] << setw(5) << type[i] << endl;
            }
        }
        string Get_Type(string target){return type[find(target)];}

}; // End of Symbols class definition

#endif // End of symbols.h
