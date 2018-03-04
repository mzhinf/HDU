/*
	pair
	pair是一种模板类型，其中包含两个数据值，两个数据的类型可以不同。
	pair<A, B> a;
	1.对于pair类，由于它只有两个元素，分别名为first和second，
	因此直接使用普通的点操作符即可访问其成员
	2.可以使用make_pair对已存在的两个数据构造一个新的pair类型
    poj 1151

*/

#include <cstdio>
#include <set>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
double x[105][2],y[105][2];
set< pair<double,int> > sy;
int main(){
    //freopen("in.txt","r",stdin);
	int n,num=1;
	while(~scanf("%d",&n)&&n!=0){
		//输入
		for(int i=0;i<n;i++){
			scanf("%lf%lf%lf%lf",&y[i][0],&x[i][0],&y[i][1],&x[i][1]);
		}

		//存入关键点
		vector< pair<double,int> > events;
		for(int i=0;i<n;i++){
			events.push_back(make_pair(x[i][0],i));
			events.push_back(make_pair(x[i][1],i+n));
		}
		sort(events.begin(),events.end());

		//平面扫描
		double S=0;
		for(int i=0;i<events.size();i++){
			int id=events[i].second%n;
			if(!sy.empty()){
                //特殊处理扫描线长度 扫描线可能出现中空
                double len=0,be=0;
                set<int> t;
                for(set< pair<double,int> >::iterator it=sy.begin();it!=sy.end();++it){
                    if(!t.empty()){
                        len+=it->first-be;
                    }
                    be=it->first;
                    int temp=it->second;
                    if(temp<n){
                        t.insert(temp);
                    }
                    else{
                        t.erase(temp%n);
                    }
                }
				S+=len*(events[i].first-events[i-1].first);
			}
			if(events[i].second<n){//扫描左端(底部)
				sy.insert(make_pair(y[id][0], id));
				sy.insert(make_pair(y[id][1], id+n));
			}
			else{//扫描右端(顶部)
				sy.erase(make_pair(y[id][0], id));
				sy.erase(make_pair(y[id][1], id+n));
			}
		}
		printf("Test case #%d\n",num++);
		printf("Total explored area: %.2lf\n\n",S);
        sy.clear();

	}
	return 0;
}
