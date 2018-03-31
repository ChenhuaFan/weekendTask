/*
对于关系链表的相关定义
*/

typedef int user_key_t;
typedef int ticket_key_t;
typedef int amount_t;
typedef int type_t;
typedef int status_t;
typedef int code_t;

// 主要结构定义
typedef struct __order__
{
    user_key_t user_id;
    ticket_key_t ticket_id;
    amount_t amount;
    type_t type;
    status_t status;
    code_t code;
    struct __order__ *next;
}order_t, *order_t_p;

// 主要方法定义
// 创建新的订单链表
order_t_p create_order(void);

// 通过ID 得到订单记录
order_t_p get_order_by_id(order_t_p order, user_key_t user_id, ticket_key_t ticket_id);

// 通过ID 删除
user_key_t delete_order_by_user_id(order_t_p order, user_key_t user_id);
ticket_key_t delete_order_by_ticket_id(order_t_p order, ticket_key_t ticket_id);

// 添加一个新的订单
order_t_p insert_new_order(order_t_p order);

// 订单读写
void order_write(order_t_p order);
void order_read(order_t_p order);