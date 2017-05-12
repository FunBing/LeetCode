class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subResult;

        iterationPermute(result, subResult, nums);

        return result;
    }

    void iterationPermute(vector<vector<int>> &result, vector<int> &subResult, vector<int> inputOfNums)
    {
        if(inputOfNums.size() == 0)
        {
            result.push_back(subResult);
            return;
        }


        for(unsigned int i = 0; i < inputOfNums.size(); ++i)
        {
            vector<int> newInputOfNums = inputOfNums;
            newInputOfNums.erase(newInputOfNums.begin() + i);

            subResult.push_back(inputOfNums[i]);
            iterationPermute(result, subResult, newInputOfNums);
            subResult.pop_back();
        }

        return;
    }
};
