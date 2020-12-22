#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>
#include <list>

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

long bagCount(map<string, vector<pair<string, int>>> &adj,
              const string& startBag = "shinygold") {
    // counts bags that contain startBag with BFS search
    list<string> queue; long bags=0;
    adj[startBag].push_back(make_pair("-1",-1));
    queue.push_back(startBag);
    while (!queue.empty()) {
        string currentBag = queue.front();
        queue.pop_front();
        for (auto bag = adj[currentBag].begin(); bag!=adj[currentBag].end();bag++) {
            string name = bag->first;
            if (name.length()>3 && (adj[name].empty() || adj[name].back().second!=-1))
                adj[name].push_back(make_pair("-1",-1)), queue.push_back(name), bags++;
        }
    }
    return bags;
}

map<string, vector<pair<string, int>>> createBagGraph(const string &inputFile) {
    // creates adjacency lists for bag relations
    string line; map<string, vector<pair<string, int>>> adj;
    ifstream bagsData(inputFile);
    while (getline(bagsData, line)) {
        auto spaceSplit = split(line, ' ');
        string bag1 = spaceSplit[0].append(spaceSplit[1]);
        for (int i=0;i<(spaceSplit.size()-4)/4 && spaceSplit.size()>7;i++) {
            string bag2 = spaceSplit[5 + 4*i].append(spaceSplit[6 + 4*i]);
            int bagNum = stoi(spaceSplit[4*(i+1)]);
            adj[bag2].push_back(make_pair(bag1, bagNum));
        }
    }
    return adj;
}

int main(int argc, char **argv) {
    (void) argc;
    string inputFile = argv[1];
    auto bagGraph = createBagGraph(inputFile);
    cout << bagCount(bagGraph) << endl;
}

