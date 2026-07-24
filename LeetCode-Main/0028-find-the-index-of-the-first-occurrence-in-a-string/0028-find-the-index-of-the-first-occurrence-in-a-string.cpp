class Solution {
public:
    int strStr(string haystack, string needle) {
        int size = needle.size();
        if (size == 0) {
            return 0;
        }
        int main_size = haystack.size();
        std::vector<int> lps(size, 0);
        int i = 1;
        int j = 0;
        while (i < size) {
            if (needle[i] == needle[j]) {
                j++;
                lps[i] = j;
                i++;
            }
            else {
                if (j !=0) {
                    j = lps[j-1];
                }
                else {
                    i++;
                }
            }
        }
        i = 0;
        j = 0;
        while (i < main_size) {
            if (needle[j] != haystack[i]) {
                if (j != 0) {
                    j = lps[j-1];
                }
                else {
                    i++;
                }
            }
            else {
                i++;
                j++;
                if (j == size) {
                    return i-size;
                }
            }
        }
        return -1;
    }
};
