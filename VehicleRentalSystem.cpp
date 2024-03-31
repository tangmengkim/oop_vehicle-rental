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
    void display()
    {
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

class Rental
{
private:
    int daysRented;
    string status;
    float fee;
    vector<Vehicle*> vehicles;

public:
    /*
    Rental(const string& vmake, const string& vmodel, const int& vspeed, const double& vdaysFee)
    : Vehicle (vmake, vmodel, vspeed) {
        this -> setStatus("Available");
        this -> setDaysFee(vdaysFee);
    };
    */

    // setter
    void addVehicle(Vehicle* vehicle)
    {
        vehicles.push_back(vehicle);
        setStatus("Available");
    }

    void setDaysRented(const int &days)
    {
        daysRented = days;
    }

    void setStatus(const string &stat)
    {
        this->status = stat;
    }

    // getter
    string getStatus(){
        return status;
    }
    
    // display
    void displaytype()
    {
        
        cout << "    Status: " << status << endl;
    }
    // Rental(const string& vmake, const string& vmodel, const double vfee  ) : Vehicle (vmake, vmodel) {}
};
/*
class Customer
{
    // customer with name and have list of rented movies
private:
    string name;
    vector<Rental> rentedVehicles;

public:
    Customer(const string &n) : name(n) {}

    string getName() const
    {
        return name;
    }
    // method to add the movie to personal list as well as flag it in the personal list
    void rentedMovie(Rental &vehicle, const int &days)
    {
        vehicle.setDaysRented(days);
        vehicle.setStatus("rented");
        rentedVehicles.push_back(vehicle);
    }

    // display all the movies in personal rented list, using loops and display()
    void displayRentals() const
    {
        cout << "Name: " << name << endl;
        cout << "================" << endl;
        double totalFees = 0;
        for (Rental vehicle : rentedVehicles)
        {
            vehicle.display();
            cout << "Rental fee: $" << vehicle.rentalFee() << endl;
            cout << "============================" << endl;
            totalFees += vehicle.rentalFee();
        }
        cout << "Fee sum: $" << totalFees << endl;
    }
    // more getters
    Rental getRentedMovie(const int &index) const
    {
        return rentedVehicles[index];
    }
    int getRentedMoviesCount() const
    {
        return rentedVehicles.size();
    }
};
*/

// main funtion initalize
void displayMenu();
void displayVehicleType();
void displayVehicle(const vector<Vehicle> &vehicles, const string& vtype);
int main()
{
    Rental rental;
    vector<Vehicle> vehicles;
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
        if(choice >= 0 && choice <=3){
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
void displayVehicle(const vector<Vehicle> &vehicles, const string& vtype){
    vector<Vehicle> vehicleList; 
    int i = 1;
    // looping and display all details, using rental member function display
    for (Vehicle vehicle : vehicles)
    {
        if( vehicle.getType() == vtype ){
        cout << "    --------------" << endl;
        cout << i << ". ";
        vehicle.display();
        vehicleList.push_back(vehicle);
        i++;
        }
    }

}

