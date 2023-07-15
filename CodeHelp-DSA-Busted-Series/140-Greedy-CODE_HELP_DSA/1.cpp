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

// N meetings in one room...........
// we have start and end time of n meetings at one time only 1 meething happen in the room , find total no of meeting that can happens.....

/*
ALGO -->
sort the ending time.
when we have to solve this in gfg then we have to use static before the cmp function..

O(n lon n)..
*/

bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    return a.second < b.second;
}

int maxMeetings(int start[], int end[], int n)
{
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back({start[i], end[i]});
    }
    sort(v.begin(), v.end(), cmp);
    int cnt = 1;
    int endans = v[0].second;
    for (int i = 1; i < n; i++)
    {
        if (v[i].first > endans)
        {
            cnt++;
            endans = v[i].second;
        }
    }
    return cnt;
}

// without using cusstom comparitor.....
int maxMeetings(int start[], int end[], int n)
{
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back({end[i], start[i]});
    }

    sort(v.begin(), v.end());
    int cnt = 1;
    int endans = v[0].first;
    for (int i = 1; i < n; i++)
    {
        if (v[i].second > endans)
        {
            cnt++;
            endans = v[i].first;
        }
    }
    return cnt;
}

// maximum meetings in one room....
bool cmp1(pair<int, pair<int, int>> &a, pair<int, pair<int, int>> &b)
{
    return a.second.first < b.second.first;
}

vector<int> maxMeetings(int N, vector<int> &S, vector<int> &F)
{
    vector<pair<int, pair<int, int>>> v;
    for (int i = 0; i < N; i++)
        v.push_back({S[i], {F[i], i + 1}});
    sort(v.begin(), v.end(), cmp1);
    int cnt = 1;
    vector<int> ans;
    int endans = v[0].second.first;
    for (int i = 1; i < N; i++)
    {
        if (v[i].first > endans)
        {
            cnt++;
            endans = v[i].second.first;
            ans.push_back(v[i].second.second);
        }
    }
    return ans;
}


