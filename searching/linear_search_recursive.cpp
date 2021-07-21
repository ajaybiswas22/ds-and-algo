/**
 * @brief Program to implement Recursive linear search
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
 * Searches for an element in an unsorted array and returns the index
 * Worst case Time Complexity: O(n)
 * Best Case Time Complexity: O(n)
 * Worst case Space Complexity: O(n)
 *
 * @param A vector containing unsorted elements
 * @param low start index of sub-array
 * @param high end index of sub-array
 * @param key item to be searched
 * @return Integer denoting index, -1 if not found
 */
int linearSearch(std::vector<int> A, int low, int high, int key)
{
    if(A[low] == key)           // key found
        return low;

    if(low>high)                // key not found (search pointer exceeded)
        return -1;

    return linearSearch(A,low+1,high,key);
}

// main function
int main(void)
{
    std::vector<int> A = {2, 4, 1, 10, 19, 6, 3, -1, 7};
    std::cout << "Array: ";
    printVector(A);
    std::cout<<"Key at index "<<linearSearch(A,0,A.size()-1,10)<<"\n";
}