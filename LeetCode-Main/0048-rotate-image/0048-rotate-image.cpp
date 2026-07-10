class Solution {
public:
    void rotate(vector<vector<int>>& matrix, int level,int size) {
        if (level == size/2) {
            return;
        }
        for (int i = level; i < size-level-1; i++) {
            // int index1 = matrix[level][i]; //00
            // int index2 = matrix[size-1-i][level]; //30
            // int index3 = matrix[size-1-level][size-1-i]; //33
            // int index4 = matrix[level+i][size-1-level]; //03
            swap(matrix[level][i],matrix[size-1-i][level]);
            swap(matrix[size-1-i][level],matrix[size-1-level][size-1-i]);
            swap(matrix[size-1-level][size-1-i],matrix[i][size-1-level]);
        }
        rotate(matrix,level+1,size);
        return;
    }
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix[0].size();
        rotate(matrix,0,size);
    }
};
