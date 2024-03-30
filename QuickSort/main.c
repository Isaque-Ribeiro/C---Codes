/*
This code have the objective to ilustrate a quicksort. On the first line is required the number of itens to be sorted.
The second line get the numbers to be sorted.

This code also can show as the choice "pivo", to this metod of sort, can affect the eficient. In this way, is presented the diference in choose
the last member of array of numbers or the median, as the PIVO

The output of this code is the array sorted and how much steps is required to sort usind the last pivo, after the steps of median pivo. 
*/

#include "quicksort.h"

int main(){
  int len, *item1, *item2, begin, end;
  int median = 0, quick = 0;

  scanf("%i", &len);
  item1 = (int*)malloc(len*sizeof(int));
  item2 = (int*)malloc(len*sizeof(int));
  for(int i=0; i<len; i++){
    scanf("%i", &item1[i]);
    item2[i] = item1[i];
  }

  begin = 0;
  end = len-1;
  quick = EndQuickSort(item1, begin, end);
  median = MedianQuickSort(item2, begin, end);
  printf("Q%i\n", quick);
  printf("M%i", median);
  return 0;
}
