#include <iostream>

using namespace std;

void swap(int* p, int* q){
    int temp = *p;
    *p = *q;
    *q = temp;
}

void quickShort(int arr[], int firstPosition, int lastPosition){
    if(firstPosition<lastPosition){
        int pivot   =   firstPosition;  //first element is pivot
        int start   =   firstPosition;
        int end     =   lastPosition;
        
        while(end>start){
            
            while(arr[start]<=arr[pivot] && start<end){
                start++;
            }
            while(arr[end]>arr[pivot]){
                end--;
            }
            
            if(end>start){
                swap(&arr[end], &arr[start]);
            }
        }
        
        swap(&arr[end], &arr[pivot]);
        quickShort(arr, firstPosition, end-1);
        quickShort(arr, end+1, lastPosition);
    }
}

void printArray(int a[], int len){
    for(int i=0; i<len; i++){
        cout << a[i] << " ";
    }
    cout << "\n";
}

int main()
{
    int arr[]={8,10,5,0,353,523,12,1,252,24,3,2,346,4532,1,3,34,546,18,9,3,10,15,2,19,5};
    int len = sizeof(arr)/sizeof(arr[0]);
    quickShort(arr, 0, len-1);
    printArray(arr, len);
    return 0;
}
