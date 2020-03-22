#include <bits/stdc++.h>
using namespace std;
#define INF 1e7
typedef pair <int,int> ii;
int main()
{
	int N;
	cin >> N;
	for(int casos = 1; casos<=N; casos++)
	{
		
		int servers,cables,sender,receiver;
		cin >> servers >> cables >> sender >> receiver;
		vector <ii> adjList[50000];
		int s,r,w;
		for (int i=0; i<cables; i++)
		{
			cin >> s >> r >> w;
			adjList[s].push_back(ii(w,r));
			adjList[r].push_back(ii(w,s));
		}
		vector <int> dist(servers,INF);
		dist[sender] = 0;
		priority_queue < ii, vector<ii>, greater<ii> > pq; // distancia, vertice.
		pq.push(ii(0,sender));
		while(!pq.empty())
		{
			int auxD = pq.top().first;
			int auxV = pq.top().second;
			pq.pop();
			if  (auxD > dist[auxV])
				continue;
			for (unsigned int i = 0; i<adjList[auxV].size(); i++)
			{
				int d = adjList[auxV][i].first;
				int v = adjList[auxV][i].second;
				if  (dist[auxV] + d < dist[v])
				{
					dist[v] = dist[auxV] + d;
					pq.push(ii(dist[v], v));
				}
			}
		}
		cout << "Case #" << casos << ": ";
		if  (dist[receiver] != INF)
			cout << dist[receiver] << endl;
		else
			cout << "unreachable" << endl;
	}
}
