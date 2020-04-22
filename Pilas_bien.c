#include <stdio.h>
#include <stdlib.h>

 struct agenda {
        int temp;
        int hum;
        int h;
        struct agenda *siguiente;
        };

 struct agenda *primero=NULL;

void Insertar();
void Ver();
void Eliminar();
void Vaciar();

 int main() {
     int x,op;
    while(x!=1){
        printf("\n======Menu Pila======\n1.-Insertar elemento \n2.-Ver la lista \n3.-Eliminar elemento \n4.-Vaciar \n5.-Salir del programa \n\n");
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
    printf("Temperatura: ");
    scanf("%d",&nw->temp);
    printf("Humedad: ");
    scanf("%d",&nw->hum);
    printf("Hora: ");
    scanf("%d",&nw->h);
          while (aux!=NULL) {
                if(aux->h == nw->h){
                 printf("Esta ocupado\n");
                 return 0;
                }
            aux = aux->siguiente;
      }
    nw->siguiente=primero;
    primero=nw;
}
void Ver() {
      struct agenda *aux;
      int p,c;
      aux = primero;
      printf("Desea \n1.-Ver un elemento \n2.-Ver pila completa\n");
      scanf("%d",&p);
      if(p==1){
        printf("Ingrese la hora en la que fue registrada\n");
        scanf("%d",&c);
        while (aux!=NULL) {
            if(aux->h == c){
            printf( "Temperatura: %d, Humedad: %d, Hora: %d\n", aux->temp,aux->hum,aux->h);
            }
        aux = aux->siguiente;
        }
      }if(p==2){
      if(primero != NULL){
      printf("\nEsta es la lista completa:\n");
      while (aux!=NULL) {
            printf( "Temperatura: %d, Humedad: %d, Hora: %d\n", aux->temp,aux->hum,aux->h);
            aux = aux->siguiente;
      }
      }else{
            printf( "\nLa lista esta vacia!!\n" );
      }
    }
    printf("Error al escoger");
    return 0;
}
void Eliminar(){
struct agenda *aux;
if((aux=malloc(sizeof(struct agenda)))==0){
       printf("No hay memoria disponible");
       return 0;
   }
    if(primero != NULL){
    aux=primero;
    printf( "Temperatura: %d, Humedad: %d, Hora: %d\n", aux->temp,aux->hum,aux->h);
    printf("Eliminado\n");
    primero=aux->siguiente;
    free(aux);
    if(primero==NULL){
        aux=NULL;
    }
    }else{
            printf( "\nLa Pila esta vacia!!\n" );
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
}
