 
long long Fibonacci_Solution1(unsigned int n)
{
    long long FibonacciOne, FibonacciTwo, FibonacciResult;
    if(n == 1)
       return FibonacciOne = 1;
    if(n == 0)
       return FibonacciTwo = 0;
    for(int i = 2; i <= n; i++)  
    {
        FibonacciResult = FibonacciOne + FibonacciTwo;
        FibonacciTwo = FibonacciOne;
        FibonacciOne = FibonacciResult;
        
    }
    return FibonacciResult;
}
long long Fibonacci_Solution2(unsigned n)
{
    long long FibonacciOne = 1, FibonacciTwo = 0 , FibonacciResult;
    if(n == 1)
       return 1;
    if(n == 0)
       return 0;
    for(int i = 2; i <= n; i++)  
    { 
        FibonacciResult = FibonacciOne + FibonacciTwo;
        FibonacciTwo = FibonacciOne;
        FibonacciOne = FibonacciResult;
        
    }
    return FibonacciResult;
}
