#include<bits/stdc++.h>
using namespace  std;

bool compare(pair<int,int> p1,pair<int,int> p2){
    return p1.first > p2.first;
}


int main(){

    vector<pair<int,int> > job;
    int n,profit,deadline;

    cin>>n;

    for(int i=0;i<n;i++){
        cin>>profit>>deadline;

        job.push_back(make_pair(profit,deadline));
    }

    sort(job.begin(),job.end(),compare);

    int maxEndTime=0;
    for(int i=0;i<n;i++){
        if(job[i].second>maxEndTime){
            maxEndTime=job[i].second;
        }
    }

    int fill[maxEndTime];

    int count=0;
    vector<int> selected;
   
    for(int i=0;i<maxEndTime;i++){
        fill[i]=-1;
    }

    for(int i=0;i<n;i++){

        int j=job[i].second-1;

        while(j>=0 && fill[j]!=-1){
            j--;
        }

        if(j>=0 && fill[j]==-1){
            fill[j]=i;
            count++;
            selected.push_back(i);
        }

    }

    cout<<"Max Number of task"<<" "<<count<<endl;

    cout<<"Selected Task Numbers"<<" ";

    for(int i=0;i<selected.size();i++){
        cout<<selected[i]+1<<" ";
    }

}
