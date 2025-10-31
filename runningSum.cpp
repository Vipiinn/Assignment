#include<iostream>
using namespace std;
int main(){
    int arr[] = {1,3,4,2,6,5,8};
    int n = sizeof(arr) / sizeof(arr[0]);

    for(int i=1;i<n;i++){
        arr[i] = arr[i] + arr[i-1];
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}