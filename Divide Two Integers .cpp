#include <iostream>
#include <math.h>
#include <limits.h>
using namespace std;
 
class Solution {
public:
    int divide(int dividend, int divisor) {
        
    int symbol = (dividend<0)^(divisor<0) ? -1 : 1;
    
    long a = labs(dividend);
    long b = labs(divisor);
    if (b == 0 || dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
    } else if (b == 1) {
             return symbol * a;
    }
    
    long result = 0;
        int i = 0;
        while(a >= b) {
            i = 0;
            while(a >= b<<i) {
                a -= b<<i;
                result += 1<<i;
                i++;
            }
        }
        return (symbol * result);
        
    }
};

int main(){
	Solution s;
	int result = s.divide(1,1);
	cout<<"sizeof(long)"<<sizeof(long)<<endl;
	cout<<"sizeof(int)"<<sizeof(int)<<endl;
	cout<<"INT_MAX"<<INT_MAX<<endl;
	cout<<"INT_MIN"<<INT_MIN<<endl;
	cout<<result<<endl;
}
