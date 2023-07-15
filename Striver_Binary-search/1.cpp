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

int binarysearch(vector<int> &arr, int target)
{
    int s = 0;
    int e = arr.size() - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] > target)
        {
            e = mid - 1;
        }
        else if (arr[mid] < target)
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return -1;
}

// recursive code....

int bsrecursive(vector<int> &arr, int target, int low, int high)
{
    if (low > high)
        return -1;
    int mid = low + (high - low) / 2;
    if (arr[mid] == target)
    {
        return mid;
    }
    else if (arr[mid] > target)
    {
        return bsrecursive(arr, target, low, mid - 1);
    }
    else if (arr[mid] < target)
    {
        return bsrecursive(arr, target, mid + 1, high);
    }
    return -1;
}

int binarysearch(vector<int> &arr, int target)
{
    int n = arr.size();
    return bsrecursive(arr, target, 0, n - 1);
}

/*
lower bounds of elements in array ---->
smallest indexes (i) such that arr[i] > =x  then i is the lower bound of element (x)....

array must be sorted to find lower bound..
*/

// naive approach ...
int lowerBound(vector<int> arr, int n, int x)
{
    int s = 0;
    int e = n - 1;
    int ans = n;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] == x)
        {
            return mid;
        }
        else if (arr[mid] > x)
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

// optimize approach...
int lowerBound(vector<int> arr, int n, int x)
{
    int s = 0;
    int e = n - 1;
    int ans = n;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] >= x)
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

/*
upper bounds of elements in array ---->
smallest indexes (i) such that arr[i] > x  then i is the upper bound of element (x)....

array must be sorted to find upper bound..
*/

// naive approach...
int upperBound(vector<int> &arr, int x, int n)
{
    int s = 0;
    int e = n - 1;
    int ans = n;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] == x)
        {
            s = mid + 1;
        }
        else if (arr[mid] > x)
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return ans;
}

// optimize approach...
int upperBound(vector<int> &arr, int x, int n)
{
    int s = 0;
    int e = n - 1;
    int ans = n;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] > x)
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

// search insert position.....

// this is similar to find the lower bound index...

int searchInsert(vector<int> &nums, int target)
{
    int s = 0;
    int end = nums.size() - 1;
    int ans = nums.size();

    while (s <= end)
    {
        int mid = s + (end - s) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] > target)
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {

            s = mid + 1;
        }

        mid = s + (end - s) / 2;
    }
    return ans;
}

int searchInsert(vector<int> &nums, int target)
{
    // this function returns the iterator...
    auto idx = lower_bound(nums.begin(), nums.end(), target);
    int ans = idx - nums.begin();
    return ans;
}

// floor and ceil in the sorted array.....
/*
floor of x --> largest no in the array <= x
ceil of x -->  smallest no in the array >= x

input arr -> [ 10, 20 , 30 ,40 , 50]  x=25
output --> floor =20 ceil =30

input arr -> [ 10, 20 , 25 ,35 , 50]  x=25
output --> floor =25 ceil =20




*/