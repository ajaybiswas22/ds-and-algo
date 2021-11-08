/**
 * @brief Program to implement 3-Way Quick Sort
 * @author Ajay Biswas
 *
 */

#include <iostream>
#include <vector>

/**
 * Swaps two values a and b
 *
 * @tparam a,b data to be swapped
 * @return void
 */
template <class T>
void swap(T *a, T *b)
{
    auto temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * Prints elements of a vector
 *
 * @tparam A Vector containing some elements
 * @return void
 */
template <class T>
void printVector(std::vector<T> A)
{
    for (auto i : A)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

/**
 * Dutch National Flag Problem.
 * Used in sorting 012.
 * Places smaller element at left of pivot, bigger at
 * right, and middle element may be repeated.
 *
 * @param A vector containing unsorted elements
 * @param low First position of sub-array
 * @param high Last position of sub-array
 * @return Integer denoting the position of partition 
 */
void partition_3_way(std::vector<int> &a, int low, int high, int &i, int &j)
{
    // To handle 2 elements
    if (high - low <= 1) {
        if (a[high] < a[low])
            swap(&a[high], &a[low]);
        i = low;
        j = high;
        return;
    }
 
    int mid = low;
    int pivot = a[high];
    while (mid <= high) {
        if (a[mid] < pivot)
            swap(&a[low++], &a[mid++]);
        else if (a[mid] == pivot)
            mid++;
        else if (a[mid] > pivot)
            swap(&a[mid], &a[high--]);
    }
 
    // update i and j
    i = low - 1;
    j = mid; // or high+1
}

/**
 * Sorts a vector of elements in ascending order using Quick Sort.
 * Worst case Time Complexity: O(n^2)
 * Best case Time Complexity: O(n)
 * Good Case (Majority Element present in each subarray): O(nloglogn)
 * Average Case Time Complexity: O(nlogn) 
 * Worst case Space Complexity: O(1)
 * Type: In-place, Not Stable
 *
 * @param A vector containing unsorted elements
 * @param low First position of sub-array
 * @param high Last position of sub-array
 * @return void
 */
void quickSort(std::vector<int> &A, int low, int high)
{
    if (low >= high) // 1 or 0 elements
        return;
 
    int i, j;
 
    // Note that i and j are passed as reference
    partition_3_way(A, low, high, i, j);
 
    // Recur two halves
    quickSort(A, low, i);
    quickSort(A, j, high);
}

// main function
int main(void)
{
    std::vector<int> A = {2, 4, 1, 10, 19, 6, 3, -1, 4};
    std::cout << "Original: ";
    printVector(A);
    quickSort(A, 0, A.size() - 1);
    printVector(A);
}