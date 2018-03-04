/*
	pair
	pair是一种模板类型，其中包含两个数据值，两个数据的类型可以不同。
	pair<A, B> a;
	1.对于pair类，由于它只有两个元素，分别名为first和second，
	因此直接使用普通的点操作符即可访问其成员
	2.可以使用make_pair对已存在的两个数据构造一个新的pair类型
    poj 2932
	5064K	2219MS
*/

#include <cstdio>
#include <set>
#include <vector>
#include <utility>
#include <algorithm>


using namespace std;
double x[40005],y[40005],r[40005];
bool inside(int i,int j){//判断i是否在j内部
	double dx = x[i] - x[j],dy = y[i] - y[j];
	return dx * dx + dy * dy <= r[j] * r[j];
}
int main(){
	int n;
	while(~scanf("%d",&n)){
		//输入
		for(int i=0;i<n;i++){
			scanf("%lf%lf%lf",&r[i],&x[i],&y[i]);
		}

		//存入关键点
		vector< pair<double,int> > events;
		for(int i=0;i<n;i++){
			events.push_back(make_pair(x[i]-r[i],i));
			events.push_back(make_pair(x[i]+r[i],i+n));
		}
		sort(events.begin(),events.end());

		//平面扫描
		set< pair<double,int> > outers;//与扫描线相交的最外层圆
		vector<int> res;
		for(int i=0;i<events.size();i++){
			int id=events[i].second%n;
			if(events[i].second<n){//扫描左端
				set< pair<double,int> >::iterator it=outers.lower_bound(make_pair(y[id],id));
				if (it != outers.end() && inside(id, it->second) ||
					it != outers.begin() && inside(id, (--it)->second)) continue;
				res.push_back(id);
				outers.insert(make_pair(y[id], id));//将进入扫描线的最外层圆插入
			}
			else{//扫描右端
				outers.erase(make_pair(y[id], id));//将离开扫描线的最外层圆移除
			}
		}
		//输出
		sort(res.begin(),res.end());
		printf("%d\n",res.size());
		for(int i=0;i<res.size();i++){
			printf("%d%c",res[i]+1,i+1==res.size()?'\n':' ');
		}
	}
	return 0;
}
