//This is my own code before read the solution
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int result = 0, goal;
        int length = nums.size(), delta = INT_MAX;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < length - 2;i++)
        {
            goal = target - nums[i];
            int begin = i + 1, end = length - 1;
            while(begin < end)
            {
                if(abs(nums[begin] + nums[end] - goal) < delta)
                {
                    delta = abs(nums[begin] + nums[end] - goal);
                    result = nums[i] + nums[begin] + nums[end];
                }
                if(nums[begin] + nums[end] - goal == 0)
                    return target;
                else if(nums[begin] + nums[end] - goal > 0 && begin < end)
                    end--;
                else if(nums[begin] + nums[end] - goal < 0 && begin < end)
                    begin++;

            }
        }

        return result;
    }
};
