#include <iostream>
#include <stdlib.h>
#include <time.h>
/* 
there are something to be attention.
Fristly, the random number will be the same if you only use function rand(),
so it should work with function srand((unsigned)time(NULL)) */
void Swap(int* SwapOne, int* SwapTwo)
{
    int temp;
    temp = *SwapTwo;
    *SwapTwo = *SwapOne;
    *SwapOne = temp;
}
int RangdomInRange(int start, int end)
{
   srand( (unsigned)time( NULL ) ); 
   int RandomNum = rand();
   std::cout << "RandomNum:" << RandomNum << std::endl;
   int result = RandomNum % (end - start + 1) + start;
   return result;
}
int Parition1(int data[], int start, int end)
{
    if(data == nullptr || start < 0 || end < 0)
    {
        exit(1);
    }
    int index = RangdomInRange(start, end);
    std::cout << "indexVaule:" << index << std::endl;
    Swap(&data[index],&data[end]);
    int small = start -1;
    for(index = start; index < end; index++)
    {
        if(data[index]< data[end])
        {
            small++;
            if(small != index)
                Swap(&data[index], &data[small]);
       }
       
    }
    small++;
    Swap(&data[small], &data[end]);
    return small;
}
int Parition2(int data[], int start, int end)
{
    if(data == nullptr || start < 0 || end < 0 || start == end)
      return 0;
    
    int indexFront = start, indexBack = end;
    int indexBase = indexFront;
    while(indexFront != indexBack)
    {
        while(data[indexBack] > data[indexBase] )
        {
            indexBack --;
        }
        /* 
        the "indexFront" and "indexBack" may be equal when excuting the statement "indexBack--"  */
        if(indexFront == indexBack)
            break;
        Swap(&data[indexBase], &data[indexBack]);
        indexBase = indexBack;
        indexFront++;
        /* 
        the "indexFront" and "indexBack" may be equal when excuting the statement "indexFront++"  */
        if(indexFront == indexBack)
          break;
        while(data[indexFront] < data[indexBase])
        {
            indexFront++;
        }
        /* 
        the "indexFront" and "indexBack" may be equal when excuting the statement "indexFront++"  */
        if(indexFront == indexBack)
            break;
        Swap(&data[indexFront], &data[indexBase]);
        indexBase = indexFront;
        indexBack--;
    }
    return indexBase;
}
int QuickSort(int data[], int start, int end)
{
/*     for(int i = start; i <= end; i++)
    {
        std::cout << data[i] << std::endl;
    } */
     if(start == end)
       return 0;
     int indexParition = Parition2(data, start, end);
/*      if(indexParition == 3)
     {
         std::cout << "debug" << std::endl;
     } */
     if(indexParition > start)
        QuickSort(data, start, indexParition -1);
     if(indexParition < end)
        QuickSort(data, indexParition + 1, end);
}
int main()
{
    int data[10] = {6, 3, 10, 4, 8, 7, 98, 24, 4, 8};
    int length = 10;
    QuickSort(data, 0, length -1);
//    Parition2(data, 0, length -1);
    for(int i = 0; i < length; i++)
    {
        std::cout << data[i] << std::endl;
    }
    return 0;
}
