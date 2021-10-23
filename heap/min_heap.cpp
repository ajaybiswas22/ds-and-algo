#include<iostream>
#include<climits>
#include<algorithm>

class MinHeap
{
    int *arr;
    int size;
    int capacity;
public:
    MinHeap(int cap)    // constructor to initialize heap
    {
        size = 0;
        capacity = cap;
        arr = new int[cap];
    }
    inline int left(int i) { return i*2 + 1; }
    inline int right(int i) { return i*2 + 2; }
    inline int parent(int i) { return (i-1)/2; }

    void insert(int data)
    {
        if(size == capacity)
            return;
        
        size++;     // increment size of minheap after insertion
        arr[size-1] = data;    // data inserted at the end

        for(int i=size-1; i!=0 && arr[parent(i)]>arr[i]; )       
        {
            // correct the position of the element
            std::swap(arr[i],arr[parent(i)]);
            i = parent(i);
        }
    }

    void min_heapify(int i)
    {
        int lt = left(i), rt = right(i);    // left and right child
        int smallest = i; // smallest node (we need to place smallest at top)

        if(lt<size && arr[lt] < arr[i])
            smallest = lt;
        if(rt<size && arr[rt] < arr[smallest])
            smallest = rt;

        if(smallest!=i)
        {
            std::swap(arr[i],arr[smallest]);
            min_heapify(smallest);
        }
    }

    int remove_min()
    {
        if(size == 0)
            return INT_MAX;

        if(size == 1)
        {
            size--;
            return arr[0];
        }

        std::swap(arr[0],arr[size-1]);
        size--;
        min_heapify(0);
        return arr[size];
    }

    void decrease_key(int i,int val)
    {
        arr[i] = val;
        while(i!=0 && arr[parent(i) > arr[i]])
        {
            std::swap(arr[i],arr[parent(i)]);
            i = parent(i);
        }
    }

    void delete_key(int i)
    {
        decrease_key(i,INT_MIN);
        remove_min();
    }

    void build_heap()
    {
        for(int i = (size-2)/2; i>=0; i--)
        {
            min_heapify(i);
        }
    }

    void printHeap()
    {
        for(int i=0;i<size;i++)
            std::cout<<arr[i]<<" ";
        std::cout<<"\n";
    }

    // following codes are used to convert array into heap
    static void heapify(int arr[], int n, int i) 
    { 
        int largest = i; // Initialize largest as root
        int l = 2 * i + 1; // left = 2*i + 1
        int r = 2 * i + 2; // right = 2*i + 2
    
        // If left child is larger than root
        if (l < n && arr[l] > arr[largest])
            largest = l;
    
        // If right child is larger than largest so far
        if (r < n && arr[r] > arr[largest])
            largest = r;
    
        // If largest is not root
        if (largest != i) {
            std::swap(arr[i], arr[largest]);
    
            // Recursively heapify the affected sub-tree
            heapify(arr, n, largest);
        }
    } 
    static void buildheap(int arr[],int n)
    {
        for (int i = n / 2 - 1; i >= 0; i--) 
            heapify(arr, n, i);
    }
    static void heapSort(int arr[], int n) 
    {  
        buildheap(arr,n); 

        for (int i = n - 1; i >= 0; i--)
        { 
            std::swap(arr[0], arr[i]);
            heapify(arr, i, 0); 
        } 
    }
    static void printHeap(int arr[],int n)
    {
        for(int i=0;i<n;i++)
            std::cout<<arr[i]<<" ";
        std::cout<<"\n";
    }
};

int main()
{
    MinHeap h(11);
    h.insert(3); 
    h.insert(2);
    h.insert(1);
    h.insert(15);
    h.insert(20);
    h.printHeap();

    int arr[] = {12, 11, 13, 5, 6, 7}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	MinHeap::heapSort(arr, n); 
    MinHeap::printHeap(arr,n);

    return 0;
}