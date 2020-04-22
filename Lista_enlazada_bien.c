#include <stdio.h>
#include <stdlib.h>

 struct agenda {
        int folio;
        char nombre[20];
        char telefono[12];
        struct agenda *siguiente;
        struct agenda *anterior;
        };

 struct agenda *primero, *ultimo;

void Registrar();
void Ver();
void Invertir();
void Eliminar();

 int main() {
     int x=0,op;
     primero = (struct agenda *) NULL;
     ultimo = (struct agenda *) NULL;
    while(x!=1){
        printf("\n========Menu========\n1.-Aumentar elemento \n2.-Ver la lista \n3.-Invertir lista \n4.-Eliminar un elemento \n5.-Salir del programa \n\n");
            printf("Escoga su accion ");
            scanf("%d",&op);
            switch(op){
                case 1:
                    Registrar();
                break;
                case 2:
                    Ver();
                break;
                case 3:
                    Invertir();
                break;
                case 4:
                    Eliminar();
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
void Registrar() {
struct agenda *n,*aux;
int i;
n=primero;
aux=primero;
printf("1.-Por la derecha\n2.-Por la izquierda\n");
scanf("%d",&i);
    if((n=malloc(sizeof(struct agenda)))==0){
        printf("No hay memoria disponible");
        return 0;
    }
    printf("\nNuevo elemento:\n");
    printf("Folio: ");
    scanf("%d",&n->folio);
          while (aux!=NULL) {
                if(aux->folio == n->folio){
                 printf("Esta ocupado\n");
                 return 0;
                }
            aux = aux->siguiente;
      }
    printf("Nombre: ");
    scanf("%s",&n->nombre);
    printf("Telefono: ");
    scanf("%s",&n->telefono);
if(primero==NULL)    {
    primero=n;
    primero->siguiente=NULL;
    primero->anterior=NULL;
    ultimo=primero;
}else if(i==1){
    ultimo->siguiente=n;
    n->siguiente=NULL;
    n->anterior=ultimo;
    ultimo=n;
}else{
    primero->anterior=n;
    n->anterior=NULL;
    n->siguiente=primero;
    primero=n;
}
}
void Ver() {
      struct agenda *auxiliar, *aux; /* lo usamos para recorrer la lista */
      auxiliar = primero;
      printf("\nEsta es la lista completa:\n");
      while (auxiliar!=NULL) {
            printf( "Folio: %d, Nombre: %s, Telefono: %s\n", auxiliar->folio,auxiliar->nombre,auxiliar->telefono);
            auxiliar = auxiliar->siguiente;
      }
 }
void Invertir() {
      struct agenda *auxiliar;
      auxiliar = ultimo;
      printf("\nEsta es la lista completa:\n");
      while (auxiliar!=NULL) {
            printf( "Folio: %d, Nombre: %s, Telefono: %s\n", auxiliar->folio,auxiliar->nombre,auxiliar->telefono);
            auxiliar = auxiliar->anterior;
  }
}
void Eliminar(){
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
                    primero->anterior=NULL;
                 }else if(actual==ultimo){
                    anterior->siguiente =NULL;
                    ultimo=anterior;
                 }else{
                    anterior->siguiente=actual->siguiente;
                    actual->siguiente->anterior=anterior;
                 }
                 printf("eliminado\n");
                 bandera=1;
                }
                anterior=actual;
                actual=actual->siguiente;
            }
            if(!bandera){
                //printf("\nNo encontrado\n");
            }else{
                free(anterior);
            }
        }else{
            printf( "\nLa lista esta vacia!!\n" );
        }
}

