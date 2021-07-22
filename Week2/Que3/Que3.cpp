#include<iostream>
#include<fstream>
using namespace std;
int main(){
    ifstream in;
    in.open("input.txt");
    ofstream out;
    out.open("output.txt");
    int n,t,k;
    int arr[100];
    in >> t;
    while(t){
        in >> n;
        for(int i=0;i<n;i++)
            in >> arr[i];
        in >> k;
        int count =1;
        for(int i=0;i<n;i++){
            for(int j=i;j<n-i-1;j++){
                if(arr[i]-arr[j]==k || arr[i]-arr[j]==-k){
                count++;
                }
            }
        }
        out << count << endl;

    t--;
    }

return 0;
}
