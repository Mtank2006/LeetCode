class Solution {
public:
    vector<vector<int>> output;
    void get_line(int n) {
        vector<int> line;
        if (n == 1) {
            line.push_back(1);
        }
        if (n >= 2) {
            line.push_back(1);
            for (int i = 1; i < n-1; i++) {
                line.push_back(output[n-2][i-1] + output[n-2][i]);
            }
            line.push_back(1);
        }
        output.push_back(line);
    }
    vector<vector<int>> generate(int numRows) {
        for (int i = 1; i <= numRows; i++) {
            get_line(i);
        }
        return output;
    }
};

// No optimisation

// class Solution {
// public:
//     vector<vector<int>> output;
//     void get_line(int n) {
//         vector<int> line;
//         line.resize(n);
//         if (n == 1) {
//             line[0] = 1;
//         }
//         if (n >= 2) {
//             line[0] = 1;
//             line[n-1] = 1;
//         }
//         for (int i = 1; i < n-1; i++) {
//             line[i] = output[n-2][i-1] + output[n-2][i];
//         }
//         output.push_back(line);
//     }
//     vector<vector<int>> generate(int numRows) {
//         for (int i = 1; i <= numRows; i++) {
//             get_line(i);
//         }
//         return output;
//     }
// };
