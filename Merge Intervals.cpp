#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool static comp(const Interval& i1,const Interval& i2){
    return i1.start < i2.start? true:false;
}
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        if(intervals.empty())
            return result;
            
        sort(intervals.begin(),intervals.end(),comp);
        
        result.push_back(intervals[0]);
        int len=intervals.size();
        for(int i=1;i<len;i++){
            if(result.back().end>=intervals[i].start){
                int larger=intervals[i].end>=result.back().end?
                    intervals[i].end:result.back().end;
                    Interval newi(result.back().start,larger);
                    result.pop_back();
                    result.push_back(newi);
            }else{
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
private:
    vector<Interval> result;
};
