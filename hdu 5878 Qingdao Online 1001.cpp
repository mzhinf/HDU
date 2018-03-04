#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
using namespace std;
typedef long long ll;
ll map[5200];
int coeff[4]={2,3,5,7};
void init(){
    priority_queue<ll, vector<ll>, greater<ll> > pq;
    set<ll> s;
    pq.push(1);
    s.insert(1);
    for(int i=1;i<5200;i++){
        ll x=pq.top(); pq.pop();
        map[i]=x;
        for(int j=0;j<4;j++){
            ll x2=x*coeff[j];
            if(!s.count(x2)){
                s.insert(x2);
                pq.push(x2);
            }
        }
    }
}
int main(){
    init();
    int t;
    ll temp;
    scanf("%d",&t);
    while(t--){
        scanf("%I64d",&temp);
        ll *i=lower_bound(map+1,map+5200,temp);
        printf("%I64d\n",*i);
    }
    return 0;
}