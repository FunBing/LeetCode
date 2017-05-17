//This is my own code
//Consider to solve the problem with backtracking
class Solution {
public:
    bool canJump(vector<int>& nums) {
        return recursionCanJump(nums, 0);
    }

    bool recursionCanJump(vector<int>& nums, int start)
    {
        if(start == nums.size() - 1 || nums[start] >= nums.size() - start - 1)
            return true;
        else if(nums[start] == 0)
            return false;

        for(int i = start + 1; i <= start + nums[start]; i++)
        {
            if(nums[start] - nums[i] == i - start)
                continue;

            if(recursionCanJump(nums, i))
                return true;
        }

        return false;

    }
};
