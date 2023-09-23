#include<iostream>
using namespace std;

// Binary heap:

class Heap
{
public:
    int *HeapArr;  // pointer to array of  heap elements
    int SizeOfHeap;  //Size of heap that will be one less tahn its original array
    int ArraySize;   //Array size for heap - maximum size for a heap(from index 0 to max index)

    //constructor to create Heap
    Heap(int arraySize)
    {
        SizeOfHeap = 0;
        ArraySize= arraySize-1;  //starating index of heap is 1
        HeapArr = new int[arraySize];    //creating heap array of size arrSize
    }

    //Insertion method that will insert at at the end of heap
    void Insert(int value)
    {
        SizeOfHeap = SizeOfHeap + 1;     //for insertion at the left most position of heap in Array
        HeapArr[SizeOfHeap] = value;   //storing value at the next available slot

        //calling buildmaxheap to max heapify the array
        BuildMaxHeap(HeapArr);
    }

    //MaxHeapify Method
    void MaxHeapify(int *Arr, int i, int n)
    {
        int LeftChild = Left(i) ;     //left child of parent
        int RightChild = Right(i) ;    // Right child of parent
        int largest;   //storing index of largest value

        if(LeftChild  <= n && Arr[LeftChild ] > Arr[i])
            largest = LeftChild ;
        else
            largest = i;     //otherwise the ith index will have largest value


        if(RightChild <= n && Arr[RightChild] > Arr[largest])
            largest = RightChild;   //storing right child as largest

        // If i is not largest then swap :
        if(largest != i)
        {
            Swap(&Arr[i], &Arr[largest]);
            MaxHeapify(Arr, largest, n);   //recursive call
        }
    }

    //FindMax Method  that returns the maximum value of the heap
    int FindMax()
    {
        return HeapArr[1];   //returns value at index1 which is the max value
    }

    //deleteMax Method
    int DeleteMax()
    {
        int temp = HeapArr[1];  //storing value at 1st index in temp variable
        HeapArr[1] = HeapArr[SizeOfHeap]; //first index stores the value at last index
        SizeOfHeap--;    //decreasing heap size

        //maxheapify to place value at index 1 at its logical position
        MaxHeapify(HeapArr, 1, SizeOfHeap);

        return temp;
    }
    //Swap Method
    void Swap(int *a, int *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    // a method that will detect left child
    int Left(int k)
    {
        return 2*k;     //returning left index
    }

    // a method that will detect right child
    int Right(int k)
    {
        return (2*k) + 1;   //returning right index
    }

    //isEmpty Method
    bool isEmpty()
    {
        if(SizeOfHeap == 0)
            return true;
        else
            return false;
    }

    //Size Method
    int Size()
    {
        return SizeOfHeap;
    }

    //BuildMaxHeap Method
    void BuildMaxHeap(int *Arr)
    {
        int n = SizeOfHeap ; //Heap size is starting from index 1

        for(int i = n/2 ; i>= 1 ; i--)
        {
            MaxHeapify(Arr, i, n);
        }
    }

    //PrintHeap MEthod
    void PrintHeap(){
        cout<<"Heap is as: ";
        for(int i=1; i<= SizeOfHeap; i++)
        {
            cout<<HeapArr[i]<<" ";
        }
        cout<<endl;
    }

    //HeapSort Method
    void HeapSort()
    {
        while(SizeOfHeap > 1) //loop until last node
        {
            //max heap is implemented during insertion
            int root = HeapArr[1];   //maximum element

            Swap(&HeapArr[1], &HeapArr[SizeOfHeap]); //swapping 1st node with last node
            SizeOfHeap--;    //decreasing heap size

            //maxheapify to place value at index 1 at its logical position
            MaxHeapify(HeapArr, 1, SizeOfHeap);

        }
    }
};
int main(){
    Heap *hp = new Heap(10);   //passing array size
    hp->Insert(5);
    hp->Insert(9);
    hp->Insert(15);
    hp->Insert(7);
    hp->Insert(12);
    hp->Insert(20);
    hp->Insert(25);
    hp->PrintHeap();

   // hp->HeapSort();
  //  cout<<"\n After  Heap Sorting: ";
   // hp->PrintHeap();
}

