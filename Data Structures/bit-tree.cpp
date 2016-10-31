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

long long tree[200010];
int MAXVAL;

void update(int idx, long long val) {
	while (idx <= MAXVAL) {
		tree[idx] += val;
		idx += (idx & -idx);
	}
}

long long query(int idx) {
	long long res = 0;
	while (idx > 0) {
		res += tree[idx];
		idx -= (idx & -idx);
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	memset(tree, 0, sizeof(tree));
	int n;
	cin >> n;
	long long a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int q;
	cin >> q;
	MAXVAL = q + n;
	for (int i = q+1; i <= q+n; i++) {
		update(i, a[i-1-q]);
	}
	int ctr = q;
	while (q--) {
		int type;
		cin >> type;
		if (type == 1) {
			int x, y;
			cin >> x >> y ;
			cout << query(y+ctr) - query(x+ctr-1) << endl;
		}
		else {
			long long x;
			cin >> x;
			update(ctr, x);
			ctr--;
		}
	}
	return 0;
}