//This is my own code
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int middle = (low + high) / 2;
        while(low <= high)
        {
            if(target == nums[middle])
                return middle;

            //���ת�۵����е��Ҳ�
            if(nums[middle] >= nums[low])
            {
                if(target >= nums[low] && target < nums[middle])
                    high = middle - 1;

                else
                    low = middle + 1;
            }
            //���ת�۵����е����
            else if(nums[middle] <= nums[high])
            {
                if(target > nums[middle] && target <= nums[high])
                    low = middle + 1;
                else
                    high = middle - 1;
            }

            middle = (low + high) / 2;
        }

        return -1;

    }
};
