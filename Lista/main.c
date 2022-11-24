#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/*
1. cercare l'elemento 55 nella lista
specifica
    dati di input: lista l, item el
    dati di output: intero 1 o -1
    postcondizione: se l contiene el restituisce 1, altrimenti -1
progettazione
    1. scorri tutti gli elementi della lista
    2. se il primo elemento della lista è uguale all'elemento cercato, restituisci 1
    3. se no, continua la ricerca nel resto della lista
    4. finiti gli elementi della lista, restituisci -1
*/
list copyList(list lis){
    list lc,la;
    item x;
    lc=newList();
    la=newList();

    while(!emptyList(lis)){
        x=getFirst(lis);
        la=consList(x,la);
        lis=tailList(lis);
    }
    while(!emptyList(la)){
        x=getFirst(la);
        lc=consList(x,lc);
        lis=consList(x,lis);
        la=tailList(la);
    }
    return lc;
}
void trovato(list lis,item el){
    list tmp=newList();
    item x;
    int i=0;

    tmp=copyList(lis);
    while(!emptyList(tmp)){
        x=getFirst(tmp);
        if(eq(x,el)){
            printf("1\n");
            i=1;
            tmp=tailList(tmp);
        }
        else
            tmp=tailList(tmp);
    }
    if(i!=1)
        printf("-1\n");
}
int main(){
    list l,lcopy;
    int pos;
    l=newList();
    lcopy=newList();

    l=consList(4,l);
    l=consList(1,l);
    l=consList(5,l);
    l=consList(14,l);
    l=consList(55,l);
    l=consList(8,l);
    l=consList(99,l);
    l=consList(33,l);

    //lcopy=copyList(l);
    trovato(l,45);

return 0;
}
