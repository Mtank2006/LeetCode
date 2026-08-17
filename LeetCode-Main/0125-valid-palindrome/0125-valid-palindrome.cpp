class Solution {
public:
    bool isPalindrome(string s) {
        size_t itr = s.size() - 1;
        size_t i = 0;
        while (i < itr) {
            while (!(((s[i] >= 65) && (s[i] <= 90)) || ((s[i] >= 97) && (s[i] <= 122)) || ((s[i] >= 48) && (s[i] <= 57)))) {
                i++;
                if (i >= itr) {
                    break;
                }
            }
            if (i >= itr) {
                break;
            }
            while (!(((s[itr] >= 65) && (s[itr] <= 90)) || ((s[itr] >= 97) && (s[itr] <= 122)) || ((s[itr] >= 48) && (s[itr] <= 57)))) {
                itr--;
                if (i >= itr) {
                    break;
                }
            }
            if (i >= itr) {
                break;
            }
            if (((s[i] >= 48) && (s[i] <= 57)) || ((s[itr] >= 48) && (s[itr] <= 57))) {
                if (s[i] != s[itr]) {
                    return false;
                }
            }
            if ((s[i] != s[itr]) && (s[i] - 32 != s[itr]) && (s[i] != s[itr] -32)) {
                return false;
            }
            i++;
            itr--;
        }
        return true;
    }
};
