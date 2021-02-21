/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {

    struct ListNode temp;
    struct ListNode* current = &temp;
    temp.val = 0; temp.next = NULL;
    int carry = 0, sum;
    while (l1 != NULL || l2 != NULL || carry != 0) {
        sum = (l1 == NULL ? 0 : l1->val) +
            (l2 == NULL ? 0 : l2->val) +
            carry;
        carry = sum / 10;
        sum = sum % 10;
        current->next = malloc(sizeof(struct ListNode));
        current->next->val = sum;
        current->next->next = NULL;
        current = current->next; //The first while will create the head node
        if (l1 != NULL) l1 = l1->next;
        if (l2 != NULL) l2 = l2->next;
    }
    return temp.next;
}

void main(void)
{
    //Input: l1 = [2, 4, 3], l2 = [5, 6, 4]
    //Output : [7, 0, 8]
    //Explanation : 342 + 465 = 807.
    struct ListNode* l1 = malloc(sizeof(struct ListNode)); //2
    l1->val = 2;
    l1->next = malloc(sizeof(struct ListNode));            //4
    l1->next->val = 4;
    l1->next->next = malloc(sizeof(struct ListNode));      //3
    l1->next->next->val = 3;
    l1->next->next->next = NULL;

    struct ListNode* l2 = malloc(sizeof(struct ListNode)); //5
    l2->val = 5;
    l2->next = malloc(sizeof(struct ListNode));            //6
    l2->next->val = 6;
    l2->next->next = malloc(sizeof(struct ListNode));      //4
    l2->next->next->val = 4;
    l2->next->next->next = NULL;

    struct ListNode* pRet;
    pRet=addTwoNumbers(l1, l2);
    printf("%d %d %d",
           pRet->val,
           pRet->next->val,
           pRet->next->next->val);
 }


