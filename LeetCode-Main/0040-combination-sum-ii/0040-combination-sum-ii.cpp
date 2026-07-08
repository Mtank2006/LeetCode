class Solution {
public:
    std::vector<std::vector<int>> combinations;
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
        currentArray.push_back(temp);
        dfs(index+1, remainingValue - temp, currentArray, initialCandidates);
        currentArray.pop_back();
        while ((index+1 < initialCandidates.size()) && (temp == initialCandidates[index+1])) {
            index++;
        }
        dfs(index+1, remainingValue, currentArray, initialCandidates);

        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> current;
        dfs(0,target,current,candidates);
    return combinations;
    }
};
