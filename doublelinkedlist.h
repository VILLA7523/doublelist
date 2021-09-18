#ifndef __DOUBLELINKEDLIST_H__
#define __DOUBLELINKEDLIST_H__
using namespace std;
template<typename T>
class DoubleList {
    private:
       class Node {
           public:
            T data;
            Node *prev;
            Node *next;
            Node(const T & d = T{} , Node *p = nullptr  , Node *n = nullptr):data{d},prev{p},next{n} {}
            Node(T && d , Node *p = nullptr , Node *n = nullptr):data{std::move(d)},prev{p},next{n} {}
       };
       
    public:
        class citerator {
            public:
                citerator() : cit(nullptr) {}

                const T & operator * () const{
                    return this->indireccion();
                }

                citerator & operator++() {
                    return *this->next;
                }

                citerator operator++(int) {
                    citerator *aux = *this;
                    ++(*this);
                    return aux;
                }

                citerator & operator--() {
                    cit = cit->prev; 
                    return *this;
                }

                citerator operator--(int) {
                    Node *aux = this->cit;
                    --(*this);
                    return aux;
                }

            protected:
                Node *cit;
                citerator(Node *p):cit{p} {}
                T & indireccion( ) const { return cit->data; } 
                friend class DoubleList <T>;
                
        };

        class iterator: public citerator{
            public:
                iterator() {}

                T & operator * () 
                {
                    return citerator::indireccion();
                }

                const T & operator *() const
                {
                    return citerator::operator*();
                }
                
                iterator & operator ++ () 
                {
                    return *this->next;
                }

                iterator operator ++(int) 
                {
                    iterator *aux = *this;
                    ++(*this);
                    return aux;
                }

                iterator & operator--() {
                    this->cit = this->cit->prev; 
                    return *this;
                }

                iterator operator --(int) {
                    Node *aux = this->cit;
                    --(*this);
                    return aux;
                }

            protected:
                iterator(Node *p): citerator{p} {}
                friend class DoubleList <T>;
                
        };

    public:
        
        DoubleList() {
            size = 0;
            head = new Node;
            tail = new Node;
            head->next = tail;
            tail->prev = head; 
        } 

        DoubleList (const DoubleList & lhs) 
        {
            size = 0;
            head = new Node;
            tail = new Node;
            head->next = tail;
            tail->prev = head; 
            for(auto & aux : lhs) //entero
                push_back(aux);
        }

        DoubleList & operator= (const DoubleList & lhs) {
            DoubleList copy = lhs;
            std::swap(*this, copy);
            return *this;
        }

        DoubleList (DoubleList && rhs) 
        {
            this->size = rhs.size;
            this->head = rhs.head;
            this->tail = rhs.tail;
            rhs.size = 0;
            rhs.head = nullptr;
            rhs.tail = nullptr;
        }

        DoubleList & operator = (DoubleList && rhs) 
        {
            std::swap(this->head, rhs->head);
            std::swap(this->tail, rhs->tail);
            std::swap(this->size, rhs->size);

            return *this;
        }

        ~DoubleList ()
        {
            clear();
            delete head;
            delete tail;
        }

        iterator begin() {
            return head->next;
        }

        iterator end() {
            return tail;
        }

        bool empty() {
            return size == 0;
        }

        void clear () {
            while (!empty()) 
            {
                pop_front();
            }
        }

        T & front () 
        {
            return *(begin());
        }

        const T & front () const
        {
            return *(begin());
        }

        T & back() 
        {
            return *(--end());
        }

        const T & back() const 
        {
            return *(--end());
        }

        int tam () const{
            return this->size;
        }

        void push_front(const T & value){
            insert(value,begin());   
        }

        void push_back(const T & value){
            insert(value,end());
        }

        void push_front(T && value){
            insert(value,begin());   
        }

        void push_back(T && value){
            insert(value,end());
        }

        void pop_front()
        {
            erase(begin());
        }

        void pop_back()
        {
            erase(--end());
        }

        /*insertar y eliminar con la clase itereator*/
        iterator insert(const T & value , iterator it) 
        {
            Node * aux = it.cit;
            size++;
            Node * newnode = new Node(value,aux->prev,aux);
            newnode->prev->next = newnode;
            aux->prev = newnode;
            return it;
        }
        
        iterator insert(T && value , iterator it)
        {
            Node * aux = it.cit;
            size++;
            Node * newnode = new Node(std::move(value),aux->prev,aux);
            newnode->prev->next = newnode;
            aux->prev = newnode;
            return it;
        }

        iterator erase(iterator it) 
        {
            if(head->next!=0) {
                Node *aux = it.cit;
                iterator r {aux->next};
                aux->prev->next = aux->next;
                aux->next->prev = aux->prev; 
                delete aux;
                size--;
                return r;
            }
            return it;
        }

        void insert(T elem_){  
                Node *new_node= new Node(elem_);  
                Node *temp=head;  
                if (!head->data) {              
                    head = new_node;
                    tail = new_node;
                    size++;
                } 
                else{
                    while(temp->next != nullptr)
                        temp=temp->next;  
                    temp->next=new_node; 
                    new_node->prev=temp;
                    tail= new_node;  
                    size++;
            }
        }

        void print(){
            Node *recorre= head->next;
            if(head->next==NULL){
                cout<<"Lista vacia"<<endl;
            }
            else{
                while(recorre!=tail){
                    cout<<recorre->data<<" ";   
                    recorre=recorre->next; 
                }
                cout<<endl;
            }
        }

        /*FUNCIONES*/
        //1. Implementar una función maximo de manera iterativa.
        void maximo_Iterativa(){ 
            Node *temp= head;
            int max=0;
            for(int i=0;i<size;i++){
                
                if (temp->data>max){
                    max=temp->data;
                }
                temp=temp->next;
            }
            cout<<"El valor maximo de la lista es : "<< max;
            cout<<endl;
        }

        //2. Implementar una función maximo de forma recursiva.

        //3. Implementar una función recursiva que imprima los datos de inicio a fin.
        void print_Recursiva_I_F(Node* temp){ 
            if (temp==nullptr){
                return; 
            }
            else{
                cout<< temp->data<<"  "; 
                print_Recursiva_I_F( temp->next);
            }
        }

        void printRIF(){
            if(size!=0){
               print_Recursiva_I_F(head->next);
            }
        }

        //4. Implementar una función recursiva que imprima los datos de fin a inicio.
        
        //5. Implementar una función iterativa que imprima los datos de fin a inicio.
        void print_Iterativa_F_I(){ 
            Node *temp= tail;
            for(int i=size;i>0;i--){
                cout<<temp->data<<" ";   //recorre la lista e imprime sus elementos
                temp=temp->prev;
            }
            cout<<endl;

        }
        //6. Implementar una función que cuente el número de elementos pares.  ́
        
        
        //7. Implementar una función que ordene los datos de forma ascendente.
        //BUBBLE METHOD
        void ordenar_Ascendente(){ 
            Node *temp= head->next;
            Node *aux;
            T elem_;
            while (temp->next!=tail){
                aux=temp->next;
                while (aux){
                    if (aux->data <temp->data){
                        elem_=temp->data;
                        temp->data=aux->data;
                        aux->data=elem_;
                    }
                    aux=aux->next;
                }
                temp=temp->next;
            }
            
        }

        //QUICKSORT
        void sort() {
            if(size!=0){
               quicksort(head->next,tail->prev);
            }
        }

        void quicksort(Node * imin , Node * imax) {
            if(imin->prev == imax) return;
            Node * k = pivote(imin , imax);
            quicksort(imin , k->prev);
            quicksort(k->next , imax);
        }

        void intercambiar(Node * imin , Node * imax) {
            T d = imin->data;
            imin->data = imax->data;
            imax->data = d;
        }

        Node * pivote(Node * imin , Node * imax){
            Node * ipiv = imin;
            Node * isec = imin->next;
            while(isec != tail){
                if(isec->data <= ipiv->data) {
                    intercambiar(isec,ipiv);
                    isec = ipiv->next;
                }else {
                    isec = isec->next;
                }
            }

            return ipiv;
        }

        //8. Implementar una función que ordene los datos de forma descendente.


        //9. Añadir un miembro dato/variable a la lista denominado pActual (puntero a nodo) y crear
        //las siguientes funciones:


        //10. void Begin() que coloca el puntero pActual a la cabeza de la lista.
        void Begin() {
            if(size!=0){
                pActual = head->next; 
            }
        }
        
        //11. void Last() que coloca el puntero pActual a al final de la lista.
        void Last() {
            if(size!=0){
                pActual = tail->prev;
            }
        }
        
        //12. void Next() que mueve el puntero pActual al siguiente nodo.
        void Next() {
            if(size != 0 && pActual != nullptr){
                pActual = pActual->next;
            }
        }
        
        //13. void Previus() que mueve el puntero pActual al nodo anterior.
        void Previus() {
            if(size != 0 && pActual != nullptr){
                pActual = pActual->prev;
            }
        }
        
        //14. T GetDato() que retorna el dato apuntado por pActual.
        T GetGato() {
            if(pActual!=nullptr){
               return pActual->dato;
           }
        }
        
        //15. Usando las funciones, Begin y Next implemente una función para imprimir los datas de
        //la lista.
        void printBN() {
            this->Begin();
            while(pActual!=nullptr) {
                std::cout<<pActual->data<<"->";
                this->Next();
            }
        }
        
        //16. Usando las funciones, Last y Previus implemente una función para imprimir los datas de
        //la lista.
        void printLP() {
            this->Last();
            std::cout<<pActual->data;
            while(pActual!=nullptr) {
                std::cout<<pActual->data<<"->";
                this->Previus();
            }
        }


    private:
        Node *head;
        Node *tail;
        Node *pActual;
        int size;
        
};

#endif