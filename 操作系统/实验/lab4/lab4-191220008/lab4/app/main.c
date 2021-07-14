#include "lib.h"
#include "types.h"

#define P sem_wait
#define V sem_post

void philosopher() {
	printf("philosopher\n");
	sem_t _forks[5] = {0};
	sem_t *forks[5] = {0};
	int ret = 0;
	for(int i = 0; i < 5; i++) {
		forks[i] = &_forks[i];
		ret = sem_init(forks[i], 1);
		if(ret == -1) {
			printf("Semaphore Initialization Error!\n");  
			return;  
		}
	}
	for(int i = 0; i < 4; i++) {
		ret = fork();
		if(ret == -1) {
			printf("Fork Error!\n");  
			return;  
		}
		if(ret != 0) {
			break;
		}
	}

	int pid = 0;
	pid = getpid() - 1;
	while(1) {
		printf("Philosopher %d: think\n", pid);
		sleep(128);
		if(pid % 2 == 0) {
			printf("Philosopher %d: pick up left fork\n", pid);
			P(forks[pid]);
			sleep(128);
			printf("Philosopher %d: pick up right fork\n", pid);
			P(forks[(pid + 1) % 5]); 
			sleep(128);
		} 
		else {
			printf("Philosopher %d: pick up right fork\n", pid);
			P(forks[(pid + 1) % 5]);
			sleep(128);
			printf("Philosopher %d: pick up left fork\n", pid);
			P(forks[pid]);
			sleep(128);
		}
		printf("Philosopher %d: eat\n", pid);
		V(forks[pid]);
		sleep(128);
		V(forks[(pid + 1) % 5]);
		sleep(128);
	}

	for(int i = 0; i < 5; i++) {
		sem_destroy(forks[i]);
	}

	return;
}

#define BUFFER_SIZE 6

void producer_consumer() {
	printf("producer_consumer\n");
	sem_t _mutex = 0;
	sem_t _full = 0;
	sem_t _empty = 0;
	sem_t *mutex = &_mutex;
	sem_t *full = &_full;
	sem_t *empty = &_empty;
	int ret = 0;
	ret = sem_init(mutex, 1);
	if(ret == -1) {
		printf("Semaphore Initialization Error!\n"); 
		return;  
	}
	ret = sem_init(full, 0);
	if(ret == -1) {
		printf("Semaphore Initialization Error!\n"); 
		return;  
	}
	ret = sem_init(empty, BUFFER_SIZE);
	if(ret == -1) {
		printf("Semaphore Initialization Error!\n"); 
		return;  
	}

	for(int i = 0; i < 4; i++) {
		ret = fork();
		if(ret == -1) {
			printf("Fork Error!\n");  
			return;  
		}
		if(ret != 0) {
			break;
		}
	}

	int pid = 0;
	pid = getpid() - 1;
	if(pid == 0) {
		while(1) {
			P(full);
			sleep(128);
			P(mutex);
			sleep(128);
			printf("Consumer  : consume\n");
			sleep(128);
			V(mutex);
			sleep(128);
			V(empty);
			sleep(128);
		}
	}
	else {
		while(1) {
			P(empty);
			sleep(128);
			P(mutex);
			sleep(128);
			printf("Producer %d: produce\n", pid);
			sleep(128);
			V(mutex);
			sleep(128);
			V(full);
			sleep(128);
		}
	}

	sem_destroy(mutex);
	sem_destroy(full);
	sem_destroy(empty);

	return;
}

void reader_writer() {
	printf("reader_writer\n");
	int readcount = 0;
	sem_t _writeblock = 0;
	sem_t _mutex = 0;
	sem_t *writeblock = &_writeblock;
	sem_t *mutex = &_mutex;
	int ret = 0;
	ret = sem_init(writeblock, 1);
	if(ret == -1) {
		printf("Semaphore Initialization Error!\n");  
		return;  
	}
	ret = sem_init(mutex, 1);
	if(ret == -1) {
		printf("Semaphore Initialization Error!\n");  
		return;  
	}

	for(int i = 0; i < 5; i++) {
		ret = fork();
		if(ret == -1) {
			printf("Fork Error!\n");  
			return;  
		}
		if(ret != 0) {
			break;
		}
	}

	int pid = 0;
	pid = getpid() - 1;
	if(pid >= 0 && pid <= 2) {
		while(1) {
			//printf("Reader %d: read request, total %d reader\n", pid, readcount);
			P(mutex);
			sleep(128);
			readcount = read();
			readcount++;
			write(readcount);
			if(readcount == 1) {
				P(writeblock);
			}
			V(mutex);
			printf("Reader %d: read, total %d reader\n", pid, readcount);
			sleep(128);
			P(mutex);
			sleep(128);
			readcount = read();
			readcount--;
			write(readcount);
			//printf("Reader %d: read over, total %d reader\n", pid, readcount);
			if(readcount == 0) {
				V(writeblock);
			}
			V(mutex);
			sleep(128);
		}
	}
	else {
		while(1) {
			//printf("Writer %d: write request\n", pid);
			P(writeblock);	
			printf("Writer %d: write\n", pid);
			sleep(128);
			//printf("Writer %d: write over\n", pid);
			V(writeblock);
			sleep(128);
		}
	
	}

	sem_destroy(writeblock);
	sem_destroy(mutex);
	
	return;
}

int uEntry(void) {
	
	// For lab4.1
	// Test 'scanf' 
	int dec = 0;
	int hex = 0;
	char str[6];
	char cha = 0;
	int ret = 0;
	while(1){
		printf("Input:\" Test %%c Test %%6s %%d %%x\"\n");
		ret = scanf(" Test %c Test %6s %d %x", &cha, str, &dec, &hex);
		printf("Ret: %d; %c, %s, %d, %x.\n", ret, cha, str, dec, hex);
		if (ret == 4)
			break;
	}
	
	// For lab4.2
	// Test 'Semaphore'
	int i = 4;

	sem_t sem;
	printf("Father Process: Semaphore Initializing.\n");
	ret = sem_init(&sem, 2);
	if (ret == -1) {
		printf("Father Process: Semaphore Initializing Failed.\n");
		exit();
	}

	ret = fork();
	if (ret == 0) {
		while (i != 0) {
			i --;
			printf("Child Process: Semaphore Waiting.\n");
			sem_wait(&sem);
			printf("Child Process: In Critical Area.\n");
		}
		printf("Child Process: Semaphore Destroying.\n");
		sem_destroy(&sem);
		exit();
	}
	else if (ret != -1) {
		while (i != 0) {
			i --;
			printf("Father Process: Sleeping.\n");
			sleep(128);
			printf("Father Process: Semaphore Posting.\n");
			sem_post(&sem);
		}
		printf("Father Process: Semaphore Destroying.\n");
		sem_destroy(&sem);
		exit();
	}

	// For lab4.3
	// TODO: You need to design and test the philosopher problem.
	// Note that you can create your own functions.
	// Requirements are demonstrated in the guide.
	
	// 注释掉前面的两个测试，并从下面选择需要进行测试的函数进行调用即可
	//philosopher();
	//producer_consumer();
	//reader_writer();
	
	return 0;
}
