class Solution {
public:
    string intToRoman(int num) {
        string roman;
        while (num >= 1000) {
            roman.push_back('M');
            num -= 1000;
        }
        if (num >= 900) {
            roman.append("CM");
            num -= 900;
        }
        if (num >= 500) {
            roman.push_back('D');
            num -= 500;
        }
        if (num >= 400) {
            roman.append("CD");
            num -= 400;
        }
        while (num >= 100) {
            roman.push_back('C');
            num -= 100;
        }
        if (num >= 90) {
            roman.append("XC");
            num -= 90;
        }
        if (num >= 50) {
            roman.push_back('L');
            num -= 50;
        }
        if (num >= 40) {
            roman.append("XL");
            num -= 40;
        }
        while (num >= 10) {
            roman.push_back('X');
            num -= 10;
        }
        if (num >= 9) {
            roman.append("IX");
            num -= 9;
        }
        if (num >= 5) {
            roman.push_back('V');
            num -= 5;
        }
        if (num >= 4) {
            roman.append("IV");
            num -= 4;
        }
        while (num >= 1) {
            roman.push_back('I');
            num -= 1;
        }
        return roman;
    }
};
