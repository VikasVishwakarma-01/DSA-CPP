#include <bits/stdc++.h>
using namespace std;

int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
    int m = languages.size();
    
    vector<unordered_set<int>> lang_sets(m);
    for(int i = 0; i < m; ++i){
        for(int lang : languages[i]){
            lang_sets[i].insert(lang);
        }
    }

    unordered_set<int> users_to_teach;
    
    for(const auto& friendship : friendships){
        int u = friendship[0] - 1;
        int v = friendship[1] - 1;

        bool can_communicate = false;
        for(int lang : lang_sets[u]) {
            if(lang_sets[v].count(lang)) {
                can_communicate = true;
                break;
            }
        }

        if(!can_communicate) {
            users_to_teach.insert(u);
            users_to_teach.insert(v);
        }
    }
    
    if(users_to_teach.empty()) {
        return 0;
    }

    int min_teachers = users_to_teach.size();

    for(int lang = 1; lang <= n; ++lang){
        int current_teachers = 0;
        for(int user_idx : users_to_teach){
            if(lang_sets[user_idx].find(lang) == lang_sets[user_idx].end()){
                current_teachers++;
            }
        }
        min_teachers = min(min_teachers, current_teachers);
    }

    return min_teachers;
}

int main() {
    int n = 2;
    vector<vector<int>> languages = {{1}, {2}, {1, 2}};
    vector<vector<int>> friendships = {{1, 2}, {1, 3}, {2, 3}};
    cout<<minimumTeachings(n, languages, friendships);
}
