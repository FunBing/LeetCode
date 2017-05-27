//This is my own code
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int length = digits.size();
        if(length == 0)
            return {};

        vector<int> result(length + 1);

        result[length] = 1;
        for(int i = length; i !=0; --i)
        {
            result[i] += digits[i - 1];
            result[i - 1] += result[i] / 10;
            result[i] %= 10;
        }

        if(result[0] == 0)
            result.erase(result.begin());

        return result;
    }
};
