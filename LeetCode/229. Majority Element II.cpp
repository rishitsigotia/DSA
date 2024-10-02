vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();

        int count1 = 0  , count2 =0;

        int element1;
        int element2;

        for(int i = 0 ; i < n ; i++)
        {
            if(count1 == 0 && nums[i] != element2) // the second check is imp so that both don't have same value
            {
                count1 = 1;
                element1 = nums[i];
            }
            else if (count2 == 0 && nums[i] != element1)
            {
                count2 = 1;
                element2 = nums[i];
            }
            else if (element1 == nums[i])
            {
                count1++;
            }
            else if (element2 == nums[i])
            {
                count2++;
            }
            else
            {
                count1--;
                count2--;    
            }
        }
        count1 =0 ;
        count2 =0 ;
        vector<int>ans;
        for(int i = 0 ; i < n ;i++)
        {
            if(nums[i] == element1)
            {
                count1++;
            }
            else if (nums[i] == element2)
            {
                count2++;
            }
        }
        int mini = (int)n/3 + 1;

        if(count1 >= mini)
            ans.push_back(element1);
        if(count2 >= mini)
            ans.push_back(element2);

        return ans;
}


For using int(n / 3) + 1 instead of just floor(n / 3)

If n is the size of the array, then n / 3 is the threshold. For example, if n = 9, then n / 3 = 3. Thus, for an element to be a majority element, it must appear more than 3 times, which means at least 4 times.


Time Complexity: O(N) + O(N), where N = size of the given array.
Reason: The first O(N) is to calculate the counts and find the expected majority elements. The second one is to check if the calculated elements are the majority ones or not.

Space Complexity: O(1) as we are only using a list that stores a maximum of 2 elements. The space used is so small that it can be considered constant.