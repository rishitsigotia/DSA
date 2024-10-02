 Doing by Moore voting Algo
 
 int majorityElement(vector<int>& nums) {
        int n = nums.size();

        int count = 0 ;  // if count =0 then time to choose new element;
        int element;

        for(int i = 0 ; i < n ;i++)
        {
            if(count == 0)
                element = arr[i];
            
            if(element == arr[i])
                count++;
            else
                count--;
        }
        int ans = 0;
        for(int i = 0 ; i< n ;i++)
        {
            if(arr[i] == element)
            {
                ans++;
            }
            if(ans > n/2)
                return element;
        }
        return -1;

    }


Time Complexity: O(N) + O(N), where N = size of the given array.
Reason: The first O(N) is to calculate the count and find the expected majority element. The second one is to check if the expected element is the majority one or not.

Note: If the question states that the array must contain a majority element, in that case, we do not need the second check. Then the time complexity will boil down to O(N).

Space Complexity: O(1) as we are not using any extra space.