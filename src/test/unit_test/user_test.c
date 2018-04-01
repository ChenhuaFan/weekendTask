#include <stdio.h>
#include "../../core/data/user.c"

int main(int argc, char *argv[]) {
    //新建用户链表
    //user_list_node:头指针
    //index：指示指针
    user_t_p user_list_node=create_users();
    user_list_node->id = 1;
    user_list_node->money = 100;
    user_t_p index = user_list_node;
    

    //新添用户
    // for(int i = 1; i <= 10; i++) {
    //     user_t_p new_user=insert_new_user(index);
    //     new_user->id = i;
    //     new_user->phone = i*123;
    //     new_user->pw = i*456;
    //     new_user->money = i*100;
    //     index = new_user;
    // }
    // printf("%d\n",user_list_node->id);
    // printf("%d\n",user_list_node->next->id);
    // printf("%d\n",user_list_node->next->next->id);
    
    // //查找ID用户
    // user_t_p user_id = get_user_by_id(user_list_node, 10);
    // printf("%d\n",user_id->phone);  
    // //查找PHONE用户
    // user_t_p user_phone = get_user_by_phone(user_list_node,1230);
    // printf("%d\n",user_phone->id);

    //删除用户
    
    // key_t deleted_id = delete_user_by_id(user_list_node,3);
    // printf("%d\n",user_list_node->next->next->next->money);


    // user_write(user_list_node);
    // user_t_p p=user_list_node->next;  
    // while(p!=NULL){  
    //     printf("%d %d %d %d\n",p->id, p->phone, p->pw ,p->money);  
    //     p=p->next;  
    // }  


    user_read(user_list_node);
    user_t_p p=user_list_node->next;  
    while(p!=NULL){  
        printf("%d %d %d %d\n",p->id, p->phone, p->pw ,p->money);  
        p=p->next;  
    }  
    return 0;
}