#include <iostream>
#include <stdlib.h>
/* There are something to be attention when coding this segment
Firstly, the struct is a style with pointer, therefore, you must sure the struct
exits(adding the "if" statement) when quoting the struct.
                8
               / \
              6   10
             /\   /\
            5  7 9  10
 */
               
struct BinaryTreeNode {
    int m_nValue;
    BinaryTreeNode* m_pParent;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};
BinaryTreeNode* CreateBinaryTreeNode(int value)
{
    BinaryTreeNode* pNode = new BinaryTreeNode();
    pNode->m_nValue = value;
    pNode->m_pParent = nullptr;
    pNode->m_pLeft = nullptr;
    pNode->m_pRight = nullptr;

    return pNode; 
}
void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight)
{
   if(pParent != nullptr)
   { 
    pParent->m_pLeft = pLeft;
    pParent->m_pRight = pRight;
    if(pLeft != nullptr)
     pLeft->m_pParent = pParent;
    if(pRight != nullptr)
     pRight->m_pParent = pParent;  
   }  
}
void DestoryTree(BinaryTreeNode* pRoot)
{
    if(pRoot == nullptr)
    {
        BinaryTreeNode* pLeft = pRoot->m_pLeft;
        BinaryTreeNode* pRight = pRoot->m_pRight;
        delete pRoot;
        pRoot = nullptr;
        DestoryTree(pLeft);
        DestoryTree(pRight);
    }
}   
BinaryTreeNode* GetNext(BinaryTreeNode* pNode)
{
    if(pNode == nullptr)
    {
        exit(1);
    }
    if(pNode->m_pParent == nullptr)
      return pNode;
    if(pNode->m_pRight != nullptr)
    {
        BinaryTreeNode* pRight = pNode->m_pRight;
        while(pRight->m_pLeft != nullptr)
        {
            pRight = pRight->m_pLeft;
        }
        return pRight;
    }
    else if(pNode->m_pParent != nullptr)
    {
        BinaryTreeNode* pCurrent = pNode;
        BinaryTreeNode* pParent = pNode->m_pParent;
        if(pParent->m_pLeft == pNode)
          return pParent;
        while(pParent != nullptr && pParent->m_pRight == pNode)
        {
            pNode = pNode->m_pParent;
            pParent = pNode->m_pParent;
        }
        return pParent;
    }
}
int main()
{
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNode9 = CreateBinaryTreeNode(9);
    BinaryTreeNode* pNode11 = CreateBinaryTreeNode(11);

    ConnectTreeNodes(pNode8, pNode6, pNode10);
    ConnectTreeNodes(pNode6, pNode5, pNode7);
    ConnectTreeNodes(pNode10, pNode9, pNode11);

    BinaryTreeNode* result = GetNext(pNode5);
    std::cout << result->m_nValue << std::endl;

    return 0;
}
