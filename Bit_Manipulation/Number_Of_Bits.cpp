// https://www.interviewbit.com/problems/number-of-1-bits/

// Time complexity:- O(p)     where p is no of bits in x
//Space complexity:- O(1)


int Solution::numSetBits(unsigned int A) {
      int c = 0;
    if(A==0)
        return 0;
    while(1)
    {
        int t =A&(A-1);
        c++;
        if(t==0)
            break;
        A=t;
            
    }
    return c;
}