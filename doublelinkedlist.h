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

        void insert (const T & value , int pos){
            if(pos <= size){ 
                int a = 1;
                Node * aux = head->next;
                while(a!=pos){
                    a++;
                    aux = aux->next;
                }
                size++;
                Node * newnode = new Node(value,aux->prev,aux);
                newnode->prev->next = newnode;
                aux->prev = newnode;  
            }            
        }
        void erase (int pos){
            if(pos <= size && head->next!=0){ 
                int a = 1;
                Node * aux = head->next;
                while(a!=pos){
                    a++;
                    aux = aux->next;
                }
                aux->prev->next = aux->next;
                aux->next->prev = aux->prev; 
                delete aux;
                size--;  
            }            
        }

        void print(){
            Node *recorre = head->next;
            if(head->next == nullptr){
                cout<<"Lista vacia"<<endl;
            }
            else{
                while(recorre!=tail){
                    cout<<recorre->data<<"  ";   
                    recorre = recorre->next; 
                }
                cout<<endl;
            }
        }

        /*FUNCIONES*/
        //1. Implementar una funci??n maximo de manera iterativa.
        void maximo_Iterativa(){ 
            if(size!=0) {
                Node *temp= head->next;
                int max=0;
            for(int i=0;i<size;i++){
                if (temp->data>max)
                    max=temp->data;
                temp=temp->next;
            }
            cout<<"Imprimiendo el valor maximo de la lista (Metodo Iterativo):\n"<< max <<endl;
            }
        }

        //2. Implementar una funci??n maximo de forma recursiva.
        int maximo_Recursivo( Node* _pActual, int max) { 
            if(_pActual == nullptr)
                return max;
            else if( _pActual->data > max) 
                    max = _pActual->data;
            return maximo_Recursivo(_pActual->next, max);
        }
            // El valor m??x inicial es el valor del 1er nodo. Se compara con el valor del sgte nodo(_pActual).
            void print_MaxRecursivo() {
                int res = maximo_Recursivo(this->head->next, this->head->data);
                cout<<"Imprimiendo el valor maximo de la lista (M??todo Recursivo):\n"<< res <<endl;   
            }

        //3. Implementar una funci??n recursiva que imprima los datos de inicio a fin.
        void print_Recursiva_I_F(Node* temp){ 
            if (temp->next==nullptr){
                return; 
            }
            else{
                cout<< temp->data<<"  "; 
                print_Recursiva_I_F( temp->next);
            }
        }

        void printRIF(){
            if (size!=0){
               print_Recursiva_I_F(head->next);
            }
        }

        //4. Implementar una funci??n recursiva que imprima los datos de fin a inicio.
        void print_Recursivo_F_I (Node* _elem) {
            if (_elem->prev != nullptr) {
                cout<< _elem->data <<"  ";
                print_Recursivo_F_I(_elem->prev);
            }
        }

        void printRFI(){
            if (size!=0){
               print_Recursivo_F_I(tail->prev);
            }
        }

        //5. Implementar una funci??n iterativa que imprima los datos de fin a inicio.
        void print_Iterativa_F_I(){ 
            Node *temp = tail->prev;
            for(int i=size;i>0;i--){
                cout<<temp->data<<"  ";   //recorre la lista e imprime sus elementos
                temp=temp->prev;
            }
            cout<<endl;

        }
        //6. Implementar una funci??n que cuente el n??mero de elementos pares.  ??
        size_t count_even () {
            Node *temp= head->next;
            size_t i = 0;
            while (temp->next) {
                if ((temp->data)%2 == 0)
                    i++;
                temp = temp->next;
            }
            return i;
        } 
        
        //7. Implementar una funci??n que ordene los datos de forma ascendente.
        //BUBBLE METHOD
        void ordenar_Ascendente(){ 
            Node *temp= head->next;
            Node *aux = nullptr;
            T elem_;
            while (temp->next){
                aux=temp->next;
                while (aux!=tail){
                    if (aux->data < temp->data){
                        elem_=temp->data;
                        temp->data=aux->data;
                        aux->data=elem_;
                    }
                    aux = aux->next;
                }
                temp = temp->next;
            }
        }

        //QUICKSORT
        void sort() {
            if(size!=0){
               quicksort(head->next,tail->prev);
            }
        }

        void quicksort(Node * imin , Node * imax) {
            if(imin->prev == imax || imin == imax) return;
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
            Node * amin  = imin;
            Node * amax  = imax;

            while(amin != amax || amin->prev == amax){
                while(amax->data >= amin->data && amin != amax || amin->prev == amax) {
                    amax = amax->prev;
                }
                intercambiar(amax,amin);
                while(amin->data <= amax->data && amin != amax || amin->prev == amax) {
                    amin = amin->next;
                }
                intercambiar(amin,amax);
            }

            return amin;
        }


        //8. Implementar una funci??n que ordene los datos de forma descendente.
        void ordenar_Descendente(){ 
            Node *temp = head->next;
            Node *aux = nullptr;
            T elem_;
            while (temp->next){
                aux = temp->next;
                while (aux!=tail){
                    if (aux->data > temp->data){
                        elem_ = temp->data;
                        temp->data = aux->data;
                        aux->data = elem_;
                    }
                    aux = aux->next;
                }
                temp=temp->next;
            }
            
        }
        //QUICKSORT
        void sortD() {
            if(size!=0){
               quicksortD(head->next,tail->prev);
            }
        }

        void quicksortD(Node * imin , Node * imax) {
            if(imin->prev == imax || imin == imax) return;
            Node * k = pivoteD(imin , imax);
            quicksortD(imin , k->prev);
            quicksortD(k->next , imax);
        }

        Node * pivoteD(Node * imin , Node * imax){
            Node * ipiv = imin;
            Node * amin  = imin;
            Node * amax  = imax;

            while(amin != amax || amin->prev == amax){
                while(amax->data <= amin->data && amin != amax || amin->prev == amax) {
                    amax = amax->prev;
                }
                intercambiar(amax,amin);
                while(amin->data >= amax->data && amin != amax || amin->prev == amax) {
                    amin = amin->next;
                }
                intercambiar(amin,amax);
            }

            return amin;
        }


        //9. A??adir un miembro dato/variable a la lista denominado pActual (puntero a nodo) y crear
        //las siguientes funciones: 
           //linea 493


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
        
        //15. Usando las funciones, Begin y Next implemente una funci??n para imprimir los datas de
        //la lista.
        void printBN() {
            this->Begin();
            while(size != 0 && pActual!=tail) {
                std::cout<<pActual->data<<"  ";
                this->Next();
            }
        }
        
        //16. Usando las funciones, Last y Previus implemente una funci??n para imprimir los datas de
        //la lista.
        void printLP() {
            this->Last();
            while(size != 0 && pActual!=head) {
                std::cout<<pActual->data<<"  ";
                this->Previus();
            }
        }

        //lab-1
        bool find(const T & value){
            if(size!=0){
                Node * tmp = this->head->next;
                while(tmp!=tail && value != tmp->data) {
                    tmp = tmp->next;
                }
                if(tmp != tail && tmp->data == value) return true;
                else return false;
            }
        }

        bool find_recursivo(Node * tmp , const T & value ) {
            if(tmp == nullptr) return false;
            if(tmp->data==value) return true;
            find_recursivo(tmp->next,value);
        }

        bool findR(const T & value) {
            find_recursivo(head->next,value);
        }

    private:
        Node *head;
        Node *tail;
        Node *pActual;
        int size;
        
};

#endif