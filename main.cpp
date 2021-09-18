#include <bits/stdc++.h>
#include "doublelinkedlist.h"

using namespace std;

int main() {
    DoubleList<int> l;
    l.push_back(9);
    l.push_back(20);
    l.push_back(12);
    l.push_back(13);
    l.push_back(46);
    l.push_back(19);
    l.push_front(-5);
    l.insert(4,4);
    cout<<"Imprimiendo datos de la lista doble"<<endl;
    l.print();
    cout<<endl;
    //1. Implementar una función maximo de manera iterativa.
    cout<<"1) Imprimiendo el MAXIMO de manera iterativa"<<endl;
    l.maximo_Iterativa();
    cout<<endl;
    //2. Implementar una función maximo de forma recursiva.
    cout<<"2) Imprimiendo el MAXIMO de manera recursiva"<<endl;
    l.print_MaxRecursivo();
    cout<<endl;
    //3. Implementar una función recursiva que imprima los datos de inicio a fin.
    cout<<"3) Imprimiendo datos de forma recursiva INICIO-FIN "<<endl;
    l.printRIF();
    cout<<endl<<endl;

    //4. Implementar una función recursiva que imprima los datos de fin a inicio.
    cout<<"4) Imprimiendo datos de forma recursiva FIN-INICIO "<<endl;
    l.printRFI();
    cout<<endl<<endl;

    //5. Implementar una función iterativa que imprima los datos de fin a inicio.
    cout<<"5) Imprimiendo datos de forma iterativa FIN-INICIO "<<endl;
    l.print_Iterativa_F_I();
    cout<<endl;
    
    //6. Implementar una función que cuente el número de elementos pares. 
    cout<<"6) Imprimiendo numero de ELEMENTOS PARES "<<endl;
    cout << l.count_even()<<endl<<endl;

    //7. Implementar una función que ordene los datos de forma ascendente.
    cout<<"7) Imprimiendo datos de forma ORDENADA ASCENDENTE "<<endl;
    l.ordenar_Ascendente(); //ordenando por el metodo bubble sort
    l.sort(); //ordenando por el metodo metodo quicksort
    l.print(); //imprimiendo de inicio a fin 
    cout<<endl;

    //8. Implementar una función que ordene los datos de forma descendente.
    cout<<"8) Imprimiendo datos de forma ORDENADA DESCENDENTE "<<endl;
     //ordenando por el metodo bubble sort
    l.sortD(); //ordenando por el metodo metodo quicksort
    l.ordenar_Descendente();
    l.print(); //imprimiendo de inicio a fin 
    cout<<endl;

    //15 (10,12,9,14) Usando las funciones, Begin y Next implemente una función para imprimir los datas de
    //la lista.
    cout<<"9|10|12|14|15) Usando las funciones, BEGIN Y NEXT "<<endl;
    l.printBN();
    cout<<endl;   
    cout<<endl;
    //16 (11,13,9,14). Usando las funciones, Last y Previus implemente una función para imprimir los datas de
    //la lista.
    cout<<"9|11|13|14|16) Usando las funciones, LAST Y PREVIUS"<<endl;
    l.printLP();
    cout<<endl<<endl;

    l.erase(4);
    l.pop_back();
    l.pop_front();

    cout<<"imprimiendo despues de borrar erase(pos), pop_front y pop_back"<<endl;
    l.printBN();
    cout<<endl<<endl;

    cout<<"FIND - encontrar recursivamente (LAB1)"<<endl;
    if(l.findR(59)){
        cout<<"el elemento 59 si esta";
    }else{
        cout<<"el elemnto 59 no esta";
    }
    cout<<endl<<endl;

    cout<<"FIND - encontrar iterativamente (LAB1)"<<endl;
    if(l.find(19)){
        cout<<"el elemento 19 si esta";
    }else{
        cout<<"el elemento 19 no esta";
    }
    cout<<endl<<endl;
    



    return 0;
}