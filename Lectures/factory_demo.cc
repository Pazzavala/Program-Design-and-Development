#include <iostream>
#include <string>

class IVehicle {
 public:
  virtual ~IVehicle() {};
  virtual std::string getName() const = 0;
};

class Car : public IVehicle {
 public:
  std::string getName() const override {
    return "car";
  }
};

class Lightrail : public IVehicle {
 public:
  std::string getName() const override {
    return "lightrail";
  }
};

class IFactory {
 public:
  virtual ~IFactory() {};
  virtual IVehicle* FactoryMethod() const = 0;
  std::string Create() const {
    IVehicle* vehicle = this->FactoryMethod();
    std::string result = "Factory: The same creator's code has just worked with " + vehicle->getName();
    delete vehicle;
    return result;
  }
};

class CarFactory : public IFactory {
 public:
  IVehicle* FactoryMethod() const override {
    return new Car();
  }
};

class LightrailFactory : public IFactory {
 public:
  IVehicle* FactoryMethod() const override {
    return new Lightrail();
  }
};

void ClientCode(const IFactory& factory) {
  std::cout << "Client: I'm not aware of the creator's class, but it still works.\n"
            << factory.Create() << std::endl;
}

int main() {
  std::cout << "App: Launched with the CarFactory.\n";
  IFactory* factory1 = new CarFactory();
  ClientCode(*factory1);
  std::cout << std::endl;
  std::cout << "App: Launched with the LightrailFactory.\n";
  IFactory* factory2 = new LightrailFactory();
  ClientCode(*factory2);

  delete factory1;
  delete factory2;
  return 0;
}