#include <bits/stdc++.h>
using namespace std;
typedef pair <int,int> ii;

int mat[25][25];
int pi[8] ={-1,-1,0,1,1,1,0,-1};
int pj[8] ={0,1,1,1,0,-1,-1,-1};
int N,resp;
void dfs(int x, int y){
	if  (mat[x][y] != 1)
		return;
	mat[x][y] = 0;
	for (int i=0;i<8;i++){
		if  (x+pi[i] >=0 && x+pi[i]<N && y+pj[i]>=0 && y+pj[i]< N && mat[x+pi[i]][y+pj[i]] == 1){
			dfs(x+pi[i],y+pj[i]);
		}
	}
}

int main(){
	int t=1;
	//ifstream ler("input.txt");
	//ofstream imp("output.txt");
	while(scanf("%d", &N) != EOF){
		
		resp = 0;
		for (int i=0;i<N;i++){
			for (int j=0;j<N;j++){
				scanf(" %1d", &mat[i][j]);
			}
		}
		for (int i=0;i<N;i++){
			for (int j=0;j<N;j++){
				if  (mat[i][j] == 1){
					dfs(i,j);
					resp++;
				}
			}
		}
		printf("Image number %d contains %d war eagles.\n",t++,resp);
	}
}

