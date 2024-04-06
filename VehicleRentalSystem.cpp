/*
    Group 6 ES1
    1. Hak Layheang     ID: B20235881
    2. Heach Tevin      ID: B20236016
    3. Khat Panhadath   ID: B20232604
    4. Tang MengKim     ID: B20231674
    5. Sung Sovansak    ID: B20231056
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Vehicle{
private:
    string make, model;
    int speed;
    float daysFee;

public:
    Vehicle(const string &vmake, const string &vmodel, const int &vspeed, const float &vdaysFee)
        : make(vmake), model(vmodel), speed(vspeed), daysFee(vdaysFee) {}
    
    // Getter
    virtual string getType() const = 0 ;
    string getModel() const{
        return model;
    }
    float getDaysFee() const{
        return daysFee;
    }
    // Display function
    void display() const{
        cout << " " << make << "\n";
        cout << "    " << model << "(Speed: " << speed << " km/hr)" << "\n";
        cout << "    Rent/day: $" << daysFee << endl;
    }
};
class Car : public Vehicle{
private:
    string type;
public:
    Car(const string &cmake, const string &cmodel, const int &cspeed, const double &cdaysFee)
        : Vehicle(cmake, cmodel, cspeed, cdaysFee){
            this -> type = "Car";
        };
    string getType() const override { return type; }
};

class Motobike : public Vehicle{
private:
    string type;
public:
    Motobike(const string &mmake, const string &mmodel, const int &mspeed, const double &mdaysFee)
        : Vehicle(mmake, mmodel, mspeed, mdaysFee){
            this -> type = "Motobike";
        };
    //override
    string getType() const override { return type; }
};
class Truck : public Vehicle {
private:
    string type;
public:
    Truck(const string &tmake, const string &tmodel, const int &tspeed, const double &tdaysFee)
        : Vehicle(tmake, tmodel, tspeed, tdaysFee){
            this -> type = "Truck";
        };
    string getType() const override { return type; }
};

class Rental{
private:
    int daysRented;
    string status;
    Vehicle* vehicle;

public:
    Rental(Vehicle* vehicles): vehicle(vehicles){
        this -> setStatus("Available");
    }
    // setter
    void setDaysRented(const int &days){
        daysRented = days;
    }
    void setStatus(const string &stat){
        this -> status = stat;
    }
    // getter
    int getDayRented() const { 
        return this -> daysRented; 
        }
    string getStatus() const {
        return this -> status;
    }
    string getType() const {
        return vehicle -> getType();
    }
    string getModel(){
        return vehicle -> getModel();
    }
    
    // display
    void display(){
        vehicle -> display();
        cout << "    Status: " << status << endl;
    }
    void displayRentalFee(){
        cout << " ---------"<< endl;
        cout << this->getModel() << " is rented for "<< this->getDayRented() << "days = "<< this ->rentalFee()<<"$"<<endl;
    }
    // Rental Function
    void rented(const int& days){
        this->setDaysRented(days);
        this ->setStatus("Rented");
    }
    void returned(){
        if(this -> getStatus() == "Returned"){
            this -> setDaysRented(0);
            this -> setStatus("Available");
            cout << "====Return Success!" << endl;
        }
        else{
            cout << "===Return Unsuccess! Try Again!" << endl;
        }
    }
    // calculator function
    float rentalFee() const {
        return (vehicle->getDaysFee()) * (this->daysRented);
    }
};
class Customer {
private:
    string name;
    vector<Rental> rentedVehicle;
public:
    Customer(){};
    Customer(const string &cname) : name(cname) {}
    // Getter
    string getName() const { return name; }

    // Member function
    void rented(Rental &vehicle, const int &days){
        if (vehicle.getStatus() == "Available"){
            vehicle.setDaysRented(days);
            vehicle.setStatus("Rented");
            vehicle.rented(days);
            rentedVehicle.push_back(vehicle);
            vehicle.displayRentalFee();
            cout << "====Rental Success!" << endl;
        }
        else{
            cout << "===Rental Unsuccess! Try Again!" << endl;
        }
    }
    void returnVehicle(Rental &vehicleRe){
        int index = 0;
        for (Rental &vehicle : rentedVehicle){
            if (vehicle.getModel() == vehicleRe.getModel()){
                vehicle.setStatus("Returned");
                break;
            }
            index++;
        }
        if (rentedVehicle.size() > 0){
            rentedVehicle.erase(rentedVehicle.begin() + (index - 1));
        }
    }
    // Display
    void displayRentals() const{
        int i = 1;
        cout << "Name: " << name << endl;
        cout << "================" << endl;
        double totalFees = 0;
        for (Rental vehicle : rentedVehicle){
            cout << i <<". ";
            vehicle.display();
            cout << " Rental fee: $" << vehicle.rentalFee() << endl;
            cout << "============================" << endl;
            totalFees += vehicle.rentalFee();
            i++;
        }
        cout << " Fee sum: $" << totalFees << endl;
    }
    // Use to display all Vehicle is rented
    void displayRented(){
        for(Rental& vehicle : rentedVehicle){
        vehicle.display();
        cout << "   Rented : "<<vehicle.getDayRented() <<"Days";
        cout << " = " << vehicle.rentalFee() <<"$" <<endl;
        }
    }
    Rental getRentedVehicle(const int &index){
        return rentedVehicle[index];
    }
    int getRentedVehicleCount(){
        return rentedVehicle.size();
    }
};

// main funtion initializer
bool closeShop();
void displayMenu();
int getIntInput();
void showCustomers(const vector<Customer>& customers);
vector<string> getUniqueVehicleType(const vector<Rental>& vehicles);
void rentalVehicle(vector<Rental>& vehicles,Customer& currentCustomer);
void returnVehicle(vector<Rental>& vehicles, Customer& currentCustomer);
void displayType (const vector<string> types);

int main(){
    vector<Customer> customers;
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

    vehicles.push_back(&car1);
    vehicles.push_back(&car2);
    vehicles.push_back(&car3);
    vehicles.push_back(&motobike1);
    vehicles.push_back(&motobike2);
    vehicles.push_back(&motobike3);
    vehicles.push_back(&truck1);
    vehicles.push_back(&truck2);
    vehicles.push_back(&truck3);

    int choice;
    bool explore = true;
    // main block running
    while (closeShop()){
        showCustomers(customers);
        // innit customer
        string name;
        int cusIndex = 0;
        bool oldCustomer = false;
        cout << "Enter name: ";
        cin >> name;
        for (Customer customer : customers){
            if (customer.getName() == name){
                oldCustomer = true;
                break;
            }
            else{ cusIndex++; }
        }
        if (oldCustomer == false){
            Customer newCustomer(name);
            customers.push_back(newCustomer);
            cusIndex = customers.size() - 1;}

        Customer &currentCustomer = customers[cusIndex];

        bool exit = false;
        while (!exit) {
            displayMenu();
            choice = getIntInput();
            if (choice >= 0 && choice < 4){
                switch (choice){
                case 0:
                    cout << endl;
                    cout << "Goodbye, " << endl;
                    exit = true;
                    break;
                case 1:
                    cout << "Selected \"Rent Vehicle\": " << endl;
                    rentalVehicle(vehicles, currentCustomer);
                    break;
                case 2:
                    cout << "Selected \"Return Vehicle\": " << endl;
                    returnVehicle(vehicles, currentCustomer);
                    break;
                case 3:
                    cout << "Selected \"View Rented Vehicle\": " << endl;
                    currentCustomer.displayRentals();
                    break;
                default:
                    exit = true;
                    break;
                }
            }
            else{
                cout << "Invalid choice" << endl;
            }
        }
    }
    return 0;
}
// =====End Main=====

bool closeShop(){
  //function to return true false, to switch between users
  int answer;
  cout << endl;
  cout << "Do you want to rent any vehicle?" << endl; 
  cout << "1. Rent Vehicle" << endl; 
  cout << "0. Exit" << endl; 
  cout << "Enter your choice: ";
  answer = getIntInput();

  if(answer == 1){ return true; }
  else {cout << "====Shop closed!====" << endl; return false; }
}
void displayMenu(){  
    cout << endl;
    cout << "====Welcome the Rental Garage!====" << endl;
    cout << "What would you like to do?" << endl;
    cout << "1. Rent Vehicle" << endl;
    cout << "2. Return Vehicle" << endl;
    cout << "3. View Rented Vehicle" << endl;
    cout << "0. Exit" << endl;
    cout << "\n Enter a choice from menu: ";
}
void displayType(const vector<string> types){
    for (int i = 1; i <= types.size(); i++){
        cout << i << ". " << types[i - 1] << endl;
    }
    cout << "Enter Number: ";
}
//a quick loop to read through the names of customers<vector>
void showCustomers(const vector<Customer> &customers){
    if (customers.size() > 0){
        cout << "Customer served: ";
        for (Customer customer : customers){
            cout << "| " << customer.getName() << " | ";
        }
        cout << endl;
    }
}

// To get unique of vehicle type 
vector<string> getUniqueVehicleType(const vector<Rental>& vehicles){
    // Create a vector to store unique types
    vector<string> Vtype;
    for (const Rental& vehicle: vehicles){
        string types = vehicle.getType();

        // Check if the type is not already in the vector
        if (find(Vtype.begin(),Vtype.end(),types) == Vtype.end()){
            Vtype.push_back(types);
        }
    };
    return Vtype;
}

void rentalVehicle(vector<Rental> &vehicles, Customer &currentCustomer){
    // get all type of vehicles and display
    vector<string> types = getUniqueVehicleType(vehicles);
    displayType(types);

    cout << "Enter a choice from type: ";
    int choosetype = getIntInput();

    if (choosetype > 0 && choosetype <= types.size()){
        int i = 1;
        vector<Rental> vehicleList;
        string type = types[choosetype - 1];
        // looping and display all details, using Rental member function display
        for (Rental &vehicle : vehicles){
            if (vehicle.getType() == type){
                cout << "    --------------" << endl;
                cout << i << ". ";
                vehicle.display();
                vehicleList.push_back(vehicle);
                i++;
            }
        }
        // User choose Vehicle Number
        cout << "Choose " << type << " you want to rent : ";
        int chooseList = getIntInput();
        // Check User input
        if (chooseList > 0 && chooseList <= vehicleList.size()){
            cout << "How many days do you want to rent? : ";
            int days = getIntInput();
            // Final Rented Process
            for (Rental &vehicle : vehicles){
                if (vehicle.getModel() == vehicleList[chooseList - 1].getModel()){
                    currentCustomer.rented(vehicle, days);
                    vehicle.rented(days);
                    break;
                }
            }
        }
    }
}

void returnVehicle(vector<Rental>& vehicles, Customer& currentCustomer){
    int totalVehicle = currentCustomer.getRentedVehicleCount();
        // Display Rented Vehicle
        for(int i = 0; i < totalVehicle; i++){
            Rental vehicle = currentCustomer.getRentedVehicle(i);
            cout << i + 1 <<". ";
            currentCustomer.displayRented();
        }
    // Select Vehicle to Return
    if (totalVehicle > 0){
        cout << "Select your Vehicle : ";  
        int index = getIntInput();
        if (index <= totalVehicle){
            Rental vehicleRe = currentCustomer.getRentedVehicle(index - 1);
            cout << endl;
            cout << "You have selected "<< vehicleRe.getModel();
            currentCustomer.returnVehicle(vehicleRe);
            for (Rental& vehicle : vehicles){
                if(vehicle.getModel() == vehicleRe.getModel()){
                    vehicle.setStatus("Returned");
                    vehicle.returned();
                    break;
                }
            }
        }
    }
    else {
        cout << endl;
        cout << "===No Rented Vehicle in list!" <<endl;
    }
}
// Function to validate integer input
int getIntInput() {
    int i;
    while (true) {
        cin >> i;
        // Check if the input operation failed
        if (cin.fail()) {
            cin.clear();
            // Discard the invalid input
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } 
        else { return i; }
    }
}