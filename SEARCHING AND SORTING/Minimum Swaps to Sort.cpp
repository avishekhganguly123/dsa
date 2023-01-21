// method 1 using map
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    int n=nums.size();
	    map<int,int>m;
	    
	    for(int i=0;i<n;i++){
	        m[nums[i]]=i;
	    }
	 
	  auto k=m.begin();
	  int cnt=0;
	  
	  for(int i=0;i<n;i++){
	        if(nums[i]!=k->first){
	            swap(nums[i],nums[k->second]);
	            m[k]=k->second;
	            k->second=i;
	            cnt++;
	        }
	        k++;
	        if(k==m.end()) break;
	    }
	    return cnt;
	}

    //method 2 using pair in vector
    int minSwaps(vector<int>&nums){
        vector<pair<int,int>>v;
	int n=nums.size();
	for(int i=0 ;i<n;i++){
	    
	   v.push_back({nums[i],i});
	    
	    
	}
	int ans=0;
	sort(v.begin(),v.end());
	
	for(int i=0 ;i<n;i++){
	    
	    if(i==v[i].second){
	        continue;
	    }
	    else{
	        ans++;
	       swap(v[i],v[v[i].second]);
	    
	        i--;//this is done to check the current element which is swapped .
	    }
	
	}
	return ans;
    }