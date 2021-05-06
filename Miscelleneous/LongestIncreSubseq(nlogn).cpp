int longestSubsequence(int n, int a[])
    {
       // your code here
       vector<int>seq;
       vector<int>index;
       int track[n];
       
       memset(track,-1,sizeof(track));
       
       seq.push_back(a[0]);
       
       index.push_back(0);
       
       int lastIndex = 0;
       
       for(int i=1;i<n;i++)
       {
           if(a[i] > seq[seq.size()-1])
           {
               track[i] = index[index.size()-1];
               seq.push_back(a[i]);
               index.push_back(i);
               lastIndex = i;
           }
           else
           {
               int place = lower_bound(seq.begin(),seq.end(),a[i]) - seq.begin();
               seq[place] = a[i];
               index[place] = i;
               if(place != 0)
                    track[i] = index[place-1];
           }
       }
      
       
       while(lastIndex!=-1)
       {
            cout<<a[lastIndex]<<" ";
            lastIndex = track[lastIndex];
       }
       cout<<"\n";
       return seq.size();
    }
