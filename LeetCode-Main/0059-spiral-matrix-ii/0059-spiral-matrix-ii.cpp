class Solution {
public:
    vector<vector<int>> output;
    int count = 1;
    void fully_initialize(int n) {
        vector<int> temp;
        for (int i = 0; i < n; i++) {
            temp.push_back(1);
        }
        for (int i = 0; i < n; i++) {
            output.push_back(temp);
        }
        return;
    }
    void box(int level,int n) {
        int top = level;
        int bottom = n - 1 - level;
        int left = level;
        int right = n - 1 - level;
        if (top>bottom||(left>right)) {
            return;
        }
        for (int i = top; i <= right; i++) {
            output[top][i] = count++;
        }
        if (top < bottom) {
            for (int i = top+1; i <= bottom; i++) {
                output[i][right] = count++;
            }
        }
        if (top < bottom) {
            for (int i = right-1; i >= top; i--) {
                output[bottom][i] = count++;
            }
        }
        if (left<right) {
            for (int i = bottom-1; i >= top+1; i--) {
                output[i][left] = count++;
            }
        }
        box(level+1,n);
    }
    vector<vector<int>> generateMatrix(int n) {
        fully_initialize(n);
        box(0,n);
        return output;
    }
};
