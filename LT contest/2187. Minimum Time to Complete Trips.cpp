You are given an array time where time[i] denotes the time taken by the ith bus to complete one trip.

Each bus can make multiple trips successively; that is, the next trip can start immediately after completing the current trip. Also, each bus operates independently; that is, the trips of one bus do not influence the trips of any other bus.

You are also given an integer totalTrips, which denotes the number of trips all buses should make in total. Return the minimum time required for all buses to complete at least totalTrips trip
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution {
public:
    bool isPossible(vector<int> &time,int n,ll curTime,int totalTrips){
        ll currentTrips = 0;
        for(int i=0;i<n;i++){
            currentTrips += floor(curTime/time[i]);
            if(currentTrips >= totalTrips){
                return true;
            }
        }
        return false;
    }
    int mini(int a,int b){
        if(a < b){
            return a;
        }
        return b;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        ll n = time.size();
        ll minElem = INT_MAX;
        for(ll i=0;i<n;i++){
            minElem = mini(minElem,time[i]);
        }
        ll start = 1, end = minElem*totalTrips;
        ll ans = end;
        while(start <= end){
            ll mid = start + ((end-start)/2);
            if(isPossible(time,n,mid,totalTrips)){
                ans = mid;
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        return ans;
    }
};
