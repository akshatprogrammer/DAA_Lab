#include<iostream>
using namespace std;
void minHeapify(int arr[], int i, int n)
{
    int left = 2*i+1;
    int right = 2*i+2;
    int minimum = i;
    if(left < n && arr[left]<arr[minimum])
    {
        minimum = left;
    }
    if(right < n && arr[right]<arr[minimum])
    {
        minimum = right;
    }
    if(minimum!=i)
    {
        swap(arr[i],arr[minimum]);
        minHeapify(arr,minimum,n);
    }

}

void buildHeap(int arr[], int n)
{
    for(int i=(n-2)/2;i>=0;i--)
    {
        minHeapify(arr,i,n);
    }
}

int extractMin(int arr[], int *n)
{
    int mini = arr[0];
    swap(arr[0],arr[(*n)-1]);
    (*n)--;
    minHeapify(arr,0,*n);
    return mini;
}

void insertHeap(int arr[], int value, int *n)
{
    (*n)++;
    arr[(*n)-1] = value;
    for(int i=(*n)-1;i!=0&&arr[i]<arr[(i-1)/2];)
    {
        swap(arr[i],arr[(i-1)/2]);
        i = (i-1)/2;
    }
}

int main()
{
    int ans=0,n;
    cout << "Enter n : ";
    cin >> n;
    int arr[n];
    cout << "Enter array elements : ";
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    buildHeap(arr, n);
   while(true)
    {
        if(n==0)
            break;
        int a = extractMin(arr, &n);
        int b = extractMin(arr, &n);
        int sum = a+b;
        cout << "sum of "  << a << " and " << b << "is " << sum << endl;
        ans += sum;
        insertHeap(arr, sum, &n);
    }
    cout << ans;
}
