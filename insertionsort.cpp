#include <iostream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;

// https://www.geeksforgeeks.org/dsa/insertion-sort-algorithm/
// insertion sort implementaiton, changed to take vector instead of array

/* Function to sort array using insertion sort */
void insertionSort(vector <int>& arr, int n)
{
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        /* Move elements of arr[0..i-1], that are
           greater than key, to one position ahead
           of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main(int argc, char const *argv[])
{
    // file name, N, seed
    vector<int> arr(stoi(argv[1]));
    srand(stoi(argv[2]));

    for (int i = 0; i < arr.size(); i++)
        arr[i] = rand();

    std::clock_t start_time = std::clock();
    for (int i = 0; i < 1000; i++)
    {
        vector<int> copy = arr;
        insertionSort(copy, copy.size());
    }
    std::clock_t tot_time = std::clock() - start_time;
    std::cout << "Time: "
              << ((double) tot_time) / (double) CLOCKS_PER_SEC
              << " seconds" << std::endl;
    return 0;
}