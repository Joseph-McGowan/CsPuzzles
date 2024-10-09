//
// Created by joseph on 09/10/2024.
//
#include "iostream"
#include "string"


using namespace std;

class automobile {
public:
    automobile() {
        setModelYear(-1);
        setModelName("Undefined");
        setManufacturerName("undefined");
    }
    friend ostream& operator<<(ostream& os, const automobile& a);

    string getManufacturerName() {
        return _manufacturerName;
    }
    void setManufacturerName(string name) {
        _manufacturerName = name;
    }

    string getModelName() {
        return _modelName;
    }
    void setModelName(string modelName) {
        if(modelName.empty()) {
            cout << "Error, name can't be empty" << "\n";
            return;
        }
        _modelName = modelName;
    }

    int getModelYear() {
        return _modelYear;
    }
    void setModelYear(int year) {
        _modelYear = year;
    }

    string autoDescription () {
        string returnString = to_string(getModelYear()) + " " + this->_manufacturerName + " " + this->_modelName + "\n";
        return returnString;
    }

    int automobileAge() {
        //implement chrono to get up to date info
        return 2024 - getModelYear();
    }


private:
    string _manufacturerName;
    string _modelName;
    int _modelYear;

};



ostream& operator<< (ostream& os, automobile& a) {
    os << a.autoDescription();
    return os;
}



int main() {

    automobile car1;
    car1.setManufacturerName("Renault");
    car1.setModelName("Clio");
    car1.setModelYear(2018);

    cout << car1.autoDescription();

    automobile car2;
    cout << car2.autoDescription();
    car2.setManufacturerName("TestCar");
    cout << car2.autoDescription();

    cout << car1;

    cout << car1.automobileAge();

}