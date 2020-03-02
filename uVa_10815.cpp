#include <bits/stdc++.h>
using namespace std;

int main()
{
	string texto;
	set <string> S;
	set <string> ::iterator it;
	while (cin >> texto)
	{
		string aux;
		for (int i=0;i<texto.length();i++)
		{
			if  (texto[i] >= 'A' && texto[i] <= 'Z')
				texto[i] = texto[i] + 32;
			if  (texto[i] < 'a' || texto[i] > 'z')
			{
				S.insert(aux);
				aux = "";
			}
			if  (texto[i] >='a' && texto[i] <= 'z')
				aux = aux + texto[i];
		}
		S.insert(aux);
	}
	for (it = S.begin(); it != S.end(); it++)
	{
		if  (it == S.begin())
			cout << *it;
		else
			cout << *it << endl;
	}
}
