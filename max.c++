//min-max//

#include<iostream>
using namespace std;
void heapify(int arr[],int n, int i)
{
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;
    if(l<n && arr[l] > arr [largest])
    largest = l;
    if(r<n && arr[r] > arr[largest])
    largest = r;
    if(largest!=i)
    {
        swap (arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
}
void minheapify(int arr[],int n, int i)
{
    int lowest = i;
    int l = 2*i+1;
    int r = 2*i+2;
    if(l<n && arr[l] < arr[lowest])
    lowest = l;
    if(r<n && arr[r] < arr[lowest])
    lowest = r;
    if(lowest != i)
    {
        swap(arr[i],arr[lowest]);
        minheapify(arr,n,lowest);
    }
}
void creatheap(int arr[],int n, int ch)
{
    switch(ch)
    {
        case 1:
        for(int i= n/2-1; i>=0;i--)
        {
            heapify(arr,n,i);
        }
        break;
        case 2:
        for(int i = n/2-1; i>=0;i--)
        {
            minheapify(arr,n,i);
        }
        break;
    }
}
void printArray(int arr[],int n)
{
    for(int i=0; i<n; ++i)
    cout<<arr[i]<<" ";
    cout<<"\n";
}
void del(int arr[],int key, int n,int ch)
{
    int flag;
    for(int i=0; i<n; i++)
    {
        if(key == arr[i])
        flag=i;
    }
    swap(arr[flag],arr[n-1]);
    --n;
    switch(ch)
    {
        case 1:
        for(int i = n/2-1; i>=0; i--)
        {
            heapify(arr,n,i);
        }
        printArray(arr,n);
        break;
        case 2:
        for(int i = n/2-1; i>=0; i--)
        {
            minheapify(arr,n,i);
        }
        printArray(arr,n);
        break;
    }
}
void Search(int arr[],int key, int n)
{
    int flag = 0;
    for(int i=0;i<n;i++)
    {
        if(key==arr[i])
        {
            cout<<key<<"id present in the heap"<<endl;
            flag++;
        }
    }
    if(flag == 0)
    {
        cout<<key<<"is not present"<<endl;
    }
    
}
int main()
{
    int n;
    cout<<"Enter the number of elements"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    int ch;
    cout<<"which heap you want to creat"<<endl;
    cout<<"1.maxheap"<<endl;
    cout<<"2.minheap"<<endl;
    cin>>ch;
    creatheap(arr,n,ch);
    cout<<"array is \n";
    printArray(arr,n);
    int s;
    cout<<"Enter the number to search"<<endl;
    cin>>s;
    Search(arr,s,n);
    int de;
    cout<<"Enter the number to be deleted"<<endl;
    cin>>de;
    del(arr,de,n,ch);
};