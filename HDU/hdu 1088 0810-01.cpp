/*
    凡事要思考清楚在做决定！！！
    交了4次 好姜
    注意:
    <hr>如果处于当前行字符数等于0的情况，则直接输出，否则先输出回车，在输出<hr>
*/
#include <cstdio>
#include <cstring>

int main(){
    //freopen("in.txt","r",stdin);
    int len=0,temp=0;
    char str[100];
	while(~scanf("%s",str)){
        if(strcmp(str,"<br>")==0){
            printf("\n");
            len=0;
        }
        else if(strcmp(str,"<hr>")==0){
            if(len!=0)printf("\n");
            printf("--------------------------------------------------------------------------------\n");
            len=0;
        }
        else{
            temp=strlen(str);
            if(temp+len+1>80){
                printf("\n%s",str);
                len=temp;
            }
            else{
                if(len==0){
                    printf("%s",str);
                    len+=temp;
                }
                else{
                    printf(" %s",str);
                    len+=temp+1;
                }
            }
        }
	}
	printf("\n");
	return 0;
}
