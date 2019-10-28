#include <iostream>
void ReplaceBlank(char string[], int length)
{
/* There are something to be attention:
Firstly, if it is C complier, it will not allow to define the variable in the block of "for" statement, but it can do if it is C++ complier. 
However.  the  sphere of the variable acting is limited to the "for" statement, such as "count" variable below. 
Secondly,  the index of array don't use the pointer 
Thirdly, as fot the variable 'A' of " A++", it not only need to assign the variable 'A' but also to insial a value to the 'A'! 
Forthly, in this code, the "string [index_behind--]" is different from the "string[--index_behind]" , one is to qoute firstly, then to  subtract 1(string [index_behind--]). 
the other is to subtract fristly 1, then to qoute(string [--index_behind])
 */
  int count = 0, i = 0;
  int index_front =0 ,  index_behind = 0;
  if (string == nullptr )
   return;
  while (string[i] != '\0')
  {
    index_front++; 
    if (string[i] == ' ')
         count++;
    i++;
  }
  index_behind = index_front + (count * 2);
  for (int i = 0; i < count; i++)
  {
  while (string[index_front] != ' ')
  {
     string[index_behind] = string[index_front];
     index_front--;
     index_behind--;
  }
  string[index_behind] = '0';
  string[--index_behind] = '2';
  string[--index_behind] = '%';
  index_front--;
  index_behind--;
  }
  std::cout<< string << std::endl;
}
int main()
{
    const long length = 100;
    char str[length] = "h  wfdsf ss f  gs ";
    ReplaceBlank(str,100);
    return 0;
}
