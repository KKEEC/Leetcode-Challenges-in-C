#include <stdlib.h>
#include <stdio.h>

struct ListNode 
{ 
    int val;
    struct ListNode *next; 
};

struct ListNode* createList(int arr[], int size) {
    if (size == 0) return NULL;

    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = arr[0];
    head->next = NULL;
    struct ListNode* current = head;

    for (int i = 1; i < size; i++) {
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = arr[i];
        newNode->next = NULL;
        current->next = newNode;
        current = newNode;
    }

    return head;
}

void printList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
}


struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) 
{
    struct ListNode merged;
    struct ListNode *current = &merged;
    merged.next = NULL;

    if (!list1)
        return (list2);
    if(!list2)
        return (list1);
    while(list1 && list2)
    {
        if (list1->val <= list2->val)
        {
            current->next = list1;
            list1 = list1->next;
        }
        else
        {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }
    if(list1)
        current->next = list1;
    else
        current->next = list2;

    return merged.next;
}

int main() {
    // Arrays to create lists
    int arr1[] = {1, 2, 4};
    int arr2[] = {1, 3, 4};

    // Create lists
    struct ListNode* list1 = createList(arr1, 5);
    struct ListNode* list2 = createList(arr2, 5);

    // Merge lists
    struct ListNode* mergedList = mergeTwoLists(list1, list2);

    // Print merged list
    printList(mergedList);

    return 0;
}
