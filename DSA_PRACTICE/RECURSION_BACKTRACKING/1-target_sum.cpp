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

void solve(int idx, vi &arr, vi &ds, int target, vvi &ans)
{
    if (idx == arr.size())
    {
        if (target == 0)
        {
            ans.push_back(ds);
        }
        return;
    }

    if (arr[idx] <= target)
    {
        ds.push_back(arr[idx]);
        solve(idx, arr, ds, target - arr[idx], ans);
        ds.pop_back();
    }

    solve(idx + 1, arr, ds, target, ans);
}

vvi targetsum(vi &arr, int target)
{
    vi ds;
    vvi ans;
    solve(0, arr, ds, target, ans);
    return ans;
}

// now if the input array contains duplicate but in output we have to give only the unique elements..
void solve(int idx, vi &arr, vi &ds, int target, set<vector<int>> &ans)
{
    if (idx == arr.size())
    {
        if (target == 0)
        {
            sort(ds.begin(), ds.end());
            ans.insert(ds);
        }
        return;
    }
    if (arr[idx] <= target)
    {
        ds.push_back(arr[idx]);
        solve(idx + 1, arr, ds, target - arr[idx], ans);
        ds.pop_back();
    }
    solve(idx + 1, arr, ds, target, ans);
}

/*
for this input --> arr-> 2 5 2 1 2 and target -> 5
expected output --> [[1 2 2 ] [5]]
recived --> [[2 1 2][2 2 1][5]]
*/

/*
to modify this what we can do is we have to sort the main array before sending it to the solve function and after doint this if we want we can remove the sort condtion in the solve function before insert the ds into set because we have already sort this and this will work perfectly ...


but this solution gives tle on leetcode for that we have to go with the forloop based solutions...
*/
vvi targetsum2(vi &arr, int target)
{
    vvi ans;
    vi ds;
    set<vector<int>> tempans;
    sort(arr.begin(), arr.end());
    solve(0, arr, ds, target, tempans);
    for (auto it : tempans)
    {
        ans.push_back(it);
    }

    // for returning the answer in sorted order...
    sort(ans.begin(), ans.end());
    return ans;
}

// another method of doing the same thing......
// this is the most optimize solution...

void helper(int idx, vi &arr, int target, vi &ds, vvi &ans)
{
    if (target == 0)
    {
        ans.push_back(ds);
        return;
    }
    for (int i = idx; i < arr.size(); i++)
    {
        if (i > idx and arr[i] == arr[i - 1])
            continue;
        if (arr[i] > target)
            break;
        ds.push_back(arr[i]);
        helper(i + 1, arr, target - arr[i], ds, ans);
        ds.pop_back();
    }
}

vvi targetsum2(vi &arr, int target)
{
    vi ds;
    vvi ans;
    sort(arr.begin(), arr.end());
    helper(0, arr, target, ds, ans);
    return ans;
}

int32_t main()
{
    __mayuk;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vi a;
        rep(i, 0, n)
        {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int target;
        cin >> target;

        // for unique elements .....
        // vvi result = targetsum(a, target);

        // for duplicate elements....
        vvi result = targetsum2(a, target);

        for (auto it : result)
        {
            for (auto id : it)
            {
                cout << id << " ";
            }
            cout << endl;
        }
    }
    return 0;
}

// combination sum 3.....
void helper(int idx, int k, int n, int currsum, vi &ds, vvi &ans)
{
    if (ds.size() == k)
    {
        if (currsum == n)
        {
            ans.push_back(ds);
        }
        return;
    }
    for (int i = idx; i <= 9; i++)
    {
        // if we dont add this condition still the code works properly but by adding this we reduce the no of steps so that if any point of time our currentsum is greater than the n then we instantly break if we dont do this here then also when the base case arise at that time if currsum!=n then also it get eliminated but for that we have to continue with this waste value so to reduce the no of steps we add this condition...
        if (currsum>n)
            break;

        ds.push_back(i);
        currsum =currsum+ i;
        helper(i + 1, k, n, currsum, ds, ans);
        ds.pop_back();
        currsum =currsum- i;
    }
}

vector<vector<int>> combinationSum3(int k, int n)
{
    vi ds;
    vvi ans;
    int currsum = 0;
    helper(1, k, n, currsum, ds, ans);
    return ans;
}