/*
    ����Ҫ˼�������������������
    ����4�� �ý�
    ע��:
    <hr>������ڵ�ǰ���ַ�������0���������ֱ�����������������س��������<hr>
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
