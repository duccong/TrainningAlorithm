#include "chinhhop.h"
#include "utils.h"
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

Utils utils;
int n, k;
int a[100];
int count = 0;

void printA() {
    for (int i = 0; i < k; i++) {
        cout << a[i];
    }
    cout << endl;
}

ChinhHop::ChinhHop()
{
    utils.input("n = ", n);
    utils.input("k = ", k);
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
}
