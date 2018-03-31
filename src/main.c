#include <stdio.h>
#include "./core/data/ticket.c"
#include "./core/data/order.c"
#include "./core/data/user.c"

ticket_t_p init_tickets;
user_t_p init_users;
order_t_p init_order;

int main(int argc, char* argv[])
{
    // 初始化需要的变量
    int op;
    // 初始化三个链表 从文件读取
    init_tickets = create_tickets();
    init_users = create_users();
    init_order = create_order();
    // 从文件读取数据
    ticket_read(init_tickets);
    order_read(init_order);
    user_read(init_users);
    // 主进程
    while(1)
    {
        printf("welcome! 你想做什么？\n");
        printf("1. 注册");
        printf("2. 登录");
        printf("3. 任意键退出");
        scanf("%d", &op);
            switch(op)
            {
            case(1): {
                // do sign up
                break;
            }
            case(2): {
                // do sign in
                break;
            }
            default: {
                // programe exit point
                // 保存链表到文件
                ticket_write(init_tickets);
                order_write(init_order);
                user_write(init_users);
                return 0;
            }
        }
    }
    
}