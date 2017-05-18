//This is my own code
//思路就是按照直觉来做==
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
            //后一个的start大于前一个的end
            if(intervals[i].start > result[pos].end)
            {
                result.push_back(intervals[i]);
                pos++;
            }
            //后一个的start小于前一个的end && 后一个的end大于前一个的end
            else if(intervals[i].end > result[pos].end)
                result[pos].end = intervals[i].end;
            //后一个的start小于前一个的end && 后一个的end小于前一个的end
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
