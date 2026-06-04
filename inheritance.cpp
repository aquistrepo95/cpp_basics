#include <iostream>

class Base {
    private:
        std::string planes;

    protected:
        std::string cars;

    public:
        Base() : planes("Boeing 747"), cars("Benz model S") {
            std::cout << "Base class constructor called" << std::endl;
        }

        void displayPlanes() {
            std::cout << "Planes: " << planes << std::endl;

            std::cout << "This is the base class display planes function" << std::endl;
        }

        void displayCars() {
            std::cout << "Cars: " << cars << std::endl;

            std::cout << "This is the base class display cars function" << std::endl;
        }


        void updatePlanes(const std::string& planes) {
            this->planes = planes;

            displayPlanes();
        }

        void updatecars(const std::string& cars) {
            this->cars = cars;

            displayCars();
        }

        ~Base() {
            planes = "";
            cars = "";

            std::cout << "Base class destructor called" << std::endl;
        }

};

class UpdateDerived : public Base {

    public:
        UpdateDerived() {
            std::cout << "UpdatePlanes class constructor called : this is a derived class" << std::endl;

        }
        
        void updatePlanes(std::string& planes) {
            std::cout << "This is the derived class update planes function" << std::endl;

            std::cout << "Enter the model of the new plane here: " << std::endl;
            std::getline(std::cin, planes);

            Base::updatePlanes(planes);
            Base::displayCars();

        }

        void updatecars(const std::string& cars) {
            std::cout << "This is the derived class update cars function" << std::endl;

            Base::updatecars(cars);
            Base::displayPlanes();

        }

        void updatePlanesandcars(const std::string& planes, const std::string& cars) {
            std::cout << "This is the derived class update planes function with both planes and cars" << std::endl;

            Base::updatePlanes(planes);
            Base::updatecars(cars);

        }

        /*
        ~UpdateDerived() {
            std::cout << "UpdatePlanes class destructor called : this is a drived class" << std::endl;
        }
        */
};

/*
class Derived2 : public Base, private Derived1 {

};
*/


int main() {
    std::cout << "Inheritance in C++" << std::endl;

    UpdateDerived derivedObj;

    //derivedObj.updatePlanesandcars("Airbus A380", "BMW M3");
    std::string planeModel = "Airbus A380";
    derivedObj.updatePlanes(planeModel);


    return 0;
}