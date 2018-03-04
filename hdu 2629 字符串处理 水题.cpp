#include <cstdio>

char map[8][20]={"Zhejiang","Beijing","Taiwan","Hong Kong","Macao","Tibet","Liaoning","Shanghai"};
char num[8][3]={"33","11","71","81","82","54","21","31"};

int main(){
	int t,i,year,month,day;
	char str[20];
	scanf("%d",&t);
	while(t--){
		scanf("%s",str);
		for(i=0;i<8;i++){
			if(str[0]==num[i][0]&&str[1]==num[i][1])break;
		}
		year=(str[6]-'0')*1000+(str[7]-'0')*100+(str[8]-'0')*10+(str[9]-'0');
		month=(str[10]-'0')*10+(str[11]-'0');
		day=(str[12]-'0')*10+(str[13]-'0');
		printf("He/She is from %s,and his/her birthday is on %02d,%02d,%04d based on the table.\n",map[i],month,day,year);
	}
	return 0;
}
