#include "../../core/data/order.c"
#include <stdio.h>
#include <stdlib.h>

int main(int args, char *argv[]) {
    order_t_p order_list = create_order();
    order_t_p order_index = NULL;
    
    // for(int i = 1; i<6;i++) {
    //     order_index = insert_new_order(order_list);
    //     order_index->user_id = i;
    //     order_index->ticket_id=i*3;
    //     order_index->amount=i*5;
    //     order_index->type=i*7;
    //     order_index->status=i*9;
    //     order_index->code=i*11;
    // }
    // order_write(order_list);
    
    order_read(order_list);
    
    order_t_p p=order_list->next;  
    while(p!=NULL){  
        printf("%d %d %d %d %d %d\n",p->user_id, p->ticket_id, p->amount ,p->type ,p->status ,p->code);  
        p=p->next;  
    }  
    return 0;
}