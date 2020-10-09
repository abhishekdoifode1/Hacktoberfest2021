//1234-20191817-5678-16151413-9101112-1211109-13141516-8765-17181920-4321
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    char name[50];
    int rate;
    struct node* next;
};
typedef struct node node_t;

void prints(node_t *head)
{
    node_t *temporary = head;
    while(temporary != NULL)
    {
        printf("Rate %i untuk judul buku ", temporary->rate);
        puts(temporary->name);
        temporary = temporary->next;
    }
    printf("\n");
}
node_t *create_node(const char *name, int value)
{
    node_t *result = malloc(sizeof(node_t));
    strcpy(result->name, name);
    result->rate = value;
    result->next = NULL;
    return result;
}

int main()
{
    node_t  n1,n2,n3;
    node_t *head;
    node_t *tmp;

    tmp = create_node("Sang Pangeran dan Jannisary Terakhir", 4);
    head = tmp;
    tmp = create_node("Supernova", 5);
    tmp->next = head;
    head = tmp;
    tmp = create_node("Aroma Karsa", 5);
    tmp->next = head;
    head = tmp;

    printf("Rating Novel Oleh Ahnaf :\n");
    prints(head);
    return 0;
}