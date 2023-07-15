#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define rep(i, a, b) for (int i = a; i < b; i++)
#define vi vector<int>
#define vvi vector<vector<int>>
#define pi pair<int, int>
#define vpi vector<pair<int, int>>
#define mii map<int, int>
#define pb push_back
#define __mayuk                       \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);
int32_t main()
{
	__mayuk;
	int t;
	cin >> t;
	while (t--)
	{
	}
	return 0;
}

// Union Find Algorithm Almost O(1) for reasonable size N. O(log*N) to be precise
struct UnionFind
{
	int n;
	vector<int> rank;
	vector<int> parent;
	// store other info as required
	UnionFind(int n)
	{
		rank.resize(n);
		fill(rank.begin(), rank.end(), 0);
		parent.resize(n);
		for (int i = 0; i < n; i++)
		{
			parent[i] = i;
		}
	}
	int get(int a)
	{
		return parent[a] = (parent[a] == a ? a : get(parent[a]));
	}
	void merge(int a, int b)
	{
		a = get(a);
		b = get(b);
		if (a == b)
		{
			return;
		}
		if (rank[a] == rank[b])
		{
			rank[a]++;
		}
		if (rank[a] > rank[b])
		{
			parent[b] = a;
		}
		else
		{
			parent[a] = b;
		}
	}
};