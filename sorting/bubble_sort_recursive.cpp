/**
 * @brief Program to implement Recursive Bubble Sort.
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
 * Sorts a vector of elements in ascending order using Bubble Sort.
 * Worst case Time Complexity: O(n^2)
 * Best Case Time Complexity: O(n^2)
 * Worst case Space Complexity: O(n)
 * Type: In-place, Stable
 *
 * @param A vector containing unsorted elements
 * @return void
 */
void bubbleSortRecursive(std::vector<int> &A, int n)
{
    if (n == 1) // base case
        return;

    for (int j = 0; j < n - 1; j++)
    {
        if (A[j] > A[j + 1])
        {
            swap(A[j], A[j + 1]);
        }
    }
    bubbleSortRecursive(A, n - 1); // Recur for remaining
}

// main function
int main(void)
{
    std::vector<int> A = {2, 4, 1, 10, 19, 6, 3, -1, 4};
    std::cout << "Original: ";
    printVector(A);
    bubbleSortRecursive(A, A.size());
    printVector(A);
}