class Solution {
public:
    vector<int> output;
    void get_line(int n) {
        output[n] = 1;
        for (int i = n-1; i > 0; i--) {
            output[i] = output[i] + output[i-1];
        }
        output[0] = 1;
    }
    vector<int> getRow(int rowIndex) {
        output.resize(rowIndex+1);
        for (int i = 0; i < rowIndex+1; i++) {
            get_line(i);
        }
        return output;
    }
};

//No optimisation


// class Solution {
// public:
//     vector<vector<int>> output;
//     void get_line(int n) {
//         vector<int> line;
//         if (n == 1) {
//             line.push_back(1);
//         }
//         if (n >= 2) {
//             line.push_back(1);
//             for (int i = 1; i < n-1; i++) {
//                 line.push_back(output[n-2][i-1] + output[n-2][i]);
//             }
//             line.push_back(1);
//         }
//         output.push_back(line);
//     }
//     vector<int> getRow(int rowIndex) {
//         for (int i = 1; i <= rowIndex+1; i++) {
//             get_line(i);
//         }
//         return output[rowIndex];
//     }
// };
