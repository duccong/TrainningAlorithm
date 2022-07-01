#include "buildpyramid.h"

vector<string> vInput;
vector<int> vArr[100];
int stones[100];
int highestStone = 0;
int highPyramid = 0;
int maxHigh = 0;
int numStones = 0;
int sumStones = 0;

void input() {
    ifstream myFile("input.txt");
    // ofstream myOpenFile("input.txt");
    // myOpenFile.is_open();
    // myOpenFile.close();
    string line;
    if (myFile.is_open()) {
        while (getline(myFile, line)) {
            // cout << line << endl;
            vInput.push_back(line);
        }
        myFile.close();
    } else {
        cout << "Unable to open file" << endl;
    }
    // print array
    // for (int i = 0; i < index; i++) {
        // cout << "index: " << i << endl;
        // for (const auto &it : arr[i]) {
            // cout << it << endl;
        // }
    // }
}

void stringToData(const string &in) {
    int number;
    int index = 0;
    stringstream stream(in);
    while (stream >> number) {
        // cout << number << endl;
        if (highestStone < number) {
            highestStone = number;
        }
        vArr[number].push_back(index);
        stones[index] = (number);
        sumStones += number;
        index++;
    }
    numStones = index;
    // print data
    // for (int i = 0; i < index; i++) {
        // // cout << "index: " << i << endl;
        // for (const auto &it : vArr[i]) {
            // cout << it;
        // }
        // cout << endl;
    // }
}

bool checkPyramidAt(int &index, int &high) {
    int r = high - 1;
    int lowerStone = r; //= high - 1;
    for (int i = 1; i <= r; i++) {
        lowerStone = high - i;
        if ((stones[index + i] < lowerStone
             || stones[index - i] < lowerStone)) {
            return false;
        }
    }
    return true;
}

void excuteBuild() {
    if (highestStone == 0) {
        cout << " >>> Can't make a pyramid" << endl;
        return;
    }
    int tmpHighest = highestStone;
    maxHigh = (numStones + 1) /2;

    bool done = false;
    while (!done) {
        // cout << "highest: " << tmpHighest << endl;
        if (tmpHighest == 1) {
            // no need to check pyramid
            highPyramid = 1;
            cout << " >>> Top at anywhere" << " - high: " << highPyramid << " ";
            //<< " highest: " << tmpHighest << " ";// << endl;
            done = true;
            break;
        }
        for (int index : vArr[tmpHighest]) {
            // loop exist stone have the same high
            // cout << "index: " << index << " - highest: " << tmpHighest << endl;
            highPyramid = tmpHighest;
            if (tmpHighest > maxHigh) {
                highPyramid = maxHigh;
            }

            int r = highPyramid - 1;
            if (index - r < 0 || index + r > numStones) {
                // cout << "invalid. Pyramid will not fully" << endl;
                continue;
            }

            if (checkPyramidAt(index, highPyramid)) {
                cout << " >>> Top at: " << index << " - high: " << highPyramid << " ";
                //<< " highest: " << tmpHighest << " "; //<< endl;
                done = true;
                break;
            }
        }

        for (int higher = highestStone; higher > tmpHighest; higher--) {
            for (int index : vArr[higher]) {
                // loop stone higher
                // cout << "index: " << index << " - highest: " << tmpHighest << endl;
                highPyramid = tmpHighest;
                if (tmpHighest > maxHigh) {
                    highPyramid = maxHigh;
                }

                int r = highPyramid - 1;
                if (index - r < 0 || index + r > numStones) {
                    // cout << "invalid. Pyramid will not fully" << endl;
                    continue;
                }

                if (checkPyramidAt(index, highPyramid)) {
                    cout << " >>> Top at: " << index << " - high: " << highPyramid << " ";
                    //<< " highest: " << tmpHighest << " "; //<< endl;
                    done = true;
                    break;
                }
            }
            if (done) break;
        }
        // loop exist stone larger the same high

        tmpHighest--;
    }

    if (done) {
        cout << "Cost: " << (sumStones - highPyramid*highPyramid) << endl;
        // cout << (sumStones - highPyramid*highPyramid) << endl;
    } else {
        cout << "Can't make a pyramid" << endl;
    }
}

void clearData() {
    for (auto &it : vArr) {
        it.clear();
    }
    vArr->clear();
    memset(&stones, 0, sizeof(stones));
    highestStone = 0;
    highPyramid = 0;
    maxHigh = 0;
    numStones = 0;
    sumStones = 0;
}


BuildPyramid::BuildPyramid()
{
    clock_t timeStart, timeEnd;
    double totalTime;
    timeStart = clock();
    input(); // -> vInput available
    for (const string &s: vInput) {
        stringToData(s);
        cout << s << endl;
        excuteBuild();
        clearData();
    }
    timeEnd = clock();
    totalTime = (double)(timeEnd - timeStart) / CLOCKS_PER_SEC;
    printf("Total time taken by CPU: %f\n", totalTime);
}
