#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
int main(){
	ifstream in;
	in.open("input.txt");
	ofstream out;
	out.open("output.txt");
	int n,k,t;
	int searches=0;
	int arr[100];
	in >> t;
	while(t){
		in >> n;
		for(int i=0;i<n;i++){
			in >> arr[i];
		}
		in >> k;
		int high = sqrt(n);
		int low = 0;
		int count=0;
		while(arr[high]<=k&&high<n){
			low=high;
			high+=sqrt(n);
		}
		for(int i=low;i<high;i++){
			searches++;
			if(arr[i]==k){
				out << "Present " << searches << endl;
				count=1;
				break;
			}
		}
		if(count==0){
				out << "Not Present " << searches << endl;
			}
		t--;
	}
}
