#include <math.h>
int maxProductAfterCutting_solution1(int length)
{
    if(length <= 0)
      return 0;
    if(length == 1)
      return 0; 
    if(length == 2)
      return 1;
    if(length == 3)
      return 2;
    
    int max = 0;
    int* products = new int[length + 1];
    products[0] = 0;
    products[1] = 1;
    products[2] = 2;
    products[3] = 3;
    for(int i = 4; i <= length; i++)
    {
        int max = 0;
        for(int j = 1; j <= i / 2; j++)
        {
            int productSeg = products[j] * products[i - j];
            if(productSeg > max)
              max = productSeg;
            
        }
        products[i] = max;
    }
    max =  products[length];
    delete[] products;
    return max;

}
int maxProductAfterCutting_solution2(int length)
{
    if(length < 2)
      return 0;
    if(length == 2)
      return 1;
    if(length == 3)
      return 2;
    int timeOf3 = length / 3;
    if(length - timeOf3 * 3 == 1)
       timeOf3 -=1;
    int timeOf2 = (length - timeOf3 * 3) / 2;
    int max = pow(3, timeOf3) * pow(2, timeOf2);
    return max;
}
