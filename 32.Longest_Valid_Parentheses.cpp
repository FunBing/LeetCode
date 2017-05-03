class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size() < 2)
            return 0;

        vector<int> stack = {};
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(')
                stack.push_back(i);
            else if(s[i] == ')')
            {
                if(!stack.empty() && s[stack.back()] == '(')
                    stack.pop_back();
                else
                    stack.push_back(i);
            }
        }

        if(stack.empty())
            return s.size();

        int start, end = s.size(), result = 0;
        while(!stack.empty())
        {
            start = stack.back();
            stack.pop_back();
            result = max(result, end - start - 1);
            end = start;
        }

        return max(result, end - 0);

    }
};
