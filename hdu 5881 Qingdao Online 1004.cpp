#include <cstdio>

int main(){
    long long L,R;
    while(~scanf("%I64d%I64d",&L,&R)){
        if(L<=1&&R<=1){
            printf("0\n");
            continue;
        }
        if(L<=2&&R<=2){
            printf("1\n");
            continue;
        }
        if(R-L<=2){
            printf("2\n");
            continue;
        }

        long long temp,ssum;
        if(L==0){
            temp=R-L-1;
            ssum=temp/2+1;
        }
        else{
            temp=R-L-2;
            ssum=temp/2+2;
        }
        printf("%I64d\n",ssum);
    }
    return 0;
}