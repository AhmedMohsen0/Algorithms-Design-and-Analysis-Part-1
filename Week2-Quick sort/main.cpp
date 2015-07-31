#include <iostream>
#include <bits/stdc++.h>
#include <stdlib.h>

using namespace std;
int cnt = 0;
int partion(int arr[], int l, int r)
{
    int len = r-l;
    int mid;
    if(len%2 == 0)
        mid = l + (len/2 - 1);
    else
        mid = l + (r-l)/2;

    vector < pair <int, int> > curr;
    curr.push_back(make_pair(arr[l], l));
    curr.push_back(make_pair(arr[r-1], r-1));
    curr.push_back(make_pair(arr[mid], mid));
    sort(curr.begin(), curr.end());
    swap(arr[l], arr[curr[1].second]);

    int pivot = arr[l];
    cnt += (len-1);
    int i = l + 1;
    for(int j = l+1; j < r; j++)
    {
        if(arr[j] <= pivot)
        {
            swap(arr[i], arr[j]);
            i += 1;
        }
    }
    swap(arr[l], arr[i-1]);
    return i-1;
}
void quickSort(int arr[], int l, int r)
{
    if(r > l)
    {
        int p = partion(arr, l, r);
        quickSort(arr, l, p);
        quickSort(arr, p+1, r);
    }
}

int arr[10007];
int main()
{
    freopen("QuickSort.txt", "r", stdin);
    for(int i = 0; i < 10000; i++)
        cin >> arr[i];
    quickSort(arr, 0, 10000);
    cout << cnt << endl;
    return 0;
}
