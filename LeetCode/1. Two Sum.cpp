// We can solve it differently  using hashing , 2 pointers and brute force 

---------------Hashing-----------------------------------
vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>mp;

        for(int i = 0 ; i < nums.size();i++)
        {
            int needed = target - nums[i];
            if(mp.find(needed) != mp.end())
            {
                return {mp[needed],i};
            }
            mp[nums[i]] = i;
        }
        return {};
    }

T.C = O(nlog(n)) for ordered map , for unordered best it can be O(n) and worst it can be O(n^2);
---------------Hashing-----------------------------------


---------------2 Pointers--------------------------------
vector<int> twoSum(vector<int>& nums, int target) 
{
sort(arr.begin(), arr.end());
    int left = 0, right = n - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target) {
            return "YES";
        }
        else if (sum < target) left++;
        else right--;
    }
}

This can be used to tell it is present or not , 
not optimal for index telling 

T.C = O(n)
---------------2 Pointers--------------------------------
