/*
本文件实现关于彩票的具体方法
*/

#include "ticket.h"
#include <stdio.h>
#include <stdlib.h>

// 创建新的彩票链表
ticket_t_p create_tickets(void)
{
    ticket_t_p temp_node = NULL;
    temp_node = (ticket_t_p)malloc(sizeof(ticket_t));  
    if (temp_node == NULL)
    {  
        // 返回错误code（在其他的资源文件中定义）
    }
    else
    {
        temp_node->next = NULL;
    }
    return temp_node;
}

ticket_t_p get_ticket_by_id(ticket_t_p tickets, key_t id)
{
    ticket_t_p P = tickets; 
    int val = 0; 
    while (P != NULL && P->id != id) {
        P = P->next;
    }
    return P;
}

key_t delete_ticket_by_id(ticket_t_p tickets, key_t id)
{
    ticket_t_p P = tickets;    
    while (P != NULL && P->id != id) {
        P = P->next;
    }
    ticket_t_p Tmp = P->next;    
    P->next = Tmp->next;    
    free(Tmp);    
    Tmp = NULL;    
    return id;
}

ticket_t_p insert_new_ticket(ticket_t_p tickets)
{
    ticket_t_p P = tickets;
    while (P->next != NULL)
    {
        P = P->next;
    }
    ticket_t_p Tmp = (ticket_t_p)malloc(sizeof(ticket_t));
    P->next = Tmp;
    Tmp->next = NULL;
    return (ticket_t_p)Tmp;
}
