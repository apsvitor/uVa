#include <bits/stdc++.h>
using namespace std;
typedef pair <int,int> ii;
bool visit[10000];
vector <int> adj[10000];
int resp;
void dfs(int pos){
	if  (visit[pos])
		return;
	visit[pos] = true;
	resp++;
	for (int i=0;i<adj[pos].size(); i++){
		if  (!visit[adj[pos][i]]){
			dfs(adj[pos][i]);
		}
	}
}

int main(){
	int t,n,m,l;
	//ifstream ler("input.txt");
	//ofstream imp("output.txt");
	scanf("%d", &t);
	while(t--){
		scanf("%d %d %d", &n,&m,&l);
		memset(visit,false,sizeof visit);
		int q[l], u,v;
		resp = 0;
		for (int i=0;i<m;i++){
			scanf("%d %d", &u,&v);
			adj[u-1].push_back(v-1);
		}
		for (int i=0;i<l;i++)
			scanf("%d", &q[i]);
		for (int i=0;i<l;i++){
			if  (!visit[q[i]-1]){
				dfs(q[i]-1);
			}
		}
		for (int i=0;i<n;i++){
			adj[i].clear();
		}
		printf("%d\n", resp);
	}
}

