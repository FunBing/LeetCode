 //The code after I read the Solution
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        long dividendLong = labs(dividend), divisorLong = labs(divisor);
        int result = 0;
        int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;


        while(dividendLong >= divisorLong)
        {
            long divisorTmp = divisorLong;
            int resultTmp = 1;

            while(dividendLong >= (divisorTmp << 1))
            {
                divisorTmp <<= 1;
                resultTmp <<= 1;
            }
            dividendLong -= divisorTmp;
            result += resultTmp;
        }

        return sign * result;
    }
};
