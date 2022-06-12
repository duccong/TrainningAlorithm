#include "part2.h"
#include "utils.h"
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

Utils utils;
int n, k;
int a[100];
int b[100];
string s;
vector<string> vS;
int count = 0;

void printA(bool checkDuplicate = false) {
    if (checkDuplicate) {
        memset(&b, 0, sizeof(b));
        for (int i = 0; i < k; i++) {
            if (b[a[i]] == 0) {
                b[a[i]] = 1;
            } else {
                return;
            }
        }
    }
    for (int i = 0; i < k; i++) {
        cout << a[i];
    }
    cout << endl;
}

void printB() {
    for (int i = 0; i < k; i++) {
        cout << b[i];
    }
    cout << endl;
}

bool checkContain(int checkNumber , int excludeIndex) {
    for (int i = 0; i < n; i++) {
        if (i != excludeIndex && a[i] == checkNumber) {
            return true;
        }
    }
    return false;
}

Part2::Part2()
{

}

void Part2::ChinhHopLap(int _n, int _k)
{
    if (_n == -1) {
        utils.input("n = ", n);
        utils.input("k = ", k);
    } else {
        n = _n;
        k = _k;
    }
    memset(&a, 0, sizeof(a));
    bool loop = true;
    do {
        for (int i = k - 1; i >= 0; i--) {
            if (a[i] < n) {
                a[i]++;
                printA();
                break;
            } else if (a[i] == n) {
                if (i - 1 < 0) {
                    loop = false;
                    break;
                }
                a[i] = 0;
                if (a[i-1] < n) {
                    a[i-1]++;
                    printA();
                    break;
                }
            }
        }
    } while (loop);
    cout << "DONE!" << endl;
}

void Part2::ChinhHop(int _n, int _k)
{
    if (_n == -1) {
        utils.input("n = ", n);
        utils.input("k = ", k);
    } else {
        n = _n;
        k = _k;
    }
    memset(&a, 0, sizeof(a));
    memset(&b, 0, sizeof(b));
    bool loop = true;
    // init first array
    for (int i = 0; i < k; i++) {
        a[i] = i;
        b[i] = 1;
    }
    printA(true);
    do {
        for (int i = k - 1; i >= 0; i--) {
            if (a[i] < n) {
                a[i]++;
                printA(true);
                break;
            } else if (a[i] == n) {
                if (i - 1 < 0) {
                    loop = false;
                    break;
                }
                a[i] = 0;
                if (a[i-1] < n) {
                    a[i-1]++;
                    printA(true);
                    break;
                }
            }
        }
    } while (loop);
    cout << "DONE!" << endl;
}

void Part2::ToHop(int _n, int _k)
{
    if (_n == -1) {
        utils.input("n = ", n);
        utils.input("k = ", k);
    } else {
        n = _n;
        k = _k;
    }
    memset(&a, 0, sizeof(a));
    bool loop = true;
    // init first array
    for (int i = 0; i < k; i++) {
        a[i] = i;
    }
    a[k] = n;
    printA();
    do {
        for (int i = k-1; i >= 0; i--) {
            if (i == 0 && a[i] == n - k) {
                // printA();
                loop = false;
                break;
            }
            if (a[i] + 1 <= (n - 1) - ((k - 1) - i)) {
                a[i]++;
                printA();
                break;
            } else if (a[i] + 1 > (n - 1) - ((k - 1) - i)) {
                // if (a[i - 1] < n - 1 - (i - (k - 1) + 1)) {
                if (a[i - 1] + 1 < a[i] ) {
                    a[i - 1]++;
                    a[i] = a[i-1] + 1;
                    printA();
                    break;
                }
            }
        }

    } while (loop);
    cout << "DONE!" << endl;
}

void Part2::HoanVi(int _n)
{
    if (_n == -1) {
        utils.input("n = ", n);
    } else {
        n = _n;
    }
    k = n;
    // utils.input("k = ", k);
    memset(&a, 0, sizeof(a));
    bool loop = true;
    // init first array
    for (int i = 0; i < n; i++) {
        a[i] = i;
    }
    printA();
    do {
        for (int i = n - 1 ; i >= 0; i--) {
            if (i == 0 && a[i] == n - 1) {
                loop = false;
                break;
            }
            if (a[i] > a[i - 1]) {
                for (int j = n - 1; j >=i; j--) {
                    // printA();
                    if (a[j] > a[i - 1]) {
                        swap(a, j, i - 1);
                        for (int c = i; c <= i + (n - 1 - i)/2; c++) {
                            swap(a, c, n - 1 - (i-c));
                        }
                        printA();
                        i = n;
                        break;
                    }
                }
            }
        }
    } while (loop);
    cout << "DONE!" << endl;
}

void Part2::swap(int *a, int i1, int i2)
{
    // cout << "Swap: " << i1 << " - " << i2 << endl;
    int tmp = a[i1];
    a[i1] = a[i2];
    a[i2] = tmp;
}

void Part2::dayNhiPhan0101()
{
    utils.input("n = ", n);
    k = n;
    // utils.input("k = ", k);
    memset(&a, 0, sizeof(a));
    bool loop = true;
    // [STEP 1] Find Combine k (times of "01") of n' ( = n - k)
    // init first array
    int timeOf01 = 2;
    k = timeOf01; // time of "01"
    for (int i = 0; i < k; i++) {
        a[i] = i;
    }
    string tmp;
    for (int j = 0; j < k; ++j) {
        tmp.append(to_string(a[j]));
    }
    vS.push_back(tmp);
    // cout << "tmp: " << tmp << endl;
    n = n - k;
    do {
        for (int i = k-1; i >= 0; i--) {
            if (i == 0 && a[i] == n - k) {
                // printA();
                loop = false;
                break;
            }
            if (a[i] + 1 <= (n - 1) - ((k - 1) - i)) {
                a[i]++;
                tmp = "";
                for (int j = 0; j < k; ++j) {
                    tmp.append(to_string(a[j]));
                }
                vS.push_back(tmp);
                break;
            } else if (a[i] + 1 > (n - 1) - ((k - 1) - i)) {
                // if (a[i - 1] < n - 1 - (i - (k - 1) + 1)) {
                if (a[i - 1] + 1 < a[i] ) {
                    a[i - 1]++;
                    a[i] = a[i-1] + 1;
                    tmp = "";
                    for (int j = 0; j < k; ++j) {
                        tmp.append(to_string(a[j]));
                    }
                    vS.push_back(tmp);
                    break;
                }
            }
        }

    } while (loop);
    // [STEP 1] DONE find Combine k (times of 01) of n' ( = n - k)

    // [STEP 2] Using result of Step 1. Append to array and generate like Comine but checking a[i] == 0 && (i == 0 || a[i-1] == 1)
    n = n + k;
    k = n;
    for(const string& s : vS) {
        // cout << "s:" << s << endl;
        memset(&a, 0, sizeof(a));
        memset(&b, 0, sizeof(b));
        int checkIndex = 0;
        for (int i = 0 ; i < timeOf01; i++) {
            int indexOf01 = s.at(i) - '0';

            b[indexOf01 + i] = 1;
            b[indexOf01 + 1 + i] = 1;

            a[indexOf01 + i] = 0;
            a[indexOf01 + 1 + i] = 1;
            // cout << " >> index: " << indexOf01 << endl;
        }
        printA();
        bool loop = true;
        do {
            for (int i = n - 1; i >=-1; i--) {
                if (i == -1) {
                    loop = false;
                    break;
                } else if (b[i] == 1) {
                    continue;
                    // break;
                } else if (a[i] == 0 && (i == 0 || a[i-1] == 1)) {
                    a[i] = 1;
                    for (int j = i + 1; j < n; j++) {
                        if (b[j] == 0) {
                            a[j] = 0;
                        }
                    }
                    // cout << ">>> " << i << endl;
                    printA();
                    break;
                }
            }
        } while (loop);
    }
   cout << "DONE!!" << endl;

}
