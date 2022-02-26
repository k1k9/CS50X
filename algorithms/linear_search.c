#include <stdio.h>
#include <cs50.h>


int main(void)
{
  int array[] = {1, 4, 5, 2, 44, 88, 213, 99, 234, 112, 9};
  int array_len = sizeof(array) / sizeof(int);
  int wanted = 9;
  int wanted_index = -1;

  // Linear search
  for (int i = 0; i < array_len; i++)
  {
    if (wanted == array[i])
    {
      wanted_index = i;
      break;
    }
  }

  // Check the results
  if (wanted_index > -1)
  {
    printf("Element %i was finded on %i(i=%i) position in array\n", wanted, wanted_index+1, wanted_index);
    return 0;
  }

  printf("Element %i was not finded in array\n", wanted);
  return 1;
}
