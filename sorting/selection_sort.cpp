/**
 * @brief Program to implement Selection Sort.
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
 * Sorts a vector of elements in ascending order using Selection Sort.
 * Worst case Time Complexity: O(n^2)
 * Best case Time Complexity: O(n^2)
 * Worst case Space Complexity: O(n)
 * Type: In-place, Not Stable
 *
 * @param A vector containing unsorted elements
 * @return void
 */
void selectionSort(std::vector<int> &A)
{
    int n = A.size();

    for(int i=0;i<n-1;i++)    // elements before i are sorted
    {
        int min_pos = i;     // index of smallest element

        for(int j=i+1;j<n;j++)
        {
            if(A[j] < A[min_pos])  // find the smallest element among rest
            {
                min_pos = j;
            }
        }
        swap(A[i], A[min_pos]);    // place the element at desired position

        std::cout << "Pass " << i << ": ";     // comment this part
        printVector(A);                        // comment this part
    }
}

// main function
int main(void)
{
    std::vector<int> A = {2, 4, 1, 10, 19, 6, 3, -1, 4};
    std::cout << "Original: ";
    printVector(A);
    selectionSort(A);
    printVector(A);
}