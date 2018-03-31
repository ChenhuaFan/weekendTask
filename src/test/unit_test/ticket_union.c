#include <stdio.h>
#include "../../core/data/ticket.h"

int main(int argc, char* argv[])
{
    printf("hello world!\n");
    // unit test
    ticket_t_p tickets = create_tickets();
    tickets->id = 1;
    printf("%p | %d", tickets, tickets->id);
    return 0;
}