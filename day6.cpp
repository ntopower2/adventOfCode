#include <string>
#include <iostream>
#include <fstream>
#include <map>

using namespace std;

long yesQuestionsSum(const string &inputFile) {
    string line; map<char, int> answers;
    long yesSum=0; int people=0;
    ifstream questionAnswers(inputFile);
    while(getline(questionAnswers, line)) {
        if (line.empty()) {
            for (auto key:answers) {
                if (key.second == people) yesSum++;
                answers[key.first] = 0;
            }
            people=0;
        } else {
            for (auto letter:line) {
                answers[letter]+=1;
            }
            people++;
        }
    }
    return yesSum;
}

int main(int argc, char **argv) {
    string inputFile = argv[1];
    cout << yesQuestionsSum(inputFile) << endl;
}