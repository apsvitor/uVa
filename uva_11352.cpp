#include <bits/stdc++.h>
#define INF 1e8
#define f first
#define s second
using namespace std;
typedef pair <int,int> ii;

int ci[8] = {-2,-2,-1,1,2,2,1,-1}, ri[8] = {-1,-1,0,1,1,1,0,-1},
	cj[8] = {-1,1,2,2,1,-1,-2,-2}, rj[8] = {0,1,1,1,0,-1,-1,-1};
int M,N;
int main(){
	int T;
	ii o,d,u,v;
	bool pode=true;
	//ifstream ler("input.txt");
	//ofstream imp("output.txt");
	scanf("%d", &T);
	while(T--){
		scanf("%d %d",&M,&N);
		char mat[101][101];
		int dist[101][101];
		for (int i=0;i<M;i++){
			for (int j=0;j<N;j++){
				dist[i][j] = INF;
				scanf(" %1c", &mat[i][j]);
				if  (mat[i][j] == 'A')
					o = ii(i,j);
				if  (mat[i][j] == 'B')
					d = ii(i,j);
			}
		}
		queue<ii> q;
		q.push(o);
		dist[o.f][o.s] = 0;
		while(!q.empty()){
			u = q.front(); q.pop();
			for (int i=0;i<8;i++){
				if  (u.f+ri[i]>=0 && u.f+ri[i]<M && u.s+rj[i]>=0 && u.s+rj[i]<N && mat[u.f+ri[i]][u.s+rj[i]] != 'Z')
					v = ii(u.f+ri[i],u.s+rj[i]);
				else
					continue;
				pode = true;
				for (int j=0;j<8 && pode;j++){
					if  (v.f+ci[j] >= 0 && v.f+ci[j] < M && v.s+cj[j] >= 0 && v.s+cj[j] < N && mat[v.f+ci[j]][v.s+cj[j]] =='Z'){
						pode = false;
					}
				}
				if  (mat[v.f][v.s] == 'B')
					pode = true;
				if  (pode && dist[u.f][u.s]+1<dist[v.f][v.s]){
					dist[v.f][v.s] = dist[u.f][u.s] + 1;
					q.push(v);
				}
			}
		}
		if  (dist[d.f][d.s] == INF)
			printf("King Peter, you can't go now!\n");
		else
			printf("Minimal possible length of a trip is %d\n", dist[d.f][d.s]);
	}
}

