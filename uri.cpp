#include <bits/stdc++.h>
#define INF 1e8
using namespace std;
typedef pair <int,int> ii;
typedef pair <int,ii> iii;
int main(){
	int N,M,u,v,inst=0,T,D;
	scanf("%d%d", &N, &M);
	while(N && M){
		vector <iii> adj[N+1];
		ii dist[N+1];
		for (int i=0;i<N+1;i++)
			dist[i] = ii(INF,INF);
		for (int i=0;i<M;i++){
			scanf("%d %d %d %d", &u,&v,&T,&D);
			adj[u].push_back(iii(v,ii(T,D)));
		}
		scanf("%d", &D);
		printf("Instancia %d\n",++inst);
		for (int i=0;i<D;i++){
			scanf("%d %d %d",&u,&v,&T); // Origem, Destino, Tempo Maximo
			queue<int> q;
			q.push(u);
			dist[u] = ii(0,0);
			while(!q.empty()){
				int aux = q.front();
				q.pop();
				for (unsigned int i=0;i<adj[aux].size();i++){
					int x = adj[aux][i].first;			//vertice
					int y = adj[aux][i].second.first;	//tempo
					int z = adj[aux][i].second.second;	//distancia
					if  (dist[x])
					
				}
			}
		}
	}
		scanf("%d%d", &N, &M);
}
