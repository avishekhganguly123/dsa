string smallestWindow (string s, string p)
    {
       int n = s.size(); 
       int m = p.size();
       if(n < m) //if size of p is greater than n then return -1
           return "-1";
       
     int count = 0;  //isliye bnaya h taki mujhe baar baar map me jaa k element ki frequency na dekhni pde
      
       int len = INT_MAX;//length of the ans string 
       int start = 0;//start of the ans string
       
       unordered_map<char, int>mp;//to store the occurence of characters in string p 
       for(char c : p)
       {
           if (mp[c] == 0)
               count++;
           mp[c]++;
       }
       
       int j =0;//end of the window
       int i=0;//start of the window 
       
       while(j<s.size())
       {
           mp[s[j]]--;
           if(mp[s[j]]==0)  //jab b mera element map me zero hoga tb tb count--
               count--;
           
           if(count==0) //agr count zero h mtlb ki mere sare elements mil chuke h mujhe
           {
               while(count==0)
               {
                   if(len>j-i+1)
                   {
                       len=min(len,j-i+1);//updating length
                       start=i; //updating new start
                   }
                   mp[s[i]]++; //jo elements repeat ho rahe h unki frequency minus me chli gai hogi to m unhe remove ya neglect kr sakta hu
                   
                   if (mp[s[i]] > 0)//jase frequency 0 se jyada hui mtlb ki mujhe us elemnt ki ab jroort h to count++
                       count++;
                   
                   i++;
               }
           }
           j++;
       }
       if (len != INT_MAX)
           return s.substr(start, len);
       else
           return "-1";

    }