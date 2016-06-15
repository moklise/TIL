//
//  dhmalloc.c
//  2yeon
//
//  Created by 민석 on 2016. 6. 13..
//  Copyright © 2016년 민석. All rights reserved.
//

#include<stdio.h>

typedef struct treeNode {
    char data; // 번호 받는 데이터
    struct treeNode* CNode[10]; // 각각의 번호 노드를 가리키는 링크
    char* Name; // 이름 노드를 가리키는 링크

}treeNode;

void menu();
void insert_phone_number(int*);
void insert_phone_name(char*);
void insert_phone(treeNode*, int*, char*);
void delete_phone_number(int*);
void delete_phone(treeNode*, int*, char*);
void search_phone_number(int*);
void search_phone(treeNode*, int*, char*);

int main()
{
    treeNode* root = (treeNode*)malloc(sizeof(treeNode));
    
    for(int i= 0 ; i < 10; i++){
        root->CNode[i] = NULL;
    }
    
    int phone[8];
    char* name = (char*)malloc(sizeof(char)*20);
    while (1) // 메뉴 출력위한 무한 루프
    {
        int choice;
        menu();
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                insert_phone_number(phone);
                insert_phone_name(name);
                insert_phone(root, phone, name);
                system("pause > NULL"); // 프로그램 일시 정지 (계속하려면 아무 키나 누르십시오... 출력 X)
                break;
            case 2:
                delete_phone_number(phone);
                delete_phone(root, phone, name);
                system("pause > NULL");
                break;
            case 3:
                search_phone_number(phone);
                search_phone(root, phone, name);
                system("pause > NULL");
                break;
            case 4:
                system("cls");
                printf("\n\n\t\t\t\t종료합니다\n");
                system("pause > NULL");
                return 0;
            default:
                printf("\t\t\t잘못입력하셨습니다. 다시 입력해주세요");
                system("pause > NULL");
                break;
        }
    }
}


void menu()
{
    system("cls");
    printf("\n\n\t\t\t=======휴대폰 생성 프로그램=======\n");
    printf("\t\t\t\t 1. 새 번호 생성\n");
    printf("\t\t\t\t 2. 기존 번호 삭제\n");
    printf("\t\t\t\t 3. 기존 번호 찾기\n");
    printf("\t\t\t\t 4. 종료\n");
    printf("\t\t\t==================================\n");
    printf("\t\t\t실행할 메뉴 : ");
}

void insert_phone_number(int* phone)
{
    system("cls");
    printf("\n\n\t\t\t===========새 번호 생성===========\n");
    printf("\t\t\t번호를 입력하세요 : 010)");
    int i;
    for (i = 0; i < 8; i++) {
        scanf("%1d", &phone[i]);
    }
}

void insert_phone_name(char* name)
{
    printf("\t\t\t이름을 입력하세요 : ");
    scanf("%s", name);
}

void insert_phone(treeNode* root, int* phone, char* name)
{
    treeNode* head;
    head = root;
    int i = 0;
    for (i = 0; i < 8; i++) {
        if (head->CNode[phone[i]] == NULL) {
            head->CNode[phone[i]] = (treeNode*)malloc(sizeof(treeNode));
            
            for(int j= 0 ; j < 10; i++){
                (head->CNode[phone[j]]) = NULL;
            }
            head->data = phone[i];
        }
        
        if (i != 7) {
            head = head->CNode[phone[i]];
        }
        else {
            head->Name = (char*)malloc(sizeof(char) * 20);
            strcpy(head->Name, name);
        }
    }
    printf("\n\t\t\t번호와 이름이 입력되었습니다.");
}

void delete_phone_number(int* phone)
{
    system("cls");
    printf("\n\n\t\t\t===========삭제 번호 입력===========\n");
    printf("\t\t\t번호를 입력하세요 : 010)");
    int i;
    for (i = 0; i < 8; i++) {
        scanf("%1d", &phone[i]);
    }
}

void delete_phone(treeNode* root, int* phone, char* name)
{
    treeNode* head;
    head = root;
    int i;
    if(head != NULL) {
        for (i = 0; i < 7; i++) {
            head = head->CNode[phone[i]];
        }
//        free(head->Name);
        printf("\n\t\t\t번호를 삭제하였습니다.");
    }
}

void search_phone_number(int* phone)
{
    system("cls");
    printf("\n\n\t\t\t===========기존 번호 입력===========\n");
    printf("\t\t\t번호를 입력하세요 : 010)");
    int i;
    for (i = 0; i < 8; i++) {
        scanf("%1d", &phone[i]);
    }
}


void search_phone(treeNode* root, int* phone, char* name)
{
    treeNode* head;
    head = root;
    int i;
    if (head != NULL) {
        for (i = 0; i < 7; i++) {
            head = head->CNode[phone[i]];
        }
        printf("\t\t\t입력하신 번호의 주인은 %s입니다.", head->Name);
    }
    else{
        printf("잘못입력됬습니다");
        exit(0);
    }
}