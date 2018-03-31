#include "../../core/data/order.c"
#include <stdio.h>
#include <stdlib.h>

int main(int args, char *argv[]) {
    order_t_p order_list = create_order();
    order_t_p order_index = NULL;
    /*
    for(int i = 1; i<6;i++) {
        order_index = insert_new_order(order_list);
        order_index->user_id = i;
        order_index->ticket_id=i*3;
        order_index->amount=i*5;
        order_index->type=i*7;
        order_index->status=i*9;
        order_index->code=i*11;
    }
    order_write(order_list);*/
    
    order_read(order_list);
    printf("%d\n",order_list->ticket_id);
    printf("%d\n",order_list->next->next->next->next->ticket_id);
    // printf("%d\n",order_list->next->next->ticket_id);

    return 0;
}