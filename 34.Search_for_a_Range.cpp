//This is my own code
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result = {-1, -1};
        int length = nums.size();
        if(length == 0)
            return result;
        else if(nums[0] == target && nums[length - 1] == target)
            return {0, length - 1};

        int low = 0, high = length - 1, middle;
        while(low <= high)
        {
            middle = (low + high) / 1;
            if(nums[middle] == target)
                break;
            if(nums[middle] < target)
                low = middle + 1;
            else if(nums[middle] > target)
                high = middle - 1;
        }

        for(int i = low; i <= middle; i++)
            if(nums[i] == target)
            {
                result[0] = i;
                break;
            }
        for(int i = high; i >= middle; i--)
            if(nums[i] == target)
            {
                result[1] = i;
                break;
            }

        return result;


    }
};
