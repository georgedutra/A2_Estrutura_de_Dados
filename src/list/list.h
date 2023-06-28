// Definição de nó
struct ListNode
{
    int iData;
    struct ListNode* ptrNext;
    struct ListNode* ptrPrev;
};

//Definição de lista
struct DoublyList
{
    struct ListNode* ptrHead;
    struct ListNode* ptrTail;
};