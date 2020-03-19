#include <bits/stdc++.h>
using namespace std;
int main()
{
	int N, casos=0;
	while (cin >> N)
	{
		casos++;
		string vertices[101], aux;
		map <string,int> lista;
		vector <int> adj[101];
		int inDegree[101] = {};
		for (int i=0;i<N;i++)
		{
			cin >> vertices[i];
			lista[vertices[i]] = i;
		}
		int M,a,b;
		cin >> M;
		for (int i=0;i<M;i++)
		{
			cin >> aux;
			a = lista[aux];
			cin >> aux;
			b = lista[aux];
			adj[a].push_back(b);
			inDegree[b]++;
		}
		priority_queue <int, vector<int> , greater<int> > q;
		for (int i=0;i<N;i++)
		{
			if  (inDegree[i] == 0)
				q.push(i);
		}
		cout << "Case #" << casos << ": Dilbert should drink beverages in this order:";
		while(!q.empty())
		{
			a = q.top();
			q.pop();
			for (vector <int>::iterator it=adj[a].begin();it!=adj[a].end();it++)
			{
				inDegree[*it]--;
				if  (inDegree[*it] == 0)
					q.push(*it);
			}
			cout << ' ' << vertices[a];
		}
		cout << ".\n\n";
	}
}
