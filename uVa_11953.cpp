#include <bits/stdc++.h>
using namespace std;
char mat[100][100];
int ships, N, nav = 0;
int VL[4] = {0,1,0,-1}, VC[4] = {1,0,-1,0};
bool visitados [100][100];
void dfs(int L, int C)
{
	if  (visitados[L][C] == true || mat[L][C] == '.')
		return;
	visitados[L][C] = true;
	for (int i=0;i<4;i++)
	{
		if  ((L+VL[i] >= 0 && L+VL[i] < N) && (C+VC[i] >= 0 && C+VC[i] < N)
			 && visitados[L+VL[i]][C+VC[i]] == false)
		{
			if  (mat[L+VL[i]][C+VC[i]] == 'x')
				nav++;
			dfs(L+VL[i],C+VC[i]);
		}
	}
}
int main()
{
	int T,casos = 0;
	cin >> T;
	while (T--)
	{
		casos++;
		cin >> N;
		ships = 0;
		for (int i=0;i<N;i++)
		{
			for (int j=0;j<N;j++)
			{
				visitados[i][j] = false;
				cin >> mat[i][j];
			}
		}
		for (int i=0;i<N;i++)
		{
			for (int j=0;j<N;j++)
			{
				nav = 0;
				if  (visitados[i][j] == false && mat[i][j] != '.')
					{
						if  (mat[i][j] == 'x')
							nav++;
						dfs(i,j);
					}
				if  (nav > 0)
					ships++;
			}
		}
		cout << "Case " << casos << ": " << ships << endl;	
	}
}
