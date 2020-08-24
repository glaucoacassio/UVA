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
using namespace std;

int main(int argc, char **argv)
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif
	int n;
	long double a, b;

	cin >> n;
	for (int i=1; i<=n; i++)
	{
		cin >> a >> b;
		if (a > b) cout << ">" << endl;
		else if (a < b) cout << "<" << endl;
		else cout << "=" << endl;
	}

	return 0;
}
