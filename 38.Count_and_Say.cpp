class Solution {
public:
    string countAndSay(int n) {
        string result;
        string num = "1";
        vector<char> nums;
        vector<int> times;
        for(int i = 1; i < n; i++)
        {
            for(auto c : num)
            {
                if(nums.empty())
                {
                    nums.push_back(c);
                    times.push_back(1);
                }
                else
                {
                    if(nums.back() == c)
                        times.back()++;
                    else
                    {
                        nums.push_back(c);
                        times.push_back(1);
                    }
                }
            }
            num = "";
            auto iterNums = nums.begin();
            auto iterTimes = times.begin();
            while(iterNums != nums.end())
            {

                num += to_string(*(iterTimes++)) + *(iterNums++);
            }
            nums = {};
            times = {};
        }

        return num;

    }
};
