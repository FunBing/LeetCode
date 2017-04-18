//This is the code after I read the solution
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > result = {};

        int length = nums.size();
        if(length < 3)
            return result;

        sort(nums.begin(), nums.end());
        int i, low, high, goal;
        for(i = 0;i < length - 2;i++)
        {
            goal = -nums[i];
            low = i + 1;
            high = length - 1;

            while(low < high)
            {
                int sum = nums[low] + nums[high];

                if(sum > goal)
                    high--;
                else if(sum < goal)
                    low++;
                else
                {
                    int result1, result2;
                    result1 = nums[low];
                    result2 = nums[high];
                    result.push_back({nums[i], nums[low], nums[high]});
                    while(result1 == nums[low] && low < high)
                        low++;
                    while(result2 == nums[high] && low < high)
                        high--;
                }
            }

            while(nums[i] == nums[i + 1])
                i++;
        }

        return result;
    }
};
