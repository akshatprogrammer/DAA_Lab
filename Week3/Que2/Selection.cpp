#include<iostream>
#include<fstream>
using namespace std;
int main(){
    ifstream in;
    ofstream out;
    in.open("input.txt");
    out.open("output.txt");
    int n,t;
    in >> t;
    int arr[100];
    while(t){
        in >> n;
        for(int i=0;i<n;i++){
            in >> arr[i];
        }
        int mid=0;
        int comparison=0,swaps=0;
        for(int i=0;i<n-1;i++){
            mid=i;
            for(int j=i+1;j<n;j++){
                if(arr[j]<arr[mid]){
                    mid=j;
                }
                comparison++;
            }
            swap(arr[mid],arr[i]);
            swaps++;
        }
        for(int i=0;i<n;i++)
            out << arr[i] << " ";
            out << endl;
        out << "Comparisons = " << comparison << endl;
        out << "Swaps = " << swaps << endl;
        t--;
    }
}
