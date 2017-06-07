//This is my own code using O(m + n) space
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int sizeRow = matrix.size();
        if(sizeRow == 0)
            return;
        int sizeCol = matrix[0].size();

        unordered_map<int, int> mappingRow, mappingCol;
        for(int row = 0; row < sizeRow; ++row)
            mappingRow[row] = 0;
        for(int col = 0; col < sizeCol; ++col)
            mappingCol[col] = 0;


        for(int row = 0; row < sizeRow; ++row)
        {
            for(int col = 0; col < sizeCol; ++col)
            {
                if(matrix[row][col] == 0)
                {
                    mappingRow[row] = 1;
                    mappingCol[col] = 1;
                }
            }
        }

        for(int row = 0; row < sizeRow; ++row)
            for(int col = 0; col < sizeCol; ++col)
                if(mappingRow[row] == 1 || mappingCol[col] == 1)
                    matrix[row][col] = 0;

        return;

    }
};
