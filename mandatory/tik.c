#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	int				number;
	struct s_list	*next;
	struct s_list	*previous;
}					t_list;

typedef struct s_stack
{
	int		stack_size;
	t_list	*top;
	t_list	*bottom;
}			t_stack;

typedef struct s_infos
{
	t_stack *a;
	t_stack *b; 
}			t_infos;

t_stack* new_stack() // constructs a new stack
{
    t_stack* s = (t_stack*)malloc(sizeof(t_stack));
    s->stack_size = 0;
    s->top = NULL;
    s->bottom = NULL;
    return s;
}

int is_empty(t_infos *infos)
{
    if(infos->a->top == NULL)
        return 1;
    else
        return 0;
}

int get_top(t_infos *infos){
    return infos->a->top->number;
}

void push_to_a(int x, t_infos *infos)
{
    t_list *temp = (t_list *)malloc(sizeof(t_list));
    if(is_empty(infos) == 1)
    {
        temp->number = x;
        temp->next = NULL;
        temp->previous = NULL;
        infos->a->top = temp;
        infos->a->stack_size++;
    }
    else
    {
        temp->number = x;
        temp->next = infos->a->top;
        temp->previous = infos->a->top;
        infos->a->top->next = temp;
        infos->a->top = temp;
        infos->a->stack_size++;
    }
}

void pop_from_a(t_infos *infos)
{
    t_list *temp;
    if(infos->a->top == NULL) return;
    temp = infos->a->top;
    infos->a->top = infos->a->top->next;
    free(temp);
}

void print_stack(t_infos *infos)
{
    t_list *temp = infos->a->top;
    if(is_empty(infos) == 1)
    {
        printf("Stack is Empty\n");
        return;
    }

    printf("Top >> \n");
    while(temp != NULL)
    {
        printf("%d\n",temp->number);
        temp = temp->next;
    }
    printf("<< End\n\n");
}

// int main()
// {
//     t_infos *infos;
//     infos->a = new_stack();
//     infos->b = new_stack();
//     int choice = -1, enter = 0;
//      printf("--------- Welcome to Stach -------\n\n");

//     while(choice != 0)
//     {
//             printf("1. Push\n");
//             printf("2. Pop\n");
//             printf("3. What is Top ?\n");
//             printf("4. Is Stack Empty ?\n");
//             printf("5. Print Stack\n");
//             printf("6. Print Stack size :\n");

//             printf("Choice: ");

//             scanf("%d",&choice);
//             printf("\n");

//             switch(choice)
//             {

//             case 1: printf("Enter the number for Push\n");
//                     scanf("%d",&enter);
//                     push_to_a(enter, infos);
//                     break;

//             case 2: pop_from_a(infos);
//                     printf("It's popped!\n");
//                     break;

//             case 3: enter = get_top(infos);
//                     printf("Top is = %d\n",enter);
//                     break;

//             case 4: enter = is_empty(infos);
//                     if(enter == 1)
//                     printf("Yes, It's empty\n");
//                     else
//                     printf("Nope, It contains elements\n");
//                     break;

//             case 5: printf("Stack Elements: \n");
//                     print_stack(infos);
//                     break;

//             case 6: printf("Size: \t");
//                     printf("%d\n",infos->a->stack_size);
//                     break;

//             default : printf("Enter numbers between 1 and 5 !");
//                       break;
//             }
//     }

//   return 0;
// }

