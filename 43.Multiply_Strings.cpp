//This is my own solution
class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> intNum1, intNum2;
        vector<int> result;

        if(num1 == "0" || num2 == "0")
            return "0";


        for(auto c : num1)
            intNum1.push_back(c - '0');

        for(auto c : num2)
            intNum2.push_back(c - '0');



        reverse(intNum1.begin(), intNum1.end());
        reverse(intNum2.begin(), intNum2.end());

        for(int i = 0; i < intNum1.size(); i++)
        {
            for(int j = 0; j < intNum2.size(); j++)
            {
                if(result.size() < i + j + 1)
                    result.push_back(intNum1[i] * intNum2[j]);
                else
                    result[i + j] += intNum1[i] * intNum2[j];
            }
        }

        string finalResult;

        for(int i = 0; i < result.size() - 1; i++)
        {
            char c = result[i] % 10 + '0';
            finalResult = c + finalResult;
            result[i + 1] += result[i] / 10;
        }
        finalResult = to_string(result.back()) + finalResult;

        return finalResult;

    }
};
