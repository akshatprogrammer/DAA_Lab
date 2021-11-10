#include <bits/stdc++.h>
using namespace std;
 
void findMajority(int arr[], int n)
{
    int maxCount = 0;
    int index = -1;
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (arr[i] == arr[j])
                count++;
        }
 
        if (count > maxCount) {
            maxCount = count;
            index = i;
        }
    }

    if (maxCount > n / 2)
        cout << "Yes" << endl;
 
    else
        cout << "No" << endl;


        sort(arr,arr+n);

         if(n%2==0){
	           
	           int n1=n/2;
	           int n2=n1-1;
	           
	           int ans=arr[n1]+arr[n2];

	           cout<<ans/2<<endl;
	       }
	       else{
	           int idx=(n+1)/2;
	           cout<< arr[idx-1]<<endl;
	       }
        
}
 

int main()
{
    int n;
    cin>>n;

    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    findMajority(arr, n);
 
    return 0;
}