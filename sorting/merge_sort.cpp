/**
 * @brief Program to implement Out-of-place Merge Sort
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
 * Out-of-place merge function implementation
 *
 * @param A vector containing unsorted elements
 * @param low First position of sub-array
 * @param mid Middle position of sub-array
 * @param high Last position of sub-array
 * @return void
 */
void merge(std::vector<int> &A, int low, int mid, int high)
{
    int i = low;     // first element's index of sub-array 1
    int j = mid;     // last element's index of sub-array 1
    int x = mid + 1; // first element's index of sub-array 2
    int y = high;    // last element's index of sub-array 2

    std::vector<int> tA(high - low + 1); // extra space for both sub arrays
    int count = 0;

    while (i <= j && x <= y) // take smaller element of two sub arrays one-by-one
    {
        if (A[i] > A[x])
        {
            tA[count] = A[x];
            x++;
        }
        else
        {
            tA[count] = A[i];
            i++;
        }
        count++;
    }

    while (count < high - low + 1) // fill remaining elements
    {
        if (i > j) // if sub-array 1 has been inserted
        {
            tA[count] = A[x];
            x++;
        }
        else // if sub-array 2 has been inserted
        {
            tA[count] = A[i];
            i++;
        }
        count++;
    }

    for (int i = 0; i < count; i++) // copy into the original array
    {
        A[low + i] = tA[i];
    }

    //std::cout<<"Merged: ";          // comment this
    //printVector(A);                 // comment this
}

/**
 * Sorts a vector of elements in ascending order using Merge Sort.
 * Worst case Time Complexity: O(nlogn)
 * Best case, Average case Time Complexity: O(nlogn)
 * Worst case Space Complexity: O(n)
 * Type: Out-of-place
 *
 * @param A vector containing unsorted elements
 * @param low First position of sub-array
 * @param high Last position of sub-array
 * @return void
 */
void mergeSort(std::vector<int> &A, int low, int high)
{
    if (low >= high)
        return; // Returns recursivly

    int mid = low + (high - low) / 2; // divide from half

    // Divide and Conquer: O(n/2) at each step
    mergeSort(A, low, mid);
    mergeSort(A, mid + 1, high);
    merge(A, low, mid, high);
}

// main function
int main(void)
{
    std::vector<int> A = {7, 8, 4, 1, 9, 12, -1, 0};
    std::cout << "Original: ";
    printVector(A);
    mergeSort(A, 0, A.size() - 1);
    printVector(A);
}