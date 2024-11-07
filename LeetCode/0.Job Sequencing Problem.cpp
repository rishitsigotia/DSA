bool static cmp(Job a , Job b)
    {
        if(a.profit > b.profit)
            return true;
        return false;
    }

vector<int> JobScheduling(Job jobs[], int n) 
    {
        if(n == 1)
            return {1,jobs[0].profit};
        
        sort(jobs,jobs + n,cmp);
        int count =0 ;
        int profit = 0 ;
        vector<int>occ(100001,-1);
        
        for(int i = 0 ; i < n ;i++)
        {
            if(occ[jobs[i].deadline] == -1)
            {
                occ[jobs[i].deadline] = jobs[i].id;
                profit += jobs[i].profit;
                count++;
            }
            else
            {
                for(int j = jobs[i].deadline ; j > 0 ; j--)
                {
                    if(occ[j] == -1)
                    {
                        profit += jobs[i].profit;
                        count++;
                        occ[j] = jobs[i].id;
                        break;
                    }
                }
            }
        }
        return {count,profit};
        
    }