class Solution {
public:
    string longestPalindrome(string s) {
        int longestNum = 0;
        int start = 0, end = 0;
        int i, j;
        int size = s.length();
        for(i = 0;i < size - 1;i++)
        {
            for(j = i + (end - start) + 1;j < size;j++)
            {
                int tempMiddle = (i + j) / 2, displacement = 1;
                int flag = 1;
                //如果长度为奇数
                if((j - i) % 2 == 0)
                {
                    while(tempMiddle + displacement <= j)
                    {
                        if(s[tempMiddle - displacement] != s[tempMiddle + displacement])
                        {
                            flag = 0;
                            break;
                        }
                        displacement++;
                    }
                }
                //如果长度为偶数
                else
                {
                    displacement = 0;
                    while((tempMiddle - displacement) >= i)
                    {
                        if(s[tempMiddle - displacement] != s[tempMiddle + 1 + displacement])
                        {
                            flag = 0;
                            break;
                        }
                        displacement++;
                    }
                }
                if(flag)
                {
                    if((end - start) <= (j - i))
                    {
                        start = i;
                        end = j;
                    }
                }
            }
        }

        string sResult = "";
        cout << start << "  " << end << endl;

        for(i = start;i <= end;i++)
        {
            sResult.push_back(s[i]);
        }

        cout << sResult;

        return sResult;
    }
};
