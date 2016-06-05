#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct LinkedListStructure{
    int data;
    struct LinkedListStructure * next;
} LinkedList;

void initializeList(LinkedList **head){
    *head = NULL;
}

LinkedList * getNode(){
    return (LinkedList*)malloc(sizeof(LinkedList));
}

int insertBack(LinkedList ** list, int value){
    LinkedList * node = getNode();
    LinkedList * aux;
    if(node == NULL)
        return 0; //error while inserting element
    node->data = value;
    node->next = NULL;
    if(*list == NULL){
        *list = node;
    } else{
        aux = *list;
        while (aux->next != NULL){
            aux = aux->next;
        }
        aux->next = node;
    }
    return 1;
}

LinkedList * checkCycle(LinkedList * head);

void traverse(LinkedList * l){
    LinkedList * aux = l;
    printf("\nTraversing...\n");
    LinkedList * element = checkCycle(l);
    while(aux != element){
        printf("%d\n", aux->data);
        aux = aux->next;
    }
    if (element != NULL){
        printf("%d\n", element->data);
        printf("%d...\n", element->next->data);
    }

}

void destructList(LinkedList ** list){
    LinkedList * aux = *list, *element;
    element = checkCycle(*list);
    while(aux != element){
        *list = (*list)->next;
        printf("Destructing: %d\n", aux->data);
        free(aux);
        aux = *list;
    }
    if(element!=NULL){
        printf("Destructing: %d\n", element->data);
        free(element);
    }
}

LinkedList * findElementOcurrence(LinkedList * list, int value){
    LinkedList * aux = list;
    while(aux != NULL){
        if(aux->data == value)
            return aux;
        aux = aux->next;
    }
    printf("\nElement not found, make sure that the list isn't empty or that the element that you are looking for really exists.\n");
    return NULL;
}

void makeCycle(LinkedList ** list, LinkedList ** element){
    if(*list == NULL){
        printf("List is empty.");
    }
    else{
        LinkedList * aux = *list;
        while(aux->next != NULL){
            aux = aux->next;
        }
        aux->next = *element;
    }
}

LinkedList * checkCycle(LinkedList * head){
    /**
    * return: 1 in case there is a cyle on the list
    *         0 in case there is no cycle
    */
    LinkedList * aux1 = head, * aux2;
    if(head == NULL){
        printf("List is empty.");
        return NULL;
    }
    if(aux1->next == head || aux1->next == aux1)
        return aux1;  // if the tail points to the head or to itself
    while(aux1!=NULL){
        aux2 = head;
        while(aux2 != aux1){
            if(aux1->next == aux2)
                return aux1;
            aux2 = aux2->next;
        }
        aux1 = aux1->next;
    }
    return NULL;  // there is no cycle
}

int main(){
    LinkedList *l;
    initializeList(&l);
    insertBack(&l, 3);
    insertBack(&l, 2);
    insertBack(&l, 4);
    insertBack(&l, 6);
    insertBack(&l, 2);
    LinkedList * c = findElementOcurrence(l, 4);
    if(c != NULL)
        makeCycle(&l, &c);
        
    if(checkCycle(l)){
        printf("The list has a cycle.\n");
    } else{
        printf("There is no cycle on the list.\n");
    }
    traverse(l);
    destructList(&l);
    return 0;
}
