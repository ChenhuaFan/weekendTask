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

// 通过type来选择彩票
ticket_t_p get_ticket_by_type(ticket_t_p tickets, type_t type)
{
    ticket_t_p P = tickets; 
    int val = 0; 
    while (P != NULL && P->type != type) {
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

void ticket_write(ticket_t_p tickets) {
    ticket_t_p p = tickets;
    FILE *w = fopen("tickets.txt","w");
    if(w==NULL)
    {
        printf("打开文件失败!");
        return; 
    }
    while(p)
    {
       fprintf(w,"%d %d %d %d %d %d %d\n",p->id, p->name, p->amount, p->type, p->price, p->status, p->time); 
        p=p->next;
    }
    fprintf(w,"\n");
    fclose(w);
}

void ticket_read(ticket_t_p tickets)
{
    int id,name,amount,type,price,status,time;
    ticket_t_p p = tickets;
    FILE *r = fopen("tickets.txt","r");
    if(r == NULL) {
        printf("打开文件失败！");
        return;
    }
    while(fscanf(r,"%d %d %d %d %d %d %d\n",&id, &name, &amount, &type, &price, &status, &time)!=EOF)
    {  
        p = insert_new_ticket(tickets);
        p->id=id;
        p->name=name;
        p->amount=amount;
        p->type=type;
        p->price=price;
        p->status=status;
        p->time=time;
    }
}
