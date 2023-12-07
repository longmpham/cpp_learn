#include <iostream>

// declare functions
void swap(int& a, int& b);
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);

int main()
{
  int myArray [] = {8,7,5,7,3,6,8,5,3,1,7,10};
  int arraySize = std::size(myArray);

  quickSorter(myArray, 0, arraySize - 1);
  for (int i = 0; i < arraySize; i++)
  {
    std::cout << myArray[i] << " ";
  }

  return 0;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Choose the last element as the pivot
    int i = low - 1;        // Index of the smaller element

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSorter(int arr[], int low, int high) {
  // IIRC this uses 3 buckets, lower, same, greater and uses a seed value.
  // to make this "easy" we'll use the first number as the seed
  // using the seed, if seed + 1 (and so on) is less than seed, put in lowerBucket
  // if seed + 1 (and so on) is the same, put in sameBucket
  // if seed + 1 (and so on) is the greater, put in greaterBucket
  // In each bucket, call the quick sorter again. The goal is to have each value in a "bucket"
  // to finally put together.
  if (low < high) {
      int pivotIndex = partition(arr, low, high);

      // Recursively sort elements before and after the pivot
      quickSort(arr, low, pivotIndex - 1);
      quickSort(arr, pivotIndex + 1, high);
  }
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}