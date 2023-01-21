#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--){
		int n,c;
		cin>>n>>c;
		int arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		sort(arr,arr+n);
		int l=1;
		int u=1e9;
		int ans=0;
		while(l<=u){
			int mid=(l+u)/2;
			int cow=1;
			int prev=arr[0];
			for(int g=1;g<n;g++){
				if(arr[g]-prev>=mid){
					cow++;
					prev=arr[g];
					if(c==cow) break;
				}
			}
			if(cow==c){
				ans=mid;
				l=mid+1;
			}else u=mid-1;
			
		}
		cout<<ans<<endl;
	}
	return 0;
}