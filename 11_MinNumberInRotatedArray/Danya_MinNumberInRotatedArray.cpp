int MinInOrder(int* numbers, int index1, int index2)
{
    int length = index2 - index1 + 1;
    int MinValue = numbers[index1];
    for(int i = 0; i < length; i++)
    {
        if(MinValue >= numbers[i + 1])
            {
                MinValue = numbers[i + 1];
            }
    }
    return MinValue;
}
int Min_Salution1(int* numbers, int length)
{ 
    if(numbers == nullptr || length <=0)
     return 0;
    int* pFront = numbers;
    int* pBack = numbers + (length - 1); 
    while((pFront + 1) != pBack)
    {
        int midIndex = (length + 1) / 2;
        int* pMid = pFront + (midIndex - 1);
        if(*pMid > *pFront)
        {
            pFront = pMid + 1;
            length = pBack - pFront;
        }
        else 
        {
           pBack = pMid - 1;
           length = pMid - pFront; 
        }     
    }
    if(*pFront > *pBack)
      return *pBack;
    else return *pFront;
}

int Min_Salution2(int* numbers, int length)
{
    int index1 = 0, index2 = length - 1;
    int indexMid = 0;
    while(numbers[index1] >= numbers[index2])
    {
        if(index2 - 1 == index1)
        {
            indexMid = index2;
            break;
        }
        indexMid = (index2 - index1) / 2;
        if(numbers[index1] == numbers[indexMid] && numbers[indexMid] == numbers[index2])
           return MinInOrder();
        if(numbers[indexMid] >= numbers[index1])
           index1 = indexMid;
        if(numbers[indexMid <= numbers[index2])
           index2 = indexMid;
    }
    return numbers[indexMid];
}
