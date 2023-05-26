#include <bits/stdc++.h>

using namespace std;

int main()
{
    int size,key, j;
    cout <<"Enter size of array : \n";
    cin>>size;
    int arr[size];
    for (int i=0 ; i < size ; i++)
    {
        cout <<"Enter "<<i+1<<" element in array : \n";
        cin>>arr[i];
    }
    for (int i = 1; i < size; i++)
    {
        key = arr[i];
        j=i-1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    for (int i = 0; i < size; i++)cout << arr[i] << ' ';

    return 0;
}
