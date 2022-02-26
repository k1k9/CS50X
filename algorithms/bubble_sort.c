#include <stdio.h>

void print_array(int a[], int n);
void bubble_sort(int a[], int n);

int main(void)
{
  int a[] = {8,6,4,2,9,7,5,3,1,88,22,33,44,77,99,11,55,66,100};
  int n = sizeof(a) / sizeof(int);
  print_array(a, n);
  bubble_sort(a, n);
}

void print_array(int a[], int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("%i, ", a[i]);
  }
  printf("\n");
} 

// Bubble sort
void bubble_sort(int a[], int n)
{
  int tmp;
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (a[i] > a[j])
      {
        tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
      }
    }
  }
  print_array(a, n);
}
