#include <cstdio>
bool r(int y){
	if (y%4==0 && y%100!=0 || y%400==0) return true;
	else return false;
}

int main(){
    //freopen("in.txt","r",stdin);
	int t;
	scanf("%d",&t);
	while(t--){
		int s,l;
		scanf("%d%d",&s,&l);
		if(r(s))l--;
		while(l>0){
            s++;
			if(r(s)){
                l--;
			}
		}
		printf("%d\n",s);
	}
	return 0;
}
