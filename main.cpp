#include <bits/stdc++.h>
#include "doublelinkedlist.h"

using namespace std;

int main() {
    DoubleList<int> l;
    l.insert(9,0);
    l.insert(11,0);
    l.insert(1,0);
    l.insert(51,0);
    l.insert(21,0);
    cout<<"Imprimiendo datos de la lista doble"<<endl;
    l.print();
    cout<<endl;

    //1. Implementar una función maximo de manera iterativa.
    l.maximo_Iterativa();

    //2. Implementar una función maximo de forma recursiva.
    //3. Implementar una función recursiva que imprima los datos de inicio a fin.
    cout<<"Imprimiendo datos de forma recursiva INICIO-FIN "<<endl;
    l.print_Recursiva_I_F(l.getHead());
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


    
    
    
    
    return 0;
}