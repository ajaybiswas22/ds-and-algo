/**
 * @brief Program to implement Bubble Sort.
 * @author Ajay Biswas
 *
 */

#include <iostream>
#include <vector>
#include <cmath>

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
 * Finds maximum digits amonng the elements
 *
 * @param A Vector containing some elements
 * @return Integer denoting number of digits.
 */
int maxDigits(std::vector<int> A)
{
    int n = A.size();
    int max_digits = 0, digits = 0;

    for(int i=0;i<n;i++)        // finding max no. of digits
    {
        if(A[i] <= 1)
        {
            digits = 1;
        }
        else
        {
            digits = ceil(log10(A[i]));
        }

        if(max_digits < digits)
        {
            max_digits = digits;
        }
    }
    return max_digits;
}

/**
 * FIlls an array with contents of a 2D vector
 *
 * @param buckets 2D Vector containing some elements digitwise
 * @return Vector of elements
 */
std::vector<int> bucketToArray(std::vector<std::vector<int>> buckets)
{
    int m = buckets.size();
    std::vector<int> X;

    for(int i=0;i<m;i++)
    {
        int n = buckets[i].size();

        for(int j=0;j<n;j++)
        {
            X.push_back(buckets[i][j]);
        }
    }
    return X;
}

/**
 * Sorts a vector of elements in ascending order using Radix Sort
 * Worst Case Time Complexity:  O(d*(n+b)) or O(nd)
 * Worst Case Space Complexity: O(n+d)
 *
 * @param A vector containing unsorted elements
 * @param base Base of number system
 * @return void
 */
void radixSort(std::vector<int> &A)
{
    int n = A.size();
    int digits = maxDigits(A);

    for(int i=0;i<digits;i++)           // looping through digit position  
    {
        std::vector<std::vector<int>> buckets(10);        // creating buckets to hold numbers

        for(int j=0;j<n;j++)            // inserts in bucket digit wise
        {
            // extract i+1 digit from LSB
            int div = pow(10,i);
            int slot = A[j]/div; 
            slot = slot%10; 
            buckets[slot].push_back(A[j]);  
        }

        // Insert back elements to array
        A = bucketToArray(buckets);
    }

}

// main function
int main(void)
{
    std::vector<int> A = {25,56,9,127,765,340,52,72,19};
    std::cout << "Original: ";
    printVector(A);
    radixSort(A);
    printVector(A);
}