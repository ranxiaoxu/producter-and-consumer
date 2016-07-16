#include"list.h"

node_p alloc_node(int data)
{
	node_p tmp = (node_p)malloc(sizeof(node_t));
	tmp->_data = data;
	tmp->_next = NULL;
	return tmp;
}
void list_init(node_pp head)
{
	*head = alloc_node(-1);
}
void del_node(node_p tmp)
{
	if(NULL != tmp){
		free(tmp);
		tmp = NULL;
	}
}
int is_empty(node_p head)
{
	if(NULL == head->_next)
		return 1;
	else
		return 0;
}
void list_insert(node_p head,int data)
{
	assert(head);
	node_p newnode = alloc_node(data);
	newnode->_next = head->_next;
	head->_next = newnode;
}
void list_remove(node_p head,int *data)
{
	assert(head);
	node_p tmp = NULL;
	if(head->_next != NULL){
		tmp = head->_next;
		head->_next = tmp->_next;
		*data = tmp->_data;
		del_node(tmp);
	}
}
void list_show(node_p head)
{
	node_p cur = head->_next;
	while(cur != NULL){
		printf("%d  ",cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}
