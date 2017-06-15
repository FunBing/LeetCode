//This is my own solution
class Solution {
public:
    typedef vector<int>::iterator intInterator;

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> subResult, nums;
        for(int i = 1; i <= n; ++i)
            nums.push_back(i);

        recursionCombine(result, subResult, nums.begin(), nums.end(), k);

        return result;
    }

    void recursionCombine(vector<vector<int>> &result, vector<int> &subResult, intInterator numsBegin, intInterator numsEnd, const int &k)
    {
        if(subResult.size() == k)
        {
            result.push_back(subResult);
            return;
        }
        else if(numsBegin == numsEnd)
            return;

        for(auto iter = numsBegin; iter != numsEnd; ++iter)
        {
            subResult.push_back(*iter);
            recursionCombine(result, subResult, iter + 1, numsEnd, k);
            subResult.pop_back();
        }
    }


};
