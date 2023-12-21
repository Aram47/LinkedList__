#ifndef LIST_H
#define LIST_H
#include "node.hpp"

    class List
    {
        private:
            Node* m_head = nullptr;
        public:
            ~List();
            void iteration(); // Պտտվում և տպում է նոդերի միջի արժեքները
            void pushFront(const int&); // Ավելացնում ա սկզբից
            void pushBack(const int&);  // Ավելացնում ա վերջից
            void popBack(); // Ջնջում ա վերջից
            void popFront(); // Ջնջում ա սկզբից
            bool empty() const; // Եթե դատարկ ա լիստը վերադարձնում ա 1 եթե դատարակ չի 0
            int size() const; // Վերադարձնում է թե քանի հատ նոդ կա (Նոդերի քանակը)
            void resize(const int&,const int& = 0); // Մեծացնում կամ կրճատում է նոդերի քանակը և արժեքավորում երկրորդ արգումենտով 
    };

#endif