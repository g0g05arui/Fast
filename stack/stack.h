
#define MANIPULATIVE_STACK
#define INLINE_STACK

#ifdef INLINE_STACK
    #define stack_attr inline
#else
    #define stack_attr
#endif

namespace FAST
{
    template<typename T>
    class stack
    {
        T * _buffer;
        unsigned int _size,_multiplier,_capacity;
    public:
        stack();
        stack(unsigned int);
       stack_attr void pop();
       stack_attr void push(const T &);
       stack_attr const unsigned int size();
       stack_attr const unsigned int capacity();
       stack_attr bool empty();
       stack_attr void set_multiplier(unsigned int);
       stack_attr const unsigned int multiplier();
       stack_attr T & top();
       #ifdef MANIPULATIVE_STACK
       stack_attr T & operator [](unsigned int);
       #endif

    };
}

namespace FAST
{
    template<typename T>
    stack<T>::stack()
    {
        _size=_capacity=0;
        _multiplier=1;
        _buffer=nullptr;
    }

    template<typename T>
    stack<T>::stack(unsigned int __capacity)
    {
        _size=0;
        _capacity=__capacity;
        _buffer=new T[__capacity];
    }

    template<typename T>
    stack_attr void stack<T>::pop()
    {
        if(_size>0)
            _size--;
    }

    template<typename T>
    stack_attr void stack<T>::push(const T & aux)
    {
        if(_size<_capacity)
            _buffer[_size++]=aux;
        else
        {
            T * __buffer = new T [_size*(1+_multiplier) + 1*(_size==0)];
            for(unsigned int i=0; i<_size; i++)
                __buffer[i]=_buffer[i];
            delete[]_buffer;
            _buffer=__buffer;
            _capacity=_capacity*(1+_multiplier) + 1*(_capacity==0);
            _buffer[_size++]=aux;
        }
    }

    template<typename T>
    stack_attr void stack<T>::set_multiplier(unsigned int aux)
    {
        _multiplier=aux;
    }

    template<typename T>
    stack_attr bool stack<T>::empty()
    {
        return _size==0;
    }

    template<typename T>
    stack_attr const unsigned int stack<T>::size()
    {
        return _size;
    }

    template<typename T>
    stack_attr const unsigned int stack<T>::capacity()
    {
        return _capacity;
    }

    template<typename T>
    stack_attr const unsigned int stack<T>::multiplier()
    {
        return _multiplier;
    }

    #ifdef MANIPULATIVE_STACK
    template<typename T>
    stack_attr T & stack<T>::operator [](unsigned int index)
    {
        return _buffer[index];
    }
    #endif
    template<typename T>
    stack_attr T & stack<T>::top()
    {
        return _buffer[_size-1];
    }
}
