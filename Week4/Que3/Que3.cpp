#include<iostream>
#include<fstream>
using namespace std;
void swap(int &n1, int &n2)
{
    int t = n1;
    n1 = n2;
    n2 = t;
}

int partition(int arr[], int l, int r)
{
    int i = l-1;
    int j= l;
    while(j < r)
    {
        if(arr[j] <= arr[r])
        {
            i++;
            swap(arr[i], arr[j]);
        }
        j++;
    }
    i++;
    swap(arr[i], arr[r]);
    return i;
}

int kSmallFind(int arr[], int l, int r, int k, int n)
{
    if(l <= r)
    {
        int p = partition(arr, l, r);
        if(p == k-1)
            return arr[p];
        else if(p > k-1)
           return kSmallFind(arr, l, p-1, k, n);
        else
            return kSmallFind(arr, p+1, r, k, n);
    }
    return -1;
}
int main()
{
    ifstream in;
    in.open("input.txt");
    ofstream out;
    out.open("output.txt");
    int t,n;
    in>>t;
    while(t--)
    {
        int k;
        in>>n;
        int arr[n];
        for(int j=0;j<n;j++)
            in>>arr[j];
        in>>k;
       int ans = kSmallFind(arr,0,(n-1),k,n);
       if(ans==-1)
        out << "Not Present\n";
       else
        out << ans << endl;
    }
    return 0;

}