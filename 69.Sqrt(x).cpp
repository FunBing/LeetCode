//This is after I saw the solution
class Solution {
public:
    int mySqrt(int x) {
        int subResult = 1, pos = 0;
        int max_limit = 1 << 31;
        while(subResult != max_limit && subResult < x / subResult)
        {
            subResult <<= 1;
            pos++;
        }

        if(subResult > x / subResult)
        {
            subResult >>= 1;
            pos--;
        }


        for(pos--; pos >= 0; pos--)
            if(subResult + (1 << pos) <= x / (subResult + (1 << pos)))
                subResult += 1 << pos;

        return subResult;
    }
};
