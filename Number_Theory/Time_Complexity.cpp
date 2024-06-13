/*
Time Complexity :
    Answer us how our code run time increase with respect to the input size 

O(N): Big O Notation 
N: No of operation our program does
n=100 our program takes 5 milliseconds(5ms)
n=1000 our program takes 10 milliseconds(10ms)

N=10
O(N)*10 - 10*10=100 ms
O(N^2)*10 - 100*10=500ms

(10*n)^2 = 100n^2 = 500ms


N=100
O(N)*10 - 100*10=1000ms


1second =1e8 operations can be done
(n^3) = n*n*n(100) = 100^3 = 1000000 = 1e6 = program is good enough
(n^3) = n*n*n(1000) = 1000^3 = 1e9 = program cant run

10000 = n^2  1e4

2 second = 2*1e8 

Time calculation:
    O(n^2+n)=O(n^2)

    n=10                        
    100+10=110
    10000+100=10100
    1000000+1000=1001000

As n increasing the contribution of n is less significant like 10 percent 1 percent 0 percent
When we increase the n more and more the value of n becomes more and more prominent 

1e6 if we can do 1e6 operation then 1e3 is nothing(we can do that as well)

    O(2n)=O(n)
    O(n^2+2n)=O(n^2)

*/

#include<iostream>
#include<vector>
#include<stdbool.h>
using namespace std;
int main()
{
    int n,m;


    for(int i=1;i<=n;i++)
    {
        //work done in O(1)
        // like addition subration like some simple operation
    }
    //O(N)
    //O(N) * Whatever we are doing inside = O(1)
    //O(N)*O(1)


    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            //work done in O(1)
            // like addition subration like some simple operation
        }
    }
    //O(N) * whatever we are doing inside loop = O(N)
    //O(N)*O(N) = N(N^2)

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            //work done in O(m)
       
        }
    }

     //O(N) * whatever we are doing inside loop = O(N) * whatever we are doing inside loop = O(M)
     //O(N)*O(N*M)
     //O(N^2*M) = O(N*N*M)



     // O(N^2) * O(M) = O(N^2*M)
     // O(N^2) * O(N) = O(N^2*N) = O(N^3)
     // O(N^2) * O(N^2) = O(N^4)
     // O(N^2) * O(N^2) * O(N^2) = O(N^6)
     // O(N^2) * O(N^2) * O(N^2) * O(N^2) = O(N^10)
     // O(N^2) * O(N^2) * O(N^2) * O(N^2) * O(N^2) = O(N^14)

    for(int i=1;i<=n;i++)
    {
        //work done in O(m)
        for(int j=1;j<=n;j++)
        {
            //work done in O(1)
       
        }
    }
    //O(N)*(O(M)+O(N))
    //O(N*(M+N))
    //O(N*M+N*N)

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            //work done in O(1)
        }
    }
    //O(N*(N+1)/2)
    //O(N*(N+1)/2) = O(N*(N+1)) = O(N*N) = O(N^2)
    /*
    n=5 = 15
    1
    1 2
    1 2 3
    1 2 3 4
    1 2 3 4 5
    */

   for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            //work done in O(m)
        }
    }
    //O(n*n)*O(m) = O(n*n*m)

    int sum=0;
    for(int i=1;sum<=n;i++)
    {
        sum+=i;
        //work done in O(1)
    }
    /*
    n=5 n=10
    1   1
    3   3
    6   6
        10
    */
   // loop will run k times
   // 1
   // 1 + 2
   // 1 + 2 + 3
   // 1 + 2 + 3 + 4
   // 1+ 2+ 3. ... +k > n
   // k*(k+1)/2 =n
   // k*(k+1) = n
   // (k*k) = n
   // k^2 = n
   // k = sqrt(n)
   // O(sqrt(n))


    for(int i=1;i<=n;i+=2)
    {
        //work done in O(1)
    }
    //O(n/2) = O(n)

    for(int i=1;i<=n;i*=2)
    {
        //work done in O(1)
    }
    //i=1 2 4 8 16 32 64 .. 2 ^i
    //k times run  
    //2^k >=n
    //k=log(n)
    //O(log(n))

    for(int i=n;i>=1;i/=2)
    {
        //work done in O(1)
    }
    /*
    n=10           n=20
    5 2 1 0      10 5 2 1 0
    1 - n = log(n)
    n - 1 = log(n)
    O(log(n))
    */

    int low=1,high=n;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        bool op;
        // work done in O(1) 
        if(op)
            low=mid+1;
        else
            high=mid-1;
    }
    /*
    N - distance
    N/2 - distance
    N/4 - distance
    N/6 - distance
    O(LogN)
    */


   /*
    Master Theorem - Recurence relation
        T(n)=T(n/2) + O(1)
        T(n)=O(log2(n))
        Master Theorem
        in half = log2(n)
   */ 

    int k=1;
    for(int i=1;i<=n;i++)
    {
        if(i>k)
        {
            // work done in O(k)
            k*=2;
        }
    }
    /*
    n= 10
    O(n)
    0
    i=2 ,0 , k=1 
    i=3 ,2 , k=2
    i=4 ,0 , k=4
    i=5 ,4 , k=8
    i=6 ,0 , k=8
    i=7 ,0 , k=8
    i=8 ,0 , k=8
    i=9 ,8 , k=16
    no of operations
    method - 1 
    
    p terms
    1+2+4+8+16....... 2^p  <=n
    1+2+4.....n/2 , n
    1+2+4..,n/4,n/2,n  = 2n
    Geometric Progression

    method - 2
    k is at max 2n
    1 + 2 + 4 + 8 + 16 ..... n
    1 2 4 8 
    n + n/2 + n/4 + n/8 ............. = 2n (using gp formula)
    sum of the series (Geometric progression)
    (Infinite series) a/(l-r)=n/(1-1/2) = 2*n  (a/l-r)

    // amortized time complexity = average time complexity 
    O(2n)+O(n)=>O(n)
    same complexity of vectors will push back for n pushes it will take 2n time
    //n=n^5, 5*1e5
    */

    for(int i=1;i<=n;i++)
    {
        //work done = 50 operations
    }
    /*
    When constants are smaller when constants become large and large then we have to include
    // 50*n
    //n =1e5 ,50*10^5 = 1e6
    //Constants
    5*n = O(n)
    n=1e5  = 5*1e5 = O(n)
    n=1e5  = 1e5*50 = 
    n=1e5  = 1e5*500 = 500*10^5  = 1e7
    n=1e5  = 1e5*5000 = 5000*1e5 = 1e8
    
    When Constants become large include it also
    Constant Factor 
    */

    /*
    1second = 1e8

    Sum of testcases

    testcase 1 n=10
    testcase 2 n=100
    testcase 3 n=1000
    testcase 4 n=100000
    
    sum of n <= 2*10^5   =>O(n*t) so that we can ignore t 
    2 4 5 ignore 20 40 50 take into consideration while time complexity
    
    n=100 , n^5 = 1e8
    n=1000 , n^2 = 1e8
    n=1e7  = O(n)
    
   */
    return 0;
}
