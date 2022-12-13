#include <stdio.h>

#include <sys/shm.h>

#include <sys/ipc.h> // Inter process communication

#include<string.h>



int main(){



void * shared_memory;



      //    key, sizeOFdata, Mode

int shmid = shmget((key_t)2345 ,1024,0666);





// attach the shared memroy

shared_memory = shmat(shmid,NULL,0);



printf("data from shared_memory : %s \n",(char*)shared_memory);



// detach from shared memory

shmdt(shared_memory);



return 0;

}

