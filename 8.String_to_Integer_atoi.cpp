class Solution {
public:
    int myAtoi(string str) {
        int i = 0;
        int flag = 1;
        int result = 0, tmp;

        //跳过所有空格
        while(str[i] == ' ')
            i++;

        //判断符号
        if(str[i] == '+')
        {
            flag = 1;
            i++;
        }
        else if(str[i] == '-')
        {
            flag = -1;
            i++;
        }

        //统计有效数字字符对应的数字
        for(; i < str.length(); i++)
        {
            if((str[i] < '0' || str[i] > '9'))
                return flag * result;

            tmp = result;

            result = result * 10 + (str[i] - '0');
            if(result / 10 != tmp)
            {
                if(flag == -1)
                    return INT_MIN;
                else
                    return INT_MAX;
            }
        }

        return flag * result;
    }
};
