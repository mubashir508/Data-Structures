#include<iostream>
#include <ctime>
using namespace std;
#define n 15

class array_sort{
    int*arr =new int[n];
public:
    void swap(int &a,int &b){
        int temp;
        temp=b;
        b=a;
        a=temp;
    }
    void insert(){
        srand(static_cast<unsigned int>(time(0)));
        for(int i=0;i<n;i++){
            arr[i]=rand()%70+1;
        }
    }
    void print(){
        for (int i =0;i<n;i++){
            cout<<arr[i]<<"  ";
        }
        cout<<endl;
    }
    int partition(int low, int high) {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }

        swap(arr[i + 1], arr[high]);
        return i + 1;
    }
    int getMax() {
        int maxVal = arr[0];
        for (int i = 1; i < n; i++) {
            if (arr[i] > maxVal) {
                maxVal = arr[i];
            }
        }
        return maxVal;
    }

    void countingSort(int exp) {
        const int BASE = 10;
        int output[n] = {0};
        int count[BASE] = {0};

        for (int i = 0; i < n; i++) {
            count[(arr[i] / exp) % BASE]++;
        }

        for (int i = 1; i < BASE; i++) {
            count[i] += count[i - 1];
        }

        for (int i = n - 1; i >= 0; i--) {
            output[count[(arr[i] / exp) % BASE] - 1] = arr[i];
            count[(arr[i] / exp) % BASE]--;
        }

        for (int i = 0; i < n; i++) {
            arr[i] = output[i];
        }
    }
    
    void bubble_sort(){
        for(int i=0;i<n-1;i++){
            for(int j=0;j<n-i-1;j++){
                if(arr[j]>arr[j+1]){
                    swap(arr[j],arr[j+1]);
                }
            }
        }
    }
    void selection_sort() {
        for (int i = 0; i < 14; i++) {
            int min_index = i;

            // Find the index of the minimum element in the unsorted part of the array
            for (int j = i + 1; j < 15; j++) {
                if (arr[j] < arr[min_index]) {
                    min_index = j;
                }
            }

            // Swap the minimum element with the first unsorted element
            if (min_index != i) {
                swap(arr[i], arr[min_index]);
            }
        }
    }
    void insertion_sort() {
        for (int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;

            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }

            arr[j + 1] = key;
        }
    }
    void quick_sort(int low, int high) {
        if (low < high) {
            int pivotIdx = partition(low, high);

            quick_sort(low, pivotIdx - 1);
            quick_sort(pivotIdx + 1, high);
        }
    }
    void radix_sort() {
        int maxVal = getMax();
        for (int exp = 1; maxVal / exp > 0; exp *= 10) {
            countingSort(exp);
        }
    }

    
};
int main(){
    array_sort a1;
    array_sort a2;
    array_sort a3;
    array_sort a4;
    array_sort a5;

    a1.insert();
    cout<<"Generated Array is: \t\t" ;
    a1.print();
    a1.bubble_sort();
    cout<<"Bubble Sorted Array is: \t" ;
    a1.print();
    cout<<endl;
    
    a2.insert();
    cout<<"Generated Array is: \t\t" ;
    a2.print();
    a2.selection_sort();
    cout<<"Selection Sorted Array is: \t" ;
    a2.print();
    cout<<endl;

    a3.insert();
    cout << "Generated Array is: \t\t";
    a3.print();
    a3.insertion_sort();
    cout << "Insertion Sorted Array is: \t";
    a3.print();
    cout<<endl;

    a4.insert();
    cout << "Generated Array is: \t\t";
    a4.print();
    a4.quick_sort(0, n - 1);
    cout << "Quick Sorted Array is: \t\t";
    a4.print();
    cout<<endl;

    a5.insert();
    cout << "Generated Array is: \t\t";
    a5.print();
    a5.radix_sort();
    cout << "Radix Sorted Array is: \t\t";
    a5.print();
    cout<<endl;

    return 0;
}