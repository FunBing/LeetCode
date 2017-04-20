//This is the code after I read the solution
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > result = {};

        int length = nums.size();
        if(length < 4)
            return result;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < length - 3; i++)
        {
            if(nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)
                break;
            else if(nums[i] + nums[length - 3] + nums[length - 2] + nums[length - 1] < target)
                continue;

            for(int j = i + 1; j < length - 2; j++)
            {
                if(nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target)
                    break;
                else if(nums[i] + nums[j] + nums[length - 2] + nums[length - 1] < target)
                    continue;

                int head = j + 1, trail = length - 1;
                int goal = nums[i] + nums[j];
                while(head < trail)
                {
                    if(goal + nums[head] + nums[trail] == target)
                    {
                        result.push_back({nums[i], nums[j], nums[head], nums[trail]});

                        do{
                            trail--;
                        }
                        while(nums[trail] == nums[trail + 1] && head < trail);

                        do{
                            head++;
                        }
                        while(nums[head] == nums[head - 1] && head < trail);
                    }

                    if(goal + nums[head] + nums[trail] > target)
                        trail--;
                    else if(goal + nums[head] + nums[trail] < target)
                        head++;
                }
                while(nums[j] == nums[j + 1] && j < length - 2)
                    j++;
            }
            while(nums[i] == nums[i + 1] && i < length - 3)
                i++;
        }


        return result;
    }
};
