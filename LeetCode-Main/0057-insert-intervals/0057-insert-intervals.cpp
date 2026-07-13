class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int size = intervals.size();
        if (size == 0) {
            intervals.push_back(newInterval);
            return intervals;
        }
        vector<vector<int>> result;
        if (intervals[size-1][1] < newInterval[0]) {
            intervals.push_back(newInterval);
            return intervals;
        }
        int count = 0;
        while ((count<size)&&(intervals[count][1] < newInterval[0])) {
            result.push_back(intervals[count]);
            count++;
        }
        while ((count<size)&&(intervals[count][1] >= newInterval[0] && intervals[count][0] <= newInterval[1])) {
            newInterval[0] = min(newInterval[0], intervals[count][0]);
            newInterval[1] = max(newInterval[1], intervals[count][1]);
            count++;
        }
        result.push_back(newInterval);
        while (count<size) {
            result.push_back(intervals[count]);
            count++;
        }
        return result;
    }
};





// class Solution {
// public:
//     vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
//         int size = intervals.size();
//         if (size == 0) {
//             intervals.push_back(newInterval);
//             return intervals;
//         }
//         int inserted = false;
//         for (int i = 0; i < size; i++) {
//             if (newInterval[0] <= intervals[i][0]) {
//                 intervals.insert(intervals.begin() + i, newInterval);
//                 inserted = true;
//                 break;
//             }
//         }
//         if (inserted == false) {
//             intervals.push_back(newInterval);
//         }
//         size++;
//         int write = 0;
//         int count = 0;
//         for (int read = 1; read < size; read++) {
//             int temp = intervals[write][1];
//             if (temp>=intervals[read][0]) {
//                 if (temp < intervals[read][1]) {
//                     intervals[write][1] = intervals[read][1];
//                 }
//             }
//             else {
//                 intervals[count++] = intervals[write];
//                 write = read;

//             }
//         }
//         intervals[count++] = intervals[write];
//         intervals.resize(count);
//         return intervals;
//     }
// };
