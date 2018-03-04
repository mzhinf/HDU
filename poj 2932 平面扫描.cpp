/*
	pair
	pair��һ��ģ�����ͣ����а�����������ֵ���������ݵ����Ϳ��Բ�ͬ��
	pair<A, B> a;
	1.����pair�࣬������ֻ������Ԫ�أ��ֱ���Ϊfirst��second��
	���ֱ��ʹ����ͨ�ĵ���������ɷ������Ա
	2.����ʹ��make_pair���Ѵ��ڵ��������ݹ���һ���µ�pair����
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
bool inside(int i,int j){//�ж�i�Ƿ���j�ڲ�
	double dx = x[i] - x[j],dy = y[i] - y[j];
	return dx * dx + dy * dy <= r[j] * r[j];
}
int main(){
	int n;
	while(~scanf("%d",&n)){
		//����
		for(int i=0;i<n;i++){
			scanf("%lf%lf%lf",&r[i],&x[i],&y[i]);
		}

		//����ؼ���
		vector< pair<double,int> > events;
		for(int i=0;i<n;i++){
			events.push_back(make_pair(x[i]-r[i],i));
			events.push_back(make_pair(x[i]+r[i],i+n));
		}
		sort(events.begin(),events.end());

		//ƽ��ɨ��
		set< pair<double,int> > outers;//��ɨ�����ཻ�������Բ
		vector<int> res;
		for(int i=0;i<events.size();i++){
			int id=events[i].second%n;
			if(events[i].second<n){//ɨ�����
				set< pair<double,int> >::iterator it=outers.lower_bound(make_pair(y[id],id));
				if (it != outers.end() && inside(id, it->second) ||
					it != outers.begin() && inside(id, (--it)->second)) continue;
				res.push_back(id);
				outers.insert(make_pair(y[id], id));//������ɨ���ߵ������Բ����
			}
			else{//ɨ���Ҷ�
				outers.erase(make_pair(y[id], id));//���뿪ɨ���ߵ������Բ�Ƴ�
			}
		}
		//���
		sort(res.begin(),res.end());
		printf("%d\n",res.size());
		for(int i=0;i<res.size();i++){
			printf("%d%c",res[i]+1,i+1==res.size()?'\n':' ');
		}
	}
	return 0;
}
