// This is normal solution here , we are using 2 pointers
// Now in the second while loop if we see , we are incrementing l++ each time and poping element.
// this can be avoided in the second solution directly put it next to right and start.
int lengthOfLongestSubstring(string s)
{
    int n = s.length();
    int ans = 0;
    unordered_set<int> st;
    int l = 0, r = 0;
    while (r < n)
    {
        while (st.find(s[r]) != st.end())
        {
            st.erase(s[l]);
            l++;
        }
        ans = max(ans, r - l + 1);
        st.insert(s[r]);
        r++;
    }
    return ans;
}

/// Optimal solution
/// moving left to right instead of poping
/// using map instead of set, storing index also.
int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int left = 0 , right =0;
        map<int,int>mp;
        int ans = 0;
        while(right < n)
        {
            if(mp.find(s[right]) != mp.end())
            {
                left = max(mp[s[right]] + 1 , left); 
            }
            mp[s[right]] = right;
            ans = max(ans,right - left +1);
            right++;
        }
        return ans;
    }