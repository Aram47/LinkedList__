#include <iostream>
#include "list.hpp"

List::~List()
{
    while (m_head)
        List::popFront();
}

void List::iteration()
{
    if (!m_head)
    {
        std::cout << "Have not NODS" << std::endl;
        return;
    }
    Node* tmp = m_head;
    while (tmp)
    {
        std::cout << tmp->m_val << std::endl;
        tmp = tmp->m_next;
    }
}

void List::pushFront(const int& val)
{
    if (!m_head) {
        m_head = new Node();
        m_head->m_val = val;
    } else {
        if (!(m_head->m_next)) {
            m_head->m_next = new Node();
            m_head->m_next->m_val = m_head->m_val;
            m_head->m_val = val;
            return;
        }
        Node* tmp = m_head->m_next;
        while (tmp)
        {
            int chlp = tmp->m_val;
            tmp->m_val = m_head->m_val;
            m_head->m_val = chlp;
            if (!(tmp->m_next))
            {
                tmp->m_next = new Node();
                tmp = tmp->m_next;
                chlp = tmp->m_val;
                tmp->m_val = m_head->m_val;
            }
            tmp = tmp->m_next;
        }
        m_head->m_val = val;
    }
}

int List::size() const
{
    Node* tmp = m_head;
    int nodsCount = 0;
    while (tmp)
    {
        ++nodsCount;
        tmp = tmp->m_next;
    }
    return nodsCount;
}

void List::pushBack(const int& val)
{
    if (!m_head) {
        m_head = new Node();
        m_head->m_val = val;
        return;
    }
    Node* tmp = m_head;
    while (tmp)
    {
        if (!(tmp->m_next))
        {
            tmp->m_next = new Node();
            tmp->m_next->m_val = val;
            return;
        }
        tmp = tmp->m_next;
    }
}

void List::popBack()
{
    if (!m_head)
        return;
    if (!(m_head->m_next))
    {
        delete m_head;
        m_head = nullptr;
        return;
    }
    Node* tmp = m_head;
    while (tmp)
    {
        if (!(tmp->m_next->m_next))
        {
            delete tmp->m_next;
            tmp->m_next = nullptr;
            return;
        }
        tmp = tmp->m_next;
    }
}

void List::popFront()
{
    if (!m_head)
        return;
    Node* tmp = m_head->m_next;
    delete m_head;
    m_head = tmp;
    tmp = nullptr;
}

bool List::empty() const
{
    if (!m_head)
        return true;
    return false;
}

void List::resize(const int& size, const int& val)
{
    if (size == List::size() || size < 0)
        return;
    else if (size > List::size())
    {
        int condition = size - List::size();
        while (condition--)
            List::pushBack(val);
    } else {
        int condition = List::size() - size;
        while (condition--)
            List::popBack();
    }
}