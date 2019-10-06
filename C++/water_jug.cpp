#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;


void waterJug(int x,int y,int z,int t){
		queue<pair<int,int> >q;
		q.push(make_pair(0,0));
		bool flag = false;
		map<pair<int,int>,pair<int,int> >m;
		m[make_pair(0,0)] = make_pair(-1,-1);
		pair<int,int> fa;
		int count = 1;
		while(q.size() > 0){
			int siz = q.size();
			for(int i=0;i<siz;i++){
				pair<int,int> p = q.front();
				q.pop();

				if(p.first == z || p.second == z){
					cout<<t<<"\n";
					fa = p;
					flag = true;
					break;
				}

				if(m.find(pair<int,int>(x,p.second)) == m.end()){
					m[pair<int,int>(x,p.second)] = make_pair(p.first,p.second);
					q.push(make_pair(x,p.second));
				}
				
				if(m.find(pair<int,int>(p.first,y)) == m.end()){
					m[pair<int,int>(p.first,y)] = make_pair(p.first,p.second);
					q.push(make_pair(p.first,y));
				}
				
				if(m.find(pair<int,int>(p.first,0)) == m.end()){
					m[pair<int,int>(p.first,0)] = make_pair(p.first,p.second);
					q.push(make_pair(p.first,0));
				}

				if(m.find(pair<int,int>(0,p.second)) == m.end()){
					m[pair<int,int>(0,p.second)] = make_pair(p.first,p.second);
					q.push(make_pair(0,p.second));
				}

				if(p.second+p.first >= x && m.find(pair<int,int>(x,p.second-(x-p.first))) == m.end()){		
					m[pair<int,int>(x,p.second-(x-p.first))] = make_pair(p.first,p.second);
					q.push(make_pair(x,p.second-(x-p.first)));
				}
				else if(p.second+p.first < x && m.find(pair<int,int>(p.first+p.second,0)) == m.end()){	
					m[pair<int,int>(p.first+p.second,0)] = make_pair(p.first,p.second);
					q.push(make_pair(p.first+p.second,0));
				}
				
				if(p.second+p.first >= y && m.find(pair<int,int>(p.first-(y-p.second),y)) == m.end()){
					m[pair<int,int>(p.first-(y-p.second),y)] = make_pair(p.first,p.second);
					q.push(make_pair(p.first-(y-p.second),y));
				}
				else if(p.second+p.first < y && m.find(pair<int,int>(0,p.first+p.second)) == m.end()){	
					m[pair<int,int>(0,p.first+p.second)] = make_pair(p.first,p.second);
					q.push(make_pair(0,p.first+p.second));
				}
			}
			if(flag){
				break;
			}
			count++;
		}

		if(!flag){
			cout<<"NO"<<"\n";
			return;
		}

		pair<int,int>p = fa;
		vector<pair<int,int> >ans;
		while(p != pair<int,int>(-1,-1)){
			ans.push_back(p);
			p = m[p];
		}

		for(int i=ans.size()-1;i>=0;i--){
			cout<<"("<<ans[i].first<<","<<ans[i].second<<")"<<"\n";
		}
}


int main(){
	int t;
	cin>>t;
	int index = 0;
	while(index < t){
		int x,y,z;
		cin>>x>>y>>z;
		waterJug(x,y,z,index);
		index++;
	}
	return 0;
}