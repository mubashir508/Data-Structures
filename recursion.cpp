#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class recursion{
public:
    int *arr = new int[10];
    
    int i=0;
    string s;
    int x;


    void insert(){
    // srand(static_cast<unsigned int>(time(0)));
        for(int i=0;i<10;i++){
            arr[i]=rand()%20+1;
        }
    }
    void printArray(){
        for (int i =0;i<10;i++){
            cout<<arr[i]<<"  ";
        }
        cout<<endl;
    }

    int fact(int n){
        if(n==0 || n==1){
            return 1;
        }
        else{
            return n* fact(n-1);
        }
    }

    int fabonacci(int n){
        if(n<=0 ){
            return 0;
        }
        if(n==1){
            return 1;
        }
        else{
            return fabonacci(n-2)+fabonacci(n-1);       
        }
    }

    void printFabonacci(int n){
        for(int i=0;i<=n;i++){
            cout<<fabonacci(i)<<"  ";
        }
        cout<<endl;
    }
    int search(int n){
        if(arr[i]==n){
            return i;
        }
        else if(i>10){
            return -1;
        }
        else {
            i+=1;
            search(n);
        }
    }

    void str_in(){
        
        cout<<"Enter String: ";
        cin>>s;
        x=s.length()-1;
    }
    bool isPalindrome(){
        if(s[i]!=s[x]){
            cout<<"It is not Palindrome"<<endl;
            return false;
        }
        if(s[i]>=s[x]){
            cout<<"It is Palindrome"<<endl;
            return true;
        }
        else{
            i+=1;
            x-=1;
            isPalindrome();
        }
    }


};
int main(){
    recursion r1;
    
    // cout<<"Factorial is: \t\t"<<r1.fact(5)<<endl;
    
    // cout<<"Fabonacci Series is: \t";
    // r1.printFabonacci(10);
    // cout<<endl;
    
    // r1.insert();
    // cout<<"Generated Array is: \t";
    // r1.printArray();
    // cout<<"Value found at "<< r1.search(5)<<"th index of Generated Array";

    r1.str_in();
    r1.isPalindrome();



    delete[] r1.arr;
    return 0;
}