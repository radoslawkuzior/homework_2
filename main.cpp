#include <iostream>
#include <vector>
#include <memory>
#include <string>
using namespace std;
class ElectronicDevice{
protected:
    string brand;
    string model;
public:
    ElectronicDevice(string brand, string model) : brand(brand), model (model) {};
    virtual void display() {
        cout<<"Brand: "<<brand<<", Model: "<<model;
    }
    virtual ~ElectronicDevice() {}
};
class Smartphone : public ElectronicDevice{
protected:
    int storageCapacity;
public:
    Smartphone(string brand, string model, int storageCapacity) : ElectronicDevice(brand, model), storageCapacity(storageCapacity) {};
    void display(){
        ElectronicDevice::display();
        cout<<", Storage Capacity: "<< storageCapacity;
    }
};
class Smartwatch : public ElectronicDevice{
protected:
    bool hasGPS;
public:
    Smartwatch(string brand, string model, bool hasGPS) : ElectronicDevice(brand, model), hasGPS(hasGPS)
    {};
    void display(){
        ElectronicDevice::display();
        cout<<", Has GPS?: "<<(hasGPS ? "Yes" : "No");
    }
};
class Laptop : public ElectronicDevice{
protected:
    int ramSize;
public:
    Laptop(string brand, string model, int ramSize) : ElectronicDevice(brand, model), ramSize(ramSize) {};
    void display (){
        ElectronicDevice::display();
        cout<<", Ram Size:"<<ramSize;}
};
class GamingLaptop : public Laptop{
protected:
    string gpuModel;
public:
    GamingLaptop (string brand, string model, int ramSize, string gpuModel) :Laptop(brand, model, ramSize), gpuModel(gpuModel) {};
    void display (){
        Laptop::display();
        cout<<", GPU Model:"<<gpuModel;}
};
class Store{
private:
    vector<unique_ptr<ElectronicDevice>> devices;
public:
    void addDevice(unique_ptr<ElectronicDevice> device){
        devices.push_back(std::move(device));
    }
    void displayDevices(){
        for (const auto& device : devices){
            device->display();
            cout<<endl;
        }
    }
};
int main()
{
    Store store;
    auto smartwatch = make_unique<Smartwatch>("Samsung", "Watch 5", true);
    auto smartphone = make_unique<Smartphone>("Iphone", "13 Pro", 64000);
    auto laptop = make_unique<Laptop>("Lenovo", "Legion", 12000);
    auto laptop2 = make_unique<Laptop>("Dell", "ForgotModel", 8000);
    auto gaminglaptop = make_unique<GamingLaptop>("Acer", "Nitro 5", 16000, "Nvidia Geforce 3050");
    store.addDevice(std::move(smartwatch));
    store.addDevice(std::move(smartphone));
    store.addDevice(std::move(laptop));
    store.addDevice(std::move(laptop2));
    store.addDevice(std::move(gaminglaptop));
    store.displayDevices();
    return 0;
}
