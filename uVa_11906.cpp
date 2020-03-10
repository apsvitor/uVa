#include <bits/stdc++.h>
using namespace std;
int mat[100][100];
bool visitados[100][100];
void dfs(int posx, int posy, int M, int N, int R, int C)
{
	if  (visitados[posx][posy] == true || mat[posx][posy] == 'W')
		return;
	visitados[posx][posy] = true;
	if  (M==0)
	{
		if  (posx+M < R && posy+N < C && mat[posx+M][posy+N] != 'W') // 1
		{
			mat[posx][posy]++;
			dfs(posx+M,posy+N, M, N, R, C);
		}
		if  (posx+M < R && posy-N >= 0 && mat[posx+M][posy-N] != 'W') // 2
		{
			mat[posx][posy]++;
			dfs(posx+M,posy-N, M, N, R, C);
		}
		if  (posx+N < R && posy+M < C && mat[posx+N][posy+M] != 'W') // 5
		{
			mat[posx][posy]++;
			dfs(posx+N,posy+M, M, N, R, C);
		}
		if  (posx-N >= 0 && posy+M < C && mat[posx-N][posy+M] != 'W') // 7
		{
			mat[posx][posy]++;
			dfs(posx-N,posy+M, M, N, R, C);
		}
	}
	else
	{
		if  (N==0)
		{
			if  (posx+M < R && posy+N < C && mat[posx+M][posy+N] != 'W') // 1
			{
				mat[posx][posy]++;
				dfs(posx+M,posy+N, M, N, R, C);
			}
			if  (posx-M >= 0 && posy+N < C && mat[posx-M][posy+N] != 'W') // 3
			{
				mat[posx][posy]++;
				dfs(posx-M,posy+N, M, N, R, C);
			}
			if  (posx+N < R && posy+M < C && mat[posx+N][posy+M] != 'W') // 5
			{
				mat[posx][posy]++;
				dfs(posx+N,posy+M, M, N, R, C);
			}
			if  (posx+N < R && posy-M >= 0 && mat[posx+N][posy-M] != 'W') // 6
			{
				mat[posx][posy]++;
				dfs(posx+N,posy-M, M, N, R, C);
			}
		}
		else
		{
			if  (M==N)
			{
				if  (posx+M < R && posy+N < C && mat[posx+M][posy+N] != 'W') // 1
				{
					mat[posx][posy]++;
					dfs(posx+M,posy+N, M, N, R, C);
				}
				if  (posx+M < R && posy-N >= 0 && mat[posx+M][posy-N] != 'W') // 2
				{
					mat[posx][posy]++;
					dfs(posx+M,posy-N, M, N, R, C);
				}
				if  (posx-M >= 0 && posy+N < C && mat[posx-M][posy+N] != 'W') // 3
				{
					mat[posx][posy]++;
					dfs(posx-M,posy+N, M, N, R, C);
				}
				if  (posx-M >= 0 && posy-N >= 0 && mat[posx-M][posy-N] != 'W') // 4
				{
					mat[posx][posy]++;
					dfs(posx-M,posy-N, M, N, R, C);
				}
			}
			else
			{
				if  (posx+M < R && posy+N < C && mat[posx+M][posy+N] != 'W') // 1
				{
					mat[posx][posy]++;
					dfs(posx+M,posy+N, M, N, R, C);
				}
				if  (posx+M < R && posy-N >= 0 && mat[posx+M][posy-N] != 'W') // 2
				{
					mat[posx][posy]++;
					dfs(posx+M,posy-N, M, N, R, C);
				}
				if  (posx-M >= 0 && posy+N < C && mat[posx-M][posy+N] != 'W') // 3
				{
					mat[posx][posy]++;
					dfs(posx-M,posy+N, M, N, R, C);
				}
				if  (posx-M >= 0 && posy-N >= 0 && mat[posx-M][posy-N] != 'W') // 4
				{
					mat[posx][posy]++;
					dfs(posx-M,posy-N, M, N, R, C);
				}
				if  (posx+N < R && posy+M < C && mat[posx+N][posy+M] != 'W') // 5
				{
					mat[posx][posy]++;
					dfs(posx+N,posy+M, M, N, R, C);
				}
				if  (posx+N < R && posy-M >= 0 && mat[posx+N][posy-M] != 'W') // 6
				{
					mat[posx][posy]++;
					dfs(posx+N,posy-M, M, N, R, C);
				}
				if  (posx-N >= 0 && posy+M < C && mat[posx-N][posy+M] != 'W') // 7
				{
					mat[posx][posy]++;
					dfs(posx-N,posy+M, M, N, R, C);
				}
				if  (posx-N >= 0 && posy-M >= 0 && mat[posx-N][posy-M] != 'W') // 8
				{
					mat[posx][posy]++;
					dfs(posx-N,posy-M, M, N, R, C);
				}
			}
		}
	}
}
int main()
{
	int T, casos=0;
	cin >> T;
	while (T--)
	{
		casos++;
		int ni = 0, np = 0;
		memset(mat,0,sizeof mat);
		memset(visitados,false,sizeof visitados);
		int R, C, M, N, W;
		cin >> R >> C >> M >> N >> W;
		int wx,wy;
		for (int i=0; i<W; i++)
		{
			cin >> wx >> wy;
			mat[wx][wy] = 'W';
		}
		dfs (0,0,M,N,R,C);
		if  (mat[0][0] == 0)
			mat[0][0] = 2;
		for (int i=0;i<R;i++)
		{
			for (int j=0;j<C;j++)
			{
				//cout << mat[i][j] << ' ';
				if  (mat[i][j]%2 == 0 && mat[i][j] != 0)
					np++;
				else
					if  (mat[i][j] != 0 && mat[i][j] != 87)
						ni++;
			}
			//cout << endl;
		}	
		cout << "Case " << casos << ": " << np << ' ' << ni << endl;
	}
}
