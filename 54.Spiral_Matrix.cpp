//This is my own code
//��������˵����ķ��������濼���õݹ���д�£����ӿɶ���

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;

        //���matrix��СΪ0�����ؿ�result
        if(matrix.size() == 0)
            return result;


        int rowStart = 0, rowEnd = matrix.size() - 1;
        int colStart = 0, colEnd = matrix[0].size() - 1;

        int start = 0, end = matrix.size() - 1;

        //ÿ�δ�ӡ������һȦ������
        while(rowStart < rowEnd && colStart < colEnd)
        {
            //������һ��
            for(int i = colStart; i <= colEnd; i++)
                result.push_back(matrix[rowStart][i]);
            //������һ��
            for(int i = rowStart + 1; i <= rowEnd; i++)
                result.push_back(matrix[i][colEnd]);
            //������һ��
            for(int i = colEnd - 1; i >= colStart; i--)
                result.push_back(matrix[rowEnd][i]);
            //������һ��
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
