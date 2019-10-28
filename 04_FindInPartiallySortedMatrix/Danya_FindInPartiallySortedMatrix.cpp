#include <iostream>
bool Find(int *matrix, int rows, int columns, int numbers )
{
  if (matrix == nullptr) 
     return false;
  int row = 0;
  int col = columns - 1;
  while (matrix[row  * columns + col] != numbers)
  {
      if ( matrix[row  * columns + col] > numbers)
          col-- ;
      else
          row ++;
      if (row == 3 && col == 0)
         return false;
  }

  return true;
}
int main()
{
  int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
  bool result = Find((int*)matrix, 4, 4, 5);
  std::cout<< result << std::endl;
}
