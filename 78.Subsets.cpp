//This is my own solution
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subResult;
        for(int i = 0; i <= nums.size(); ++i)
        {
            recursionSubsets(result, subResult, nums, 0, i);
        }

        return result;
    }

    void recursionSubsets(vector<vector<int>> &result, vector<int> &subResult, vector<int> &nums, int start, int k)
    {
        if(k == 0)
        {
            result.push_back(subResult);
            return;
        }

        for(int i = start; i < nums.size() && nums.size() - i >= k; ++i)
        {
            subResult.push_back(nums[i]);
            recursionSubsets(result, subResult, nums, i + 1, k - 1);
            subResult.pop_back();
        }

        return;
    }
};
