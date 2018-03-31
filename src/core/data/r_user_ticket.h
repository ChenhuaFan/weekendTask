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
typedef struct __ticket__
{
    user_key_t user_id;
    ticket_key_t ticket_id;
    amount_t amount;
    type_t type;
    status_t status;
    code_t code;
    struct __ticket__ *next;
}r_ticket_user_t, *r_ticket_user_t_p;

// 主要方法定义
// 创建新的订单链表
r_ticket_user_t_p create_tickets(void);

// 通过ID 得到订单记录
r_ticket_user_t_p get_ticket_by_id(r_ticket_user_t_p *r_ticket_user, user_key_t user_id, ticket_key_t ticket_id);

// 通过ID 删除
user_key_t delete_ticket_by_user_id(r_ticket_user_t_p *r_ticket_user, user_key_t user_id);
ticket_key_t delete_ticket_by_ticket_id(r_ticket_user_t_p *r_ticket_user, ticket_key_t ticket_id);

// 添加一个新的订单
r_ticket_user_t_p insert_new_ticket(r_ticket_user_t_p *r_ticket_user);

// io
void write(r_ticket_user_t r_ticket_user);
r_ticket_user_t_p read(void);