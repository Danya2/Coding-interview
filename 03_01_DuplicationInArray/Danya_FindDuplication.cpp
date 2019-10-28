
#include <iostream>
bool duplicate(int numbers[], int length, int *duplication)
/* there are something to be attention when coding the this function
 Fristly, checking  up the array if null and meeting the condition, such as the things done by the front two statement: "if" and "for" 
 secondly, the "return" using 
 thirdly, when swaping the numbers, it is not assignment statement but is to assign another "temp" variable 
 */
{
if(numbers == nullptr || length <=0)
{
    return false;
}
for(int i = 0; i < length; i++)
{
    if(numbers[i] < 0 || numbers[i] > length - 1)
    {
      return false;
    }
}
for (int i=0; i < length; i++)
{
      while(i != numbers[i])
      {
       if(i == numbers[numbers[i]])
       {
         *duplication = numbers[i];
         return true; /* it will return if any duplication num */
       }
       else 
       {
        /*  swap the numbers*/
           int temp = numbers[i];
           numbers[i] = numbers[temp];
           numbers[temp] = temp;
       }
      }
//      i++;
}
}
int main()
{
    int numbers[7] = {2,3,1,0,2,5,3};
    int duplication; 
    bool result = duplicate(numbers, 7, &duplication);
    std::cout << duplication << std::endl;
    return 0;
}
