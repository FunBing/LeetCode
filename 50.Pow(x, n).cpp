//This is the code after I read the solution
class Solution {
public:
    double myPow(double x, int n) {
        double result = 1;

        if(n == 0)
            return 1.0;
        else if(x == 1)
            return 1.0;
        else if(x == -1)
            return n % 2 == 1 ? -1.0 : 1;

        if(n < 0)
        {
            n = -n;
            x = 1 / x;
        }

        unsigned int p = n;
        while(p)
        {
            if(p % 2)
                result *= x;
            x *= x;
            p >>= 1;
        }

        return result;
    }
};
