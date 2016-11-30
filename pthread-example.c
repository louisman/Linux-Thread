/*

Ref : https://github.com/jackzzjack/blogger

*/
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

/*
 * 在 thread_1 裡面執行一個無窮迴圈，並不斷印出 thread_1 訊息
 * 為了避免不斷的 loop，我們用 sleep function 在每次迴圈停 1 秒
 */
void *thread_1(void *argv)
{
	while(1)
	{
		sleep(1);
		printf("I am thread_1 (sleep 1 sec)\n");
	}
}
/*
 * 基本上和 thread_1 相同，但時間停留 2 秒
 */
void *thread_2(void *argv)
{
	while (1)
	{
		sleep(2);
		printf("I am thread_2 (sleep 2 sec)\n");
	}
}

int main()
{
	pthread_t t1, t2;//先宣告兩個 pthread 的變數
	int ret_1 ,ret_2;

	//計算main thread執行間隔時間
	struct timeval tv, tv2;
	unsigned long long start_utime = 0;
	unsigned long long end_utime = 0;

	//之後開始建立並執行這兩個 thread，這兩個 thread 分別執行上面 thread_1, thread_2 這兩個 function
	pthread_create(&t1, NULL, &thread_1, NULL);
	pthread_create(&t2, NULL, &thread_2, NULL);

	//而我們自己的 main thread 也同樣執行無窮迴圈，每次停留三秒 
	while(1)
	{
		gettimeofday(&tv,NULL);
		sleep(3);
		printf("I am main thread (sleep 3 sec)\n");
		gettimeofday(&tv2,NULL);
		printf("Main Thread Runtime %llu usec\n", (end_utime - start_utime));
	}
	return 0;
}
