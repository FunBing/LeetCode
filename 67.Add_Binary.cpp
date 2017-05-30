//This is my own code
class Solution {
public:
    string addBinary(string a, string b) {
        if(a.size() > b.size())
            return addBinary(b, a);

        //所有a的长度 <= b的长度
        int lengthA = a.size(), lengthB = b.size();

        for(int i = 1; i <= lengthA; ++i)
        {
            b[lengthB - i] += a[lengthA - i] - '0';
            if(b[lengthB - i] >= '2')
            {
                if(lengthB - i == 0)
                {
                    b[0] -= 2;
                    b.insert(b.begin(), '1');

                    return b;
                }

                b[lengthB - i - 1] += 1;
                b[lengthB - i] -= 2;
            }

        }

        for(int i = lengthB - lengthA - 1; i > 0; --i)
        {
            if(b[i] >= '2')
            {
                b[i] -= 2;
                b[i - 1] +=1 ;
            }
        }

        if(b[0] < '2')
            return b;
        else
        {
            b[0] -= 2;
            b.insert(b.begin(), '1');
        }

        return b;


    }
};
