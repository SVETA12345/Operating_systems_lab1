#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int main(int argc, char* argv[])
{
    string s = "Hello, ";
    ofstream out;
    if (argc>1)
    {
         for (int i = 1; i < argc; ++i)
    {
        s.append(argv[i]);
    }
        cout << s;
    }
    else {
        out.open("error.txt");
        out << "Произошла ошибка" << endl;
        cout << "Произошла ошибка";
    }
    out.close(); 
}