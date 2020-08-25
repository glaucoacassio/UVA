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
#define INF 1000000000
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vector<vii> AdjList;

int main(int argc, char **argv)
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif
	int V, E, a, b;

	while (cin >> V && V)
	{
		AdjList.assign(V, vii());

		cin >> E;
		for (int i = 0; i < E; i++)
		{
			cin >> a >> b;
			AdjList[a].push_back(ii(b, 0));
			AdjList[b].push_back(ii(a, 0));
		}

		vi color(V, INF);
		color[0] = 0;
		bool isBipartido = true;
		queue<int> q;
		q.push(0);
		while (!q.empty() && isBipartido)
		{
			int u = q.front();  q.pop();
			for (int i = 0; i <(int)AdjList[u].size(); i++)
			{
				ii v = AdjList[u][i];
				if (color[v.first] == INF)
				{
					color[v.first] = 1 - color[u];
					q.push(v.first);
				}
				else if (color[v.first] == color[u])
				{
					isBipartido = false; 
					break;
				}
			}
		}
		if (isBipartido)
			cout << "BICOLORABLE." << endl;
		else
			cout << "NOT BICOLORABLE." << endl;
	}
	return 0;
}
