#include <bits/stdc++.h>
using namespace std;
char M[100][100];
string mov;
long long int tam = -1, moedas = 0;
void dfs(int Linha, int Coluna, int posL, int posC, char direcao)
{
	tam++;
	if  (tam > mov.length())
		return;
	if  (M[posL][posC] == '*')
	{
		moedas++;
		M[posL][posC] = '1';
	}
	if  (direcao == 'N')
	{
		if  (mov[tam] == 'E')
			dfs(Linha,Coluna,posL,posC,'O');
		else
		{
			if  (mov[tam] == 'D')
				dfs(Linha,Coluna,posL,posC,'L');
			else // garantido que mov[tam] == 'F'
			{
				if  (posL-1 >= 0 && M[posL-1][posC] != '#')
					dfs(Linha,Coluna,posL-1,posC,'N');
				else
					dfs(Linha,Coluna,posL,posC,'N');
			}
		}
	}
	else
	{
		if  (direcao == 'S')
		{
			if  (mov[tam] == 'E')
				dfs(Linha,Coluna,posL,posC,'L');
			else
			{
				if  (mov[tam] == 'D')
					dfs(Linha,Coluna,posL,posC,'O');
				else // garantido que mov[tam] == 'F'
				{
					if  (posL+1 < Linha && M[posL+1][posC] != '#')
						dfs(Linha,Coluna,posL+1,posC,'S');
					else
						dfs(Linha,Coluna,posL,posC,'S');
				}
			}
		}
		else
		{
			if  (direcao == 'O')
			{
				if  (mov[tam] == 'E')
					dfs(Linha,Coluna,posL,posC,'S');
				else
				{
					if  (mov[tam] == 'D')
						dfs(Linha,Coluna,posL,posC,'N');
					else // garantido que mov[tam] == 'F'
					{
						if  (posC-1 >= 0 && M[posL][posC-1] != '#')
							dfs(Linha,Coluna,posL,posC-1,'O');
						else
							dfs(Linha,Coluna,posL,posC,'O');
					}
				}
			}
			else // garantido que a direcao sera Leste
			{
				if  (mov[tam] == 'E')
					dfs(Linha,Coluna,posL,posC,'N');
				else
				{
					if  (mov[tam] == 'D')
						dfs(Linha,Coluna,posL,posC,'S');
					else // garantido que mov[tam] == 'F'
					{
						if  (posC+1 < Coluna && M[posL][posC+1] != '#')
							dfs(Linha,Coluna,posL,posC+1,'L');
						else
							dfs(Linha,Coluna,posL,posC,'L');
					}
				}
			}
		}
	}
	return;
}

int main()
{
	int L, C, S;
	cin >> L >> C >> S;
	while (L && C && S)
	{
		int lin, col;
		char aux;
		moedas = 0;
		tam = -1;
		for (int i=0; i<L; i++)
		{
			for (int j=0;j<C; j++)
			{
				cin >> M[i][j];
				if  (M[i][j]>='L' && M[i][j]<='S')
				{
					lin = i;
					col = j;
					aux = M[i][j];
				}
			}
		}
		cin >> mov;
		dfs(L,C,lin,col,aux);
		cout << moedas << endl;
		cin >> L >> C >> S;
	}
}
