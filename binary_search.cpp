/*
@author     : SRvSaha
Description : Basic Binary Search Iterative Implementation
TimeStamp   : 8th April, 11.35 AM
*/

#include <bits/stdc++.h>
#define MAX 100
using namespace std;
int binary_search(int A[],int size, int x){
    int high = size - 1;
    int low = 0;
    while( high >= low){
        int mid = (high + low)/2;
        if(A[mid] == x)
            return mid;
        else if(A[mid] > x){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return -1;
}
int main(){
    int A[MAX];
    int n,x;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    printf("Enter the elements in the array : ");
    for(int i = 0; i < n; i++)
        scanf("%d",&A[i]);
    sort(A, A+n);
    printf("Srted Array is : ");
    for(int i = 0; i < n ; i++)
        printf("%d ",A[i]);
    printf("\n");
    printf("Enter the element you want to search: ");
    scanf("%d",&x);
    if (binary_search(A, n, x) == -1){
        printf("Element not found\n");
    }
    else{
        printf("Element found at index : %d\n",binary_search(A, n , x));
    }
    return 0;
}
