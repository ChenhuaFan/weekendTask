#include <stdio.h>
#include "../../core/data/ticket.c"


int show(ticket_t_p tickets) {
    ticket_t_p p = tickets;
    while(p != NULL) {
        printf("%p | %d | %p\n", p, p->id, p->next);
        p = p->next;
    }
}

void ticket_test()
{
    ticket_t_p tickets;
    ticket_t_p t_index;
    //
    printf("创建彩票方法测试\n");
    tickets = create_tickets();
    tickets->id = 1;
    printf("%p | %d | %p\n", tickets, tickets->id, tickets->next);
    //
    printf("新增彩票方法测试\n");
    t_index = insert_new_ticket(tickets);
    t_index->id = 2;
    printf("%p | %d | %p\n", t_index, t_index->id, t_index->next);
    //
    for(int i=3; i<20; i++) {
        t_index = insert_new_ticket(tickets);
        t_index->id = i;
        //printf("%p | %d | %p\n", t_index, t_index->id, t_index->next);
    }
    t_index = get_ticket_by_id(tickets, 19);
    printf("%p | %d | %p\n\n", t_index, t_index->id, t_index->next);

    show(tickets);
}

int main(int argc, char* argv[])
{
    printf("ticket unit test!\n");
    // unit test
    ticket_test();
    // end 
    return 0;
}