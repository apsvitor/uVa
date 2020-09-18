#include <bits/stdc++.h>
using namespace std;
typedef pair <int,int> ii;

char mat[103][103];
int pi[8] ={-1,-1,0,1,1,1,0,-1};
int pj[8] ={0,1,1,1,0,-1,-1,-1};
int M,N,resp;
void dfs(int x, int y){
	if  (mat[x][y] != '@')
		return;
	mat[x][y] = '*';
	for (int i=0;i<8;i++){
		if  (x+pi[i] >=0 && x+pi[i]<M && y+pj[i]>=0 && y+pj[i]< N && mat[x+pi[i]][y+pj[i]] == '@'){
			dfs(x+pi[i],y+pj[i]);
		}
	}
}

int main(){
	int t=1;
	//ifstream ler("input.txt");
	//ofstream imp("output.txt");
	scanf("%d %d",&M,&N);
	while(M){
		resp = 0;
		for (int i=0;i<M;i++){
			for (int j=0;j<N;j++){
				scanf(" %1c", &mat[i][j]);
			}
		}
		for (int i=0;i<M;i++){
			for (int j=0;j<N;j++){
				if  (mat[i][j] == '@'){
					dfs(i,j);
					resp++;
				}
			}
		}
		printf("%d\n",resp);
		scanf("%d %d",&M,&N);
	}
}

