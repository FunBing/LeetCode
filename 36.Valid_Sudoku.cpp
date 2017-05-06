//After I read the Solution
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int length = board.size();
        vector<vector<bool>> row(length, vector<bool>(10, false));
        vector<vector<bool>> col(length, vector<bool>(10, false));
        vector<vector<bool>> block(length * length / 9, vector<bool>(10, false));


        for(int i = 0; i != length; i++)//row
        {
            for(int j = 0; j != length; j++)//col
            {
                if(board[i][j] != '.')
                {
                    int dot = board[i][j] - '0' - 1;
                    //检查行/列/小块
                    if(row[i][dot] || col[j][dot] || block[i / 3 * 3 + j / 3][dot])
                        return false;
                    row[i][dot] = col[j][dot] = block[i / 3 * 3 + j / 3][dot] = true;
                }
            }
        }

        return true;

    }
};
