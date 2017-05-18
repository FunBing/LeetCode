//This is my own code
//˼·���ǰ���ֱ������==
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.size() == 0)
            return {};

        sort(intervals.begin(), intervals.end(), cmpIt);


        vector<Interval> result = {intervals[0]};
        int pos = 0;

        for(int i = 1; i < intervals.size(); i++)
        {
            //��һ����start����ǰһ����end
            if(intervals[i].start > result[pos].end)
            {
                result.push_back(intervals[i]);
                pos++;
            }
            //��һ����startС��ǰһ����end && ��һ����end����ǰһ����end
            else if(intervals[i].end > result[pos].end)
                result[pos].end = intervals[i].end;
            //��һ����startС��ǰһ����end && ��һ����endС��ǰһ����end
            else
                continue;
        }

        return result;

    }

    static bool cmpIt(Interval &inter1, Interval &inter2)
    {
        return inter1.start < inter2.start;
    }
};
