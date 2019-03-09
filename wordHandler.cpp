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

wordHandler::wordHandler(FileInput _fin) {
    fin = _fin;
}
// contain the most word number
int wordHandler::gen_chain_word(char* words[], int len, char* result[], char head, char tail, bool enable_loop) {
    
    //FileInput fin;
    //fin.readFile();
    char front, rear;
    int cur;
    //char rear = fin.inArr[0].at(-1);
    int i = 0;
    int j, k = 0;
    int size = fin.asize;
    int count = 1;
    int tcnt = 0;
    int ind = 0;
    int res[32];
    vector<string> wchain, tchain;
    bool flag = false;

    while(i < size) {
        flag = false;
        tchain.empty();
        k = 0;
        tchain[0] = fin.inArr[i];
        rear = fin.inArr[i].at(-1);
        cur = i;
        for(j = 0; j < size; j++) {
            if (j == cur){
                continue;
            }
            count = 1;
            front = fin.inArr[j].at(0);
            if(front == rear) {
                i = j;
                count++;
                tchain[k+1] = fin.inArr[j];
                k++;
                flag = true;
                break;
            }
        }
        if(flag) {
            continue;
        }
        if(count > tcnt) {
            wchain = tchain;
        }
    }
    if( ! flag) {
        cout << "No chain could be found!" << endl;
    }
    if(head != 0 || tail != 0) {
        wordHandler::Operate(head, tail, tchain, count);
    }
    return count;
}

int wordHandler::gen_chain_char(char* words[], int len, char* result[], char head, char tail, bool enable_loop)
{
    
    int cur;
    int i = 0, j, k;
    int charCnt = 0;
    int tcharCnt = 0;
    vector<string> wchain,tchain;
    bool flag = false;
    int size = fin.asize;
    char front,rear;

    while(i < size)
    {
        k = 0;
        tchain.empty();
        tchain[0] = fin.inArr[i];
        rear = fin.inArr[i].at(-1);
        cur = i;
        for (j=0; j < size; j++)
        {
            if (j == cur){
                continue;
            }
            front = fin.inArr[j].at(0);
            if (front == rear)
            {
                i = j;
                tchain[k] = fin.inArr[j];
                charCnt = charCnt + tchain[k].length();
                k++;
                flag = true;
                break;
            }
            
        }
        if (flag)
        {
            continue;
        }
        if (charCnt > tcharCnt)
        {
            wchain = tchain;
        }        
    }
    if( ! flag) {
        cout << "No chain could be found!" << endl;
    }
    if(head != 0 || tail != 0) {
        wordHandler::Operate(head, tail, tchain, tchain.size());
    }
    return charCnt;
}

vector<string> wordHandler:: Operate(char head, char tail,  vector<string> words,int length){
    int i;
    int j=0;
    vector<string>::iterator ite;
    i = length;
    while(i > 0){
        char tmp = words[i].at(-1);
        if (tmp != tail){
            words.pop_back();
        }
        else {
            break;
        }
        i--;
        if(i == 0) {
            cout << "The input tail char cannot be found in chain!" << endl;
        }
    }
    while(j < i){
        char tmp = words[0].at(0);
        if (tmp != head){
            //删除当前元素
            ite = words.begin();
            ite = words.erase(ite);
        }
        else {
            break;
        }
        j++;
        if(j == i) {
            cout << "The input head char cannot be found in chain!" << endl;
        }
    }
    return words;
}
