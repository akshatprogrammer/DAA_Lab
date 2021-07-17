#include<iostream>
#include<fstream>
using namespace std;
int main(){
	ifstream in;
	in.open("input.txt");
	ofstream out;
	out.open("output.txt");
	int t;
	int arr[100];
	in >> t;
	int n,k;
	int count=0,index;
	while(t){
		count=0;
		index=0;
		in >> n;
		for(int i=0;i<n;i++){
			in >> arr[i];
		}
		in >> k;
		for(int i=0;i<n;i++){
			if(arr[i]==k){
				count=1;
				index=i+1;
			}
		}
		if(count==1){
			out << "Present "<<index << endl;
		}
		else{
			out << "Not Present " << n << endl;
		}
		t--;
	}

		
}
