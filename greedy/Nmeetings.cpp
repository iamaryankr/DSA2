#include<bits/stdc++.h>
using namespace std;

int maximumMeetings(vector<int> &start, vector<int> &end){
    int n = start.size();
    vector<pair<int,int>> v;
    for(int i=0; i<n; i++){
        v.push_back({start[i], end[i]});
    }
    sort(v.begin(), v.end());
    int ans = 1;
    for(int i=0; i<n; i++){
        if(v[i].second >= v[i+1].first){
            v[i+1].second = min(v[i+1].second, v[i].second);
        }
        else ans++;
    }
    return ans;
}