#define MANIPULATIVE_STACK
#define INLINE_STACK
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
        #ifdef INLINE_STACK
            inline
        #endif
            void pop();
        #ifdef INLINE_STACK
            inline
        #endif
            void push(const T &);
        #ifdef INLINE_STACK
            inline
        #endif
            const unsigned int size();
        #ifdef INLINE_STACK
            inline
        #endif
            const unsigned int capacity();
        #ifdef INLINE_STACK
            inline
        #endif
            bool empty();
        #ifdef INLINE_STACK
            inline
        #endif
            void set_multiplier(unsigned int);
        #ifdef INLINE_STACK
            inline
        #endif
            const unsigned int multiplier();
        #ifdef INLINE_STACK
            inline
        #endif
            T & top();
        #ifdef MANIPULATIVE_STACK
        #ifdef INLINE_STACK
            inline
        #endif
            T & operator [](unsigned int);
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
    #ifdef INLINE_STACK
    inline
    #endif
    void stack<T>::pop()
    {
        if(_size>0)
            _size--;
    }

    template<typename T>
    #ifdef INLINE_STACK
    inline
    #endif
    void stack<T>::push(const T & aux)
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
    #ifdef INLINE_STACK
    inline
    #endif
    void stack<T>::set_multiplier(unsigned int aux)
    {
        _multiplier=aux;
    }

    template<typename T>
    #ifdef INLINE_STACK
    inline
    #endif
    bool stack<T>::empty()
    {
        return _size==0;
    }

    template<typename T>
    #ifdef INLINE_STACK
    inline
    #endif
    const unsigned int stack<T>::size()
    {
        return _size;
    }

    template<typename T>
    #ifdef INLINE_STACK
    inline
    #endif
    const unsigned int stack<T>::capacity()
    {
        return _capacity;
    }

    template<typename T>
    #ifdef INLINE_STACK
    inline
    #endif
    const unsigned int stack<T>::multiplier()
    {
        return _multiplier;
    }

    #ifdef MANIPULATIVE_STACK
    template<typename T>
    #ifdef INLINE_STACK
    inline
    #endif
    T & stack<T>::operator [](unsigned int index)
    {
        return _buffer[index];
    }
    #endif

    template<typename T>
    #ifdef INLINE_STACK
    inline
    #endif
    T & stack<T>::top()
    {
        return _buffer[_size-1];
    }
}
