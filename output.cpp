#include <iostream>
#include <fstream> 
#include <vector>
#include <string>

using namespace std;

class output{
    public:
    void _output(vector<string> chain);
};

void output::_output(vector<string> chain) {
    int n = chain.size();
    int i;
    for(i = 0; i < n; i++) {
        cout << chain[i] << endl;
    }
}