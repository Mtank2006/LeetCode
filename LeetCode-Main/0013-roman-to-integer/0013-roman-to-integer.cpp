class Solution {
public:
    int romanToInt(string s) {
        int size = s.size();
        int sum = 0;
        for (int i = 0; i < size; i++) {
            switch (s[i]) {
                case 'I':
                    sum += 1;
                    if (i+1 < size && (s[i+1] == 'V' || s[i+1] == 'X')) {
                        if (s[i+1] == 'V') {
                            sum += 3;
                            i++;
                        }
                        else {
                            sum += 8;
                            i++;
                        }
                    }
                    break;
                case 'V':
                    sum += 5;
                    break;
                case 'X':
                    sum += 10;
                    if (i+1 < size && (s[i+1] == 'L' || s[i+1] == 'C')) {
                        if (s[i+1] == 'L') {
                            sum += 30;
                            i++;
                        }
                        else {
                            sum += 80;
                            i++;
                        }
                    }
                    break;
                case 'L':
                    sum += 50;
                    break;
                case 'C':
                    sum += 100;
                    if (i+1 < size && (s[i+1] == 'D' || s[i+1] == 'M')) {
                        if (s[i+1] == 'D') {
                            sum += 300;
                            i++;
                        }
                        else {
                            sum += 800;
                            i++;
                        }
                    }
                    break;
                case 'D':
                    sum += 500;
                    break;
                case 'M':
                    sum += 1000;
                    break;
            }
        }
        return sum;
    }
};
