//#define LOCAL
#include <cstdio>
#include <cstring>
char c[27]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char p[27]="VWXYZABCDEFGHIJKLMNOPQRSTU";
int main(){
    #ifdef LOCAL
        freopen("data.in","r",stdin);
        freopen("data.out","w",stdout);
    #endif
    char temp[1000];
    while(~scanf("%[^\n]",temp)){
        getchar();
        if(strcmp(temp,"START")==0){
            scanf("%[^\n]",temp);
            getchar();
            for(int i=0,j;i<strlen(temp);i++){
                for(j=0;j<26;j++){
                    if(temp[i]==c[j]){
                        printf("%c",p[j]);
                        break;
                    }
                }
                if(j==26)printf("%c",temp[i]);
            }
            printf("\n");
        }
        if(strcmp(temp,"END")==0)continue;
        if(strcmp(temp,"ENDOFINPUT")==0)break;
    }
    return 0;
}
