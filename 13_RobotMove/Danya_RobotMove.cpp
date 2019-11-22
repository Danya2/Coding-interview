/*
There are something to be attention
Fristly, you should inisial the value when you define the variable, for example,  in line 16, it will return a uncertain value if 
you don not inisial a value to the variable and the "number" is equal with "0" */
int movingCountCore(int threshold, int rows, int cols, int row, int col, bool* visited);
bool check(int threshold, int rows, int cols, int row, int col, bool* visited);
int getDigitSum(int number);

bool check(int threshold, int rows, int cols, int row, int col, bool* visited)
{
    if(row >= 0 && row < rows && col >= 0 && col < cols && visited[row * cols + col] == false && getDigitSum(row) + getDigitSum(col) <= threshold)
       return true;
    return false;   
}
int getDigitSum(int number)
{
    int digNum = 0, digSum = 0;
    while(number != 0)
    {
        digNum = number % 10;
        number = number / 10;
        digSum += digNum; 
    }
    return digSum;
}
int movingCountCore(int threshold, int rows, int cols, int row, int col, bool* visited)
{
    int count = 0;
    if(check(threshold, rows, cols, row, col, visited))
    {
        visited[row * cols + col] = true;
        count = 1 + movingCountCore(threshold, rows, cols, row - 1, col, visited) +
                    movingCountCore(threshold, rows, cols, row + 1, col, visited) +
                    movingCountCore(threshold, rows, cols, row, col - 1, visited) + 
                    movingCountCore(threshold, rows, cols, row, col + 1, visited) ;
    }
    return count;
    
}
int movingCount(int rows, int cols, int threshold)
{
    if(threshold < 0 || cols <= 0 || rows <= 0)
       return 0;
    bool* visited = new bool[rows * cols];
    for(int i = 0; i < rows * cols; i++)
    {
        visited[i] = false;
    }
    int count = movingCountCore(threshold, rows, cols, 0, 0, visited);
    delete[] visited;
    return count;
}
