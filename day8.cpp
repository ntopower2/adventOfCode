#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(const string& s, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

pair<long, bool> accumValue(const string& inputfile, int lineNum) {
    string line; long accum = 0, i=0;
    bool visited[640]={false};
    string data[640][2];
    ifstream instructions(inputfile);
    while (getline(instructions, line)) {
        auto spaceSplit = split(line, ' ');
        data[i][0] = spaceSplit[0];
        data[i][1] = spaceSplit[1];
        i++;
    }
    i=0;
    while (!visited[i] && i!=636) {
        visited[i] = true;
        auto command = data[i][0];
        auto num = stoi(data[i][1]);
        if (lineNum == i && (command == "jmp" || command == "nop"))
            command = (command=="jmp")?"nop":"jmp";
        if (command == "jmp") i+=num;
        else if (command == "acc") {
            i++; accum+=num;
        } else if (command == "nop") i++;
        else cout << data[i][0] << endl;
    }
    return make_pair(accum, i==636);
}



int main(int argc, char **argv) {
    string inputFile = argv[1];
    for (int i=0;i<636;i++) {
        auto outForI = accumValue(inputFile, i);
        if (outForI.second) cout << outForI.first <<endl;
    }
}