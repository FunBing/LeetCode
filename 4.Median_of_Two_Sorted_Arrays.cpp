class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double result;
        int i, j;
        int m = nums1.size(), n = nums2.size();

        //排除m = 0 or n = 0
        if(m == 0)
        {
            if(n % 2 == 1)
                result = nums2[n / 2];
            else
                result = (nums2[n / 2 - 1] + nums2[n / 2]) / 2.0;

            return result;
        }
        else if(n == 0)
        {
            if(m % 2 == 1)
                result = nums1[m / 2];
            else
                result = (nums1[m / 2 - 1] + nums1[m / 2]) / 2.0;

            return result;
        }

        if(n >= m)
        {
            int lowA = 0, highA = m;

            i = (lowA + highA) / 2;
            j = (m + n + 1) / 2 - i;

            while(lowA <= highA)
            {
                if(i > 0 && j < n && nums1[i - 1] > nums2[j])
                    highA = i - 1;
                else if(i < m && j > 0 && nums2[j - 1] > nums1[i])
                    lowA = i + 1;
                else
                    break;

                i = (lowA + highA) / 2;
                j = (m + n + 1) / 2 - i;
            }

        }
        else
        {
            int lowB = 0, highB = n;

            j = (lowB + highB) / 2;
            i = (m + n + 1) / 2 - j;

            while(lowB <= highB)
            {
                if(j > 0 && i < m && nums2[j - 1] > nums1[i])
                    highB = j - 1;
                else if(i > 0 && j < n && nums1[i - 1] > nums2[j])
                    lowB = j + 1;
                else
                    break;

                j = (lowB + highB) / 2;
                i = (m + n + 1) / 2 - j;
            }
        }

        if(i > 0 && j > 0 && i < m && j < n)//如果不是边界情况
        {
            if((m + n) % 2 == 1)
                result = nums1[i - 1] > nums2[j - 1] ? nums1[i - 1] : nums2[j - 1];
            else
                //前部分最大的值与后部分最小的值之和/2
                result = (((nums1[i - 1] > nums2[j - 1] ? nums1[i - 1] : nums2[j - 1])
                    + (nums1[i] < nums2[j] ? nums1[i] : nums2[j]))) / 2.0;
        }
        else if(i == 0 && j == n)
        {
            if((m + n) % 2 == 1)
                result = nums2[j - 1];
            else
                result = (nums1[0] + nums2[n - 1]) / 2.0;
        }
        else if(i == m && j == 0)
        {
            if((m + n) % 2 == 1)
                result = nums1[i - 1];
            else
                result = (nums2[0] + nums1[m - 1]) / 2.0;
        }
        else if(i == 0)
        {
            if((m + n) % 2 == 1)
                result = nums2[j - 1];
            else
                result = (nums2[j - 1]
                    + (nums1[i] < nums2[j] ? nums1[i] : nums2[j])) / 2.0;
        }
        else if(j == 0)
        {
            if((m + n) % 2 == 1)
                result = nums1[i - 1];
            else
                result = (nums1[i - 1]
                    + (nums1[i] < nums2[j] ? nums1[i] : nums2[j])) / 2.0;
        }
        else if(i == m)
        {
            if((m + n) % 2 == 1)
                result = nums1[i - 1] > nums2[j - 1] ? nums1[i - 1] : nums2[j - 1];
            else
                result = ((nums1[i - 1] > nums2[j - 1] ? nums1[i - 1] : nums2[j - 1])
                    + nums2[j]) / 2.0;

        }
        else if(j == n)
        {
            if((m + n) % 2 == 1)
                result = nums1[i - 1] > nums2[j - 1] ? nums1[i - 1] : nums2[j - 1];
            else
                result = ((nums1[i - 1] > nums2[j - 1] ? nums1[i - 1] : nums2[j - 1])
                    + nums1[i]) / 2.0;
        }


        return result;
    }
};
