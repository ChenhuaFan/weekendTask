#include <stdio.h>
#include "./core/data/ticket.c"
#include "./core/data/order.c"
#include "./core/data/user.c"

// 重要全局变量
ticket_t_p init_tickets;
ticket_t_p index_tickets;
user_t_p init_users;
user_t_p index_user;
order_t_p init_order;
order_t_p index_order;

// 主要功能声明
void registe(user_t_p init_users, user_t_p index_user);
void login(ticket_t_p init_tickets, ticket_t_p index_tickets, user_t_p init_users, user_t_p index_user, order_t_p init_order, order_t_p index_order);
void admin(ticket_t_p init_tickets, ticket_t_p index_tickets, user_t_p init_users, user_t_p index_user, order_t_p init_order, order_t_p index_order);
void common_user(ticket_t_p init_tickets, ticket_t_p index_tickets, user_t_p init_users, user_t_p index_user, order_t_p init_order, order_t_p index_order);

// 次要功能声明

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
                registe(init_users, index_user);
                break;
            }
            case(2): {
                login(init_tickets, index_tickets, init_users, index_user, init_order, index_order);
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

void registe(user_t_p init_users, user_t_p index_user)
{
    phone_t phone;
    pw_t pw;
    index_user = insert_new_user(init_users);
    printf("欢迎加入，请输入 电话 密码 以注册\n");
    scanf("%d %d", &phone, &pw);
    user_t_p temp = get_user_by_phone(init_users, phone);
    if(temp == NULL){
        // 没有注册过
        index_user->id = (get_last_user_Id(init_users) + 1);
        index_user->phone = phone;
        index_user->pw = pw;
        index_user->money = 0;
        printf("注册成功!\n");
    } else {
        // 注册过
        printf("您已经注册过了，请直接登录.\n");
        return;
    }
}

void login(ticket_t_p init_tickets, ticket_t_p index_tickets, user_t_p init_users, user_t_p index_user, order_t_p init_order, order_t_p index_order)
{
    phone_t phone;
    pw_t pw;
    printf("请输入 电话 密码 以登录\n");
    scanf("%d %d", &phone, &pw);
    user_t_p temp = user_auth(init_users, phone, pw);
    if(temp == NULL)
    {
        printf("账户认证失败\n");
        return;
    } else {
        printf("欢迎您 %d", temp->phone);
        index_user = temp;
        if(index_user->phone == 123456)
        {
            // 管理员
        } else {
            // 普通用户
        }
        return;
    }
}

void admin(ticket_t_p init_tickets, ticket_t_p index_tickets, user_t_p init_users, user_t_p index_user, order_t_p init_order, order_t_p index_order)
{
    int op;
    printf("欢迎您，管理员。您想要做什么？");
    printf("1. 添加彩票\n");
    printf("2. 删除彩票\n");
    printf("3. 查询彩票\n");
    printf("4. 彩票排序\n");
    printf("5. 彩票状态查询\n");
    printf("6. 注销\n");
    scanf("%d", &op);
    switch(op){
        case(1): {
            
            break;
        }
        case(2): {

            break;
        }
        case(3): {

            break;
        }
        case(4): {

            break;
        }
        case(5): {

            break;
        }
        case(6): {

            break;
        }
        default: {
            printf("输入有误. 退出\n");
            return;
        }
    }
}

void commen_user(ticket_t_p init_tickets, ticket_t_p index_tickets, user_t_p init_users, user_t_p index_user, order_t_p init_order, order_t_p index_order)
{
    int op;
    printf("欢迎您，%d。您想要做什么？", index_user->phone);
    printf("1. 查看个人信息\n");
    printf("2. 修改密码\n");
    printf("3. 查看中奖信息\n");
    printf("4. 购买彩票\n");
    printf("5. 注销\n");
    switch(op){
        case(1): {

            break;
        }
        case(2): {

            break;
        }
        case(3): {

            break;
        }
        case(4): {

            break;
        }
        case(5): {

            break;
        }
        default: {
            printf("输入有误. 退出\n");
            return;
        }
    }
}