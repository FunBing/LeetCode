 //This is my own code
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int length = nums.size();

        for(int i = length - 2; i >= 0; i--)
        {
            if(nums[i] < nums[i + 1])
            {
                for(int j = length - 1; j > i; j--)
                {
                    if(nums[i] < nums[j])
                    {
                        int tmp = nums[i];
                        nums[i] = nums[j];
                        nums[j] = tmp;
                        sort(nums.begin() + i + 1, nums.end());
                        return;
                    }
                }
            }
        }

        sort(nums.begin(), nums.end());
        return;
    }

};
