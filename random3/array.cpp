#include<bits/stdc++.h>
using namespace std;

void merge(int array[], int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    int leftArr[n1], rightArr[n2];
    for(int i = 0; i < n1; i++)
        leftArr[i] = array[left + i];
    for(int j = 0; j < n2; j++)
        rightArr[j] = array[mid + 1 + j]; 
    
    int i = 0, j = 0, k = left;
    
    while(i < n1 && j < n2){
        if(leftArr[i] <= rightArr[j]){
            array[k] = leftArr[i];
            i++;
        }
        else{
            array[k] = rightArr[j];
            j++;
        }
        k++;
    }
    while(i < n1){
        array[k] = leftArr[i];
        i++;
        k++;
    }
    while(j < n2){
        array[k] = rightArr[j];
        j++;
        k++;
    }
}
void mergeSort(int array[], int left, int right){
    if(left < right){
        int mid = left + (right - left) / 2;
        
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);
        
        merge(array, left, mid, right);
    }
}
int main(){
    int size = 50;
    int arr[size];
    srand(time(NULL));

    for(int i=0; i<size; i++){
        arr[i] = rand()%100;
    }

    cout<<"Before sorting:\n";
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    mergeSort(arr, 0, size-1);

    cout<<"After sorting:\n";
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}
