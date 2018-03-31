/*
本文件实现关于用户的具体方法
*/

#include "user.h"
#include <stdio.h>
#include <stdlib.h>

//创建新的用户链表
user_t_p create_users(void) {
    user_t_p user_node=NULL;
    user_node = (user_t_p)malloc(sizeof(user_t));
    if(user_node==NULL) {
        exit(1);        
    }
    user_node->next=NULL;
    return user_node;
}

// 查找特定账号密码的用户
user_t_p user_auth(user_t_p users, phone_t phone, pw_t pw) {
    user_t_p p = users;
    do {
       if(p->phone == phone && p->pw == pw) {
            return p;
        }
        p=p->next;
    }
    while(p->next != NULL);
    return NULL;
}

// 得到最后的用户ID号
key_t get_last_user_Id(user_t_p users)
{
    user_t_p P = users;
    while (P->next != NULL)
    {
        P = P->next;
    }
    return P->id;
}

//根据手机号查找用户
user_t_p get_user_by_phone(user_t_p users, phone_t phone) {
    user_t_p P = users; 
    while (P != NULL) {
        if(P->phone == phone) {
            return P;
        } else {
            P = P->next;
        }
    }
    return NULL;
}

//根据Id查找用户
user_t_p get_user_by_id(user_t_p users, key_t id) {
    user_t_p p = users;
    while(p->next != NULL || p->id != id) {
        p=p->next;
    }
    if(p->id == id) {
        return p;
    }
    if(p->next == NULL) {
        printf("找不到该用户\n");
        return NULL;
    }  
    return NULL;
}

//删除制定ID用户
key_t delete_user_by_id(user_t_p users, key_t id) {
   
    user_t_p p = users;    
    while (p != NULL && p->id != id) {
        p = p->next;
    }
    user_t_p temp = p->next;
    p->next = temp->next;    
    free(temp);    
    temp = NULL;    
    return id;
}

//添加用户
user_t_p insert_new_user(user_t_p user) {
    user_t_p newuser;
    newuser = (user_t_p)malloc(sizeof(user_t));
    if(newuser == NULL) {
        printf("CREATE FAILED!");
        exit(1);
    }
    newuser->next = user->next;
    user->next = newuser;
    return newuser;
}

//用户读写

void user_write(user_t_p users) {
    user_t_p p = users;
    FILE *w =fopen("users.txt","w");
    if(w==NULL)
    {
        printf("打开文件失败!");
        return; 
    }
    while(p)
    {
        fprintf(w,"%d %d %d %d\n", p->id, p->phone, p->pw, p->money);
        p=p->next;
    }
    fclose(w);
}

void user_read(user_t_p users) {
    int id,phone,pw,money;
    user_t_p p = users;
    FILE *r = fopen("users.txt","r");
    if(r == NULL) {
        printf("打开文件失败！");
        return;
    }
    while(fscanf(r,"%d %d %d %d\n",&id, &phone, &pw, &money)!=EOF)
    {  
        p = insert_new_user(users);
        p->id=id;
        p->phone=phone;
        p->pw=pw;
        p->money=money;
    }
}
