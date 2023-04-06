#include <stdio.h>  
#include <stdlib.h>  
/* The below structure node is defined as a node of a binary tree consists  
of left child and the right child, along with the pointer next which points to the next node */  
struct node   
{  
    char info ;  
    struct node* l ;  
    struct node* r ;  
    struct node* nxt ;  
};  
struct node *head=NULL;  
/* Helper function that allocates a new node with the 
given data and NULL left and right pointers. */  
struct node* newnode(char data)  
{  
    struct node* node = (struct node*) malloc ( sizeof ( struct node ) ) ;  
    node->info = data ;  
    node->l = NULL ;  
    node->r = NULL ;  
    node->nxt = NULL ;  
    return ( node ) ;  
}  
void Inorder(struct node* node)   {  
    if ( node == NULL)  
        return ;  
    else  
    {  
    /* first recur on left child */  
    Inorder ( node->l ) ;  
    /* then print the data of node */  
    printf ( "%c " , node->info ) ;   
    /* now recur on right child */  
    Inorder ( node->r ) ;  
    }  
}    
void push ( struct node* x )  
{  
    if ( head == NULL )  
    head = x ;  
    else  
    {  
        ( x )->nxt = head ;  
        head = x ;  
    }  
}  
struct node* pop()  
{  
    // Poping out the top most [pointed with head] element  
    struct node* n = head ;  
    head = head->nxt ;  
    return n ;  
}  
int main()  
{  
    char t[] = { 'X' , 'Y' , 'Z' , '*' , '+' , 'W' , '/' } ;  
    int n = sizeof(t) / sizeof(t[0]) ;  
    int i ;  
    struct node *p , *q , *s ;  
    for ( i = 0 ; i < n ; i++ )   {  
        // if read character is operator then popping two  
        // other elements from stack and making a binary  
        // tree  
        if ( t[i] == '+' || t[i] == '-' || t[i] == '*' || t[i] == '/' || t[i] == '^' )   {  
            s = newnode ( t [ i ] ) ;  
            p = pop() ;  
            q = pop() ;  
            s->l = q ;  
            s->r = p;  
            push(s);  
        }  
        else {  
            s = newnode ( t [ i ] ) ;   
            push ( s ) ;  
        }  
    }  
    // printf("\nBinary Expression Tree of: %s", t);
    printf ( "\n The Inorder Traversal of Expression Tree: " ) ;  
    Inorder ( s ) ;  
    return 0 ;  
}  
