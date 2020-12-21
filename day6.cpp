#include <string>
#include <iostream>
#include <fstream>
#include <map>

using namespace std;

long yesQuestionsSum(const string &inputFile) {
    string line; map<char, bool> answers;
    long yesSum=0;
    ifstream questionAnswers(inputFile);
    while(getline(questionAnswers, line)) {
        for (auto letter:line) {
            answers[letter] = true;
        }
        if (line.empty()) {
            for (auto key:answers) {
                if (key.second) yesSum++;
                answers[key.first] = false;
            }
        }
    }
    return yesSum;
}

int main(int argc, char **argv) {
    string inputFile = argv[1];
    cout << yesQuestionsSum(inputFile) << endl;
}