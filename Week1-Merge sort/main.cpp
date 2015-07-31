#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void myMerge(int arr[], int l, int mid, int r)
{
    int sz1 = mid - l + 1;
    int sz2 = r - mid;

    int tempLeft[sz1], tempRight[sz2];
    for(int i = 0; i < sz1; i++)
        tempLeft[i] = arr[l+i];
    for(int i = 0; i < sz2; i++)
        tempRight[i] = arr[mid+1+i];

    int i = 0, j = 0, k = l;
    while(i < sz1 && j < sz2)
    {
        if(tempLeft[i] < tempRight[j])
        {
            arr[k] = tempLeft[i];
            i += 1;
        }
        else
        {
            arr[k] = tempRight[j];
            j += 1;
        }
        k += 1;
    }
    while(i < sz1)
    {
        arr[k] = tempLeft[i];
        k += 1;
        i += 1;
    }
    while(j < sz2)
    {
        arr[k] = tempRight[j];
        k += 1;
        j += 1;
    }
}
void mergeSort(int arr[], int l, int r)
{
    if(l < r)
    {
        int mid = l + (r-l)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        myMerge(arr, l, mid, r);
    }
}
int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    mergeSort(arr, 0, 6);
    for(int i = 0; i < 6; i++)
        cout << arr[i] << " \n"[i==5];
    return 0;
}
