#ifndef INPUT
#define INPUT

#include <iostream>
#include <fstream> 
#include <vector>
#include <string>
using namespace std;

class FileInput
{

    public:
        void readFile(string path);
        vector<string> inArr;
        int asize;

};

#endif