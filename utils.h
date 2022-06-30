#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;
class Utils
{
public:
    Utils();
    void input(string cmd, int& in);

    void workWithFile() {
        string line;
        // ofstream myOpenFile("input.txt");
        // myOpenFile.is_open();
        // myOpenFile.close();
        ifstream myFile("input.txt");
        if (myFile.is_open()) {
            while (getline(myFile, line)) {
                cout << line << endl;
            }
            myFile.close();
        } else {
            cout << "Unable to open file" << endl;
        }

        int number;
        if (myFile.is_open()) {
            while (myFile >> number) {
                cout << number << endl;
            }
            myFile.close();
        } else {
            cout << "Unable to open file" << endl;
        }
    }
};

#endif // UTILS_H
