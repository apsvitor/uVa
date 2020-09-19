#include <bits/stdc++.h>
#define INF 1e8
using namespace std;
typedef pair <int,int> ii;

int main(){
	int NC,u,v,t=1,resp;
	scanf("%d", &NC);
	//ifstream ler("input.txt");
	//ofstream imp("output.txt");
	while(NC){
		int TTL,cont = 0,s;
		map <int,int> m;
		vector<int> adj[31];
		for (int i=0;i<NC;i++){
			scanf("%d %d", &u, &v);
			if  (m.insert(ii(u,cont)).second)
				cont++;
			if  (m.insert(ii(v,cont)).second)
				cont++;
			adj[m.find(u)->second].push_back(m.find(v)->second);
			adj[m.find(v)->second].push_back(m.find(u)->second);
		}
		
		scanf("%d %d",&s,&TTL);
		while(s || TTL){
			resp = 0;
			queue<int> q;
			int dist[31], aux;
			for (int i=0;i<cont;i++){
				dist[i] = -10;
			}
			u = m.find(s)->second;
			q.push(u);
			dist[u] = TTL;
			while(!q.empty()){
				aux = q.front();
				q.pop();
				for (int i=0;i<adj[aux].size();i++){
					v=adj[aux][i];
					if  (dist[aux]-1 > dist[v] && dist[aux]-1>=0){
						dist[v] = dist[aux]-1;
						q.push(v);
					}
				}
			}
			for (int i=0;i<cont;i++){
				if  (dist[i]>=0)
					resp++;
			}
			printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",t++,cont-resp,s,TTL);
			scanf("%d %d",&s,&TTL);
		}
		scanf("%d", &NC);
	}
}

