#include <bits/stdc++.h>
using namespace std;
#define INF 1e7
typedef pair <int,int> ii;
int cor[200];
bool bipart;
vector <int> adjList[200];
void dfs(int posI, int color)
{
	if  (cor[posI] != 0 || bipart == false)
		return;
	cor[posI] = color;
	for (unsigned int i=0;i<adjList[posI].size();i++)
	{
		if  (cor[posI] == cor[adjList[posI][i]])
		{
			bipart = false;
			return;
		}
		if  (cor[adjList[posI][i]] == 0)
		{
			//cor[adjList[posI][i]] = -color;
			dfs(adjList[posI][i], -color);
		}
	}
}
int main()
{
	int Tests;
	cin >> Tests;
	while(Tests--)
	{
		memset(cor,0,sizeof cor);
		int junctions, streets, c = 1;
		cin >> junctions >> streets;
		int j1,j2;
		bipart = true;
		for (int i=0;i<streets;i++)
		{
			cin >> j1 >> j2;
			adjList[j1].push_back(j2);
			adjList[j2].push_back(j1);
		}
		int guards = 0;
		bool visitados[200] = {};
		memset(visitados,false, sizeof visitados);
		for (int i=0;i<junctions;i++)
		{
			if  (cor[i] == 0)
			{
				dfs(i, c);
				int guards1 = 0, guardsMinus1 = 0;
				for (int j=0;j<junctions;j++)
				{
					if  (cor[j] == 1 && visitados[j] == false)
					{
						guards1++;
						visitados[j] = true;
					}
					else
					{	
						if  (cor[j] == -1 && visitados[j] == false)
						{
							guardsMinus1++;
							visitados[j] = true;
						}
					}
				}
				if  (guards1 == 0)
					guards+= guardsMinus1;
				else
					if  (guardsMinus1==0)
						guards+= guards1;
					else
						if  (guards1 <= guardsMinus1)
							guards+= guards1;
						else
							guards+= guardsMinus1;
			}
		}
		for (int i =0;i<junctions;i++)
			adjList[i].clear();
		if  (bipart == false)
			cout << -1 << endl;
		else
			cout << guards << endl;
	}
}
