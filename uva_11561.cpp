#include <bits/stdc++.h>
using namespace std;
typedef pair <int,int> ii;

char mat[51][51];
int pi[4] ={-1,0,1,0};
int pj[4] ={0,1,0,-1};
int resp;
void dfs(int x, int y){
	if  (mat[x][y] == '#')
		return;
	mat[x][y] = '#';
	for (int i=0;i<4;i++){
		if  (mat[x+pi[i]][y+pj[i]] == 'T')
			return;
	}
	for (int i=0;i<4;i++){
		if  (mat[x+pi[i]][y+pj[i]] == 'G')
				resp++;
		dfs(x+pi[i],y+pj[i]);
	}
}

int main(){
	int W,H,px,py;
	//ifstream ler("input.txt");
	//ofstream imp("output.txt");
	while(scanf("%d %d", &W, &H) != EOF){
		for (int i=0;i<H;i++){
			for (int j=0;j<W;j++){
				cin >> mat[i][j];
				if  (mat[i][j] == 'P'){
					px=i; py=j;
				}
			}
		}
		resp=0;
		dfs(px,py);
		printf("%d\n",resp);
	}
}

