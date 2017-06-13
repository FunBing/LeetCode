class Solution {
public:
    void sortColors(vector<int>& nums) {
        unordered_map<int, int> bucket;
        bucket[0] = 0;
        bucket[1] = 0;
        bucket[2] = 0;
        for(auto num : nums)
            bucket[num]++;

        int pos = 0;
        for(int i = 0; i < bucket[0]; i++)
            nums[pos++] = 0;
        for(int i = 0; i < bucket[1]; i++)
            nums[pos++] = 1;
        for(int i = 0; i < bucket[2]; i++)
            nums[pos++] = 2;

        return;
    }
};
