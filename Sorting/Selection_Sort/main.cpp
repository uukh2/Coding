#include <bits/stdc++.h>

using namespace std;

void selection_sort(int arr[], int n)
{

    int mn;
    for (int i = 0; i < n - 1; i++)
    {
        mn = i;
        for (int j = i + 1; j < n; j++) if (arr[j] < arr[mn]) mn = j;
        swap(arr[mn], arr[i]);
    }
}
int main()
{
    int size;
    cout <<"Enter size of array : \n";
    cin>>size;
    int arr[size];

    for (int i=0 ; i < size ; i++)
    {
        cout <<"Enter "<<i+1<<" element in array : \n";
        cin>>arr[i];
    }
    selection_sort(arr,size);

    for(int i=0; i<size; i++)cout<<arr[i]<<' ';

    return 0;
}
//khaled ibrahem
