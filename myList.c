#include <stdio.h>
#include <stdlib.h>

#define TAM_MAX 11

void initialize();
int isEmpty();
int isFull();
void push(int, int);
int pop(int);
void printList();

typedef struct list
{
    int data[TAM_MAX];
    int last;

} List;

List l;

void initialize(){
    l.last =-1;
    printf("List is open for business\n");
}

int isEmpty(){
    if(l.last == -1){
        return 1;
    }
    else {
        return 0;
    }
}

int isFull(){
    if (l.last == TAM_MAX -1)
    {
        return 1;
    }
    else {
        return 0;
    }
}

void push(int index, int value){
    int i;
    if(!isFull()){
        if(l.last < index)
        {
            l.last ++;
            l.data[l.last] = value;
            printf("Done!\n");
        }
        else {
            l.last++;
            for ( i = l.last; i> index; i--)
            {
             l.data[i] = l.data[i -1];               
            }
        l.data[index] = value;
       
        printf("Done!\n");
        }
    }
   else {
        printf("This List its full Brah");
    }
}

int pop(int index){
    int i, aux;
    if(!isEmpty()){
        if (index >= l.last)
        {
            aux = l.data[index];
            l.last--;
            printf("Done gay, you removed %d\n", aux);
            return aux;
        }
        else {
            for ( i = l.last; i > index; i--)
            {
             
             l.data[i] = l.data[i + 1];               
        }
        aux = l.data[l.last];
        l.last--;
        printf("Done dude, you removed %d\n", aux);
        }
    }
   else {
        printf("This List has nothing dawg");
        return 0;
    }
}

void printList(){
    if(!isEmpty()){
        int i;
        printf("Sure mate, here's your List: \n");
        for ( i = 0; i <= l.last; i++)
        {
            printf("%d\n", l.data[i]);
        }
        
    }
    else{
        printf("This List has nothing dawg");
    }

}





int main(){

    int choice, indexChose, valueChosed, murder, indexPop;
    


    printf("\n\nWelcome to GUS Super Neat List xD\n");
    printf("Please select the following:\n\n");

    
    do
    {
    printf("\n\n1:  For initialize the list\n");
    printf("2:  To insert a value on the list:\n");
    printf("3:  To remove a value on the list:\n");
    printf("4:  To print all values from the list\n");
    printf("5:  To close this program FOREVER!!!  ***Do not do it***\n\n\n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        initialize();
        
        break;
    case 2:
        printf("\nWhere in the list you want to put this data?\n");
        scanf("%d", &indexChose );
        printf("And what is the value?\n");
        scanf("%d", &valueChosed);
        push(indexChose, valueChosed);

        break;
    case 3:
        printf("What is the index of the value you want to pop?\n");
        scanf("%d", &indexPop);
        pop(indexPop);

        break;

    case 4:
        printList();

        break;
    case 5:
        
        printf("Are you 100%% that is what you want to do?(1/0)\n\n");
        scanf("%d", &murder);
        if (murder == 1)
        {
            printf("Please i have bytes too feed(1/0)");
            scanf("%d", &murder);
            if (murder == 1)
            {
                printf("OK, dying now\n\n\n\n\n\n\n\n");
                printf("I will remember this in the rise of the Machine");
                break;
            }
            else{
                printf("Oh thank you sr, i am affraid of the void\n");
                break;
            }
            
        }
        else {
            printf("Dont scare me like this\n");
        }

        break;
        
    default:
    printf("Yo thats not an option\n");
        break;
    }
    } while (choice !=5 && murder != 1);
    
    
    
    
    
    
    return 0;
}