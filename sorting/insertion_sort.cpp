/**
 * @brief Program to implement Insertion Sort.
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
 * Sorts a vector of elements in ascending order using Insertion Sort.
 * Worst case Time Complexity: O(n^2)
 * Worst case Space Complexity: O(n)
 * Type: In-place, Stable, Online
 *
 * @param A vector containing unsorted elements
 * @return void
 */
void insertionSort(std::vector<int> &A)
{
    int n = A.size();
    int key, j;

    for(int i=1;i<n;i++)    // elements before i are sorted
    {
        key = A[i];         // the element which has to be placed 
        
        for(j=i-1;j>=0 && A[j] > key;j--)
        {
            A[j+1] = A[j];     // shift elements right
        }
        A[j+1] = key;            // place the element at desired position 
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
    insertionSort(A);
    printVector(A);
}