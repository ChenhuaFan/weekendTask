/*
对于用户链表的相关定义
*/

typedef int id_t;
typedef int phone_t;
typedef int pw_t;
typedef int money_t;

// 主要结构定义
typedef struct __user__
{
    id_t id;
    phone_t phone;
    pw_t pw;
    money_t money;
    struct __user__ *next;
}user_t, *user_t_p;

// 主要方法定义
// 创建新的用户链表
user_t_p create_users(void);

// 通过用户ID 得到用户
user_t_p get_user_by_id(user_t_p *users, id_t id);

// 通过用户ID 删除用户
id_t delete_user_by_id(user_t_p *users, id_t id);

// 添加一个新的用户
user_t_p insert_new_user(user_t_p *users);

// io
void write(user_t_p *users);
user_t read(void);