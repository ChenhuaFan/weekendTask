/*
对于彩票链表的相关定义
*/
typedef int key_t;
typedef int name_t;
typedef int amount_t;
typedef int type_t;
typedef int price_t;
typedef int status_t;
typedef int my_time_t;

// 主要结构定义
typedef struct __ticket__
{
    key_t id;
    name_t name;
    amount_t amount;
    type_t type;
    price_t price;
    status_t status;
    my_time_t time;
    struct __ticket__ *next;
}ticket_t, *ticket_t_p;

ticket_t_p tickets;

// 主要方法定义
// 创建新的彩票链表
ticket_t_p create_tickets(void);

// 通过彩票ID 得到彩票
ticket_t_p get_ticket_by_id(ticket_t_p tickets, key_t id);

// 通过彩票ID 删除
key_t delete_ticket_by_id(ticket_t_p tickets, key_t id);

// 添加一个新的彩票
ticket_t_p insert_new_ticket(ticket_t_p tickets);

// io
void ticket_write(ticket_t_p tickets);
ticket_t_p ticket_read(ticket_t_p tickets);