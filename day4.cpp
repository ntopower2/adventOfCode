
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <regex>

using namespace std;

vector<string> split(const string& s, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}

bool isValid(const string& key) {
    auto field = key.substr(0, key.find(':'));
    auto value = key.substr(key.find(':')+1);
    regex exp("^#[a-f0-9]{6}"), nineDigits("^[0-9]{9}");
    if (field == "byr" && stoi(value) >= 1920 && stoi(value) <= 2002) return true;
    else if (field == "iyr" && stoi(value) >= 2010 && stoi(value) <= 2020) return true;
    else if (field == "eyr" && stoi(value) >= 2020 && stoi(value) <= 2030) return true;
    else if (field == "hgt" && (
            value.find("cm")!=string::npos && stoi(value)>=150 && stoi(value)<=193) ||
            (value.find("in")!=string::npos && stoi(value)>=59 && stoi(value)<=76)) return true;
    else if (field == "hcl" && regex_match(value, exp)) return true;
    else if (field == "ecl" && (value == "amb" || value == "blu" || value == "brn" || value == "gry" ||
            value == "grn" || value == "hzl"|| value == "oth")) return true;
    else if (field == "pid" && regex_match(value, nineDigits)) return true;
    else if (field == "cid") return true;
    else return false;
}

long validPassports(const string &filename, map<string, bool> keywords = {
                           {"byr",false},
                           {"iyr",false},
                           { "eyr", false },
                           { "hgt", false },
                           { "hcl", false },
                           { "ecl", false },
                           { "pid", false },
                           { "cid", false }}) {

    ifstream passportFile(filename);
    long valid = 0, i=0; string line;
    while (getline(passportFile, line)) {
        vector<string> spacesSplit = split(line, ' ');
        for (const auto& spaceSplit:spacesSplit) {
            auto word = spaceSplit.substr(0,spaceSplit.find(':'));
            if (isValid(spaceSplit)) keywords[word] = true;
        }
        if (line.empty()) {
            for (auto key:keywords) {
                if (key.second && key.first!="cid") i++;
                keywords[key.first] = false;
            }
            if (i==keywords.size()-1) valid++;
            i=0;
        }
    }
    return valid;
}

int main(int argc, char** argv) {
    string inputFile = argv[1];
    cout << validPassports(inputFile) << endl;
}