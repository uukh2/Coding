#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n,temp,C=0;
    bool flag = true;
    cin>>n;
    int arr[n];
    for(int i=0 ; i < n ; i++)cin>>arr[i];
    for(int i=0 ; i < n ; i++)
    {
        for(int j=i+1 ; j < n ; j++)
        {
            if(arr[i]>arr[j])
            {
                //swap(arr[i],arr[j]);
                temp = arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
                flag = false;
            }
            C++;
        }
        if(flag)break;
    }
    for(int i=0 ; i < n ; i++)cout<<arr[i]<<' ';
    cout<<"Number of round : "<<C<<'\n';

    return 0;
}
//khaled ibrahem
