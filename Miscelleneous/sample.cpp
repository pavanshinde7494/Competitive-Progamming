#include<bits/stdc++.h>
using namespace std;


vector<int>job[1000];
int dp[1000];

// compare acc. to finish times
bool cmp(vector<int>p, vector<int>q)
{
    if(p[1] == q[1])
    {
        if(p[0] == q[0])
            return p[2]>q[2];
        else
            return p[0]<q[0];
    }
    return p[1]<q[1];
}


// compute last valid job to be consider
int trace(int curJob)
{
    for(int i = curJob-1;i>=0;i--)
    {
        if(job[curJob][0] >= job[i][1])
            return i;
    }
    return -1;
}

void maxProfit(int no_jobs)
{
   for(int curJob = 0 ; curJob < no_jobs ; curJob++)
   {
        // including curJob
        int includeJob = job[curJob][2];
        int lastJobTobeConsidered = trace(curJob);
        if(lastJobTobeConsidered != -1)
        {
            includeJob += job[lastJobTobeConsidered][2];
        }

        // exclude curJob
        int excludeJob = dp[curJob-1];

        // calculating given sub problem
        dp[curJob] = max( includeJob , excludeJob );
   }
}


int main()
{
    int no_jobs;
    cin>>no_jobs;
    for(int i=0;i<no_jobs;i++)
    {
        // Taking input for start time , end time and profit for each job
        int st , et , profit ;
        cin>>st>>et>>profit;
        job[i].push_back(st) ; job[i].push_back(et) ; job[i].push_back(profit);
    }

    // sorted acc. to their finish times
    sort(job , job + no_jobs , cmp);

    maxProfit(no_jobs);

    cout<<dp[no_jobs-1];
}
