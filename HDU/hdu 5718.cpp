/*
	其他的思路:先将n-1位的数存在一个数组中再把另一个数加入计算
	读v O(n) 存数 O(n) 计算 O(n)
*/

#include <cstdio>
#include <cstring>

char str[10000005];
int v[15];

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%s",str);
		int n=strlen(str);
		memset(v,0,sizeof(v));
		for(int i=0;i<n;i++) v[str[i]-'0']++;
		if(n-v[0]<=1){
			printf("Uncertain\n");
			continue;
		}
		bool flag=false;
		//第二个数字 a
		int j,a,len=n-1;
		for(j=1;!v[j];j++);
		a=j;
		v[j]--;
		//最后一位 j
		for(j=0;!v[j];j++);
		v[j]--;
		//最后一位之和 end
		int end=(a+j)%10;
		//判断是否有进位
		if(a+j>=10){
			//有进位 flag=true;
			flag=true;
			//判断进位数是否为9
			for(j=0;!v[j];j++);
			if(j==9){
				printf("1");
				while(v[9]--){
					printf("0");
				}
				printf("%d\n",end);
				continue;
			}
		}
		//开始输出
		//最后两位
		for(j=0;j<10&&!v[j];j++);
		j%=10;
		v[j]--;
		if(flag)j++;
		end=j*10+end;
		if(len<=2){
			printf("%d\n",end);
			continue;
		}
        //
		for(j=9;j>0&&!v[j];j--);
		for(int i=len-2;i>0;){
			while(v[j]--){
				printf("%d",j);
				i--;
			}
			j--;
		}
		printf("%02d\n",end);
	}
	return 0;
}
