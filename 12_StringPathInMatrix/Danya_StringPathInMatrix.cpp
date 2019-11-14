/* 
there are something to be attention when coding the following functions
Fristly, the String style "adhsahdh" can be access with the way of array index. Experically, for the matrix, the index is "row * cols + col"
Secondly, for the access security, the same as the pointer, we should check up the index of array or matrix
Thirdly, for the recursion, you must and must write the condition of ending, for example, the code segment: 
if(str[pathLength] == '\0')
    {
        return true;
    }*/
bool hasPathCore(const char* matrix, int rows, int cols, int row, int col, const char* str, int& pathLength, bool* visited)
{
    if(str[pathLength] == '\0')
    {
        return true;
    }
    bool hasPath = false;
    if(row >= 0 && row <= rows && col >= 0 && col <= cols && matrix[row * cols + col] == str[pathLength] && !visited[row * cols + col])
    {
        visited[row * cols + col] = true;
        pathLength++;
        bool left = hasPathCore(matrix, rows, cols, row, col - 1, str, pathLength, visited);
        bool right = hasPathCore(matrix, rows, cols, row, col + 1, str, pathLength, visited);
        bool up =  hasPathCore(matrix, rows, cols, row - 1, col, str, pathLength, visited);
        bool down = hasPathCore(matrix, rows, cols, row + 1, col, str, pathLength, visited);
        hasPath = left || right || up || down;
        if(!hasPath)
        {
            pathLength--;
            visited[row * cols + col] = false;
        }   
    }
    return hasPath;
}
bool hasPath(const char* matrix, int rows, int cols, const char* str)
{
    bool* visited = new bool[rows * cols];
    memset(visited, 0, rows * cols);
    int pathLength = 0;
    for(int row = 0; row < rows; row++)
    {
      for(int col = 0; col < cols; col++)
       {
           /* attention: don't use the "return"  directly in order to continue the "for" cycle  */
            if(hasPathCore(matrix, rows, cols, row, col, str, pathLength, visited))
              return true;         
       }
    }
    return false;
}
