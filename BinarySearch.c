#include <stdio.h>

int binarySearch(int arr[], int left, int right, int x) {
   while (left <= right) {
      int mid = left + (right - left) / 2;
      if (arr[mid] == x) {
         return mid;
      }
      if (arr[mid] < x) {
         left = mid + 1;
      }
      else {
         right = mid - 1;
      }
   }
   return -1;
}
//Best case: O(1) , Worst case: O(log n)
//Space Complexity:O(1)
int main() {
   int arr[] = {1, 3, 4, 7, 9, 11};
   int n = sizeof(arr) / sizeof(arr[0]);
   int x = 7;
   int result = binarySearch(arr, 0, n - 1, x);
   if (result == -1) {
      printf("Element not found.\n");
   }
   else {
      printf("Element found at index %d.\n", result);
   }
   return 0;
}

