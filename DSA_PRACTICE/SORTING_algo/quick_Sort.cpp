#include <iostream>
using namespace std;

int partition(int arr[], int s, int e)
{

   int pivot = arr[s];

   int cnt = 0;
   for (int i = s + 1; i <= e; i++)
   {
      if (arr[i] <= pivot)
      {
         cnt++;
      }
   }

   // place pivot at right position
   int pivotIndex = s + cnt;
   swap(arr[pivotIndex], arr[s]);

   // left and right wala part smbhal lete h
   int i = s, j = e;

   while (i < pivotIndex && j > pivotIndex)
   {

      while (arr[i] <= pivot)
      {
         i++;
      }

      while (arr[j] > pivot)
      {
         j--;
      }

      if (i < pivotIndex && j > pivotIndex)
      {
         swap(arr[i++], arr[j--]);
      }
   }

   return pivotIndex;
}

void quickSort(int arr[], int s, int e)
{

   // base case
   if (s >= e)
      return;

   // partitioon karenfe
   int p = partition(arr, s, e);

   // left part sort karo
   quickSort(arr, s, p - 1);

   // right wala part sort karo
   quickSort(arr, p + 1, e);
}

int main()
{

   int arr[10] = {2, 4, 1, 6, 9, 9, 9, 9, 9, 9};
   int n = 10;

   quickSort(arr, 0, n - 1);

   for (int i = 0; i < n; i++)
   {
      cout << arr[i] << " ";
   }
   cout << endl;

   return 0;
}

int partition(int A[], int low, int high)
{
   int pivot = A[low];
   int i = low + 1;
   int j = high;
   int temp;

   do
   {
      while (A[i] <= pivot)
      {
         i++;
      }

      while (A[j] > pivot)
      {
         j--;
      }

      if (i < j)
      {
         temp = A[i];
         A[i] = A[j];
         A[j] = temp;
      }
   } while (i < j);

   // Swap A[low] and A[j]
   temp = A[low];
   A[low] = A[j];
   A[j] = temp;
   return j;
}

void quickSort(int A[], int low, int high)
{
   int partitionIndex; // Index of pivot after partition

   if (low < high)
   {
      partitionIndex = partition(A, low, high);
      quickSort(A, low, partitionIndex - 1);  // sort left subarray
      quickSort(A, partitionIndex + 1, high); // sort right subarray
   }
}
