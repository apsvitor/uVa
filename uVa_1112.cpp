#include <bits/stdc++.h>
using namespace std;
#define INF 1e7
typedef pair <int,int> ii;
typedef pair <int,ii> iii;
int main()
{
	int casos;
	cin >> casos;
	while(casos--)
	{
		int N, exits, timeLimit, M;
		cin >> N >> exits >> timeLimit >> M;
		vector <ii> adjList[101]; // dist, vertice
		int auxSource, auxDest, W;
		for (int i=0;i<M;i++)
		{
			cin >> auxSource >> auxDest >> W;
			adjList[auxDest-1].push_back(ii(W,auxSource-1));
		}
		int dist[101];
		for (int i=0;i<N;i++)
			dist[i] = INF;
		dist[exits-1] = 0;
		priority_queue <ii, vector <ii>, greater <ii> > pq; //dist, vertice
		
		pq.push(ii(dist[exits-1], exits-1));
		while(!pq.empty())
		{
			int d = pq.top().first;
			int v = pq.top().second;
			pq.pop();
			if  (d > dist[v])
			{
				//cout << "skip em " << v+1 << "  "  << dist[v] << endl;
				continue;
			}
			for (unsigned int i=0;i<adjList[v].size();i++)
			{
				ii x = adjList[v][i]; //dist,vertice
				if  (dist[v] + x.first < dist[x.second])
				{
					dist[x.second] = dist[v] + x.first;
					pq.push(ii(dist[x.second], x.second));
				}
			}
		}
		int ratos = 0;
		for (int i=0;i<N;i++)
		{
			if  (dist[i] - timeLimit <= 0)
				ratos++;
		}
		cout << ratos << endl;
		if  (casos != 0)
			cout << endl;
	}
}
