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

/*
1. initialized temporary array
2. declare starting index of left half of arr
3. declare starting index of right half of arr
4. storing elements in the temporary array in a sorted manner
5. if elements on the left half are still left then copy them into temp array
6. if elements on the right half are still left then copy them into temp array
7. transfering all elements from temporary arr to main arr

NOTE --->
 here in temp we have to subtract the value of low because the in main array value of low can be anything it is not always starting from 0 according to different recursive calls but in the temporary array all the elements starting from 0 so we need to subtract the value of low from temp array before copying it to main array....

*/

void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    // left is the starting pointer of left array and right is the startin pointer of right array.......
    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    // for a single call we have to copy the content of temp array into the fixed range [low, high] ......
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

void mergeSort(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return;

    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);

    merge(arr, low, mid, high);
}

// we can write the mergesort function by another way by just changing the base case......

// the recursive calls is execute only upto low < high once low >= high automatically function return........
void mergeSort2(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}

int32_t main()
{
    __mayuk;
    int t;
    cin >> t;
    while (t--)
    {
        vector<int> arr = {9, 4, 7, 6, 3, 1, 5};
        int n = 7;

        cout << "Before Sorting Array: " << endl;
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;

        // both the functions working same....
        mergeSort(arr, 0, n - 1);
        mergeSort2(arr, 0, n - 1);

        cout << "After Sorting Array: " << endl;
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

// quick sort ............

// if we start the value of i from low+1 then in many cases it will give wrong answer so for that it is better to start it with low.....

int partition(int arr[], int low, int high)
{
    int i = low, j = high, pivot = arr[low];
    while (i < j)
    {
        while (arr[i] <= pivot and i <= high - 1)
        {
            i++;
        }

        while (arr[j] > pivot and j >= low + 1)
        {
            j--;
        }

        if (i < j)
            swap(arr[i], arr[j]);
    }

    swap(pivot, arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int partionidx = partition(arr, low, high);
        quickSort(arr, low, partionidx - 1);
        quickSort(arr, partionidx + 1, high);
    }
}

// similar to mergeSort we can also write the quickSort in another method by changing the way of writing the base case.......

void quickSort2(int arr[], int low, int high)
{
    if (low >= high)
        return;

    int partionidx = partition(arr, low, high);
    quickSort(arr, low, partionidx - 1);
    quickSort(arr, partionidx + 1, high);
}
