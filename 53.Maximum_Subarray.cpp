class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sumForNow, start = 0, end = 0, sum = 0;

        sumForNow = nums[0];
        for(int i = 0; i < nums.size(); i++)
        {
            if(sum <= 0)
            {
                if(sumForNow >= 0 && nums[i] <= 0 || sumForNow < 0 && nums[i] < sumForNow)//sumForNowÓÐµ×ÆøÁË
                    continue;
                else
                {
                    start = i;
                    end = i;
                    sum = nums[i];
                }
            }
            else
            {
                end = i;
                sum += nums[i];
            }

            sumForNow = sumForNow > sum ? sumForNow : sum;

        }

        return sumForNow;

    }
};
