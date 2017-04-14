class Solution {
public:
    int reverse(int x) {
        int result = 0, flag = 1;
        long int test;
        if(x < 0)
        {
            flag = -1;
            x = -x;
        }
        while(x > 0)
        {
            test = (long int)result * 10 + x % 10;
            result = test;
            if(test != result)
                return 0;

            x /= 10;
        }

        return flag * result;
    }
};
