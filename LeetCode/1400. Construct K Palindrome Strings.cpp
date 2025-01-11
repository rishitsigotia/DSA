class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.length();
        if(n < k)
            return false;
        
        map<char,int>mp;
        for(auto it : s)
        {
            mp[it]++;
        }
        int odd_freq = 0;

        for(auto it :mp)
        {
            if(it.second%2)
                odd_freq++;
        }

        return odd_freq <= k;
    }
};

Here basically you have to get the intution 
it depends on the how many times you can split the string into palindrom

like the deciding factor is the string of odd frequency

Here
aabbccc ->  a is even frequency, b is even freqency but c is of odd.

so if k = 1 abcccba is a possibilty
k = 2 aabb + ccc 
k = 3 aa + bb + ccc
k = 4 a + bb + a + cc {many different combination can be there}

now if aaabbccc is there
at k = 1 no arrangment is possible to split the string
k = 2 aaa + cbcbc
k = 3 aaa + ccc + bb