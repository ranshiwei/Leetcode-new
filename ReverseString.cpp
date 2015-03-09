#include <iostream>
#include <sstream>
#include <stack>
#include <list>
using namespace std;
class Solution{
	public:
		void reverseWords(string &s)
		{
			/*
				if((s[0] == ' ')||(s.size()==0))
			{}
			else
			{
    			istringstream iss(s);
    			while(iss>>st)
    			{
    				sstack.push(st);
    			}
    			len = sstack.size();
    			while( len > 1 )
    			{
    				cout<<sstack.top()<<" "; 
    				sstack.pop();
    				len--;
    			} 
    			cout<<sstack.top()<<endl;
    			sstack.pop();
			}
			*/
			if((s[0] == ' ')||(s.size()==0))
			{}
			else
			{
				istringstream iss(s);
				while(iss>>st)
    			{
					vs.push_front(st);
				}
				list<string>::iterator first = vs.begin(),last=vs.end();;
				while(first!=last)
				{
					cout<<*first<<" ";
					first++;
				}
			}
		}
		private:
			int len;
			list<string>  vs;
			string st;
			stack<string> sstack;
};
int main(int argc,char *argv[])
{
	Solution so;
	string str = "hello world";
	so.reverseWords(str);
} 
