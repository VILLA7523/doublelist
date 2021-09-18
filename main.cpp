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
    cout<<"Imprimiendo datos de la lista doble"<<endl;
    l.print();
    cout<<endl;

    //1. Implementar una función maximo de manera iterativa.
    l.maximo_Iterativa();

    //2. Implementar una función maximo de forma recursiva.

    //3. Implementar una función recursiva que imprima los datos de inicio a fin.
    cout<<"Imprimiendo datos de forma recursiva INICIO-FIN "<<endl;
    l.printRIF();
    cout<<endl;

    //4. Implementar una función recursiva que imprima los datos de fin a inicio.
    cout<<"Imprimiendo datos de forma iterativa FIN-INICIO "<<endl;
    l.print_Iterativa_F_I();

    //5. Implementar una función iterativa que imprima los datos de fin a inicio.
    //6. Implementar una función que cuente el número de elementos pares.  ́
    //7. Implementar una función que ordene los datos de forma ascendente.
    cout<<"Imprimiendo datos de forma ORDENADA ASCENDENTE "<<endl;
    l.ordenar_Ascendente();
    l.print();
    //8. Implementar una función que ordene los datos de forma descendente.

    l.printBN();
    cout<<endl;
    //15 (10,12,9,14) Usando las funciones, Begin y Next implemente una función para imprimir los datas de
    //la lista.
      
    l.printLP();  
    //16 (11,13,9,14). Usando las funciones, Last y Previus implemente una función para imprimir los datas de
    //la lista.
       



    return 0;
}