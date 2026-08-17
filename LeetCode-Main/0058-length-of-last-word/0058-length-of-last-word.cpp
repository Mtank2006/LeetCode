class Solution {
public:
    int lengthOfLastWord(string s) {
        size_t itr = s.size() - 1;
        int count = 0;
        while (s[itr] == ' ') {
            itr--;
        }
        while ((itr > 0) && (s[itr] != ' ')) {
            count++;
            itr--;
        }
        if (s[itr] != ' ') {
            count++;
        }
        return count;
    }
};
