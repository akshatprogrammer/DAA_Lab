#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

struct triplets
{
    int weight;
    int volume;
    int index;
};
struct myComparator
{
    bool operator()(triplets t1, triplets t2){
        return t1.volume/(float)t1.weight > t2.volume/(float)t2.weight;
    }
};
int main()
{
    int n,cap;
    float ans=0.0;
    cout << "Enter the value of n : ";
    cin >> n;
    vector<triplets> v;
    vector<pair<int,int>> itwt;
    for(int i=0;i<n;i++)
    {
        triplets t;
        cin >> t.weight >> t.volume;
        t.index = i;
        v.push_back(t);
    }
    sort(v.begin(), v.end(), myComparator());
    cout << "Enter the capacity : ";
    cin >> cap;
    for(int i=0;i<n;i++)
    {
        if(v[i].weight <= cap)
        {
            ans += v[i].volume;
            cap -= v[i].weight;
            itwt.push_back({v[i].index, v[i].weight});
        }
        else{
            ans += ((v[i].volume/(float)v[i].weight))*cap;
            int j = ceil((v[i].volume/(float)v[i].weight))*cap;
            itwt.push_back({v[i].index, j});
            break;
        }
    }
    cout << ans << endl;
    for(auto i : itwt)
    {
        cout << i.first+1 << " - " << i.second << endl;
    }
}
