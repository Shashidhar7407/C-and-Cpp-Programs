#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<semaphore.h>
#inc de<pthread.h>

using namespace std;

sem_t mutex;
sem_t db;

void *db_object(void*);
void read_db();
void write_db();


pthread_t object[5];

int main()
{
    sem_init(&mutex,0,1);
    sem_init(&db,0,1);
    
    for(int i=0i<5;i++)
    {
            pthread_create(&object[i],NULL,db_object,(void*)"New Object");
    }
    
    for(int i=0i<5;i++)
    {
            pthread_join(&object[i],NULL,db_object,(void*)"New Object");
    }
    
