
#include <iostream>
#include <map>

using namespace std;

int validPasswords(char* filename) {
//  Given a list of rules corresponding to strings
//  decide which strings are valid for their rule
//  e.g. 1-5 x: vvxlx
    FILE *numList = fopen(filename,"r");
    if (numList== nullptr) return -1;

    char buff[100];
    int valid = 0;
    while (fgets(buff, sizeof(buff), numList)) {
        int a, b, i = 0, hits=0; char c, s[50];
        sscanf(buff, "%d-%d %c: %s\n", &a, &b, &c, s);
        while (s[i]!='\0') {
            if (s[i]==c) hits++;
            i++;
            if (hits > b) s[i] = '\0';
        }
        valid = (hits>=a && hits <=b)?valid+1:valid;
    }
    return valid;
}

int validPasswords2(char* filename) {
//  changed rule: either pos[a] or pos[b] should be x
//  e.g. 1-5 x: vvxlx
    FILE *numList = fopen(filename,"r");
    if (numList== nullptr) return -1;

    char buff[100];
    int valid = 0;
    while (fgets(buff, sizeof(buff), numList)) {
        int a, b; char c, s[50];
        sscanf(buff, "%d-%d %c: %s\n", &a, &b, &c, s);
        valid = ((s[a-1]==c) != (s[b-1] == c))?valid+1:valid;
    }
    return valid;
}

int main() {
    char inputFile[] ="../inputFiles/day2.txt";
    cout << validPasswords(inputFile) << endl;
    cout << validPasswords2(inputFile) << endl;
}
