#include <bits/stdc++.h>
using namespace std;
int main()
{
	int E;
	cin >> E;
	vector <int> adj[E];
	for (int i=0;i<E;i++)
	{
		int numFriends, friendOf;
		cin >> numFriends;
		for (int j=0;j<numFriends;j++)
		{
			cin >> friendOf;
			adj[i].push_back(friendOf);
		}
	}
	int Tests;
	cin >> Tests;
	while(Tests--)
	{
		int sourceOfNews, boomDay, boomSize = 0, dia = 1, pessoasDia = 0;
		bool visitados[E] = {};
		cin >> sourceOfNews;
		queue <int> q;
		pair <int,int> dist[E] = {};
		dist[sourceOfNews] = make_pair(1, sourceOfNews);
		q.push(sourceOfNews);
		while(!q.empty())
		{
			int aux = q.front();
			int pessoas = 0;
			q.pop();
			visitados[aux] = true;
			for (unsigned int i = 0; i < adj[aux].size(); i++)
			{
				if  (visitados[adj[aux][i]] == false)
				{
					visitados[adj[aux][i]] = true;
					q.push(adj[aux][i]);
					dist[adj[aux][i]].first = dist[aux].first + 1;
					dist[adj[aux][i]].second = adj[aux][i];
					pessoas++;
				}
			}
				if  (dia == dist[aux].first)
					pessoasDia+=pessoas;
				else
				{
					pessoasDia = pessoas;
					dia = dist[aux].first;
				}
				if  (pessoasDia > boomSize)
				{
					boomSize = pessoasDia;
					boomDay = dia;
				}
		}
		if  (adj[sourceOfNews].size() == 0)
			cout << 0 << endl;
		else
			cout << boomSize << ' ' << boomDay << endl;
	}
}
