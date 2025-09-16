/*
There is a school that has classes of students and each class will be having a final exam. You are given a 2D integer array classes, where classes[i] = [passi, totali]. You know beforehand that in the ith class, there are totali total students, but only passi number of students will pass the exam.

You are also given an integer extraStudents. There are another extraStudents brilliant students that are guaranteed to pass the exam of any class they are assigned to. You want to assign each of the extraStudents students to a class in a way that maximizes the average pass ratio across all the classes.

The pass ratio of a class is equal to the number of students of the class that will pass the exam divided by the total number of students of the class. The average pass ratio is the sum of pass ratios of all the classes divided by the number of the classes.

Return the maximum possible average pass ratio after assigning the extraStudents students. Answers within 10-5 of the actual answer will be accepted.
*/

#include <bits/stdc++.h>
using namespace std;
        
double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
    priority_queue<pair<double, pair<double, double>>> pq;
    for(int i = 0; i < classes.size(); i++){
        double pass = classes[i][0];
        double total = classes[i][1];
        double ratio1 = pass/total;
        double ratio2 = (pass+1)/(total+1);
        double gain = (ratio2-ratio1);
        pq.push({gain, {pass, total}});
    }
    while(extraStudents) {
        auto x = pq.top();
        pq.pop();
        double pass = (x.second).first;
        double total = (x.second).second;
        double ratio1 = (pass+1)/(total+1);
        double ratio2 = (pass+2)/(total+2);
        double gain = (ratio2-ratio1);
        pq.push({gain, {pass+1, total+1}});
        extraStudents--;
    }

    int n = classes.size();
    double ans = 0;
    while(pq.size() > 0){
        auto x = pq.top();
        pq.pop();
        double pass = (x.second).first;
        double total = (x.second).second;
        double ratio = pass/total;
        ans += ratio;
    }
    return ans/n;
}

int main() {
    vector<vector<int>> classes = {{1, 2}, {3, 5}, {2, 2}};
    int extraStudents = 2;
    double ans = maxAverageRatio(classes, extraStudents);
    cout<< ans << endl;
}