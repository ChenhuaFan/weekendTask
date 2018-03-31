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

ticket_t_p get_ticket_by_id(ticket_t_p* tickets, uid_t id);
{
    while(*tickets->next != NULL)
    {
        if(tickets->id == id) 
        {
            return tickets;
        } 
        else 
        {
            // 返回错误code（在其他的资源文件中定义）
        }
        tickets = tickets->next;
    }
}

uid_t delete_ticket_by_id(ticket_t_p* tickets, uid_t id)
{
    ticket_t_p temp_node = NULL;
    while(*tickets->next != NULL)
    {
        if(*tickets->next->id == id)
        {
            // free next指针指向的节点
            temp_node = tickets->next->next;
            free(tickets->next);
            tickets->next = temp_node;
        }
        tickets = tickets->next;
    }
    // 返回错误code
}

ticket_t_p insert_new_ticket(ticket_t_p* tickets)
{
    while(1)
    {
        if(tickets->next == NULL)
        {
            tickets->next = (ticket_t_p)malloc(sizeof(ticket_t));  
            if (tickets->next == NULL)
            {  
                // 返回错误code（在其他的资源文件中定义）
            }
            else
            {
                tickets->next = NULL;
            }
            return tickets->next;
        }
    }
}