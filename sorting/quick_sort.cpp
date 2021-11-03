/**
 * @brief Program to implement Quick Sort with first element as the pivot.
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
void swap(T &a, T &b)
{
    auto temp = a;
    a = b;
    b = temp;
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
 * This function takes first element as pivot and
 * Correctly positions pivot in sorted array such that
 * elements before < pivot < elements after
 *
 * @param A vector containing unsorted elements
 * @param low First position of sub-array
 * @param high Last position of sub-array
 * @return Integer denoting the position of partition 
 */
int partition(std::vector<int> &A, int low, int high)
{
    int i = low, j = high;
    int pivot = A[low];

    while (true)
    {
        while (A[i] <= pivot) // increment i until you find A[i] > pivot
        {
            i++;
        }
        while (A[j] > pivot) // decrement j until you find A[j] <= pivot
        {
            j--;
        }

        if (i < j)
        {
            /* place smaller elements at left of pivot
               and larger elements at left of pivot.
               NOTE: Pivot is not placed yet. 
             */
            swap(A[i], A[j]);
        }
        else
        {
            swap(A[low], A[j]); // place the pivot
            break;
        }
    }

    return j; // return pivot position
}

/**
 * Sorts a vector of elements in ascending order using Quick Sort.
 * Worst case Time Complexity: O(n^2)
 * Best case, Average case Time Complexity: O(nlogn)
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
    int k; // position for partition

    if (low < high)
    {
        k = partition(A, low, high); // A[k] is at right position

        // Divide and Conquer: O(k) + O(n-k)
        quickSort(A, low, k - 1);  // apply quicksort on 1st half
        quickSort(A, k + 1, high); // apply quicksort on 2nd halt
    }
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