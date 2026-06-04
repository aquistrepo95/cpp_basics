#include <iostream>
#include <vector>


class Base {
    public:
        std::string name;
        int age;
        std::vector<std::string> hobbies;
        std::string address;


    Base(std::string name, int age, std::vector<std::string> hobbies) : name(name), age(age), hobbies(hobbies) {
        std::cout << "This is the default constructor of the base class" << std::endl;
    }

    Base (const Base& obj) {
        this->name = obj.name;
        this->age  = obj.age;
        this->hobbies = obj.hobbies;

        std::cout << "This is the copy constructor of the base class" << std::endl;
    }

    void displayHobbies() {
        std::cout << "My Hobbies are: " << std::endl;

        for(const auto& hobby : hobbies) {
            std::cout << hobby << std::endl;
        }
    }

    ~Base() {
        std::cout << "This is the destructor of the base class" << std::endl;
    }

};

int main() {

    Base obj1("Anthony", 30, {"Reading", "Traveling", "Cooking"});
    Base obj2 = obj1; // This will invoke the copy constructor

    std::cout << "----------------------------- constructor ----------------------------" << std::endl;
    std::cout << "Name: " << obj1.name << ", Age: " << obj1.age << std::endl;
    obj1.displayHobbies();

    std::cout << "----------------------------- copy constructor ----------------------------" << std::endl;
    std::cout << "Name: " << obj2.name << ", Age: " << obj2.age << std::endl;
    obj2.displayHobbies();

    return 0;

}