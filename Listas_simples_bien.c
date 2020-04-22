#include <stdio.h>
#include <stdlib.h>

 struct agenda {
        int folio;
        char nombre[20];
        char telefono[12];
        struct agenda *siguiente;
        };

 struct agenda *primero, *ultimo;

void Registrar(struct agenda *q);
void Ver(struct agenda *q);
void Buscar(struct agenda *q);
void Eliminar(struct agenda *q);

 int main() {
     int x=0,op;
     primero = (struct agenda *) NULL;
     ultimo = (struct agenda *) NULL;
    while(x!=1){
        printf("\n========Menu========\n1.-Aumentar elemento \n2.-Buscar un elemento \n3.-Eliminar un elemento \n4.-Ver toda la lista \n5.-Salir del programa \n\n");
            printf("Escoga su accion ");
            scanf("%d",&op);
            switch(op){
                case 1:
                    Registrar(primero);
                break;
                case 2:
                    Buscar(primero);
                break;
                case 3:
                    Eliminar(primero);
                break;
                case 4:
                    Ver(primero);
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
 void Registrar(struct agenda *q) {
    struct agenda *nuevo,*aux;
    int bandera=0;
    aux=primero;
    if((nuevo=malloc(sizeof(struct agenda)))==0){
        printf("No hay memoria disponible");
        return 0;
    }
      printf("\nNuevo elemento:\n");
      printf("Folio: ");
      scanf("%d",&nuevo->folio);
            if(primero != NULL){
            while (aux != NULL && bandera != 1){
                if(nuevo->folio == aux->folio){
                printf("Esta ocupado\n");
                return 0;
                 bandera=1;
                }
                aux=aux->siguiente;
            }
        }
      printf("Nombre: ");
      scanf("%s",&nuevo->nombre);
      printf("Telefono: ");
      scanf("%s",&nuevo->telefono);
nuevo->siguiente = NULL;
if (primero==NULL) {
    primero = nuevo;
    ultimo = nuevo;
 }else{
     ultimo->siguiente = nuevo;
     ultimo = nuevo;
 }
 }
 void Ver(struct agenda *q) {
      struct agenda *auxiliar; /* lo usamos para recorrer la lista */
      auxiliar = primero;
      printf("\nEsta es la lista completa:\n");
      while (auxiliar!=NULL) {
            printf( "Folio: %d, Nombre: %s, Telefono: %s\n", auxiliar->folio,auxiliar->nombre,auxiliar->telefono);
            auxiliar = auxiliar->siguiente;
      }
 }
void Buscar(struct agenda *q) {
        struct agenda *actual;
        actual=primero;
        int bandera=0, buscador=0;
        printf("Ingrese el Folio\n");
        scanf("%d",&buscador);
        if(primero != NULL){
            while (actual != NULL && bandera != 1){
                if(actual->folio == buscador){
                 printf( "Folio: %d, Nombre: %s, Telefono: %s\n",actual->folio,actual->nombre,actual->telefono);
                 bandera=1;
                }
                actual=actual->siguiente;
            }
            if(!bandera){
                printf("\nNo encontrado\n");
            }
        }else{
            printf( "\nLa lista esta vacia!!\n" );
        }
  }
  void Eliminar(struct agenda *q){
        struct agenda *actual,*anterior;
        actual=primero;
        anterior=NULL;
        int bandera=0, buscador=0;
        printf("Ingrese el Folio que desee eliminar\n");
        scanf("%d",&buscador);
        if(primero != NULL){
            while (actual != NULL && bandera != 1){
                if(actual->folio == buscador){
                 printf( "Folio: %d, Nombre: %s, Telefono: %s\n",actual->folio,actual->nombre,actual->telefono);
                 if(actual==primero){
                    primero=primero->siguiente;
                 }else if(actual==ultimo){
                    anterior->siguiente =NULL;
                    ultimo=anterior;
                 }else{
                    anterior->siguiente=actual->siguiente;
                 }
                 printf("eliminado\n");
                 bandera=1;
                }
                anterior=actual;
                actual=actual->siguiente;
            }
            if(!bandera){
                printf("\nNo encontrado\n");
            }
        }else{
            printf( "\nLa lista esta vacia!!\n" );
        }
  }


