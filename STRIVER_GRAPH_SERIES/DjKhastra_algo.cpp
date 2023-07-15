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

// in this portion we see the different methods to implement the djkhasta algorithm......

// 1. djkhastra using priority_queue t.c --> O(e*logv), where e is the total edges and v is total vertexs.......
vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    vector<int> dist(V, 1e9);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[S] = 0;
    pq.push({0, S});
    while (!pq.empty())
    {
        int currnode = pq.top().second;
        int currdist = pq.top().first;
        pq.pop();
        for (auto it : adj[currnode])
        {
            int nextnode = it[0], nextdist = it[1];

            if (dist[nextnode] > currdist + nextdist)
            {
                dist[nextnode] = currdist + nextdist;
                pq.push({dist[nextnode], nextnode});
            }
        }
    }
    return dist;
}
/*
2.. djkhastra using set data structure ---->
    we can use set data structure to implement this algorithm because set stored everything in sorted ascending order so the minimum value is always at top of the set also similar to the min heap....

*/

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    vector<int> dist(V, 1e9);
    set<pair<int, int>> st;
    dist[S] = 0;
    st.insert({0, S});
    while (!st.empty())
    {
        auto it = *(st.begin());
        // because in case of sets we have iterators....
        int currnode = it.second, currdist = it.first;

        st.erase(it);
        for (auto it : adj[currnode])
        {
            int nextnode = it[0], nextdist = it[1];
            if (dist[nextnode] > currdist + nextdist)
            {
                // if the distance is not 1e9 it means someone already reached there and now we got a better distance than that value so there is no sence of keeping that into set so we remove that value and put the new one into the set.....
                if (dist[nextnode] != 1e9)
                    st.erase({dist[nextnode], nextnode});

                dist[nextnode] = currdist + nextdist;
                st.insert({dist[nextnode],nextnode});
            }
        }
    }

    return dist;
}

// this kind of removing functionality we not get into the priority_queue so thats why in case of priority_queue the number of iterations is more as compare to set.....