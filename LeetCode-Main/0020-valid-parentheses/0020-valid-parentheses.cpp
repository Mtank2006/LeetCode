class Solution {
public:
    bool isValid(string s) {
        int size = s.size();
        if (size % 2 == 1) {
            return false;
        }
        vector<char> stack;
        for (int i = 0; i < size; ++i) {
            if (stack.empty()) {
                stack.push_back(s[i]);
            }
            else if ((s[i] == ')' && stack.back() == '(') || (s[i] == '}' && stack.back() == '{') ||(s[i] == ']' && stack.back() == '[')) {
                stack.pop_back();
            }
            else if ((s[i] == '(') || (s[i] == '{') || (s[i] == '[')) {
                stack.push_back(s[i]);
            }
            else {
                return false;
            }
        }
        if (stack.empty()) {
            return true;
        }
        return false;
    }
};
