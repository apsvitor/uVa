#include <bits/stdc++.h>
using namespace std;
int main()
{
	int R,C;
	cin >> R >> C;
	while (R && C)
	{
		int numRowsB;
		int mat[R][C] = {}, dist[R][C] = {};  // cor 0 (unvisited)
		cin >> numRowsB;
		for (int i=0;i<numRowsB;i++)
		{
			int linRow,bombsPerRow;
			cin >> linRow >> bombsPerRow;
			for (int j=0;j<bombsPerRow;j++)
			{
				int bombCol;
				cin >> bombCol;
				mat[linRow][bombCol] = -1; // bomba
			}
		}
		int sourceL,sourceC, destL, destC;
		cin >> sourceL >> sourceC
			>> destL >> destC;
		dist[sourceL][sourceC] = 0;
		//===================================
		queue  <pair <int,int > > q;
		q.push(make_pair(sourceL,sourceC));
		while(!q.empty())
		{
			int Y = q.front().first; 
			int X = q.front().second;
			q.pop();
			mat[Y][X] = 1;
			if  (X+1 <= C-1 && mat[Y][X+1] == 0 && dist[Y][X+1] == 0)	//direita
			{
				dist[Y][X+1] = dist[Y][X] + 1;
				q.push(make_pair(Y,X+1));
			}
			if  (Y+1 <= R-1 && mat[Y+1][X] == 0 && dist[Y+1][X] == 0)	//baixo
			{	
				dist[Y+1][X] = dist[Y][X] + 1;
				q.push(make_pair(Y+1,X));
			}	
			if  (X-1 >= 0 && mat[Y][X-1] == 0 && dist[Y][X-1] == 0)	//esquerda
			{	
				dist[Y][X-1] = dist[Y][X] + 1;
				q.push(make_pair(Y,X-1));
			}
			if  (Y-1 >= 0 && mat[Y-1][X] == 0 && dist[Y-1][X] == 0)	//cima
			{
				dist[Y-1][X] = dist[Y][X] + 1;
				q.push(make_pair(Y-1,X));
			}			
		}
		cout << dist[destL][destC] << endl;
		cin >> R >> C;
	}
}
