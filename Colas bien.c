#include <stdio.h>
#include <stdlib.h>

 struct agenda {
        int codigo;
        char nombre[20];
        char asunto[50];
        struct agenda *siguiente;
        };

 struct agenda *primero, *ultimo=NULL;

void Insertar();
void Ver();
void Eliminar();
void Vaciar();

 int main() {
     int x,op;
    while(x!=1){
        printf("\n======Menu cola======\n1.-Insertar elemento \n2.-Ver la lista \n3.-Eliminar elemento \n4.-Vaciar \n5.-Salir del programa \n\n");
            printf("Escoga su accion ");
            scanf("%d",&op);
            switch(op){
                case 1:
                    Insertar();
                break;
                case 2:
                    Ver();
                break;
                case 3:
                    Eliminar();
                break;
                case 4:
                    Vaciar();
                break;
                case 5:
                    printf("Chao, buen dia :3\n");
                    x=1;
                break;
                default:
                    printf("Error\n");
                break;
        }
}
return 0;
}
void Insertar() {
struct agenda *nw,*aux;
aux=primero;
if((nw=malloc(sizeof(struct agenda)))==0){
       printf("No hay memoria disponible");
       return 0;
   }
    printf("\nNuevo elemento:\n");
    printf("Nombre: ");
    scanf("%s",&nw->nombre);
    printf("Codigo de cliente: ");
    scanf("%d",&nw->codigo);
          while (aux!=NULL) {
                if(aux->codigo == nw->codigo){
                 printf("Esta ocupado\n");
                 return 0;
                }
            aux = aux->siguiente;
      }
    printf("Asunto: ");
    scanf("%s",&nw->asunto);
    if(primero==NULL){
        primero=nw;
        primero->siguiente=NULL;
        ultimo=nw;
    }else{
        ultimo->siguiente=nw;
        nw->siguiente=NULL;
        ultimo=nw;
    }
}
void Ver() {
      struct agenda *aux;
      int p,c;
      aux = primero;
      printf("Desea \n1.-Ver un elemento \n2.-Ver cola completa\n");
      scanf("%d",&p);
      if(p==1){
        printf("Ingrese el codigo de cliente\n");
        scanf("%d",&c);
        while (aux!=NULL) {
            if(aux->codigo == c){
            printf( "Nombre: %s, Codigo de cliente: %d, Asunto: %s\n", aux->nombre,aux->codigo,aux->asunto);
            }
        aux = aux->siguiente;
        }
      }
      if(primero != NULL){
      printf("\nEsta es la lista completa:\n");
      while (aux!=NULL) {
            printf( "Nombre: %s, Codigo de cliente: %d, Asunto: %s\n", aux->nombre,aux->codigo,aux->asunto);
            aux = aux->siguiente;
      }
      }else{
            printf( "\nLa lista esta vacia!!\n" );
      }
}
void Eliminar(){
struct agenda *aux;
if((aux=malloc(sizeof(struct agenda)))==0){
       printf("No hay memoria disponible");
       return 0;
   }
    if(primero != NULL){
    aux=primero;
    printf( "Nombre: %s, Codigo de cliente: %d, Asunto: %s\n", aux->nombre,aux->codigo,aux->asunto);
    printf("Eliminado\n");
    primero=aux->siguiente;
    free(aux);
    if(primero==NULL){
        aux=NULL;
        ultimo=NULL;
    }
    }else{
            printf( "\nLa cola esta vacia!!\n" );
        }

}
void Vaciar(){
struct agenda *aux;
if((aux=malloc(sizeof(struct agenda)))==0){
       printf("No hay memoria disponible");
       return 0;
   }
   while(primero!=NULL){
        aux=primero;
        primero=aux->siguiente;
        free(aux);
   }
  primero=NULL;
  ultimo=NULL;
}
