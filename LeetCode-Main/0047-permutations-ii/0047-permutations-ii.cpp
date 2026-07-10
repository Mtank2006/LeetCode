class Solution {
public:
    vector<vector<int>> output;
    void backtrack(vector<int>& current, int index) {
        int size = current.size();
        if (index == size) {
            output.push_back(current);
            return;
        }
        set<int> used;
        for (int i = index; i < size; i++) {
            if (used.contains(current[i])) {
                continue;
            }
            used.insert(current[i]);
            swap(current[i],current[index]);
            backtrack(current,index+1);
            swap(current[i],current[index]);
        }
        return;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {

        backtrack(nums,0);
        return output;

    }
};
