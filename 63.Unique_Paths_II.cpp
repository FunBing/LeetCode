//This is my own code
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n;
        if(m > 0)
            n = obstacleGrid[0].size();

        if(obstacleGrid[0][0] == 1)
            return 0;

        vector<vector<int>> res(m, vector<int>(n, 0));
        res[0][0] = 1;
        for(int i = 1; i < m; i++)
            if(obstacleGrid[i][0] != 1 && res[i - 1][0] == 1)
                res[i][0] = 1;

        for(int i = 1; i < n; i++)
            if(obstacleGrid[0][i] != 1 && res[0][i - 1] == 1)
                res[0][i] = 1;

        for(int i = 1; i < m; i++)
            for(int j = 1; j < n; j++)
                if(obstacleGrid[i][j] != 1)
                    res[i][j] = res[i - 1][j] + res[i][j - 1];

        return res[m - 1][n - 1];

    }
};
