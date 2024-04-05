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
    
    virtual string getType() const = 0 ;

    string getModel() const{
        return model;
    }
    float getDaysFee() const{
        return daysFee;
    }

    void display() const {
        cout << " " << make << "\n";
        cout << "    " << model << "(Speed: " << speed << " km/hr)"
             << "\n";
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
    string getStatus() const {
        return this -> status;
    }
    string getType() const {
        return vehicle -> getType();
    }
    
    // display
    void displaytype(){
        vehicle -> display();
        cout << "    Status: " << status << endl;
    }
    // calculator function
    float rentFee() const {
        return vehicle -> getDaysFee() * daysRented;
    }
    
};
class Customer {
    private:
        string name;
        vector<Rental> rentedVehicle;
    public:
    Customer(const string& cname) :name(cname){}      


    string getName() const { return name; }
    
    void customerInformation(){
        cout << "Enter Your Name Here: ";
        cin >> name;
    }
};

// main funtion initializer
void displayMenu();
int getIntInput();
vector<string> allVehicleType(const vector<Rental>& vehicles);
void selectVehicle(const vector<Rental>& vehicles, const string& vtype);
void rentalVehicle(const vector<Rental>& vehicles);
void displayType (const vector<string> types);
bool openShop();

int main(){
    Customer customer("Customer");
    // customer.customerInformation();
    cout << customer.getName();

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
    while(openShop()){

    };

    bool exit = false;
    while (!exit){

        displayMenu();
        cin >> choice;
        if(choice >= 0 && choice < 4){
            switch (choice)
            {
            case 0:
                cout << "Goodbye, " << endl;
                exit = true;
                break;
            case 1:
                cout << "Selected \"Rent Vehicle\": "<< endl;
                rentalVehicle(vehicles);
                break;
            case 2:

                break;
            case 3:

                break;
            default:
                exit = true;
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
void rentalVehicle(const vector<Rental>& vehicles){
    vector<string> types = allVehicleType(vehicles);
    displayType(types);
    cout << "type size = "<< types.size() <<endl;
    cout << "Enter Number: "; 
    int choosetype = getIntInput();

    if (choosetype > 0 && choosetype <= types.size()){
        string type = types[choosetype - 1];
        selectVehicle(vehicles,type);
        return;
    }         
}

void displayType (const vector<string> types){
    for (int i = 1; i <= types.size(); i++){
        cout << i << ". "<< types[i-1] <<endl;
    }
}

void selectVehicle(const vector<Rental>& vehicles, const string& vtype){
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
    cout << "Choose " << vtype << " you want to rent :";
        int chooseList = getIntInput();
    if (chooseList > 0 && chooseList <= vehicleList.size()){
        cout << "okay" << endl;

        
    }else{
        chooseList = 1;
    cout<<"no";
    }
}


vector<string> allVehicleType(const vector<Rental>& vehicles){
    // Create a vector to store unique types
    vector<string> Vtype;
    for (const Rental& vehicle: vehicles){
        string types = vehicle.getType();

        // Check if the type is not already in the vector
        if (find(Vtype.begin(),Vtype.end(),types) == Vtype.end()){
            // If not found, display the type and add it to the vector
            Vtype.push_back(types);
        }
    };
    return Vtype;
}

bool openShop(){
    string customerName;
    
}
// Function to validate integer input
int getIntInput() {
    int i;
    while (true) {
        cin >> i;
        // Check if the input operation failed
        if (cin.fail()) {
            // Clear the error flag
            cin.clear();
            // Discard the invalid input
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            // Notify the user of the error
        } else {
            // Input operation succeeded, return the integer
            return i;
        }
    }
}