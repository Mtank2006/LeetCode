// BY TACKING TRACK OF RELEVENT TO OLD ARRAY

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int size = intervals.size();
        if (size == 1) {
            return intervals;
        }
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
                return a[0] < b[0];
        });
        int write = 0;
        int count = 0;
        for (int read = 1; read < size; read++) {
            int temp = intervals[write][1];
            if (temp>=intervals[read][0]) {
                if (temp < intervals[read][1]) {
                    intervals[write][1] = intervals[read][1];
                }
            }
            else {
                intervals[count++] = intervals[write];
                write = read;

            }
        }
        intervals[count++] = intervals[write];
        // for (int i = count; i < size; i++) {
        //     intervals.pop_back();
        // }
        intervals.resize(count);
        return intervals;
    }
};

// BY TACKING TRACK OF RELEVENT TO NEW ARRAY

// class Solution {
// public:
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {
//         int size = intervals.size();
//         if (size == 1) {
//             return intervals;
//         }
//         sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
//                 return a[0] < b[0];
//         });
//         vector<vector<int>> result;
//         int write = 0;
//         for (int read = 1; read < size; read++) {
//             int temp = intervals[write][1];
//             if (temp>=intervals[read][0]) {
//                 if (temp < intervals[read][1]) {
//                     intervals[write][1] = intervals[read][1];
//                 }
//             }
//             else {
//                 result.push_back(intervals[write]);
//                 write = read;

//             }
//         }
//         result.push_back(intervals[write]);
//         return result;
//     }
// };



// BY MANUAL ERASE


// class Solution {
// public:
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {
//         int size = intervals.size();
//         if (size == 1) {
//             return intervals;
//         }
//         sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
//                 return a[0] < b[0];
//         });
//         for (int i = 0; i < size-1; i++) {
//             int erased = 0;
//             int temp = intervals[i][1];
//             if (temp>=intervals[i+1+erased][0]) {
//                 if (temp >= intervals[i+1+erased][1]) {
//                 }
//                 else {
//                     intervals[i][1] = intervals[i+1+erased][1];
//                 }
//                 erased++;
//                 size--;
//                 for (int j = 0; j < size-erased-i; j++){
//                     intervals[i+j+1] = intervals[i+j+1+erased];

//                 }
//                 intervals.pop_back();
//                 i--;
//             }

//         }
//         return intervals;
//     }
// };



//  BY ERASE


// class Solution {
// public:
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {
//         sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
//                 return a[0] < b[0];
//         });
//         int size = intervals.size();
//         for (int i = 0; i < size-1; i++) {
//             int temp = intervals[i][1];
//             if (temp>=intervals[i+1][0]) {
//                 if (temp >= intervals[i+1][1]) {
//                     intervals.erase(intervals.begin() +i+1);
//                 }
//                 else {
//                     intervals[i][1] = intervals[i+1][1];
//                     intervals.erase(intervals.begin() +i+1);
//                 }
//                 i--;
//                 size--;

//             }
//         }
//         return intervals;
//     }
// };
