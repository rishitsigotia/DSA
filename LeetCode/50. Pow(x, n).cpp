double myPow(double x, int n) 
{
    long np = n; 
    if(n < 0)
    {
        np = np*-1;   // here if you take n*-1 then it will cause overflow because max -ve "int" value,
                      // cannot be converted to postive int.
    }        
    
    double ans = 1;
    while(np)
    {
        if(np %2 ==0)  // 2 ^ 10
        {
            x = x * x;    // (4) = 2 x 2
            np= np/2;  // 4 ^ 5
        }
        else{            // 4^5 
            ans = x *ans;     // ans = 4 
            np = np-1;     // ( 4 ) (4^4)
        }
    }

    if(n < 0)
    {
        ans = 1/ans;
    }
    return ans;
}

Time Complexity: O(log n)

Space Complexity: O(1)