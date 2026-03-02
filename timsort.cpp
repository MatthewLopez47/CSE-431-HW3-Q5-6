#include <vector>
#include <random>
#include <string>
#include <ctime>
#include <iostream>

using namespace std;

const int k = 30;

// https://www.geeksforgeeks.org/dsa/merge-sort/
// merge sort implementation and insertion sort

/* Function to sort array using insertion sort */
void insertionSort(vector <int>& arr, const int left, const int right)
{
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;

        /* Move elements of arr[0..i-1], that are
           greater than key, to one position ahead
           of their current position */
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Merges two subarrays of arr[].
// First subarray is arr[left..mid]
// Second subarray is arr[mid+1..right]
void merge(vector<int>& arr, int left, int mid, int right){

    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temp vectors
    vector<int> L(n1), R(n2);

    // Copy data to temp vectors L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    // Merge the temp vectors back
    // into arr[left..right]
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[],
    // if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[],
    // if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// begin is for left index and end is right index
// of the sub-array of arr to be sorted
void timSort(vector<int>& arr, int left, int right){
    int size = right - left + 1;

    if (size <= k)
    {
        insertionSort(arr, left, right);
        return;
    }
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    timSort(arr, left, mid);
    timSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main(int argc, char const *argv[])
{
    // file name, N, seed
    vector<int> arr(stoi(argv[1]));
    srand(stoi(argv[2]));
    //k = stoi(argv[3]);

    for (int i = 0; i < arr.size(); i++)
        arr[i] = rand();

    std::clock_t start_time = std::clock();
    for (int i = 0; i < 1000; i++)
    {
        vector<int> copy = arr;
        timSort(copy, 0, copy.size() - 1);
    }
    std::clock_t tot_time = std::clock() - start_time;
    std::cout << "Time: "
              << ((double) tot_time) / (double) CLOCKS_PER_SEC
              << " seconds" << std::endl;

    return 0;
}