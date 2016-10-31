/*
Author : lifecodemohit
*/

#ifdef __APPLE__

    #include <cassert>
    #include <iostream>
    #include <iomanip>
    #include <ctime>
    #include <cstdio>
    #include <vector>
    #include <algorithm>
    #include <utility>
    #include <queue>
    #include <stack>
    #include <string>
    #include <cstring>
    #include <sstream>
    #include <map>
    #include <set>
    #include <unordered_map>
    #include <unordered_set>

#else

    #include <bits/stdc++.h>

#endif  

using namespace std;

long long power_mod(int x, int e, int mod) {
	if (e == 0)	return 1;
	if (e == 1)	return x;
	long long ans = power_mod(x, e/2, mod);
	ans = (ans * ans) % mod;
	if (e%2)
		ans = (ans * x) % mod;
	return ans;
}

int main()
{
	cout << power_mod(2, 10, 100000);
	return 0;
}