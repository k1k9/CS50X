#include <stdio.h>

int main(void)
{
  // Basic conifg
  int array[] = {33, 122, 312, 8883, 123123, 3, 4, 5,9, 29, 10, 88, 31, 55};
  int array_length = sizeof(array) / sizeof(int);
  int wanted = 29;
  int wanted_index, tmp;

  // Sort array
  for (int i = 0; i < array_length; i++)
  {
    for (int j = i + 1; j < array_length; j++)
    {
      if (array[i] > array[j])
      {
        tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
      }
    }
  }

  // Binary search
  int start = 0;
  int end = array_length-1;
  int middle;

  while(start <= end)
  {
    middle = start + (end - start) / 2;

    if (array[middle] > wanted)
    {
      end = middle-1;
    }
    else if (array[middle] < wanted)
    {
      start = middle+1;
    }
    else
    {
      break;
    }

  }

  if (array[middle] == wanted)
  {
    printf("FOUND! array[%i] = %i and wanted is %i\n", middle, array[middle], wanted);
  }
  else
  {
    printf("Number %i isn not in this array!\n", wanted);
  }
}
