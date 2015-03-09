#include <iostream>
using namespace std;

class Solution{
	public:
		
	int minmaxn(int N){
		int len=0,i,temp=N;
		int result=0;
		while((N/10)!=0){
			N/=10;
			len++;
		}
		int num[len+2];
		while(len>=0){
			int number = temp%10;
			temp/=10;
			cout<<number<<endl;
			num[len--]==temp;
		}
		num[len+1]=0;
		cout<<len<<endl;
		for(int j=0;j<=len+1;j++)
			cout<<num[j]<<endl;
			
		bool flag = true;
		while(flag){
			flag=false;
			for(int k=0;k<=len+1;k++){
				if(num[k]==num[k+1]){
					flag=true;
					num[k]+=1;
					if(num[k]>=10){
						num[k]=num[k]%10;
						num[k+1]+=1;
					}
				}
			}
		}
		int length =len;
		for(;length>0;length--)
			result += num[length]*10;
		return result;
	}
};
int main(int argc,char *argv[])
{
	Solution s;
	int rresult = s.minmaxn(1234);
	cout<<rresult;
}
