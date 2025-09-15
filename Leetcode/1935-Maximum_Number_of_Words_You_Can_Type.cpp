#include <bits/stdc++.h>
using namespace std;


int canBeTypedWords(string text, string brokenLetters) {
    int n = 0;
    for(int i = 0; i < text.size(); i++) {
        if(text[i] == ' ') n++;
    }

    vector<unordered_set<char>> vec(n+1);
    int j = 0;
    for(int i = 0; i < text.size(); i++) {
        if(text[i] == ' ') j++;
        if(text[i] != ' ') vec[j].insert(text[i]);
    }

    unordered_set<int> set;
    for(int i = 0; i < brokenLetters.size(); i++) {
        char ch = brokenLetters[i];
        for(int j = 0; j < vec.size(); j++) {
            if(vec[j].find(ch) != vec[j].end()) {
                set.insert(j);
            }
        }
        if(set.size() == vec.size()) break;
    }

    return vec.size()-set.size();
}

int main() {
    string text = "hello world", brokenLetters = "ad";
    cout<< canBeTypedWords(text, brokenLetters) << endl;
}