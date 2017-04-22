class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> mapCharacter;
        mapCharacter['('] = ')';
        mapCharacter['{'] = '}';
        mapCharacter['['] = ']';


        vector<char> vec = {};
        for(int i = 0;i < s.size();i++)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
                vec.push_back(s[i]);
            else if(vec.size() > 0 && s[i] == mapCharacter[vec[vec.size() - 1]])
                vec.pop_back();
            else
                return false;
        }

        if(vec.size() == 0)
            return true;
        else
            return false;


    }
};
