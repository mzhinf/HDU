/*
	pair
	pair��һ��ģ�����ͣ����а�����������ֵ���������ݵ����Ϳ��Բ�ͬ��
	pair<A, B> a;
	1.����pair�࣬������ֻ������Ԫ�أ��ֱ���Ϊfirst��second��
	���ֱ��ʹ����ͨ�ĵ���������ɷ������Ա
	2.����ʹ��make_pair���Ѵ��ڵ��������ݹ���һ���µ�pair����
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
		//����
		for(int i=0;i<n;i++){
			scanf("%lf%lf%lf%lf",&y[i][0],&x[i][0],&y[i][1],&x[i][1]);
		}

		//����ؼ���
		vector< pair<double,int> > events;
		for(int i=0;i<n;i++){
			events.push_back(make_pair(x[i][0],i));
			events.push_back(make_pair(x[i][1],i+n));
		}
		sort(events.begin(),events.end());

		//ƽ��ɨ��
		double S=0;
		for(int i=0;i<events.size();i++){
			int id=events[i].second%n;
			if(!sy.empty()){
                //���⴦��ɨ���߳��� ɨ���߿��ܳ����п�
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
			if(events[i].second<n){//ɨ�����(�ײ�)
				sy.insert(make_pair(y[id][0], id));
				sy.insert(make_pair(y[id][1], id+n));
			}
			else{//ɨ���Ҷ�(����)
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
