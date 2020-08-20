/*
O número máximo de nós é 26. (De A a Z).
O gráfico sempre será numerado de 0 a 26 0 <= nós <27
Eu brinco com o valor ASCII para obter o valor do nó. ou seja, 'A' - 65 = 0, 'B' - 65 = 1, 'C' - 65 = 2…. e assim por diante.
Imprima uma linha em branco entre os casos. O último caso não precisa da linha em branco.
*/
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
#include <array>
#define MAX 105
using namespace std;

enum { NAO_VISITADO, VISITADO };

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vi dfs_num;
vector<vii> AdjList;

void dfs(int u)
{
    dfs_num[u] = VISITADO;
    for (int i = 0; i < (int)AdjList[u].size(); i++)
    {
        ii v = AdjList[u][i];
        if (dfs_num[v.first] == NAO_VISITADO)
            dfs(v.first);
    }
}

void readGraph()
{
    string edge;
    char node1, node2;

    getline(cin, edge);
    while (getline(cin, edge))
    {
        if (edge.size() == 0)
            break;
        node1 = edge[0] - 65;//A -> Codigo Ascii 65
        node2 = edge[1] - 65;
        AdjList[node1].push_back(ii(node2, 0));//(vizinho, peso)
        AdjList[node2].push_back(ii(node1, 0));
    }
}

int main(int argc, char *argv[])
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int N, numCC, flag = 0;
    string nodes;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> nodes;
        AdjList.assign(nodes[0] - 64, vii()); //Enche de um monte de espaco em branco
        dfs_num.assign(nodes[0] - 64, NAO_VISITADO);
        readGraph();

        numCC = 0;
        for (int j = 0; j < dfs_num.size(); j++)
            if (dfs_num[j] == NAO_VISITADO)
                ++numCC, dfs(j);

        if (flag == 0) flag++;
        else printf("\n");

        cout << numCC << endl;
    }

    return 0;
}
