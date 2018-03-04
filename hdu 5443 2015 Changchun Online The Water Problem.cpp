/*
	2015 ACMICPC Asia Regional Changchun Online
	The Water Problem

	Ïß¶ÎÊ÷
*/
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N = 1025;
int n, dat[2 * MAX_N -1];

void init(int n_){
    n = 1;
    while(n < n_)n *= 2;
    for(int i = 0; i < 2 * n - 1; i++) dat[i] = -1;
}

void update(int k, int a){
    k += n - 1;
    dat[k] = a;
    while(k > 0){
        k = (k - 1) / 2;
        dat[k] = max(dat[k * 2 + 1],dat[k * 2 +2]);
    }
}

int query(int a, int b, int k, int l, int r){
    if(r <= a || b<= l) return -1;

    if(a <= l && r <= b) return dat[k];
    else{
        int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
        int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
        return max(vl, vr);
    }
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n_,m,t,a,b;
        scanf("%d",&n_);
        init(n_);
        for(int i=0;i<n_;i++){
            scanf("%d",&t);
            update(i,t);
        }
        scanf("%d",&m);
        for(int i=0;i<m;i++){
            scanf("%d%d",&a,&b);
            t = query(a-1, b, 0, 0, n);
            printf("%d\n",t);
        }
    }
    return 0;
}
