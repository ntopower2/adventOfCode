#include <string>
#include <iostream>
#include <fstream>
#include <map>

using namespace std;

long getSeatId(string seat) {
    long row=0, col=0;
    for (int i=0;i<7;i++) if (seat[i]=='B') row+= 1<<(6-i);
    for (int i=7;i<10;i++) if (seat[i]=='R') col+= 1<<(9-i);
    return (row*8)+col;
}

long computeMaxId(const string &filename) {
    ifstream passportFile(filename);
    long maxId = 0; string line;
    while (getline(passportFile, line)) {
        maxId = (maxId < getSeatId(line)) ? getSeatId(line) : maxId;
    }
    return maxId;
}

int findMissing(const string&filename) {
    ifstream passportFile(filename);
    long maxId = computeMaxId(filename); string line;
    long seats[maxId-1] = {0};
    while (getline(passportFile, line)) {
        seats[getSeatId(line)] = 1;
    }
    for (int i=0;i<maxId-1;i++) if (!seats[i] && seats[i+1] && seats[i-1]) return i;
}

int main(int argc, char **argv) {
    string inputFile = argv[1];
    cout << computeMaxId(inputFile) << endl;
    cout << findMissing(inputFile) << endl;
}