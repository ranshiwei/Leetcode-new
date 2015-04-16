class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> p;
        p.push_back(1);
        result.push_back(p);
        if(rowIndex==0)
            return result[0];
        p.clear();
        int i=2;
        while(i<=rowIndex+1){
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
        return result[rowIndex];
    }
private:
    vector<vector<int> > result;
};
