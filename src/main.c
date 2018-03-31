#include <stdio.h>
#include "./core/data/ticket.c"
#include "./core/data/order.c"

void init()
{
    ticket_t_p tickets = create_tickets();
    ticket_t_p t_index = NULL;
    order_t_p orders = create_order();
    tickets->id = 1;
    orders->ticket_id = 1;
    t_index = insert_new_ticket(tickets);
    t_index->id = 2;
    printf("t: %d; t->n: %d | o: %d\n", tickets->id, tickets->next->id, orders->ticket_id);
}

int main(int argc, char* argv[])
{
    printf("hello world!");
    init();
    return 0;
}