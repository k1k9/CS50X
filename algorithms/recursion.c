#include <stdio.h>

int factorial(int n);

int main(void)
{
  int n = 10;
  int f = factorial(n);
  printf("%i\n",f);
}

int factorial(int n)
{
  if(n > 1)
  {
    n = n * factorial(n-1);
  }
  return n;
}
