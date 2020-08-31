#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <cstdio>
#include <stack>
#include <string.h>
#include <queue>
#include <iomanip>
#include <math.h>
#include <utility>
#include <sstream>
#include <cstdlib>
#include <fstream>
#include <climits>
#include <clocale>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define SQ(a) (a) * (a)
#define INF 1000000000
//compara se numero flutuantes sao iguais if(abs(a-b) < 1e-9)   a e b sao iguais...
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long int ll;

int main(int argc, char const *argv[])
{
	setlocale(LC_ALL, "Portuguese");
	ios::sync_with_stdio(false);
	cin.tie(0);
	int AdjMatrix[200][200], consultas, c1, c2, d, V, E, test_case = 0;

	while(cin >> V >> E >> consultas && (V || E || consultas))
	{
			for (int i = 1; i <= V; i++)
			{
				for (int j = 1; j <= V; j++)
					AdjMatrix[i][j] = INF;
				AdjMatrix[i][i] = 0;
			}
			
			for(int i = 1; i <= E; i++)
			{
				cin >> c1 >> c2 >> d;
				AdjMatrix[c1][c2] = d;
				AdjMatrix[c2][c1] = d;
			}

			for (int k = 1; k <= V; k++) 
				for (int i = 1; i <= V; i++)
					for (int j = 1; j <= V; j++)
						AdjMatrix[i][j] = min(AdjMatrix[i][j], max(AdjMatrix[i][k], AdjMatrix[k][j]));
			
			if(test_case) cout << endl;
			cout << "Case #" << ++test_case << endl; 
			for (int i = 1; i <= consultas; i++)
			{
				cin >> c1 >> c2;
				if(AdjMatrix[c1][c2] != INF) cout << AdjMatrix[c1][c2] << endl;
				else cout << "no path" << endl; 
			}
	}
	return 0;
}
