class Solution {
public:
    int myAtoi(string str) {
        int i = 0;
        int flag = 1;
        int result = 0, tmp;

        //�������пո�
        while(str[i] == ' ')
            i++;

        //�жϷ���
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

        //ͳ����Ч�����ַ���Ӧ������
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
