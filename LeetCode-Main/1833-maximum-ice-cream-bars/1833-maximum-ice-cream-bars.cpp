class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int bars = 0;
        int costsArr[100001] = {};
        for (int i : costs) {
            costsArr[i]++;
        }
        for (int  i = 0; i < 100001; ++i) {
            if (costsArr[i] == 0)
                continue;

            int take = min(costsArr[i], coins / i);
            bars += take;
            coins -= take * i;

            if (coins < i)
                break;
        }
        return bars;
    }
};

// there is an integer overflow

// class Solution {
// public:
//     int maxIceCream(vector<int>& costs, int coins) {
//         // std::sort(costs.begin(), costs.end());
//         int bars = 0;
//         int costsArr[100001] = {};
//         for (int i : costs) {
//             costsArr[i]++;
//         }
//         for (int  i = 0; i < 100001; ++i) {
//             if (coins >= i * costsArr[i]) {
//                 bars += costsArr[i];
//                 coins -= i * costsArr[i];
//             }
//             else {
//                 while (coins >= i) {
//                     bars++;
//                     coins -= i;
//                 }
//                 break;
//             }
//         }
//         return bars;
//     }
// };

// by sorting

// class Solution {
// public:
//     int maxIceCream(vector<int>& costs, int coins) {
//         std::sort(costs.begin(), costs.end());
//         int bars = 0;
//         for (int i : costs) {
//             if (i > coins) {
//                 break;
//             }
//             coins -= i;
//             bars++;
//         }
//         return bars;
//     }
// };
