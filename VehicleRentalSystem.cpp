#include<iostream>
#include <vector>
#include <string>
using namespace std;

class Vehicle {
    private:
        string type,make, model;
        int speed;
        float daysFee;
        
    public:
    Vehicle (const string& vtype, const string& vmake, const string& vmodel, const int& vspeed, const float& vdaysFee) 
        : type(vtype), make(vmake), model(vmodel), speed(vspeed), daysFee(vdaysFee) {}

    void display(){
        cout << " " << type << " : " << make << "\n";
        cout << "    " << model << "(Speed: " << speed << " km/hr)" << "\n";
        cout << "    Rent/day: $" << daysFee <<endl;
    }
};
class Car : public Vehicle {
    public:
    Car(const string& cmake, const string& cmodel, const int& cspeed, const double& cdaysFee) 
        : Vehicle ("Car", cmake, cmodel, cspeed, cdaysFee) {};
};
class Motobike : public Vehicle {
    public:
    Motobike(const string& mmake, const string& mmodel, const int& mspeed, const double& mdaysFee) 
        : Vehicle ("Motobike", mmake, mmodel, mspeed, mdaysFee){};
};
class Truck : public Vehicle {
    public:
    Truck(const string& tmake, const string& tmodel, const int& tspeed, const double& tdaysFee) 
        : Vehicle ("Truck", tmake, tmodel, tspeed, tdaysFee){};
};

class Rental : public Vehicle {
    private:
        int daysRented;
        string status;
        float daysFee, fee;
    public:
        /*
        Rental(const string& vmake, const string& vmodel, const int& vspeed, const double& vdaysFee) 
        : Vehicle (vmake, vmodel, vspeed) {
            this -> setStatus("Available");
            this -> setDaysFee(vdaysFee);
        };
        */
        void setDaysRented (const int& days){
            daysRented = days;
        }
        void setDaysFee(const float& dayF){
            daysFee = dayF;
        }
        void setStatus(const string& stat){
            this->status = stat;
        }

        void display(){
            Vehicle::display();
            cout << "    Status: " << status <<endl;
        }
        // Rental(const string& vmake, const string& vmodel, const double vfee  ) : Vehicle (vmake, vmodel) {}
};

//main funtion initalize
void display(const vector<Vehicle>& vehicles);

int main(){
    vector<Vehicle> vehicles;
    
    Car car1("Sedan", "Toyota Corolla", 120, 50);
    Car car2("SUV", "Honda CR-V", 110, 65);
    Car car3("Sports car", "BMW M4", 180, 200);

    Motobike motobike1("Dirt bike", "Harley-Davidson", 80, 35);
    Motobike motobike2("Cruiser", "Yamaha R1", 170, 120);
    Motobike motobike3("Sport bike", "Kawasaki KX250F", 120, 35);

    Truck truck1("Pickup truck", "Ford F-150", 100, 75);
    Truck truck2("Cargo van","Chevralot Express", 90, 95);
    Truck truck3("Dump truck", "Peterbilt", 80, 300);
    
    vehicles.push_back(car1);
    vehicles.push_back(car2);
    vehicles.push_back(car3);

    display(vehicles);

    return 0;
}
void rentVehicle(){

}
void display(const vector<Vehicle>& vehicles){
    int i = 1;
  //looping and display all details, using rental member function display
    for(Vehicle trucks : vehicles){
        cout << "    --------------" << endl;
        cout << i << ". ";
        trucks.display();
        i++;
    }
}