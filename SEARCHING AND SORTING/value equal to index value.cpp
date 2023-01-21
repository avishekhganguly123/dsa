vector<int> valueEqualToIndex(int arr[], int n) {
	    // code here
	    vector<int>res;
	    for(int i=0;i<n;i++){
	        if((i+1)==arr[i]) res.push_back(arr[i]);
	    }
	    
	    return res;
	}