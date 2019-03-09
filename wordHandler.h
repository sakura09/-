#ifndef HANDLE
#define HANDLE

#include <iostream>
#include <fstream> 
#include <vector>
#include <string>
#include "input.h"
//#include "input.cpp"

using namespace std;

class wordHandler {
    public:
    wordHandler(FileInput _fin);
    int gen_chain_word(char* words[], int len, char* result[], char head, char tail, bool enable_loop);
    int gen_chain_char(char* words[], int len, char* result[], char head, char tail, bool enable_loop);
    vector<string> Operate(char head, char tail,  vector<string> words,int length);
    private:
    FileInput fin;
};

#endif