#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    vector<vector<int>> matrix = {{3,0,1,4,2},{5,6,3,2,1},{1,2,0,1,5},{4,1,0,1,7},{1,0,3,0,5}};
    vector<int> query = {1,2,2,4}; // 对应row1, col1, row2, col2
    map<vector<int>, int> map;
    int sum = 0;
    int n = matrix.size(); // 行
    int m = matrix[0].size(); // 列
    // 定义矩阵的方法之一
    using Matrix = int[n+1][m+1];
    Matrix new_matrix = {};

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            new_matrix[i+1][j+1] = new_matrix[i+1][j] + new_matrix[i][j+1] - new_matrix[i][j] + matrix[i][j]; // 由于补齐，matrix中的i,j相当于new_matrix中的i+1, j+1;
        }
    }
    // 返回值的时候也要注意边界，需要减除的部分，行和列需要分别减1
    cout << new_matrix[query[2]+1][query[3]+1] - new_matrix[query[0]][query[3]+1] - new_matrix[query[2]+1][query[1]] + new_matrix[query[0]][query[1]] << endl;
}

