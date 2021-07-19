/**
 * @brief Program to implement Modified Bubble Sort whose best case is O(n)
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
 * Sorts a vector of elements in ascending order using Modified Bubble Sort.
 * Worst case Time Complexity: O(n^2)
 * Best Case Time Complexity: O(n)
 * Worst case Space Complexity: O(n)
 * Type: In-place, Stable
 *
 * @param A vector containing unsorted elements
 * @return void
 */
void bubbleSortModified(std::vector<int> &A)
{
    int n = A.size();
    bool isSwapped = false;

    for (int i = 0; i < n - 1; i++) // bubble sort requires n-1 passes at worst
    {
        if(isSwapped || i==0)     // proceed to inner loop if swapping took place previously
        {
            isSwapped = false;                  // resetting isSwapped

            for (int j = 0; j < n - i - 1; j++) // largest element gets placed after each pass
            {
                if (A[j] > A[j + 1]) // compares two adjacent elements
                {
                    isSwapped = true;
                    swap(A[j], A[j + 1]);
                }
            }
            std::cout << "Pass " << i + 1 << ": "; // comment this part
            printVector(A);                        // comment this part
        }
        else
        {
            break;      // no further sorting is required as No swap took place
        }
        
    }
}

// main function
int main(void)
{
    std::vector<int> A = {1,2,3,10,4,5,6,7,8,9};
    std::cout << "Original: ";
    printVector(A);
    bubbleSortModified(A);
    printVector(A);
}