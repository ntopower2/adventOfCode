
#include <iostream>
#include <fstream>
#include <map>
#include <cstring>

using namespace std;
int countTrees(const string& filename, int right=3, int down=1) {
    ifstream gridFile(filename);
    if (gridFile.bad()) return -1;
    int trees=0, i=0, period;
    string line;
    getline(gridFile, line);
    period = line.length();
    while (getline(gridFile, line)) {
        i++;
        if (!(i%down) && line[(i*right)%period] == '#') trees++;
    }
    return trees;
}

int main(int argc, char** argv) {
    string inputFile = argv[1];
    cout << countTrees(inputFile) << endl;
}