/**
 * @brief Program to implement recursive binary search
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
 * Worst case Space Complexity: O(n)
 *
 * @param A vector containing sorted elements
 * @param key item to be searched
 * @return Integer denoting index, -1 if not found
 */
int binarySearchRecursive(std::vector<int> A, int low, int high, int key)
{
    if (low > high) // not found
    {
        return -1;
    }

    int mid = low + (high - low) / 2; // middle element

    if (A[mid] == key) // key found
    {
        return mid;
    }
    else if (A[mid] < key) // search in right half
    {
        return binarySearchRecursive(A, mid + 1, high, key);
    }
    else if (A[mid] > key) // search in left half
    {
        return binarySearchRecursive(A, low, mid - 1, key);
    }
}

// main function
int main(void)
{
    std::vector<int> A = {16, 26, 34, 56, 98, 101, 341, 487, 1000};
    std::cout << "Array: ";
    printVector(A);
    std::cout << "Key at index " << binarySearchRecursive(A, 0, A.size() - 1, 34) << "\n";
}