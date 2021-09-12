#ifndef __DOUBLELINKEDLIST_H__
#define __DOUBLELINKEDLIST_H__

template<typename T>
class DoubleList {
    private:
       class Node {
           public:
            T data;
            Node *prev;
            Node *next;
            Node(const T & d = T{} , Node *p = nullptr  , Node *n = nullptr):data{},prev{p},next{n} {}
            Node(T && d , Node *p = nullptr , Node *n = nullptr):data{std::move(d)},prev{p},next{n} {}
       };
       
    public:
        class iterator {
            public:
                iterator() : it(nullptr) {} //CONSTRUCCION DE ITERATOR

                T & operator * () const{
                    return it->data;
                }

                iterator & operator ++ () {
                    it = it->next;
                    return *this;
                }

                iterator operator ++(int) {
                    iterator aux = *this;
                    ++(*this);
                    return aux;
                }

                iterator & operator -- () {
                    it = it->prev;
                    return *this;
                }

                iterator operator -- (int) {
                    iterator aux = *this;
                    --(*this);
                    return aux;
                }

                bool operator == ( const iterator & rhs ) const
                { return it == rhs.it; }
                bool operator != ( const iterator & rhs ) const
                { return !( *this == rhs ); }


            protected:
                Node *it;
                iterator(Node *p):it{p} {}
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
            //clear();
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
            return size() == 0;
        }

        void clear () {
            while (!empty) 
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


 
    
        

    private:
        Node *head;
        Node *tail;
        int size;
};

#endif