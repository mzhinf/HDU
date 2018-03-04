/*
    包含数学规律
    f   0 1 2 3 4 5 6 7 8 9 10
    val 1 2 0 2 2 1 0 1 1 2 0
    8个一轮回 2和6可以被整除
    相当于4个一轮回2被整除
	(2和6 2 代表取余后值)
*/
#include <cstdio>
int main(){
    int n;
    while(~scanf("%d",&n)){
	   if (n%4==2)
		   printf("yes\n");
	   else
		   printf("no\n");
    }
	return 0;
}
