#include <stdio.h>
#include <stdlib.h>

//Fibonacci Numbers -> 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233...
//F(N) = F(N-1) + F(N-2)
//F(0) = 1, F(1) = 1

/*
fib(5)
+--fib(4)
|  +--fib(3)
|  |   +--fib(2)
|  |   |   +--fib(1)
|  |   |   +--fib(0)
|  |   +--fib(1)
|  +--fib(2)
|     +--fib(1)
|     +--fib(0)
+--fib(3)
   +--fib(2)
   |   +--fib(1)
   |   +--fib(0)
   +--fib(1)

We can show something like that in our Code.

*/

int counter;

int FibonacciWithRecursion(int N, int depth);
int FibonacciWithoutRecursion(int N);

int main()
{
    int i;
    for(i = 5; i <= 5; ++i)
    {
        counter = 0;
        int f = FibonacciWithRecursion(i, 0);
        printf("fib(%d) = %d, Number of Calls = %d\n", i, f, counter);
    }

    printf("------------------------------------------\n");

    int n = 47;
    for(i = 0; i < n; ++i)
    {
        printf("fib(%d) : %d\n",i,FibonacciWithoutRecursion(i));
    }

    return 0;
}

int FibonacciWithRecursion(int N, int depth)
{
    int i;
    for(i = 0; i < depth; ++i)
        printf("   ");
    printf("fib(%d)\n", N);

    counter++;
    if(N <= 1) return 1;
    return FibonacciWithRecursion(N-1, depth+1) + FibonacciWithRecursion(N-2, depth+1);
}

int FibonacciWithoutRecursion(int N)
{
    int number1 = 0;
    int number2 = 1;
    int nextNumber = 0;
    int i;

    if(N==0 || N==1)
        return N;

    for(int i = 2; i <= N; ++i)
    {
        nextNumber = number1 + number2;
        number1 = number2;
        number2 = nextNumber;
    }
    return nextNumber;
}
