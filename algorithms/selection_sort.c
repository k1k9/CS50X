#include <stdio.h>

void print_array(int a[], int n);
void selection_sort(int a[], int n);

int main(void)
{
  int a[] = {8,6,4,2,9,7,5,3,1,88,22,33,44,77,99,11,55,66,100};
  int n = sizeof(a) / sizeof(int);
  print_array(a, n);
  selection_sort(a, n);
}


void print_array(int a[], int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("%i, ", a[i]);
  }
  printf("\n");
}

void selection_sort(int a[], int n)
{
  int tmp, tmpi;
  for (int i = 0; i < n; i++)
  {
    tmp = i;
    for (int j = i + 1; j < n; j++)
    {
      if (a[j] < a[tmp])
      {
        tmp = j;
      }
    }
    // Swap
    tmpi = a[i];
    a[i] = a[tmp];
    a[tmp] = tmpi;
  }

  print_array(a, n);
}
