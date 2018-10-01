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
    static bool cmp(Interval a, Interval b){
        return a.start<b.start;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        vector<Interval> ans;
        int len=0;
        if(intervals.size()==0){
            return ans;
        }
        ans.push_back(intervals[0]);
        len=1;
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i].start<=ans[len-1].end){
                ans[len-1].end=max(ans[len-1].end, intervals[i].end);
            }else{
                ans.push_back(intervals[i]);
                len++;
            }
        }
        return ans;
    }
};