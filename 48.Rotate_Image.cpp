class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        recursionRotate(matrix, 0, matrix.size());
        return;
    }

    void recursionRotate(vector<vector<int>>& matrix, int start, int length)
    {
        int endPos = start + length - 1;
        if(length <= 1)
            return;
        else
        {
            for(int i = 0; i < length - 1; i++)
            {
                int tmp = matrix[start][start + i];

                matrix[start][start + i] = matrix[endPos - i][start];
                matrix[endPos - i][start] = matrix[endPos][endPos - i];
                matrix[endPos][endPos - i] = matrix[start + i][endPos];
                matrix[start + i][endPos] = tmp;
            }
            recursionRotate(matrix, start + 1, length - 2);
        }
        return;
    }
};
