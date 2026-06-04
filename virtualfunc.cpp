#include <iostream>

class Base {
    public:

    virtual void display() {
        std::cout << "This is the base class display function" << std::endl;
    }

    virtual void show() {
        std::cout << "This is the base class show function" << std::endl;
    }

    virtual ~Base() {
        std::cout << "This is the base class destructor" << std::endl;
    }
};

class Derived1 : public Base {
    public:

    void display() override{
        std::cout << "This is the derived1 class display function" << std::endl;
    }
    
    ~Derived1() {
        std::cout << "This is the derived1 class destructor" << std::endl;
    }

};

class Derived2 : public Derived1{
    public:
    void show() override {
        std::cout << "This is derived2 class show function" << std::endl;
    }

    ~Derived2() {
        std::cout << "This is the derived2 class destructor" << std::endl;
    }
};

int main() {

    Base* baseptr  = new Derived1;
    Base* baseptr2 = new Derived2;

    baseptr->display();
    baseptr2->show();
    
    delete baseptr2;

    
}