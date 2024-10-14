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

