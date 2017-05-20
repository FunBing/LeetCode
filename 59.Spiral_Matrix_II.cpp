class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if(n <= 0)
            return {};

        vector<vector<int>> result(n, vector<int>(n));


        int num = 1;
        int times[2] = {n, n - 1};
        int move[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};


        int iDir = 0;
        int pRow = 0, pCol = -1;
        while(times[iDir % 2])
        {
            for(int i = 0; i < times[iDir % 2]; i++)
            {
                pRow += move[iDir % 4][0];
                pCol += move[iDir % 4][1];

                result[pRow][pCol] = num++;
            }

            times[iDir % 2]--;
            iDir++;
        }

        return result;
    }
};
