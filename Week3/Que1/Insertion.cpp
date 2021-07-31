#include<iostream>
#include<fstream>
using namespace std;
int main(){
    ifstream in;
    ofstream out;
    in.open("input.txt");
    out.open("output.txt");
    int t,n;
    int arr[100];
    in >> t;
    while(t){
        in >> n;
        for(int i=0;i<n;i++)
            in >> arr[i];
        int shifts=0,comparison=0;
        int key=0,j;
        for(int i=1;i<n;i++){
            key=arr[i];
            j=i-1;
            while(j>=0 && arr[j]>key){
                arr[j+1]=arr[j];
                j--;
                shifts++;
                comparison++;
            }
            arr[j+1]=key;
            comparison++;
        }
        for(int i=0;i<n;i++)
            out << arr[i] << " ";
            out << endl;
        out << "Shifts = " << shifts << endl;
        out << "Comparisons = " << comparison << endl;
        t--;
    }
}
