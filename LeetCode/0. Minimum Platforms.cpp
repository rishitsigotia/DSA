int findPlatform(vector<int>& arr, vector<int>& dep) 
{
       int count =0;
       int max_count = 0;
       int n = arr.size();
       sort(arr.begin(),arr.end());
       sort(dep.begin(),dep.end());
       
       int i = 0 , j = 0;
       while(i < n)
       {
           if(arr[i] <= dep[j]) // the train is still there in the platform.
           {
               count++;
               i++;
           }
           else
           {
               count--; // if arr is greater than departure of other train, then we don't have to worry.
               j++;
           }
           max_count = max(max_count,count);
       }
       return max_count;
       
}

Time Complexity: O(nlogn) Sorting takes O(nlogn) and traversal of arrays takes O(n) so overall time complexity is O(nlogn).

Space complexity: O(1)  (No extra space used).