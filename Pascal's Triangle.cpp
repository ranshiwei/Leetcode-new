class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        if(numRows==0)
            return result;
        vector<int> p;
        p.push_back(1);
        result.push_back(p);
        if(numRows==1)
            return result;
        p.clear();
        int i=2;
        while(i<=numRows){
            vector<int> pre=result.back();
            p.push_back(1);
            for(int j=1;j<i-1;j++){
                p.push_back(pre[j-1]+pre[j]);
            }
            p.push_back(1);
            result.push_back(p);
            p.clear();
            i++;
        }
        return result;
    }
private:
    vector<vector<int> > result;
};
