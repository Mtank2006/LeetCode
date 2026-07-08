class Solution {
public:
    void dfs(int index, int remainingValue, vector<int>& currentArray, vector<int>& initialCandidates) {
        if (remainingValue == 0) {
            combinations.push_back(currentArray);
            return;
        }
        if (index == initialCandidates.size()) {
            return;
        }
        int temp = initialCandidates[index];
        if (temp > remainingValue) {
            return;
        }

        dfs(index+1, remainingValue, currentArray, initialCandidates);
        currentArray.push_back(temp);
        dfs(index, remainingValue - temp, currentArray, initialCandidates);
        currentArray.pop_back();

        return;
    }
    std::vector<std::vector<int>> combinations;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> current;
        dfs(0,target,current,candidates);
    return combinations;
    }
};
