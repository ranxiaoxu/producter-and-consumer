#include"list.h"

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

node_p head = NULL;

void *product(void *arg)
{
	int done = 0;
	while(!done){
		pthread_mutex_lock(&lock);
		int data = rand()%1000;
		list_insert(head,data);
		printf("product...done...data is %d\n",data);
		pthread_mutex_unlock(&lock);
		printf("producter wake up consumer...\n");
		pthread_cond_signal(&cond);
		sleep(2);
	}
}

void *consume(void *arg)
{
	int done = 0;
	int data = 0;
	while(!done){
		pthread_mutex_lock(&lock);
		while(is_empty(head))
			pthread_cond_wait(&cond,&lock);
		list_remove(head,&data);
		printf("consume...done...date is %d\n",data);
		pthread_mutex_unlock(&lock);
		sleep(2);
	}
}
int main()
{
	list_init(&head);
//	int i = 0;
//	for(;i < 10;++i){
//		list_insert(head,i);
//		list_show(head);
//		sleep(1);
//	}
//	int ret = 0;
//	for(i = 0;i < 10;++i){
//		list_remove(head,&ret);
//		list_show(head);
//		sleep(1);
//	}
	pthread_t consumer,producter;
	pthread_create(&consumer,NULL,consume,NULL);
	pthread_create(&producter,NULL,product,NULL);
	pthread_join(consumer,NULL);
	pthread_join(producter,NULL);
	
	pthread_mutex_destroy(&lock);
	pthread_cond_destroy(&cond);
	return 0;
}
