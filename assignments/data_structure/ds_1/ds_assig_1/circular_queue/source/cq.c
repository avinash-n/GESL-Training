#include "header.h"
f = 0;
r = -1;
count = 0;
int main()
{
        int choice;
        int element;

        printf("enter your choice\n1.enqueue\n2.dequeue\n3.display\n4.break\n");
        scanf("%d",&choice);

        switch(choice)
        {
                case 1 :

                                printf("enter element\n");
                                scanf("%d",&element);
                                enqueue(element);
                                main();
                                break;
                case 2 :


                                dequeue(queue);
                                main();
                                break;
                case 3:

                                display(queue);
                                main();
                                break;
                case 4 : break;
                default : printf("invalid choice\n");
        }
        return 0;
}
