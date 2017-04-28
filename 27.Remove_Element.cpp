class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int posOld = 0, posNew = 0;
        for(posOld = 0; posOld < nums.size(); posOld++)
            if(nums[posOld] != val)
                nums[posNew++] = nums[posOld];

        return posNew;
    }
};
