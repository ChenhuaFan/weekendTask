/*
本文件实现关于关系链表的具体方法
*/

#include "order.h"
#include <stdio.h>
#include <stdlib.h>

// 创建新的订单链表
order_t_p create_order(void)
{
    order_t_p temp_node = NULL;
    temp_node = (order_t_p)malloc(sizeof(order_t));
    if (temp_node == NULL)
    {
        // 返回错误code
    }
    else
    {
        temp_node->next = NULL;
    }
    return temp_node;
}

// 通过ID 得到订单记录
order_t_p get_order_by_id(order_t_p order, user_key_t user_id, ticket_key_t ticket_id)
{
    order_t_p P = order; 
    int val = 0; 
    while (P != NULL && (P->user_id != user_id || P->ticket_id != ticket_id)) {
        P = P->next;
    }
    return P;
}

// 通过ID 删除
user_key_t delete_order_by_user_id(order_t_p order, user_key_t user_id)
{
    order_t_p P = order;    
    while (P != NULL && P->user_id != user_id) {
        P = P->next;
    }
    order_t_p Tmp = P->next;
    P->next = Tmp->next;    
    free(Tmp);    
    Tmp = NULL;    
    return user_id;
}

ticket_key_t delete_order_by_ticket_id(order_t_p order, ticket_key_t ticket_id)
{
    order_t_p P = order;    
    while (P != NULL && P->ticket_id != ticket_id) {
        P = P->next;
    }
    order_t_p Tmp = P->next;
    P->next = Tmp->next;    
    free(Tmp);    
    Tmp = NULL;    
    return ticket_id;
}

// 添加一个新的订单
order_t_p insert_new_order(order_t_p order)
{
    order_t_p P = order;
    while (P->next != NULL)
    {
        P = P->next;
    }
    order_t_p Tmp = (order_t_p)malloc(sizeof(order_t));
    P->next = Tmp;
    Tmp->next = NULL;
    return (order_t_p)Tmp;
}

// 订单读写
void order_write(order_t_p order)
{
    order_t_p p = order;
    FILE *w =fopen("order.txt","w");
    if(w==NULL)
    {
        printf("打开文件失败!");
        return; 
    }
    while(p)
    {
        fprintf(w,"%d %d %d %d %d %d\n", p->user_id, p->ticket_id, p->amount, p->type, p->status, p->code);
        p=p->next;
    }
    fprintf(w,"\n");
    fclose(w);
}

order_t_p order_read(order_t_p order)
{
    
}