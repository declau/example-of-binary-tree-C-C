#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;



struct arvore_bin{
       int info;
       struct arvore_bin *esquerda;
       struct arvore_bin *direita;
};

arvore_bin *raiz;

arvore_bin *visita_arvore(arvore_bin *ra, arvore_bin *r, int pValor){
    if(r == NULL){
        r = (arvore_bin *) malloc (sizeof(arvore_bin));
        if (r == NULL){
            printf("\n\nError. No memory to allocate\n\n");
            system("pause");
            exit(0);
        }
        r->esquerda = NULL;
        r->direita = NULL;
        r->info = pValor;

        if(ra == NULL){
            printf("\nAdded this number is the root.\n");
            system("pause");
            return r;
        }
        if(pValor < ra->info){
            ra->esquerda = r;
            printf("\nThis number was added to the left of %d\n", ra->info);
        }else{
            ra->direita = r;
            printf("\nThis number was added to the right of %d\n", ra->info);
        }
        system("pause");
        return r;
    }
    if(pValor < r->info){
        visita_arvore(r, r->esquerda, pValor);
    }else{
        visita_arvore(r, r->direita, pValor);
    }
}

void incluir (void){
     int vValor;
     printf("\nEnter the value to insert: ");
     scanf("%d", &vValor);
     if (raiz == NULL){
        raiz = visita_arvore(raiz, raiz, vValor);
     }else{
        visita_arvore(raiz, raiz, vValor);
     }
}

void preordem(arvore_bin *pNo){
    if (pNo != NULL){
       printf("%d - \n", pNo->info);
       preordem(pNo->esquerda);
       preordem(pNo->direita);
    }
}

void posordem(arvore_bin *pNo){
    if (pNo != NULL){
       posordem(pNo->esquerda);
       posordem(pNo->direita);
       printf("%d - \n", pNo->info);
    }
}

void emordem(arvore_bin *pNo){
    if (pNo != NULL){
       emordem(pNo->esquerda);
       printf("%d - \n", pNo->info);
       emordem(pNo->direita);
    }
}

int listar(arvore_bin *pNo){
   int a=1,b=1;
   if(pNo != NULL){
      printf("TEM");
      printf("%d",pNo->info);
      a=listar(pNo->esquerda);///a==0 case left subtree==NULL
      b=listar(pNo->direita);///a==0 case right subtree==NULL
      if(b==0 && a==0){
          printf("()");///print  () if and only if it finds a leaf node
      }else if(b==0 && a!=0){
          ///it happens to find a node with the right leg null
          //printf("()");
      }else if(b!=0 && a==0){
         ///it happens to find a node with the left leg null
         //printf("()");
      }
      printf("TEM");///closes the representation of a root
   }else{
       return 0;//returns 0 case tree == NULL
   }
}
  int findMin(arvore_bin *raiz) {
    if(raiz == NULL) {
       printf("Error: Tree is empty\n" );
       return -1;
    }
    else if(raiz -> esquerda == NULL) {
         printf("- %d - \n", raiz->info);
		 return raiz-> info;
         
    }
    // Search in left subtree.
    return findMin(raiz-> esquerda);
   }
  int findMax(arvore_bin *raiz) {
    if(raiz == NULL) {
       printf("Error: Tree is empty\n" );
       return -1;
    }
    else if(raiz -> direita == NULL) {
         printf("- %d - \n", raiz->info);
		 return raiz-> info;
         
    }
    // Search in right subtree.
    return findMax(raiz-> direita);
   }
    int size(arvore_bin *raiz) {
        if(raiz != NULL) {
    	   printf("- %d - \n", raiz->info);
             return (size(raiz->esquerda) +1+ size(raiz->direita));    
        }
         else  {
		     return 0;      
         }
   }
int main (void){
    int op;
    raiz=NULL;
    while(1){
        system ("cls");
        printf ("\nMenu");
        printf ("\n\n 1. Insert");
        printf ("\n 2. Display Tree");
        printf ("\n 3. Display Tree in PreOrder");
        printf ("\n 4. Display Tree in PosOrder");
        printf ("\n 5. Display Tree in InOrder");
        printf ("\n 6. Display the Min value");
        printf ("\n 7. Display the Max value");
        printf ("\n 8. Display the size");
        printf ("\n 9. Exit");
        printf ("\n\n Enter your option: ");
        scanf ("%d",&op);
        fflush(stdin);
        switch (op) {
            case 1 : incluir();
                     break;
            case 2 : listar(raiz);
                     puts("\n\n");
                     system("pause");
                     break;
            case 3 : preordem(raiz);
                     system("pause");
                     break;
            case 4 : posordem(raiz);
                     system("pause");
                     break;
            case 5 : emordem(raiz);
                     system("pause");
                     break;
            case 6 : findMin(raiz);
                     system("pause");
                     break;
            case 7 : findMax(raiz);
                     system("pause");
                     break;
			case 8 : size(raiz);
                     system("pause");
                     break;                     
            case 9 : exit(0);
            default: printf ("\nOpcao errada");
                     system ("pause");
                     break;
        }
   }
}
