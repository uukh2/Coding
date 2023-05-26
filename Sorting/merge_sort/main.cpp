#include<bits/stdc++.h>

using namespace std;

void merge_s(int arr[],int l,int m,int r)
{
    int i,j,k;
    int n1=m-l+1;
    int n2=r-m;

    int *L=new int[n1] , *R=new int[n2];

    for(int i=0; i<n1; i++) L[i]=arr[l+i];
    for(int j=0; j<n2; j++) R[j]=arr[m+1+j];

    i=j=0;
    k=l;

    while(i<n1&&j<n2)
    {
        if(L[i]<=R[j])
        {
            arr[k]=L[i];
            i++;
        }
        else
        {
            arr[k]=R[j];
            j++;
        }
        k++;
    }

    while(i<n1)
    {
        arr[k]=L[i];
        i++;
        k++;
    }


    while(j<n2)
    {
        arr[k]=R[j];
        j++;
        k++;
    }
}

void M_sort(int arr[],int l,int r)
{
    if(l<r)
    {
        int m=l+(r-l)/2;
        M_sort(arr,l,m);
        M_sort(arr,m+1,r);
        merge_s(arr,l,m,r);
    }
}
void print(int arr[],int length)
{
    for(int i=0; i<length; i++)cout<<arr[i]<<' ';
    cout<<'\n';
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
    M_sort(arr,0,size-1);
    print(arr,size);

}
