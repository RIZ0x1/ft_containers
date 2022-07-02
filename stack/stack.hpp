#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

namespace ft
{
    template <class T, class Container = ft::vector<T> >
    class stack
    {
        public:
            typedef T         value_type;
            typedef Container container_type;
            typedef size_t    size_type;

            explicit stack (const container_type& container = container_type()) : _container(container)
            {}

            ~stack()
            {}

            bool empty() const
            {
                return (this->_container.empty());
            }

            size_type size() const
            {
                return (this->_container.size());
            }

            value_type& top()
            {
                return (this->_container.back());
            }

            const value_type& top() const
            {
                return (this->_container.back());
            }

            void push (const value_type& val)
            {
                this->_container.push_back(val);
            }

            void pop()
            {
                this->_container.pop_back();
            }

            template <class Tn, class ContainerN>
                friend bool operator== (const ft::stack<Tn, ContainerN>& lhs, const ft::stack<Tn, ContainerN>& rhs);

            template <class Tn, class ContainerN>
                friend bool operator!= (const ft::stack<Tn, ContainerN>& lhs, const ft::stack<Tn, ContainerN>& rhs);

            template <class Tn, class ContainerN>
                friend bool operator< (const ft::stack<Tn, ContainerN>& lhs, const ft::stack<Tn, ContainerN>& rhs);

            template <class Tn, class ContainerN>
                friend bool operator<= (const ft::stack<Tn, ContainerN>& lhs, const ft::stack<Tn, ContainerN>& rhs);

            template <class Tn, class ContainerN>
                friend bool operator> (const ft::stack<Tn, ContainerN>& lhs, const ft::stack<Tn, ContainerN>& rhs);

            template <class Tn, class ContainerN>
                friend bool operator>= (const ft::stack<Tn, ContainerN>& lhs, const ft::stack<Tn, ContainerN>& rhs);

        protected:
            container_type _container;
    };

    template <class T, class Container>
        bool operator== (const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs)
        { return (lhs._container == rhs._container); }

    template <class T, class Container>
        bool operator!= (const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs)
        { return (lhs._container != rhs._container); }

    template <class T, class Container>
        bool operator< (const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs)
        { return (lhs._container < rhs._container); }

    template <class T, class Container>
        bool operator<= (const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs)
        { return (lhs._container <= rhs._container); }

    template <class T, class Container>
        bool operator> (const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs)
        { return (lhs._container > rhs._container); }

    template <class T, class Container>
        bool operator>= (const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs)
        { return (lhs._container >= rhs._container); }
}

#endif
