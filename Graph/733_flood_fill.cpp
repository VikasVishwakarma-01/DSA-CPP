#include <bits/stdc++.h>
using namespace std;

int initialColor;
int newColor;
void dfs(vector<vector<int>>& image, int currRow, int currCol) {
    int n = image.size();
    int m = image[0].size();
    if(currRow < 0 || currCol < 0 || currRow >= n || currCol >= m) return;
    if(image[currRow][currCol] != initialColor) return;

    image[currRow][currCol] = newColor;
    
    dfs(image, currRow-1, currCol);//u
    dfs(image, currRow+1, currCol);//d
    dfs(image, currRow, currCol-1);//l
    dfs(image, currRow, currCol+1);//r

}
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    if(color == image[sr][sc]) return image;
    initialColor = image[sr][sc];
    newColor = color; 
    dfs(image, sr, sc);
    return image;
}

int main() {
    vector<vector<int>> image = {{1,1,1}, {1,1,0}, {1,0,1}};
    int sr = 1, sc = 1, color = 2;
    floodFill(image, sr, sc, color);
    for(int i = 0; i < image.size(); i++){
        for(int j = 0; j < image[0].size(); j++){
            cout<<image[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}