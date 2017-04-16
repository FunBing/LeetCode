//The code is a solution after I read the solutions :)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int flag, result = 0;
        while(i < j)
        {
            flag = min(height[i], height[j]);
            result = max(result, (j - i) * flag);
            while(height[i] <= flag && i < j)i++;
            while(height[j] <= flag && i < j)j--;
        }

        return result;
    }
};
