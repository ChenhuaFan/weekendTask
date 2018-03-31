/*
本文件实现关于关系链表的具体方法
*/

#include "order.h"
#include <stdio.h>
#include <stdlib.h>

// 创建新的订单链表
order_t_p create_order(void)
{
    order_t_p temp_node = NULL;
    temp_node = (order_t_p)malloc(sizeof(order_t));
    if (temp_node == NULL)
    {
        // 返回错误code
    }
    else
    {
        temp_node->next = NULL;
    }
    return temp_node;
}

// 通过ID 得到订单记录
order_t_p get_order_by_id(order_t_p order, user_key_t user_id, ticket_key_t ticket_id)
{
    while(order->next != NULL)
    {
        if(order->user_id == user_id && order->ticket_id == ticket_id)
        {
            return order;
        }
        else
        {
            // 返回错误code
        }
        order = (order_t_p)order->next;
    }
    return NULL;
}

// 通过ID 删除
user_key_t delete_order_by_user_id(order_t_p order, user_key_t user_id)
{
    while(order->next != NULL)
    {
        if(order->user_id == user_id)
        {
            return user_id;
        }
        else
        {
            // 返回错误code
        }
        order = (order_t_p)order->next;
    }
    return -1;
}

ticket_key_t delete_order_by_ticket_id(order_t_p order, ticket_key_t ticket_id)
{
    while(order->next != NULL)
    {
        if(order->ticket_id == ticket_id)
        {
            return ticket_id;
        }
        else
        {
            // 返回错误code
        }
        order = (order_t_p)order->next;
    }
    return -1;
}

// 添加一个新的订单
order_t_p insert_new_order(order_t_p order)
{
    while(1)
    {
        if(order->next == NULL)
        {
            order->next = (order_t_p)malloc(sizeof(order_t));  
            if (order->next == NULL)
            {
                // 返回错误code（在其他的资源文件中定义）
            }
            else
            {
                order->next = NULL;
            }
            return (order_t_p)order->next;
        }
    }
}