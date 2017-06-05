class Solution {
public:
    string simplifyPath(string path) {
        if(path.back() != '/')
            path += '/';

        int length = path.size();
        vector<string> resVector;
        string subResult;
        string result = "";
        bool flag = 0;



        for(int i = 0; i < length; ++i)
        {
            if(path[i] == '/' && flag == false)
                flag = true;
            else if(path[i] == '/' && flag == true)
            {
                if(subResult == ".")
                    ;
                else if(subResult == "..")
                {
                    if(resVector.size() > 0)
                        resVector.pop_back();
                }
                else if(subResult != "")
                    resVector.push_back(subResult);
                subResult = "";
            }
            else
                subResult += path[i];
        }

        for(auto row : resVector)
        {
            result += "/" + row;
        }

        if(result == "")
            result = "/";

        return result;
    }
};
