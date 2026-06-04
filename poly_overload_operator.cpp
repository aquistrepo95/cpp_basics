#include <iostream>

class Base {
    public:
        std::string name;
        int age;
        int length;
        int height;

        Base(std::string name, int age) : name(name), age(age) {};
        Base(int length, int height) : length(length), height(height) {};

        
        //overloading the ostream operator function within the class
        std::ostream& operator<<(std::ostream& COUT) {
            COUT << "name:" << this->name << " age: " << this->age << std::endl;

            COUT << "This is the overloaded operator function location inside the base class" << std::endl;

            return COUT;   
        }

        //overloading the addition operator function outside the class
        int operator+(const Base& obj) {
            auto len = this->length + obj.length;
            auto hei = this->height + obj.height;

            return len + hei;
        }

};
/*
void operator <<(std::ostream& COUT, Base& obj) {
    COUT << "name: " << obj.name << " age: " << obj.age << std::endl;

    COUT << "This is the overloaded operator function located outside the base class" << std::endl;
}*/



int main() {
    Base obj1("Anthony" , 30);
    Base obj2(10, 20);
    Base obj3(15, 25);

    //this is within the class
    // i.e object << cout
    //obj1 << std::cout;

    //this is outside the class
    // i.e cout << object
    //std::cout << obj1;


    //overloading the addition operator function outside the class
    int obj4 = obj2 + obj3; 
    std::cout << "The result of the addition operator function is: " << obj4 << std::endl;

    return 0;
}