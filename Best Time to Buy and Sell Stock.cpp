class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len=prices.size();
        if(len==0)
            return 0;
        int maxprice=INT_MIN,minprice=INT_MAX;
        for(int i=0;i<len;i++){
            minprice=min(minprice,prices[i]);
            maxprice=max(maxprice,prices[i]-minprice);
        }
        return maxprice;
    }
};

