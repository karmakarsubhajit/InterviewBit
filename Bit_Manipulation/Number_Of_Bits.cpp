// https://www.interviewbit.com/problems/number-of-1-bits/

// Time complexity:- O(p)     where p is no of bits in x
//Space complexity:- O(1)


int Solution::numSetBits(unsigned int A) {
  
    int c = 0;
    if(A==0)
        return 0;
    while(A!=0)
    {
        A =A&(A-1);
        c++;
            
    }
    return c;
}