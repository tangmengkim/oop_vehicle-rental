#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Vehicle
{
private:
    string type, make, model;
    int speed;
    float daysFee;

public:
    Vehicle(const string &vtype, const string &vmake, const string &vmodel, const int &vspeed, const float &vdaysFee)
        : type(vtype), make(vmake), model(vmodel), speed(vspeed), daysFee(vdaysFee) {}
    string getType() const{
        return type;
    }
    string getModel() const{
        return model;
    }
    float getDaysFee() const{
        return daysFee;
    }
    void display() const {
        cout << " " << type << " : " << make << "\n";
        cout << "    " << model << "(Speed: " << speed << " km/hr)"
             << "\n";
        cout << "    Rent/day: $" << daysFee << endl;
    }
};
class Car : public Vehicle
{
public:
    Car(const string &cmake, const string &cmodel, const int &cspeed, const double &cdaysFee)
        : Vehicle("Car", cmake, cmodel, cspeed, cdaysFee){};
};
class Motobike : public Vehicle
{
public:
    Motobike(const string &mmake, const string &mmodel, const int &mspeed, const double &mdaysFee)
        : Vehicle("Motobike", mmake, mmodel, mspeed, mdaysFee){};
};
class Truck : public Vehicle
{
public:
    Truck(const string &tmake, const string &tmodel, const int &tspeed, const double &tdaysFee)
        : Vehicle("Truck", tmake, tmodel, tspeed, tdaysFee){};
};

class Rental{
private:
    int daysRented;
    string status;
    float fee;
    const Vehicle& vehicle;

public:
    Rental(const Vehicle& vehicle): vehicle(vehicle){
        this -> setStatus("Available");
    }

    // setter
    void setDaysRented(const int &days){
        daysRented = days;
    }
    void setStatus(const string &stat){
        this->status = stat;
    }

    // getter
    string getStatus(){
        return status;
    }
    string getType(){
        return vehicle.getType();
    }

    // display
    void displaytype(){
        vehicle.display();
        cout << "    Status: " << status << endl;
    }

};


// main funtion initalize
void displayMenu();
void displayVehicleType();
void displayVehicle(const vector<Rental> &vehicles, const string& vtype);
int main()
{
    vector<Rental> vehicles;
    Car car1("Sedan", "Toyota Corolla", 120, 50);
    Car car2("SUV", "Honda CR-V", 110, 65);
    Car car3("Sports car", "BMW M4", 180, 200);

    Motobike motobike1("Dirt bike", "Harley-Davidson", 80, 35);
    Motobike motobike2("Cruiser", "Yamaha R1", 170, 120);
    Motobike motobike3("Sport bike", "Kawasaki KX250F", 120, 35);

    Truck truck1("Pickup truck", "Ford F-150", 100, 75);
    Truck truck2("Cargo van", "Chevralot Express", 90, 95);
    Truck truck3("Dump truck", "Peterbilt", 80, 300);

    vehicles.push_back(car1);
    vehicles.push_back(car2);
    vehicles.push_back(car3);
    vehicles.push_back(motobike1);
    vehicles.push_back(motobike2);
    vehicles.push_back(motobike3);
    vehicles.push_back(truck1);
    vehicles.push_back(truck2);
    vehicles.push_back(truck3);

    int choice;
    bool explore = true;
    bool exit = false;

    while (!exit){
        displayMenu();
        cin >> choice;
        if(choice >= 0 && choice <=4){
            switch (choice)
            {
            case 0:
                cout << "Goodbye, " << endl;
                exit = true;
                break;
            case 1:
                cout << "Selected \"Rent Vehicle\": "<< endl;
                displayVehicleType();
                int Vtype;
                cin >> Vtype;
                if (Vtype >0 && Vtype <=3){
                    switch (Vtype)
                    {
                    case 1:
                        displayVehicle(vehicles,"Car");
                        break;
                    case 2:
                        displayVehicle(vehicles,"Motobike");
                        break;
                    case 3:
                        displayVehicle(vehicles,"Truck");
                        break;
                    
                    default:
                        break;
                    }
                }
                break;
            case 2:

                break;
            case 3:

                break;
            default:
                break;
            }
        }else{
            cout << "Invalid choice" << endl;
        }
    }
    return 0;
}

void displayMenu()
{  
    cout << endl;
    cout << "====Welcome the Rental Garage!====" << endl;
    cout << "What would you like to do?" << endl;
    cout << "1. Rent Vehicle" << endl;
    cout << "2. Return Vehicle" << endl;
    cout << "3. View Rented Vehicle" << endl;
    cout << "0. Exit" << endl;
    cout << "\n Enter a choice from menu: ";

}
void displayVehicleType(){
    cout << endl;
    cout << "1. Car" << endl;
    cout << "2. Motobike" << endl;
    cout << "3. Truck" << endl;
    cout << "\n Enter a choice from menu: ";
}
void rentVehicle(){

}
void displayVehicle(const vector<Rental>& vehicles, const string& vtype){
    vector<Rental> vehicleList; 
    int i = 1;
    // looping and display all details, using rental member function display
    for (Rental vehicle : vehicles)
    {
        if( vehicle.getType() == vtype ){
        cout << "    --------------" << endl;
        cout << i << ". ";
        vehicle.displaytype();
        vehicleList.push_back(vehicle);
        i++;
        }
    }

}

