#include <cstdio>
#include <cstring>
char str[10000000];
double a[120000];

int judge(char *str){
    int len=strlen(str);
    if(len>7)return 119999;
    int num=0;
    for(int i=0;i<len;i++){
        num=num*10+(str[i]-'0');
    }
    return num;
}

int main(){
    double sum=1;
    a[0]=1,a[1]=1;
    //freopen("out.txt","w",stdout);
    for(int i=2;i<120000;i++){
        sum=sum+1.0/i/i;
        //printf("%d %.5lf\n",i,sum);
        a[i]=sum;
    }

    while(~scanf("%s",&str)){
        int m=judge(str);
        if(m<120000){
            printf("%.5lf\n",a[m]);
        }
        else{
            printf("%.5lf\n",a[119999]);
        }
    }
    return 0;
}
