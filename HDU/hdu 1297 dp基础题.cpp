/*
    分析:
	分析n个人最后一个人的可能性
    男:前n-1合法即可
    女:由于女生人数不少于2人则有两种情况
       1.前n-2合法+女女
       2.前n-2不合法+女女 --> 前n-4合法+男+女 +女女

    dp[n]=dp[n-1]+dp[n-2]+dp[n-4];
    
    dp[0]=1,dp[1]=1,dp[2]=2,dp[3]=4;
    
    数据量超过long long 要使用大数
*/
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
struct BigInteger {
	static const int BASE = 100000000;
	static const int WIDTH = 8;
	vector<int> s;
	BigInteger(long long num = 0) { *this = num; } //构造函数
	BigInteger operator = (long long num);
	BigInteger operator = (const string& str);
	BigInteger operator + (const BigInteger& b) const;
	void print();

};
BigInteger BigInteger::operator = (long long num) { //赋值运算符
	s.clear();
	do {
		s.push_back(num % BASE);
		num /= BASE;
	} while(num > 0);
	return *this;
}
BigInteger BigInteger::operator = (const string& str) { //赋值运算符
	s.clear();
	int x, len = (str.length() - 1) / WIDTH + 1;
	for(int i = 0; i < len; i++) {
		int end = str.length() - i*WIDTH;
		int start = max(0, end - WIDTH);
		sscanf(str.substr(start, end-start).c_str(), "%d", &x);
		s.push_back(x);
	}
	return *this;
}
BigInteger BigInteger::operator + (const BigInteger& b) const {
	BigInteger c;
	c.s.clear();
	for(int i = 0, g = 0; ; i++) {
		if(g == 0 && i >= s.size() && i >= b.s.size()) break;
		int x = g;
		if(i < s.size()) x += s[i];
		if(i < b.s.size()) x += b.s[i];
		c.s.push_back(x % BASE);
		g = x / BASE;
	}
	return c;
}
void BigInteger::print(){
	printf("%d",s.back());
	for(int i = s.size()-2; i >= 0; i--){
		printf("%08d",s[i]);
	}
	printf("\n");
}

BigInteger dp[1001];
int main(){
	int n;
	dp[0]=1,dp[1]=1,dp[2]=2,dp[3]=4;
	for(int i=4;i<1001;i++)dp[i]=dp[i-1]+dp[i-2]+dp[i-4];
	while(~scanf("%d",&n)){
		dp[n].print();
	}
    return 0;
}
