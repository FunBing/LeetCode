class Solution {
public:
    string getPermutation(int n, int k) {
        vector<string> nums;
        string result;
        for(int i = 1; i <= n; i++)
            nums.push_back(to_string(i));
        int pos = n - 1;
        int fact = 1;
        k--;
        while(pos)
        {
            fact = calFact(pos);
            result += nums[k / fact];
            nums.erase(nums.begin() + k / fact);
            k %= fact;
            pos--;
        }
        result += nums[0];

        return result;

    }

    int calFact(int num)
    {
        int fact = 1;
        while(num)
            fact *= num--;

        return fact;
    }
};
