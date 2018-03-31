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
    user_t_p new_user_1=insert_new_user(index);
    new_user_1->id = 2;
    new_user_1->money = 200;
    index=new_user_1;
    //printf("%d\n",index->id);
    

    user_t_p new_user_2=insert_new_user(index);
    new_user_2->id = 3;
    new_user_2->money = 300;
    index=new_user_2;

    user_t_p new_user_3=insert_new_user(index);
    new_user_3->id = 4;
    new_user_3->money = 400;
    index=new_user_3;

    user_t_p new_user_4=insert_new_user(index);
    new_user_4->id = 5;
    new_user_4->money = 500;
    index=new_user_4;

    user_t_p new_user_5=insert_new_user(index);
    new_user_5->id = 6;
    new_user_5->money = 600;
    index=new_user_5;
 //   printf("%d\n",index->id);

    printf("%d\n",user_list_node->id);
    printf("%d\n",user_list_node->next->id);
    printf("%d\n",user_list_node->next->next->id);
    
    //查找用户
    //user_t_p user_id_node = get_user_by_id(user_list_node,3);
    //printf("%d",user_id_node->money);
    //p1rintf("%d",user_id_node->money);
    

    //删除用户
    
    key_t deleted_id = delete_user_by_id(user_list_node,2);
    printf("%d\n",user_list_node->next->next->money);


    return 0;
}