#include <stdio.h>
#include <string.h>
#define N 65536
int longestValidParentheses(const char *s)
{
	int i,j,n;
	int dp[N];
	int max=0;
	n=strlen(s);
	for(i=0;i<N;i++)
		dp[i]=0;
	for(i=n-2;i>=0;i--)
	{
		if(s[i]=='(')
		{
			j=i+1+dp[i+1];
			if(j<n && s[j]==')')
			{
				dp[i]=dp[i+1]+2;
				if(j+1<n)
					dp[i]+=dp[j+1];
			}
		}
		if(max<=dp[i])
			max=dp[i];
	}
	return max;
}
int main()
{   
    	const char *s="))()()";
	printf("%d\n",longestValidParentheses(s));
    return 0;
} 

