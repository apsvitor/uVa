#include <bits/stdc++.h>
using namespace std;
int main()
{
	int Tests;
	cin >> Tests;
	while(Tests--)
	{
		vector < pair < string, pair < int, int> > > nomeTamanho; //palavra, posicao,tamanho
		vector <int> adjList[201];
		string aux;
		for (int i=0;aux!="*"; i++)
		{
			cin >> aux;
			nomeTamanho.push_back(make_pair(aux,make_pair(i,aux.length())));
		}
		string linha;
		cin.ignore();
		getline(cin,linha);
		while (linha.size())
		{
			string initialWord, finalWord;
			int cont;
			for (cont=0;linha[cont] != ' ';cont++)
				initialWord+=linha[cont];
			for(cont+=1;cont<linha.length();cont++)
				finalWord+=linha[cont];
			int tam = initialWord.length();
			vector <pair <string, int> > comparisonVet;
			for (unsigned int i=0;i<nomeTamanho.size();i++)
			{
				if  (nomeTamanho[i].second.second == tam) 
					comparisonVet.push_back(make_pair(nomeTamanho[i].first,nomeTamanho[i].second.first));
			}
			int initialPos, finalPos;
			for (unsigned int i=0;i<comparisonVet.size();i++)
			{
				string s1 = comparisonVet[i].first;
				if  (s1 == initialWord)
					initialPos = comparisonVet[i].second;
				if  (s1 == finalWord)
					finalPos = comparisonVet[i].second;
				for (unsigned int j=i+1;j<comparisonVet.size();j++)
				{
					string s2 = comparisonVet[j].first;
					int igual = 0;
					for (unsigned int k=0;k < s1.size();k++)
					{
						if  (s1[k] == s2[k])
							igual++;
					}
					if  (igual == s1.size()-1)
					{
						adjList[comparisonVet[i].second].push_back(comparisonVet[j].second);
						adjList[comparisonVet[j].second].push_back(comparisonVet[i].second);
					}
				}
			}
			int dist[201];
			dist[initialPos] = 0;
			queue <int> q;
			q.push(initialPos);
			bool visitados[201] = {};
			while(!q.empty())
			{
				int a = q.front();
				q.pop();
				visitados[a] = true;
				for (unsigned int i=0;i<adjList[a].size();i++)
				{
					if  (visitados[adjList[a][i]] == false)
					{
						dist[adjList[a][i]] = dist[a] + 1;
						q.push(adjList[a][i]);
						visitados[adjList[a][i]] = true;
					}
				}
			}
			cout << initialWord << ' ' << finalWord << ' ' << dist[finalPos] << endl;
			getline(cin,linha);
		}
		if (Tests!=0)
			cout << "\n";
	}
}
