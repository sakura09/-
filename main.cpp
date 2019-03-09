#include <iostream>
#include <fstream> 
#include <vector>
#include <string>

#include "input.h"
#include "wordHandler.h"

using namespace std;

int main(int argc, char* argv[]) {
    FileInput fin;
    //wordHandler wh;
    char* result[100];
    char* ptr = argv[1];
    int i = 1;

    char* _words[100];
    int _len;
    bool con = false;
    bool recur = false;
    bool run = false;

    char head, tail;
    char fun = '\0';
    while(true) {
        con = false;
        switch (ptr[1])
        {
            /*case 'w':
                fin.readFile(argv[2]);
                wordHandler whw(fin);
                whw.gen_chain_word(_words, _len, result, 0, 0, false);
                run = true;
                break;

            case 'c':
                fin.readFile(argv[2]);
                wordHandler whc(fin);
                whc.gen_chain_char(_words, _len, result, 0, 0, false);
                run = true;
                break;
*/
            case 'r':
                recur = true;
                con = true;
                break;

            case 'h':
                ptr++;
                head = *ptr;
                con = true;
                break;

            case 't':
                ptr++;
                tail = *ptr;
                con = true;
                break;

            case 'w': 
                fun = 'w';
                break;

            case 'c':
                fun = 'c';
                break;

            default:
                break;
        }
        if(con) {
            i++;
            ptr = argv[i];
            continue;
        }
        else {
            break;
        }
    }
    fin.readFile(argv[i + 1]);
    if(fun == 'w') {
        wordHandler whword(fin);
        whword.gen_chain_word(_words, _len, result, head, tail, recur);
    }
    else if(fun == 'c') {
        wordHandler whchar(fin);
        whchar.gen_chain_char(_words, _len, result, head, tail, recur);
    }
    else {
        cout << "Invalid command!" << endl;
    }
}