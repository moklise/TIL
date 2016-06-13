//
//  dhmalloc.c
//  2yeon
//
//  Created by 민석 on 2016. 6. 13..
//  Copyright © 2016년 민석. All rights reserved.
//

#include <stdio.h>

typedef struct ABC {
    int data;
    struct ABC* next;
}AAA;

int main(void){
    AAA* a;
    AAA* b;
    AAA* head;
    
    a = (AAA*) malloc(sizeof(AAA));
    b = (AAA*) malloc(sizeof(AAA));
    a->data = 10;
    a->next = b; // *a = *b 이런 연산이 정확하게 이루어지려면 a, b 모두 할당되어있어야 한다.
    b->data = 20;
    
    head = a;
    
    printf("a : %d\n", a->data);
    printf("b : %d\n", b->data);
    
    printf("a->next->data : %d\n", (a->next->data));
    
    head = head->next;
    printf("head->data : %d", (head->data));
}

void delete_phone(treeNode* root, int* phone, char* name)
{
    treeNode* head;
    head = root;
    int i;
    for (i = 0; i < 6; i++)
    {
        if(head->CNode[phone[i]] != NULL)
        {
           head = head->CNode[phone[i]];
        }else{
            // 번호가 존재하지않음.
            // break;
        }
    }
    head = head->CNode[phone[7]];
    free(head->Name);
    printf("\t\t\t번호를 삭제하였습니다.");
}