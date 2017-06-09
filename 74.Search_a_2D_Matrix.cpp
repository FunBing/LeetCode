//This is my own solution
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return false;

        int low = 0, high = matrix.size() - 1;
        int middle;

        while(low <= high)
        {
            middle = (low + high) / 2;
            if(matrix[middle][0] <= target && matrix[middle].back() >= target)
            {
                int subMiddle;
                low = 0, high = matrix[middle].size() - 1;
                while(low <= high)
                {
                    subMiddle = (low + high) / 2;
                    if(matrix[middle][subMiddle] == target)
                        return true;
                    else if(matrix[middle][subMiddle] > target)
                        high = subMiddle - 1;
                    else if(matrix[middle][subMiddle] < target)
                        low = subMiddle + 1;
                }

                return false;
            }
            else if(matrix[middle][0] > target)
                high = middle - 1;
            else if(matrix[middle].back() < target)
                low = middle + 1;
        }

        return false;
    }
};
