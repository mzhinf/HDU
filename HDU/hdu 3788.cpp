/*
    Accepted:
    zooooj ozojo oozojoo ozooojooo oozooojoooooo
    Wrong Answer:
    zj jozojoo oozojoz joz ozojoz ozooojoo
*/
#include <cstdio>

bool f(char *str){
    int znum=0,zf=-1,jnum=0,jf=-1,other=0;
    for(int i=0;str[i]!='\0';i++){
        switch(str[i]){
            case 'z':znum++,zf=i;break;
            case 'j':jnum++;jf=i;break;
            case 'o':break;
            default: other++;
        }
    }
    if(znum==1&&jnum==1&&other==0){
        if(zf<jf)return true;
    }
    return false;
}

int main(){
	int m[3];
	char str[1005];
	while(~scanf("%s",str)){
        if(!f(str)){
            printf("Wrong Answer\n");
            continue;
        }
		m[0]=m[1]=m[2]=0;
		int i=0;
		while(str[i]=='o'){
			m[0]++;
			i++;
		}
		i++;
		while(str[i]=='o'){
			m[1]++;
			i++;
		}
		i++;
		while(str[i]=='o'){
			m[2]++;
			i++;
		}
		//еп╤о
        if(m[1]==1&&m[0]==m[2])printf("Accepted\n");
        else{
            if(m[0]*m[1]==m[2]&&m[1]>0)printf("Accepted\n");
            else printf("Wrong Answer\n");
        }
	}
	return 0;
}
