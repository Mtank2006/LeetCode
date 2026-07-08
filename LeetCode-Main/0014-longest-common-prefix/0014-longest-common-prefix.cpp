class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
            return "";
        std::string common = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            std::string temp;
            for (int j = 0; j < min(common.size(), strs[i].size()); j++) {
                if (common[j] == strs[i][j]) {
                    temp += strs[i][j];
                }
                else {
                    break;
                }
            }
            common = temp;
        }
    return common;
    }
};
