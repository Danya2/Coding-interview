#include <iostream>
#include <stdlib.h>
#include "Danya_Queue.h"
int main()
{
    CQueue<char> queue;

    queue.appendTail('a');
    queue.appendTail('b');
    queue.appendTail('c');

    char head = queue.deleteHead();
    std::cout << head << std::endl;
    head = queue.deleteHead();
    std::cout << head << std::endl;
    return 0;
}
