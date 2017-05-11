 //The solution code is not so different with mine
//But it has a KEY improvement
//It's
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        vector<vector<int>> result;
        vector<int> savePoint;

        sort(candidates.begin(), candidates.end());

        iterationCombinationSum2(candidates, 0, result, savePoint, target);

        return result;
    }


    void iterationCombinationSum2(vector<int>& candidates, int startPos, vector<vector<int>>& result, vector<int> &savePoint, int target)
    {
        if(target == 0)
        {
            result.push_back(savePoint);
            return;
        }
        else if(target < 0)
            return;

        for(int i = startPos; i < candidates.size(); i++)
        {
            if(i > startPos && candidates[i] == candidates[i - 1])
                continue;
            savePoint.push_back(candidates[i]);
            iterationCombinationSum2(candidates, i + 1, result, savePoint, target - candidates[i]);
            savePoint.pop_back();
        }
    }

};
