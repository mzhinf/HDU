#include <cstdio>
char str[100005];
long long sum;
void solve(int &i){
    long long num=0;
    for(;str[i]=='q'&&str[i]=='q';i++)num++;
    sum+=(1+num)*num/2;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        sum=0;
        scanf("%s",str);
        for(int i=0;str[i]!='\0';++i){
            if(str[i]=='q')solve(i);
        }
        printf("%I64d\n",sum);
    }
    return 0;
}