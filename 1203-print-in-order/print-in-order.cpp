class Foo {
    private :
    atomic<int>m_turn;
public:
    Foo() {
        m_turn = 1;
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        m_turn =2; // m_turn.store(2)
    }

    void second(function<void()> printSecond) {

      spinLock(2);  
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
      
        m_turn = 3;
    }

    void third(function<void()> printThird) {
        
        spinLock(3);
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }

    void spinLock(int turn)
    {
        while(m_turn.load(memory_order_acquire) != turn){}
    }
};