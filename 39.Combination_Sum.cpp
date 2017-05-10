//This is my own ugly code
//�ݹ鷨���
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<vector<int>> result;

        sort(candidates.begin(), candidates.end());

        //�Ȼ���һ�����޸��������޸���
        int highTime = -1, lowTime = -1;
        int num = 0;
        while(num <= target)
        {
            num += candidates.back();
            lowTime++;
        }
        num = 0;
        while(num <= target)
        {
            num += candidates.front();
            highTime++;
        }

        for(int times = lowTime; times <= highTime; times++)
        {
            vector<vector<int>> tmpResult = recursionSum(candidates, target, times);
            if(!tmpResult.empty())
                for(auto tmpSubResult : tmpResult)
                    result.push_back(tmpSubResult);
        }

        for(auto &subResult : result)
            sort(subResult.begin(), subResult.end());

        sort(result.begin(), result.end());
        auto it = unique(result.begin(), result.end());


        result.resize(distance(result.begin(), it));

        return result;
    }

    //�ݹ麯��
    vector<vector<int>> recursionSum(vector<int>& candidates, int target, int times)
    {
        vector<vector<int>> result;
        //��ֹ����
        if(times == 1)
        {
            if(target >= candidates.front() && target <= candidates.back())
            {
                int low = 0, high = candidates.size() - 1;
                int middle = 0;
                while(low <= high)
                {
                    middle = (low + high) / 2;
                    if(candidates[middle] == target)
                    {
                        vector<int> tmpResult = {candidates[middle]};
                        result.push_back(tmpResult);
                        return result;
                    }
                    else if(candidates[middle] > target)
                        high = middle - 1;
                    else
                        low = middle + 1;
                }
            }
            return result;
        }

        //�ų������������
        if(candidates.front() * times > target || candidates.back() * times < target)
            return result;

        //�����ݹ����
        for(int i = 0; i < candidates.size(); i++)
        {
            vector<vector<int>> recursionResult = recursionSum(candidates, target - candidates[i], times - 1);
            if(!recursionResult.empty())
            {
                for(auto recursionSubResult : recursionResult)
                {
                    recursionSubResult.push_back(candidates[i]);
                    result.push_back(recursionSubResult);
                }
            }
        }

        return result;

    }
};
