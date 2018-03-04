#include <cstdio>
#include <cstring>
typedef long long ll;
int mod;
#define N 5
struct Matrix{//0 - N-1
	int n,m;
    ll mat[N][N];
    Matrix(int n,int m):n(n),m(m){memset(mat,0,sizeof(mat));}
};
//矩阵乘法
Matrix operator *(Matrix &a,Matrix &b){
	Matrix res(a.n,b.m);
	for(int i=0;i<a.n;i++){
		for(int j=0;j<b.m;j++){
			res.mat[i][j]=0;
			for(int k=0;k<a.m;k++){
				res.mat[i][j]=(res.mat[i][j]+a.mat[i][k]*b.mat[k][j])%mod;
			}
		}
	}
	return res;
}
//矩阵快速幂
Matrix mpow_mod(Matrix ans,ll n)
{
	Matrix res(ans.n,ans.n);
	for(int i=0;i<ans.n;i++){//初始化res为单位阵
		for(int j=0;j<ans.n;j++){
			if(i==j)res.mat[i][j]=1;
			else res.mat[i][j]=0;
		}
	}
    while(n>0){
        if(n&0x1)res=res*ans;
        ans=ans*ans;
        n>>=1;
    }
    return res;
}
//快速幂
ll pow_mod(ll ans,ll n){
    ll res=1;
    while(n>0)
    {
        if(n&0x1)res=(res*ans)%mod;
        ans=(ans*ans)%mod;
        n>>=1;
    }
    return res;
}
//欧拉函数
int euler_phi(int n){
	int res = n;
	for(int i = 2; i * i <= n; i++){
		if(n % i ==0){
			res = res / i * (i - 1);
			for(; n % i == 0; n /= i);
		}
	}
	if(n != 1) res = res / n * (n - 1);
	return res;
}

int re(){
	char str[10];
	int res=0;
	scanf("%s",str);
	for(int i=0;str[i]!='\0';i++){
		res=res*10+(str[i]-'0');
	}
	return res;
}

int main(){
	int t;
	scanf("%d",&t);

	while(t--){
		int n=re();
		int y=re();
		int x=re();
		int s=re();

		//欧拉函数
		mod=euler_phi(s+1);
		//矩阵快速幂
		Matrix f(4,4);
		f.mat[0][1]=f.mat[1][0]=f.mat[2][2]=f.mat[1][3]=f.mat[3][3]=1;
		f.mat[1][2]=2;
		f.mat[1][1]=f.mat[2][1]=4;
		Matrix res(1,4);
		res.mat[0][0]=0,res.mat[0][1]=1,
		res.mat[0][2]=0,res.mat[0][3]=0;
		f=mpow_mod(f,(ll)n*y);
		res=res*f;
		//快速幂
		int k=res.mat[0][3]+mod;
		mod=s+1;
		printf("%I64d\n",pow_mod(x,k));
	}
	return 0;
}
