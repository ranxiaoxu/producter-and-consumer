#pragma once

#include<stdio.h>
#include<pthread.h>
#include<assert.h>
#include<stdlib.h>

typedef struct _node{
	int _data;
	struct _node *_next;
}node_t,*node_p,**node_pp;


node_p alloc_node(int data);
void list_init(node_pp head);
void del_node(node_p tmp);
int is_empty(node_p head);
void list_insert(node_p head,int data);
void list_remove(node_p head,int *data);
