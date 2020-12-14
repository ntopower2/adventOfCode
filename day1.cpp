
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int productForPair(const string& filename, int target=2020) {
//  Given a list of numbers, searches for a pair of nums
//  that adds up to 2020 and returns their product
    ifstream numList(filename);
    if (numList.bad()) return -1;
    int num;
    map<int, int> remain;
    while (numList >> num) {
        if (!remain.count(num)) remain[target-num] = num;
        else return num*remain[num];
    }
    return 0;
}

int productForTriplet(const string& filename, int target=2020) {
//  Given a list of numbers, searches for a triplet of nums
//  that adds up to 2020 and returns their product
    ifstream numList(filename);
    if (numList.bad()) return -1;
    int num;
    vector<int> nums;
    while (numList >> num) {
        nums.push_back(num);
    }
    sort(nums.begin(), nums.end());
    for (int i=0;i<nums.size()-2;++i) {
        int j=i+1, k=nums.size()-1;
        while (j<k) {
            if (nums[j]+nums[k] < target-nums[i])
                j++;
            else if (nums[j]+nums[k] > target-nums[i])
                k--;
            else
                return nums[j]*nums[k]*nums[i];
        }
    }
    return 0;
}

int main() {
    string inputFile = "../inputFiles/day1.txt";
    cout << productForPair(inputFile) << endl;
    cout << productForTriplet(inputFile) << endl;
}
