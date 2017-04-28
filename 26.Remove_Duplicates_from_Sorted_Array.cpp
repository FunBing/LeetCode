//This is my own code
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;

        int preNum = nums[0];
        int flag = 0;
        if(nums[nums.size() - 1] == INT_MAX)
            flag = 1;

        int length = 1;
        for(int i = 1;i < nums.size();i++)
        {
            if(nums[i] != preNum)
            {
                preNum = nums[i];
                length++;
            }
            else
            {
                nums[i] = INT_MAX;
            }
        }

        if(length != nums.size())
        {
            remove(nums.begin(), nums.end(), INT_MAX);
            if(flag)
                nums.push_back(INT_MAX);
        }

        return length;

    }
};
