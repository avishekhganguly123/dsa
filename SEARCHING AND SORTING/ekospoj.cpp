#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main() {
	// your code here
	ll n,m,s,e,mid;
	cin>>n>>m;
	ll arr[n];
	for(ll i=0;i<n;i++) cin>>arr[i];
	
	s=0;
	e=*max_element(arr,arr+n);
	ll ans=0;
	while(s<=e){
		mid=s+((e-s)/2);
		ll temp=0;
		for(ll i=0;i<n;i++){
			if(arr[i]>mid) temp+=arr[i]-mid;
		}
		if(temp>=m) {
			s=mid+1;
			ans=mid;
		}
		else{
			e=mid-1;
		}
	   }
	   cout<<ans;
     
	return 0;
	
}  