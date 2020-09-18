#include <bits/stdc++.h>
using namespace std;
typedef pair <int,int> ii;

char mat[27][27];
int pi[8] ={-1,-1,0,1,1,1,0,-1};
int pj[8] ={0,1,1,1,0,-1,-1,-1};
int M,N,resp;
void dfs(int x, int y){
	if  (mat[x][y] != '1')
		return;
	resp++;
	mat[x][y] = '0';
	for (int i=0;i<8;i++){
		if  (x+pi[i] >=0 && x+pi[i]<M && y+pj[i]>=0 && y+pj[i]< N && mat[x+pi[i]][y+pj[i]] == '1'){
			dfs(x+pi[i],y+pj[i]);
		}
	}
}

int main(){
	int t;
	string s;
	//ifstream ler("input.txt");
	//ofstream imp("output.txt");
	scanf("%d",&t);
	getline(cin,s);
	cin.ignore();
	while(t--){
		resp = 0;
		M=0;
		int maior = 0;
		while(getline(cin,s) && s.size()){
			for (int j=0;j<s.size();j++){
				mat[M][j] = s[j];
			}
			M++;
			N = s.size();
		}
		for (int i=0;i<M;i++){
			for (int j=0;j<N;j++){
				if  (mat[i][j] == '1'){
					resp = 0;
					dfs(i,j);
					if  (resp > maior)
						maior = resp;
				}
			}
		}
		printf("%d\n",maior);
		if  (t)
			printf("\n");
	}
}

