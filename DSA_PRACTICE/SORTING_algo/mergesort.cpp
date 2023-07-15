#include <iostream>
using namespace std;

// method 1 here we use two new array for storing the data  and also here we dont pass the mid in merge code..

// void merge(int *arr, int s, int e)
// {

//    int mid = (s + e) / 2;

//    int len1 = mid - s + 1;
//    int len2 = e - mid;

//    int *first = new int[len1];
//    int *second = new int[len2];

//    // copy values
//    int mainArrayIndex = s;
//    for (int i = 0; i < len1; i++)
//    {
//       first[i] = arr[mainArrayIndex++];
//    }

//    mainArrayIndex = mid + 1;
//    for (int i = 0; i < len2; i++)
//    {
//       second[i] = arr[mainArrayIndex++];
//    }

//    // merge 2 sorted arrays
//    int index1 = 0;
//    int index2 = 0;
//    mainArrayIndex = s;

//    while (index1 < len1 && index2 < len2)
//    {
//       if (first[index1] < second[index2])
//       {
//          arr[mainArrayIndex++] = first[index1++];
//       }
//       else
//       {
//          arr[mainArrayIndex++] = second[index2++];
//       }
//    }

//    while (index1 < len1)
//    {
//       arr[mainArrayIndex++] = first[index1++];
//    }

//    while (index2 < len2)
//    {
//       arr[mainArrayIndex++] = second[index2++];
//    }

//    delete[] first;
//    delete[] second;
// }

// void mergeSort(int *arr, int s, int e)
// {

//    // base case
//    if (s >= e)
//    {
//       return;
//    }

//    int mid = (s + e) / 2;

//    // left part sort karna h
//    mergeSort(arr, s, mid);

//    // right part sort karna h
//    mergeSort(arr, mid + 1, e);

//    // merge
//    merge(arr, s, e);
// }

// 2.. this is second method here we use to send the mid value in merge function...

void printArray(int *A, int n)
{
   for (int i = 0; i < n; i++)
   {
      printf("%d ", A[i]);
   }
   printf("\n");
}

void merge(int A[], int mid, int low, int high)
{
   int i, j, k, B[100];
   i = low;
   j = mid + 1;
   k = low;

   while (i <= mid && j <= high)
   {
      if (A[i] < A[j])
      {
         B[k] = A[i];
         i++;
         k++;
      }
      else
      {
         B[k] = A[j];
         j++;
         k++;
      }
   }
   while (i <= mid)
   {
      B[k] = A[i];
      k++;
      i++;
   }
   while (j <= high)
   {
      B[k] = A[j];
      k++;
      j++;
   }
   for (int i = low; i <= high; i++)
   {
      A[i] = B[i];
   }
}

void mergeSort(int A[], int low, int high)
{
   int mid;
   if (low < high)
   {
      mid = (low + high) / 2;
      mergeSort(A, low, mid);
      mergeSort(A, mid + 1, high);
      merge(A, mid, low, high);
   }
}

int main()
{

   int n;
   cin >> n;
   int arr[n];
   for (int i = 0; i < n; i++)
   {
      cin >> arr[i];
   }

   mergeSort(arr, 0, n - 1);

   for (int i = 0; i < n; i++)
   {
      cout << arr[i] << " ";
   }
   cout << endl;

   return 0;
}