/*
    ������ѧ����
    f   0 1 2 3 4 5 6 7 8 9 10
    val 1 2 0 2 2 1 0 1 1 2 0
    8��һ�ֻ� 2��6���Ա�����
    �൱��4��һ�ֻ�2������
	(2��6 2 ����ȡ���ֵ)
*/
#include <cstdio>
int main(){
    int n;
    while(~scanf("%d",&n)){
	   if (n%4==2)
		   printf("yes\n");
	   else
		   printf("no\n");
    }
	return 0;
}
