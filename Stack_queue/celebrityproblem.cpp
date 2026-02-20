#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        int top = 0, down = n - 1;

        // Elimination phase
        while(top < down) {
            if(mat[top][down] == 1) {
                top++;
            }
            else if(mat[down][top] == 1) {
                down--;
            }
            else {
                top++;
                down--;
            }
        }

        // Verification phase
        for(int i = 0; i < n; i++) {
            if(i == top) continue;

            if(mat[top][i] != 0 || mat[i][top] != 1) {
                return -1;
            }
        }

        return top;
    }
};

int main() {
    Solution sol;

    // Example matrix
    vector<vector<int>> mat = {
        {0, 1, 1},
        {0, 0, 1},
        {0, 0, 0}
    };

    int result = sol.celebrity(mat);

    if(result == -1)
        cout << "No Celebrity" << endl;
    else
        cout << "Celebrity is person index: " << result << endl;

    return 0;
}
