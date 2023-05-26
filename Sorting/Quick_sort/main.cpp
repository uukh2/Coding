#include<bits/stdc++.h>

using namespace std;

int P(int arr[], int l, int h)
{
    int pivot = arr[h];
    int i = l - 1;

    for (int j = l; j <= h - 1; ++j)
    {

        if (arr[j] <= pivot)
        {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[h]);

    return i + 1;
}


void Q_sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivo = P(arr, low, high);
        Q_sort(arr, low, pivo - 1);
        Q_sort(arr, pivo + 1, high);
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

    Q_sort(arr,0,size-1);

    for(int i=0; i<size; i++) cout<<arr[i]<<' ';

    return 0;
}
