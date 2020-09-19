#include <bits/stdc++.h>
#define INF 1e8
#define ft first
#define sd second
using namespace std;
typedef pair <int,int> ii;

int pi[8]={-2,-2,-1,1,2,2,1,-1}, pj[8]={-1,1,2,2,1,-1,-2,-2};
int dist[8][8];

int main(){
	string s1,s2;
	while(cin >> s1 >> s2){
		for (int i=0;i<8;i++)
			for (int j=0;j<8;j++)
				dist[i][j] = INF;
		ii s=ii(s1[0]-'a',s1[1]-'1'), d=ii(s2[0]-'a',s2[1]-'1'), v;
		queue <ii> q;
		q.push(s);
		dist[s.ft][s.sd] = 0;
		while(!q.empty()){
			ii aux = q.front();
			q.pop();
			for (int i=0;i<8;i++){
				v = ii(aux.ft+pi[i], aux.sd+pj[i]);
				if  (aux.ft+pi[i]>=0 && aux.ft+pi[i]<8 &&
					 aux.sd+pj[i]>=0 && aux.sd+pj[i]<8 &&
					 dist[aux.ft][aux.sd]+1<dist[v.ft][v.sd]){
					dist[v.ft][v.sd] = dist[aux.ft][aux.sd]+1;
					q.push(v);
				}
			}
		}
		printf("To get from %s to %s takes %d knight moves.\n",s1.c_str(),s2.c_str(),dist[d.ft][d.sd]);
	}
	//ifstream ler("input.txt");
	//ofstream imp("output.txt");
}

