#include <iostream>
int countRange(const int *numbers, int length, int start, int end)
{
  int count = 0;
  for (int i=0; i < length; i++)
  {
    if (start <= numbers[i] && numbers[i] <= end )
    count++;
  }
  return count; 
}
int getDuplication(const int *numbers, int length)
/* There are something to be attention:
Firstly, the priority about the operator: the "((end - start) >> 1) + start " is difference from the "(end - start) >> 1 + start ";
the "+-" takes precedence over the ">>, <<"
*/
{
if (numbers == nullptr)
{
    return -1;
}
int start = 1;
int end;
end = length - 1;
while (end >= start)
{
    int middle = ((end - start) >> 1) + start;
    int count = countRange(numbers, length, start, middle);
    if (start == end )
    {
        if (count > 1)
          return start;
        else 
           break;
    }
    if (count == middle -start + 1)
      start = middle + 1;
    else 
       end = middle;
    
}

}
int main()
{
    int numbers[8]{2,3,5,4,3,2,6,7};
    int duplication = getDuplication(numbers, 8);
    std::cout << duplication << std::endl; 
}
