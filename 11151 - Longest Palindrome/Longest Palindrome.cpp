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
using namespace std;

string s;
int tc, len, dp[1005][1005];

int longestPalin(int l, int r)
{
	if (l == r)
		return 1;
	if (l + 1 == r)
	{
		if (s[l] == s[r])
			return 2;
		else
			return 1;
	}
	if (dp[l][r] != -1)
		return dp[l][r];

	if (s[l] == s[r])
		return dp[l][r] = 2 + longestPalin(l + 1, r - 1);
	else
		return dp[l][r] = max(longestPalin(l, r - 1), longestPalin(l + 1, r));
}

int main()
{
	cin >> tc;
	cin.ignore();
	while (tc--)
	{
		getline(cin, s);
		len = s.length();
		memset(dp, -1, sizeof(dp));
		cout << longestPalin(0, len - 1) << endl;
	}
	return 0;
}
