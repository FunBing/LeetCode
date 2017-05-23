//This is the code after I read the solution
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m > n)
            return uniquePaths(n, m);

        vector<int> res(m, 1);

        for(int i = 1; i < n; i++)
        {
            for(int j = 1;j < m; j++)
                res[j] += res[j - 1];
        }

        return res[m - 1];
    }
};
