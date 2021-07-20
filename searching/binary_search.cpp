/**
 * @brief Program to implement iterative binary search
 * @author Ajay Biswas
 *
 */
#include <iostream>
#include <vector>

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
 * Searches for an element in a sorted array and returns the index
 * Worst case Time Complexity: O(logn)
 * Best Case Time Complexity: O(1)
 * Worst case Space Complexity: O(1)
 *
 * @param A vector containing sorted elements
 * @param key item to be searched
 * @return Integer denoting index, -1 if not found
 */
int binarySearch(std::vector<int> A, int low, int high, int key)
{
    int mid;
    while (low <= high)
    {
        mid = low + (high - low) / 2; // middle element

        if (A[mid] == key) // key found
        {
            return mid;
        }
        else if (A[mid] < key) // search in right half
        {
            low = mid + 1;
        }
        else if (A[mid] > key) // search in left half
        {
            high = mid - 1;
        }
    }
    return -1; // not found
}

// main function
int main(void)
{
    std::vector<int> A = {16, 26, 34, 56, 98, 101, 341, 487, 1000};
    std::cout << "Array: ";
    printVector(A);
    std::cout << "Key at index " << binarySearch(A, 0, A.size() - 1, 101) << "\n";
}