#include <iostream>

using namespace std;

int partitioning1(int arr[], int start, int endd)
{
    int p = arr[start];
    int i = start;
    int j = endd;
    while(i<j)
    {
        do
        {
            i++;
        }
        while(arr[i] <= p);
        do
        {
            j--;
        }
        while(arr[j] > p);
        if(i < j)swap(arr[i], arr[j]);
    }
    swap(arr[start], arr[j]);

    return j;
}

void Quick_Sort1(int arr[], int start, int endd )
{
    if(start < endd)
    {
        int pivo = partitioning1(arr, start, endd);
        Quick_Sort1(arr, start, pivo);
        Quick_Sort1(arr, pivo + 1, endd);
    }
}

int partitioning2(int arr[], int left, int right)
{
    int i=left, j=right, pivo = i;
    while(true)
    {
        while(arr[pivo] <= arr[j] && pivo != j) j--;

        if(pivo == j)break;
        else if(arr[pivo] > arr[j])
        {
            swap(arr[j], arr[pivo]);
            pivo = j;
        }

        while(arr[pivo] >= arr[i] && pivo != i) i++;

        if(pivo == i)break;
        else if(arr[pivo] < arr[i])
        {
            swap(arr[i], arr[pivo]);
            pivo = i;
        }

    }
    return pivo;
}

void Quick_Sort2(int arr[], int left, int right )
{
    if(left < right)
    {
        int pivo = partitioning2(arr, left, right);
        Quick_Sort2(arr, left, pivo-1);
        Quick_Sort2(arr, pivo + 1, right);
    }
}


int partitioning(int arr[], int l, int h)
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


void Quick_Sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivo = partitioning(arr, low, high);
        Quick_sort(arr, low, pivo - 1);
        Quick_sort(arr, pivo + 1, high);
    }
}

int main()
{
    int sizeofarr;
    cout <<"Enter size of array : \n";
    cin>>sizeofarr;
    //int arr[sizeofarr];
    int arr[100];

    for (int i=0 ; i < sizeofarr ; i++)
    {
        cout <<"Enter "<<i+1<<" element in array : \n";
        cin>>arr[i];
    }

      Quick_Sort(arr, 0 , sizeofarr-1);
     //Quick_Sort1(arr, 0 , sizeofarr);
    //Quick_Sort2(arr, 0 , sizeofarr-1);

    for(int i = 0 ; i < sizeofarr ; i++) cout<<arr[i]<<' ';
    cout<<'\n';

    return 0;
}
//khaled ibrahem
