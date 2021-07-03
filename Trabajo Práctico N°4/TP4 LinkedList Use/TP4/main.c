#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

typedef struct{
char nombre[20];
int edad;
}eMascota;

void mostrarUnaMascota(eMascota* mascota);
void mostrarMascotas(LinkedList* this);
int mayorA2(void* pMascota);
int edadMayor(void* pMascota1,void* pMascota2);

int main()
{
    LinkedList* this=ll_newLinkedList();//creamos el linkedlist
    LinkedList* this2=NULL;//creamos otro linkedlist
    LinkedList* this3=NULL;//creamos otro linkedlist
    LinkedList* this4=NULL;//creamos otro linkedlist

    eMascota mascota1={"pepito",4};//creamos elementos para poner dentro del linkedlist
    eMascota mascota2={"panchito",2};
    eMascota mascota3={"lola",1};
    eMascota mascota4={"pedrito",8};
    eMascota mascota5={"chiki",6};

    eMascota mascota6={"flurfy",5};
    eMascota* mascotaAux;

    if(this==NULL)//comprobamos que el linkedlist no sea null
    {
        printf("hubo un problema");
        exit(1);
    }


    ll_add(this,&mascota1);//agregamos elementos dentro del linkedlist
    ll_add(this,&mascota2);
    ll_add(this,&mascota3);
    ll_add(this,&mascota4);
    ll_add(this,&mascota5);
    mostrarMascotas(this);//mostramos la lista



    this2=ll_clone(this);//clonamos la lista this
    ll_set(this2,1,&mascota6);//modificamos un elemento del la lista
    mascotaAux=ll_pop(this2,3);//la funcion pop elimina y devuelve un elemento
    printf("El nombre de la mascota eliminada es %s\n",mascotaAux->nombre);
    if(ll_contains(this2,&mascota4)){//vemos si mascota4 esta contenido dentro de la lista this2
        //si la mascota esta dentro de la lista mostramos en que pocision esta
        printf("Esta mascota esta contenida en la lista y su indice es %d",ll_indexOf(this2,&mascota4));
    }
    mostrarMascotas(this2);//mostramos la lista



    this3=ll_subList(this,1,4);//hacemos una sublista de this y se la asignamos a this3
    ll_remove(this3,0);//eliminamos un elemento de la lista
    if(ll_containsAll(this,this3)){//usamos la funcion containsAll para ver si los elementos de la lista this3 estan en la lista this
        printf("los elementos de la lista this3 estan contenidos dentro de la lista this\n");
    }
    mostrarMascotas(this3);//mostramos la lista
    if(ll_clear(this3)){//eliminamos los todos elementos de la lista this3
        printf("Los elementos de la lista fueron eliminados\n");
    }
    if (ll_isEmpty(this3)){//nos fijamos si la lista esta vacia
        printf("la lista esta vacia\n");
    }



    this4=ll_filter(this,mayorA2);//creamos una lista con que cumpla con la condicion dada en la funcion ll_filter
    ll_sort(this4,edadMayor,1);//ordenamos la lista segun la condicion dada en la funcion ll_sort
    mostrarMascotas(this4);//mostramos la lista





    ll_deleteLinkedList(this);//Eliminamos la lista this
    ll_deleteLinkedList(this2);//Eliminamos la lista this2
    ll_deleteLinkedList(this3);//Eliminamos la lista this3
    ll_deleteLinkedList(this4);//Eliminamos la lista this4
    return 0;
}
void mostrarUnaMascota(eMascota* mascota)
{
    if(mascota!=NULL)
    {
        printf("%10s%5d\n",mascota->nombre,mascota->edad);
    }
}
void mostrarMascotas(LinkedList* this)
{
    int len;
    if (this!=NULL)
    {
        len=ll_len(this);
        printf("el tama%co de la lista es de %d\n",164,len);//mostramos cuantos elementos tiene la lista
        printf("%10s%5s\n","nombre","edad");
        for(int i=0;i<len;i++)
        {
            mostrarUnaMascota(ll_get(this,i));//usamos la funcion ll_get para traer una mascota
        }
        printf("\n");
    }
}
int mayorA2(void* pMascota)
{
    int retorno=0;
    eMascota* mascota=NULL;
    if(pMascota!=NULL)
    {
        mascota=(eMascota*)pMascota;
        if(mascota->edad>2)
        {
            retorno=1;
        }
    }
    return retorno;
}

int edadMayor(void* pMascota1,void* pMascota2)
{
    int retorno=-1;
    eMascota* mascota1=NULL;
    eMascota* mascota2=NULL;
    if(pMascota1!=NULL && pMascota2!=NULL)
    {
        mascota1=(eMascota*)pMascota1;
        mascota2=(eMascota*)pMascota2;
        if(mascota1->edad>mascota2->edad)
        {
            retorno=1;
        }
    }
    return retorno;
}
