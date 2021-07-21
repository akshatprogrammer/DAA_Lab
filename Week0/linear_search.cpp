#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
	ifstream inFile;
	int count=0;
	string nameFile;
	inFile.open("input.txt");
	ofstream myFile;
	myFile.open("output.txt");
	if (!inFile){
    cout << "Unable to open file input.txt";
    exit(1);
    }
    int n,k;
    int arr[100];
    while(!inFile.eof()){
    	inFile >> n;
    	for(int i=0;i<n;i++){
    		inFile >> arr[i];
		}
		inFile >> k;
	}
	
	// Linear Search
	for(int i=0;i<n;i++){

		if(arr[i]==k){
			count=1;
		}
	}
	if(count==1){
		myFile << "Key Element Found :)" << endl;
	}
	else{
		myFile << "Key Element Not Found :)" << endl;
	}
    
}
