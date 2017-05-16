//This is my own code
//代码采用了迭代的方法，后面考虑用递归重写下，增加可读性

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;

        //如果matrix大小为0，返回空result
        if(matrix.size() == 0)
            return result;


        int rowStart = 0, rowEnd = matrix.size() - 1;
        int colStart = 0, colEnd = matrix[0].size() - 1;

        int start = 0, end = matrix.size() - 1;

        //每次打印最外面一圈的数据
        while(rowStart < rowEnd && colStart < colEnd)
        {
            //最上面一行
            for(int i = colStart; i <= colEnd; i++)
                result.push_back(matrix[rowStart][i]);
            //最右面一列
            for(int i = rowStart + 1; i <= rowEnd; i++)
                result.push_back(matrix[i][colEnd]);
            //最下面一行
            for(int i = colEnd - 1; i >= colStart; i--)
                result.push_back(matrix[rowEnd][i]);
            //最左面一列
            for(int i = rowEnd - 1; i > rowStart; i--)
                result.push_back(matrix[i][colStart]);

            rowStart++;
            colStart++;
            rowEnd--;
            colEnd--;
        }

        if(rowStart == rowEnd)
            for(int i = colStart; i <= colEnd; i++)
                result.push_back(matrix[rowStart][i]);
        else if(colStart == colEnd)
            for(int i = rowStart; i <= rowEnd; i++)
                result.push_back(matrix[i][colStart]);

        return result;

    }
};
