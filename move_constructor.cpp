#include <iostream>
#include <vector>
#include <utility>

class Base {
    public:
        std::string name;
        int age;
        std::vector<std::string> hobbies;

        Base(std::string name, int age, std::vector<std::string> hobbies) : name(name), age(age), hobbies(hobbies) {

            std::cout << "This is the default constructor of the base class" << std::endl;
        }

        Base (Base&& obj) noexcept {
            this->name = obj.name;
            this->age  = obj.age;
            this->hobbies = obj.hobbies;

            std::cout << "This is the move constructor of the base class" << std::endl;

            obj.name = "";
            obj.age = 0;
            obj.hobbies.clear();
        }

        ~Base() {
            std::cout << "This is the destructor of the base class" << std::endl;
            name = "";
            age = 0;
            hobbies.clear();
        }

        void displayHobbies() {
            std::cout << "My Hobbies are: " << std::endl;

            for(const auto& hobby : hobbies) {
                std::cout << hobby << std::endl;
            }
        }
};

int main() {

    Base obj1("Anthony", 30, {"Reading", "Traveling", "Cooking"});
    Base obj2 = std::move(obj1); // This will invoke the move constructor

    std::cout << "----------------------------- move constructor ----------------------------" << std::endl;
    std::cout << "Name: " << obj2.name << "," << " Age: " << obj2.age << std::endl;
    obj2.displayHobbies();

    return 0;
}