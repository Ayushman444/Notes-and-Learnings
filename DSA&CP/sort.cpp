#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void sortColumnsDescending(vector<vector<int>>& matrix) {
    int numRows = matrix.size();
    int numCols = matrix[0].size();

    for (int col = 0; col < numCols; ++col) {
        sort(matrix.begin(), matrix.end(), [&](const vector<int>& a, const vector<int>& b) {
            return a[col] > b[col];
        });
    }
}

int main() {
    vector<vector<int>> matrix = {
        {3, 1, 4},
        {1, 5, 9},
        {2, 6, 5}
    };

    cout << "Original Matrix:" << endl;
    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    sortColumnsDescending(matrix);

    cout << "\nMatrix with columns sorted in descending order:" << endl;
    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}


3 6 9
2 5 5
1 1 4