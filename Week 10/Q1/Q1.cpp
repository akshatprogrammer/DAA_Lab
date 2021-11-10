#include<bits/stdc++.h>
using namespace std;

struct Activity{
    int start;
    int finish;

};
bool compare(Activity a1,Activity a2){
    return a1.finish<a2.finish;
}

void  selectMaxActivities(Activity arr[],int n){
    
    sort(arr,arr+n,compare);
    int i,j;

    i=0;
  
    vector<int> selected;
    
    selected.push_back(i);
    int nonconflicting=1;
    

     for (j = 1; j < n; j++)
    {
      
      if (arr[j].start >= arr[i].finish)
      {
          ++nonconflicting;
          selected.push_back(j);
          i = j;
      }
     

    }
    cout<<"No of non conflicting activities"<<" "<<nonconflicting<<endl;

      cout<<"List of selected activities"<<" ";
      for(int k=0;k<selected.size();k++){
          cout<<selected[k]+1<<" ";
      }


}

int main(){
    int n;
    cin>>n;

    int start[n];
    int end[n];

    for(int i=0;i<n;i++){
       cin>>start[i];
    
    }

     for(int i=0;i<n;i++){
         cin>>end[i];
    }
     
   
    Activity arr[n];
    for(int i=0;i<n;i++){
        arr[i].start=start[i];
        arr[i].finish=end[i];
    }


    selectMaxActivities(arr,n);

}