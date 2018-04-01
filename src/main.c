#include <stdio.h>
#include <time.h>
#include "./core/data/ticket.c"
#include "./core/data/order.c"
#include "./core/data/user.c"

// 重要全局变量
ticket_t_p init_tickets;
ticket_t_p index_tickets = NULL;
user_t_p init_users;
user_t_p index_user = NULL;
order_t_p init_order;
order_t_p index_order = NULL;

// 主要功能声明
void registe(user_t_p init_users, user_t_p index_user);
void login(ticket_t_p init_tickets, ticket_t_p index_tickets, user_t_p init_users, user_t_p index_user, order_t_p init_order, order_t_p index_order);
void admin(ticket_t_p init_tickets, ticket_t_p index_tickets, user_t_p init_users, user_t_p index_user, order_t_p init_order, order_t_p index_order);
void commen_user(ticket_t_p init_tickets, ticket_t_p index_tickets, user_t_p init_users, user_t_p index_user, order_t_p init_order, order_t_p index_order);

// 次要功能声明
void clear_screen(){
    printf("\033[2J");
}

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
    // set head
    init_tickets = init_tickets;
    init_order = init_order;
    init_users = init_users;
    //test print list
    user_t_p i = init_users;
    ticket_t_p j = init_tickets;
    order_t_p k = init_order;
    // while(i->next != NULL)
    // {
    //     printf("\t%d \t%d \t%d\n", i->id, i->phone, i->pw);
    //     i = i->next;
    // }
    // printf("--\n");
    // while(j->next != NULL)
    // {
    //     printf("\t%d \t%d \t%d\n", j->id, j->name, j->amount);
    //     j = j->next;
    // }
    // printf("--\n");
    // while(k->next != NULL)
    // {
    //     printf("\t%d \t%d \t%d\n", k->user_id, k->ticket_id, k->amount);
    //     k = k->next;
    // }
    // 主进程
    while(1)
    {
        int op;
        if(index_user == NULL) {
            printf("\033[37m\nwelcome! 你想做什么？\n\033[0m");
            printf("1. 注册\n");
            printf("2. 登录\n");
            printf("3. 任意键退出\n");
            scanf("%d", &op);
            clear_screen();
        } else {
            op = 2;
        }
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
                ticket_write(init_tickets->next);
                order_write(init_order->next);
                user_write(init_users->next);
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
        printf("欢迎您 %d\n", temp->phone);
        index_user = temp;
        if(index_user->phone == 123456)
        {
            // 管理员
            admin(init_tickets, index_tickets, init_users, index_user, init_order, index_order);
        } else {
            // 普通用户
            commen_user(init_tickets, index_tickets, init_users, index_user, init_order, index_order);
        }
        return;
    }
}

void admin(ticket_t_p init_tickets, ticket_t_p index_tickets, user_t_p init_users, user_t_p index_user, order_t_p init_order, order_t_p index_order)
{
    int op;
    clear_screen();
    printf("欢迎您，管理员。您想要做什么？\n");
    printf("1. 添加彩票\n");
    printf("2. 删除彩票\n");
    printf("3. 查询彩票\n");
    printf("4. 开奖\n");
    printf("5. 注销\n");
    scanf("%d", &op);
    switch(op){
        case(1): {
            clear_screen();
            index_tickets = insert_new_ticket(init_tickets);
            printf("请输入您想添加的彩票的信息");
            printf("名字?\n");
            scanf("%d", &(index_tickets->name));
            printf("发行数量?\n");
            scanf("%d", &(index_tickets->amount)); 
            printf("种类?\n");
            scanf("%d", &(index_tickets->type)); 
            printf("价格?\n");
            scanf("%d", &(index_tickets->price));
            printf("状态?\n");
            scanf("%d", &(index_tickets->status));
            index_tickets->time = 0;
            index_tickets->code = -1;
            printf("恭喜，添加成功!");
            break;
        }
        case(2): {
            clear_screen();
            int type;
            printf("您想删除哪一款彩票\n");
            scanf("%d", &type);
            index_tickets = get_ticket_by_type(init_tickets, type);
            delete_ticket_by_id(init_tickets, index_tickets->id);
            printf("删除成功! \n");
            break;
        }
        case(3): {
            clear_screen();
            int type;
            printf("您想查询哪一款彩票\n");
            scanf("%d", &type);
            ticket_t_p k = get_ticket_by_type(init_tickets, type);
            printf("彩票ID\t%d\t彩票名字\t%d\n彩票类型\t%d\t彩票价格\t%d\n开奖状态\t%d\t开奖时间\t%d\n发型总量\t%d\n--->\n", k->id, k->name, k->type, k->price, k->status, k->time, k->amount);
            break;
        }
        case(4): {
            clear_screen();
            type_t type;
            printf("您想要开奖的彩票类型是?\n");
            scanf("%d", &type);
            index_tickets = get_ticket_by_type(init_tickets, type);
            srand((unsigned) time(NULL));
            right_code code = rand() % 10001;
            index_tickets->code = code;
            index_tickets->status = 1;
            printf("本次 %d型 彩票开奖结果为【%d】", type, code);
            break;
        }
        case(5): {
            index_user = NULL;
            return;
            break;
        }
        default: {
            clear_screen();
            printf("输入有误. 退出\n");
            return;
        }
    }
}

void commen_user(ticket_t_p init_tickets, ticket_t_p index_tickets, user_t_p init_users, user_t_p index_user, order_t_p init_order, order_t_p index_order)
{
    int op;
    clear_screen();
    printf("您想要做什么？\n");
    printf("1. 查看个人信息\n");
    printf("2. 修改密码\n");
    printf("3. 查看中奖信息\n");
    printf("4. 购买彩票\n");
    printf("5. 充值\n");
    printf("6. 注销\n");
    scanf("%d", &op);
    switch(op){
        case(1): {
            clear_screen();
            printf("Id号\t%d\n电话号码\t%d\n剩余金额\t%d\n", index_user->id, index_user->phone, index_user->money);
            break;
        }
        case(2): {
            clear_screen();
            printf("请输入新密码");
            int new_pw, confrim_pw;
            scanf("%d", &new_pw);
            printf("请再次输入一次");
            scanf("%d", &confrim_pw);
            if(new_pw == confrim_pw){
                printf("修改成功");
                index_user->pw = new_pw;
            }
            break;
        }
        case(3): {
            clear_screen();
            // 查看order中的信息.
            type_t type;
            printf("您要查看哪款彩票的开奖结果？\n");
            scanf("%d", &type);
            index_tickets = get_ticket_by_type(init_tickets, type);
            index_order = get_order_by_id(init_order, index_user->id, index_tickets->id);
            if(index_tickets->code < 0) {
                printf("还未开奖，请耐心等待\n");
            } else {
                if(index_tickets->code == index_order->code)
                    printf("恭喜中奖！\n");
                else
                    printf("很遗憾，您未中奖.\n");
            }
            break;
        }
        case(4): {
            clear_screen();
            // 在order中添加节点，并修改彩票类型
            type_t type;
            amount_t amount;
            code_t code;
            printf("您想买哪种类型的彩票?\n");
            scanf("%d", &type);
            printf("您想购买多少注？\n");
            scanf("%d", &amount);
            printf("您下注的号码是？ \n");
            scanf("%d", &code);
            // get tickets
            index_tickets = get_ticket_by_type(init_tickets, type);
            index_order = insert_new_order(init_order);
            money_t money = index_user->money - (amount * index_tickets->price);
            if(money < 0 || amount > index_tickets->amount)
            {
                printf("余额不足 或 购买基数太大。无法购买。\n");
            } else {
                // add data
                index_order->user_id = index_user->id;
                index_order->ticket_id = index_tickets->id;
                index_order->amount = amount;
                index_order->type = type;
                index_order->status = 0;
                index_order->code = code;
                // set data
                index_tickets->amount = (index_tickets->amount - amount);
                index_user->money = money;
                printf("恭喜，您已购买成功. 开奖时间为 %d\n 请关注抽奖。", index_tickets->time);
            }
            break;
        }
        case(5): {
            clear_screen();
            money_t money;
            printf("您想充值的金额为？");
            scanf("%d", &money);
            index_user->money = (index_user->money + money);
            return;
            break;
        }
        case(6): {
            index_user = NULL;
            return;
            break;
        }
        default: {
            clear_screen();
            printf("输入有误. 退出\n");
            return;
        }
    }
    return;
}