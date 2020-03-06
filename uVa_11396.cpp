#include <bits/stdc++.h>
using namespace std;
vector <int> adj[301];
int cor[301];
bool visit[301];
bool dfs(int pos, int color, bool r) // posicao inicial, cor, resposta
{
	if  (visit[pos] == true || r == false)
		return r;
	visit[pos] = true;
	for (unsigned int i=0; i<adj[pos].size();i++)
	{
		if  (visit[adj[pos][i]] == false)
		{
			cor[adj[pos][i]] = -color;
			r=dfs(adj[pos][i],-color,r);
			
			if(!r) 
				return r;
		}
		if  (cor[pos] == cor[adj[pos][i]])
		{
			r = false;
			return r;
		}
	}
	return r;	
}
int main()
{
	int V;
	cin >> V; // vertices
	while (V)
	{
		int pi,pf, aux = 1;
		bool resp = true;
		cin >> pi >> pf;
		while (pi || pf)
		{
			adj[pi-1].push_back(pf-1);
			adj[pf-1].push_back(pi-1);
			cin >> pi >> pf;
		}
		for (int i=0;i<V;i++)
		{
			visit[i] = false;
			cor[i] = 0;
		}
		cor[0] = aux;
		resp = dfs(0,aux,resp);
		if  (resp == true)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		for (int i=0;i<V;i++)
			adj[i].clear();
		cin >> V;
	}
}
