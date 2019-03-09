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

void FileInput::readFile(string path)
{
    ifstream readFile(path);
    char wordArr[5000];
    readFile>>wordArr;
    int i=0;
    int j=0, num = 0;
    while(wordArr[i] != '\0')
    {
        char temp[100];
        if ((wordArr[i] >= 'a' && wordArr[i] <= 'z') || (wordArr[i] >= 'A' && wordArr[i] <= 'Z'))
        {
            temp[j] = wordArr[i];
            j++;
        }
        inArr[num] = temp;
        num++;
        i++;
        j = 0;
    }
    asize = num;
}