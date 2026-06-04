#include <iostream>
#include <vector>

class Base {
    public:
        std::string name;
        int age;
        std::vector<std::string> cities;


    Base(std::string name, int age, std::vector<std::string> cities) : name(name), age(age), cities(cities) {
        std::cout << "This is the default constructor of the base class" << std::endl;
    }

    Base& operator=(Base&& obj) noexcept {

        // check for self assignment
        if(this == &obj) {
            return *this;
        }

        // set the current object data member to their default values
        this->name = "";
        this->age = 0;
        this->cities.clear();

        // move the data members from the source object to the current object
        this->name   = obj.name;
        this->age    = obj.age;
        this->cities = obj.cities;

        // reset the source object data members to their default values
        obj.name = "";
        obj.age  = 0;
        obj.cities.clear();

        std::cout << "This is the move assignment operator of the base class" << std::endl;
        
        // return the current object by reference
        return *this;
    }

    void display() {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
        std::cout << "Cities: " << std::endl;

        for(const auto& city : cities) {
            std::cout << city << std::endl;
        }
    }

    ~Base() {
        std::cout << "This is the destructor of the base class" << std::endl;
        name = "";
        age = 0;
        cities.clear();
    }

};


int main() {

    Base obj1("Anthony", 30, {"New York", "Los Angeles", "Chicago"});
    Base obj2("John", 25, {"Miami", "Houston", "Phoenix"});

    std::cout << "----------------------------- before move assignment object1 ----------------------------" << std::endl;
    obj1.display();

    std::cout << "----------------------------- before move assignment object2 ----------------------------" << std::endl;
    obj2.display();


    obj2 = std::move(obj1); // This will invoke the move assignment operator

    std::cout << "----------------------------- after move assignment object2 ----------------------------" << std::endl;
    obj2.display();

    return 0;
}