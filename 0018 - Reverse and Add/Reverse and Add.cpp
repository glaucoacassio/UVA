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

typedef unsigned long long int datatype;

datatype reverse(datatype n)
{	
	datatype s = 0;
	while (n)
	{
		s = s * 10 + n % 10;
		n /= 10;  
	}
	return s;
}

int	main(int argc, char **argv)
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif
	int tc, count_num;
	datatype n;

	cin >> tc;
	for (int i=0; i<tc; i++)
	{
		cin >> n;
		count_num = 0;
		datatype m = reverse(n);
		while (n != m)
		{
			count_num++;
			n += m;
			m = reverse(n);
		}
		cout << count_num << " " << n << endl;
	}
	return 0;
}
