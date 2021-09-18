#include <bits/stdc++.h>
#include "doublelinkedlist.h"

using namespace std;

int main() {
    DoubleList<int> l;
    l.insert(9);
    l.insert(20);
    l.insert(12);
    l.insert(13);
    l.insert(46);
    l.insert(19);
    cout<<"Imprimiendo datos de la lista doble"<<endl;
    l.print();


    //1. Implementar una función maximo de manera iterativa.
    l.maximo_Iterativa();

    //2. Implementar una función maximo de forma recursiva.
    l.print_MaxRecursivo();
        

    //3. Implementar una función recursiva que imprima los datos de inicio a fin.
    cout<<"Imprimiendo datos de forma recursiva INICIO-FIN "<<endl;
    l.printRIF();
    cout<<endl;

    //4. Implementar una función recursiva que imprima los datos de fin a inicio.
    cout<<"Imprimiendo datos de forma recursiva FIN-INICIO "<<endl;
    l.printRFI();
    cout<<endl;

    //5. Implementar una función iterativa que imprima los datos de fin a inicio.
    cout<<"Imprimiendo datos de forma iterativa FIN-INICIO "<<endl;
    l.print_Iterativa_F_I();
    
    //6. Implementar una función que cuente el número de elementos pares. 
    cout<<"Imprimiendo número de ELEMENTOS PARES "<<endl;
    cout << l.count_even()<<endl;

    //7. Implementar una función que ordene los datos de forma ascendente.
    cout<<"Imprimiendo datos de forma ORDENADA ASCENDENTE "<<endl;
    l.ordenar_Ascendente();
    l.print();

    //8. Implementar una función que ordene los datos de forma descendente.
    cout<<"Imprimiendo datos de forma ORDENADA DESCENDENTE "<<endl;
    l.ordenar_Descendente();
    l.print();
    

    return 0;
}