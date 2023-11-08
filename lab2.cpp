#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <chrono>
#include <fstream>
#include <cmath>

using namespace std::chrono;
using namespace std;

mutex m;

void loadFromFile(string fileName)
{
    cout<<"filename: "<<fileName<<endl;
    auto start1 = system_clock::now();
    m.lock();
    int x;
    ifstream fin;
    fin.open(fileName, ios::in);
    fin >> x;
    cout<<"x: "<<x<<endl;
    auto finish1 = system_clock::now();
    auto duration1 = duration_cast<nanoseconds>(finish1 - start1).count();
    cout<< "duration1: " << duration1 << endl;
    auto start2 = system_clock::now();
    x = log(x);
    x = x * 10;
    fin.close();
    m.unlock();
    auto finish2 = system_clock::now();
    auto duration2 = duration_cast<nanoseconds>(finish2 - start2).count();
    cout<< "duration2: " << duration2 << endl;
}

int main(int argc, char* argv[])
{
    vector <thread> threads;
    threads.reserve(argc);
    for (int i = 1; i <= argc; i++)
        threads.push_back(thread(loadFromFile, argv[i]));
    for (auto& th : threads)
        th.join();
}