#include<stdio.h>
#include<math.h>

double factorial(int n);
double compute(double x, int n);

// function to calaculate factorial value

double factorial(int n)
    {
        if(n == 1)
        {
            return 1;
        }
        else
        {
            return n*factorial(n-1);
        }
        
    }

// function to calaculate the sum of series

double compute(double x, int n)
    {
        n = n-1;
        if(n == 0)
        {
            return x;
        }
        else
        {
            return x+pow(-1, n)*(2*n+1)*x/factorial(2*n+1);
        }

    }

int main()
{
    double x;
    int n;

    printf("Enter x value:  ");
    scanf("%lf", &x);
    printf("Enter n value:  ");
    scanf("%i", &n);

    printf("Result: %lf", compute(x, n));

    return 100;
}