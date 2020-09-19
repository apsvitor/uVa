#include <bits/stdc++.h>
#define INF 1e8
using namespace std;
typedef pair <int,int> ii;

int main(){
	int L,U,R,t=1;
	scanf("%d %d %d", &L,&U,&R);
	while (L || U || R){
		int buttons[R],dist[10000],aux;
		for (int i=0;i<R;i++)
			scanf("%d", &buttons[i]);
		for (int i=0;i<10000;i++)
			dist[i] = INF;
		queue <int> q;
		q.push(L);
		dist[L] = 0;
		while(!q.empty() && q.front()!=U){
			aux = q.front();
			q.pop();
			for (int i=0;i<R;i++){
				if  (dist[aux]+1<dist[(aux+buttons[i])%10000]){
					dist[(aux+buttons[i])%10000] = dist[aux]+1;
					q.push((aux+buttons[i])%10000);
				}
			}
		}		
		if  (dist[U] == INF)
			printf("Case %d: Permanently Locked\n", t++);
		else
			printf("Case %d: %d\n", t++, dist[U]);
		scanf("%d %d %d", &L,&U,&R);
	}
	//ifstream ler("input.txt");
	//ofstream imp("output.txt");
}

