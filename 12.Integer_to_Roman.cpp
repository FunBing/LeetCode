class Solution {
public:
    string intToRoman(int num) {
        string unit[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        string tent[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string hundred[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string thousand[] = {"", "M", "MM", "MMM"};

        return thousand[(num / 1000) % 10] + hundred[(num / 100) % 10] + tent[(num / 10) % 10] + unit[num % 10];

    }
};
