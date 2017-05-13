//This is my own code
//using the mind of iteration
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        vector<vector<int>> result;
        vector<int> subResult;

        sort(nums.begin(), nums.end());

        iterationPermuteUnique(nums, result, subResult);

        return result;
    }

    void iterationPermuteUnique(vector<int> subNums, vector<vector<int>> &result, vector<int> &subResult)
    {
        if(subNums.size() == 0)
        {
            result.push_back(subResult);
            return;
        }

        for(unsigned int i = 0; i < subNums.size(); i++)
        {
            if(i > 0 && subNums[i] == subNums[i - 1])
                continue;

            vector<int> nextSubNums = subNums;
            subResult.push_back(subNums[i]);
            nextSubNums.erase(nextSubNums.begin() + i);
            iterationPermuteUnique(nextSubNums, result, subResult);
            subResult.pop_back();
        }

        return;
    }
};
