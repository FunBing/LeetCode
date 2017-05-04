//This is my own solution
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int length = nums.size();
        int low = 0, high = length - 1;
        int middle = 0;
        while(low <= high)
        {
            middle = (low + high) / 2;
            if(nums[middle] == target)
                return middle;
            else if(nums[middle] > target)
            {
                if(middle == 0 || nums[middle - 1] < target)
                    return middle;
                else
                    high = middle - 1;
            }
            else//nums[midlle] < target
            {
                if(middle == length - 1 || nums[middle + 1] > target)
                    return middle + 1;
                else
                    low = middle + 1;
            }
        }

    }
};
