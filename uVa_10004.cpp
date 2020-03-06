#include <bits/stdc++.h>
using namespace std;
vector <int> adj[200];
int cor[200];
bool visit[200];
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
	int N;
	cin >> N; // vertices
	while (N)
	{
		int E, pi,pf, aux = 1; // arestas
		cin >> E;
		bool resp = true;
		for (int i=0;i<E;i++)
		{
			cin >> pi >> pf;
			adj[pi].push_back(pf);
			adj[pf].push_back(pi);
		}
		for (int i=0;i<N;i++)
		{
			visit[i] = false;
			cor[i] = 0;
		}
		cor[0] = aux;
		resp = dfs(0,aux,resp);
		if  (resp == true)
			cout << "BICOLORABLE." << endl;
		else
			cout << "NOT BICOLORABLE." << endl;
		for (int i=0;i<N;i++)
			adj[i].clear();
		cin >> N;
	}
}
