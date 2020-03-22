#include <bits/stdc++.h>
using namespace std;
#define INF 1e7
typedef pair <int,int> ii;
typedef pair <int,ii> iii;
int main()
{
	int tests;
	cin >> tests;
	while(tests--)
	{
		//source = 0,0		destination = n-1,m-1
		int N,M;
		cin >> N >> M;
		int adjMatrix[N][M];
		int dist[N][M];
		for (int i=0;i<N;i++)
		{	for(int j=0;j<M;j++)
			{
				cin >> adjMatrix[i][j];
				dist[i][j] = INF;
			}
		}
		dist[0][0] = adjMatrix[0][0];
		priority_queue < iii, vector <iii>, greater<iii> > pq; // dist, lin, col
		pq.push(iii(dist[0][0],ii(0,0)));
		while(!pq.empty())
		{
			iii aux = pq.top();
			pq.pop();
			int D = aux.first;
			int Lin = aux.second.first;
			int Col = aux.second.second;
			if  (D > dist[Lin][Col])
				continue;
			if  (Col+1<M && D + adjMatrix[Lin][Col+1] < dist[Lin][Col+1])		//direita
			{
				dist[Lin][Col+1] = D + adjMatrix[Lin][Col+1];
				pq.push(iii(dist[Lin][Col+1], ii(Lin,Col+1)));
			}
			if  (Lin+1<N && D + adjMatrix[Lin+1][Col] < dist[Lin+1][Col]) 		//baixo
			{
				dist[Lin+1][Col] = D + adjMatrix[Lin+1][Col];
				pq.push(iii(dist[Lin+1][Col],ii(Lin+1,Col)));
			}
			if  (Col-1>=0 && D + adjMatrix[Lin][Col-1] < dist[Lin][Col-1])		//esquerda
			{
				dist[Lin][Col-1] = D + adjMatrix[Lin][Col-1];
				pq.push(iii(dist[Lin][Col-1],ii(Lin,Col-1)));
			}
			if  (Lin-1>=0 && D + adjMatrix[Lin-1][Col] < dist[Lin-1][Col])		//cima
			{
				dist[Lin-1][Col] = D + adjMatrix[Lin-1][Col];
				pq.push(iii(dist[Lin-1][Col],ii(Lin-1,Col)));
			}
		}
		cout << dist[N-1][M-1] << endl;
	}
}
