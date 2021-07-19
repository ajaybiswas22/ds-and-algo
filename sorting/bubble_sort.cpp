/**
 * @brief Program to implement Bubble Sort.
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
void bubbleSort(std::vector<int> &A)
{
    int n = A.size();

    for (int i = 0; i < n - 1; i++) // bubble sort requires n-1 passes at worst
    {
        for (int j = 0; j < n - i - 1; j++) // largest element gets placed after each pass
        {
            if (A[j] > A[j + 1]) // compares two adjacent elements
            {
                swap(A[j], A[j + 1]);
            }
        }
        std::cout << "Pass " << i + 1 << ": "; // comment this part
        printVector(A);                        // comment this part
    }
}

// main function
int main(void)
{
    std::vector<int> A = {2, 4, 1, 10, 19, 6, 3, -1, 4};
    std::cout << "Original: ";
    printVector(A);
    bubbleSort(A);
    printVector(A);
}