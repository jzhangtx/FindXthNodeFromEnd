// FindXthNodeFromEnd.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class ListNode
{
public:
    int data;
    ListNode* next;
    ListNode(int data)
        : data(data)
        , next(nullptr)
    {}
};

ListNode* GetListFromInput(ListNode** ppHead, int count)
{
    if (count == 0)
        return nullptr;

    std::cout << "Enter " << count << " numbers of the list: ";
    ListNode* pTail = *ppHead;
    for (int i = 0; i < count; ++i)
    {
        int data = 0;
        std::cin >> data;
        if (*ppHead == nullptr)
        {
            *ppHead = new ListNode(data);
            pTail = *ppHead;
        }
        else
        {
            pTail->next = new ListNode(data);
            pTail = pTail->next;
        }
    }

    return pTail;
}

void PrintList(ListNode* pHead)
{
    if (pHead == nullptr)
        return;

    std::cout << pHead->data;
    pHead = pHead->next;

    while (pHead != nullptr)
    {
        std::cout << ", " << pHead->data;
        pHead = pHead->next;
    }
}

void FreeList(ListNode* pNode)
{
    if (pNode == nullptr)
        return;

    FreeList(pNode->next);
    delete pNode;
}

ListNode* GetNodeByIndex(ListNode* pHead, int index)
{
    if (index == -1)
        return nullptr;

    for (int i = 0; i < index; ++i)
    {
        pHead = pHead->next;
    }

    return pHead;
}

// Make the function recursive, so that it only traverse the list once
//  not sure if this is the fastest. Another solution would be count the
//  the total element in the list, then find the right node. Will need to
//  benchmark the two to figure out which solution is better. Maybe the
//  second is better, since it won't need waste time on prepairing the
//  parameters when calling this function
ListNode* XthNodeFromEnd(ListNode* head, int& x /*to use recursive, this value needs to be changed*/)
{
    if (head == nullptr)
    {   // start conting backword, need to clean the return value pNode
        return nullptr;
    }

    ListNode* pTemp = XthNodeFromEnd(head->next, x);
    if (pTemp != nullptr)   // if the node has been found, return it
        return pTemp;
    if (--x == 0)           // the node has not been found, need to count down
    {                       // here we go! we got it. need to store the node into
                            //  the return value
        return head;
    }

    // the node has not been found yet, return nullptr
    return nullptr;
}

int main()
{
    while (true)
    {
        int count = 0;
        std::cout << "Number of nodes in list: ";
        std::cin >> count;
        if (count <= 0)
            break;

        ListNode* pHead = nullptr;
        ListNode* pTail = GetListFromInput(&pHead, count);

        std::cout << "Enter number n to remove the nth element from the end: ";
        int index = -1;
        std::cin >> index;

        int xth = index;
        ListNode* pNode = XthNodeFromEnd(pHead, index);

        std::cout << "The " << xth << "th node from the end is " << (pNode ? pNode->data : -1);
        std::cout << std::endl;

        FreeList(pHead);
    }
}
