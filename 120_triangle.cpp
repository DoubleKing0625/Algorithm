//
// Created by Peng Qixiang on 2017/8/20.
//
/*
// Given a triangle, find the minimum path sum from top to bottom.
// Each step you may move to adjacent numbers on the row below.
// Input:
//  [
//     [2],
//   [3,4],
//  [6,5,7],
// [4,1,8,3]
// ]
// Output: 2+3+5+1 = 11
*/

# include <cstdlib>
# include <iostream>
# include <vector>

using namespace std;

// from bottom to top
// tc : o(n*n)  sc : o(1)

// assuming triangle is saved as n*n triangular matrix
int minimumTotal(vector<vector<int>>& triangle){
    int size = triangle.size();
    for(int i = size - 2; i >= 0; i--){
        for(int j = 0; j < i + 1; j++){// j < i + 1 !!!! disgusting 0-started index problem
            triangle[i][j] += (triangle[i + 1][j] < triangle[i + 1][j + 1] ? triangle[i + 1][j] : triangle[i + 1][j + 1]);
        }
    }
    return triangle[0][0];
}

int main() {
    vector<vector<int>> triangle(3, vector<int>(3));
    triangle[0][0] = 1;
    triangle[1][0] = 2;
    triangle[1][1] = 1;
    triangle[2][0] = 1;
    triangle[2][1] = 2;
    triangle[2][2] = 1;
    cout << minimumTotal(triangle) << endl;
    return 0;
}
