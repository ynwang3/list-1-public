#include <stdio.h>
#include <malloc.h>
#include <assert.h>

#include "list.h"

struct list *create_list()
{
    struct list *l = (struct list *)malloc( sizeof(struct list) );
    l->counter = 0; 
    return l;	
}
struct list *insert(struct list *l, int i, T e)
{
    int j;
    for(j=l->counter;i<j;j--){
        l->ele[j+1]=l->ele[j];
    }
    l->counter++;
    l->ele[i]=e;
    return l;
}

struct list *delete_at(struct list *l, int i)
{
    int j;
    for(j=i;j<l->counter;j++){
        l->ele[j]=l->ele[j+1];
    }
    l->counter--;
    return l;
}

int size( struct list *l )
{
    return l->counter;
}

T get( struct list *l, int i )
{
    return l->ele[i];
}

void replace( struct list *l, int i, T e )
{
    l->ele[i]=e;
}

int index( struct list *l, T e )
{
    int i;
    for(i=0;i<l->counter;i++)
        if(l->ele[i]==e)return i;
    return -1;    //not found
}
