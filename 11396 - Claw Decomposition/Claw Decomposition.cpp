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
	int V, a, b;

	while(scanf("%d", &V), V)
	{
		AdjList.assign(V, vii());
		
		while(scanf("%d %d", &a , &b) && (a || b))
		{
			AdjList[a - 1].push_back(ii(b - 1, 0));
			AdjList[b - 1].push_back(ii(a - 1, 0));
		}
		
		queue<int> q;
		q.push(0);
		vi color(V, INF);
		color[0] = 0;
		bool isBipartido = true;
		while (!q.empty() && isBipartido)
		{
			int u = q.front(); 
			q.pop();
			for (int j = 0; j < (int)AdjList[u].size(); j++)
			{
				ii v = AdjList[u][j];
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

		if(isBipartido)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
