#include <iostream>



/**
 * Duck Class
*/
class Duck {
  protected:
    float cost;
    float tax;
    
  public:
    
    virtual void Identify(void) = 0;
    float getTax() {
        return this->tax;
    }
    float getCost() {
        return this->cost;
    }
    float getTotalCost() {
      return this->cost*(1.0+this->tax);
    }
};

/**
 * Mallard Ducks
*/
class Mallard : public Duck {
  public:
    Mallard() {
        this->cost = 12.61;
    };
    void Identify(void) {
      std::cout << "I am a Mallard duck\n";
    }
};

class MinnesotanMallard : public Mallard {
  public:
    MinnesotanMallard() {
        this->tax = .06875;
    }
    void Identify(void) {
      std::cout << "I am a Mallard duck from MN\n";
    }
};

class NYMallard : public Mallard {
  public:
    NYMallard() {
        this->tax = 0.045;
    }
    void Identify(void) {
      std::cout << "I am a Mallard duck from NY\n";
    }
};

class CalifornianMallard : public Mallard {
  public:
    CalifornianMallard() {
      this->tax = 0.0725;
    }
  
    void Identify(void) {
      std::cout << "I am a Mallard duck from MN\n";
    }
};

/**
 * Wood Ducks
*/
class Woodduck : public Duck {
  public:
    Woodduck() {
        this->cost = 150;
    }
};

class MinnesotanWoodduck : public Woodduck {
  public:
    MinnesotanWoodduck() {
        this->tax = .06875;
    }
    void Identify(void) {
      std::cout << "I am a Wood duck from MN\n";
    }
};

class NYWoodduck : public Woodduck {
  public:
    NYWoodduck() {
        this->tax = 0.045;
    }
    void Identify(void) {
      std::cout << "I am a Wood duck from NY\n";
    }
};

class CalifornianWoodduck : public Woodduck {
  public:
    CalifornianWoodduck() {
      this->tax = 0.0725;
    }
    void Identify(void) {
      std::cout << "I am a Wood duck from CA\n";
    }
};

/**
 * Rubber Ducks
*/
class Rubberduck : public Duck  {
  public:
    Rubberduck() {
        this->cost = 0.01;
    }
    void Identify(void) {
      std::cout << "I am a Rubber duck\n";
    }
};

class MinnesotanRubberduck : public Rubberduck {
  public:
    MinnesotanRubberduck() {
        this->tax = 0.06875;
    }
    void Identify(void) {
      std::cout << "I am a Rubber duck from MN\n";
    }
};

class NYRubberduck : public Rubberduck {
  public:
    NYRubberduck() {
        this->tax = .045;
    }
    void Identify(void) {
      std::cout << "I am a Rubber duck from NY\n";
    }
};

class CalifornianRubberduck : public Rubberduck {
  public:
    CalifornianRubberduck() {
      this->tax = 0.0725;
    }
    void Identify(void) {
      std::cout << "I am a Rubber duck from CA\n";
    }
};

/**
 * Factories
*/
class IFactory {
  public:
    IFactory() {};
    virtual Mallard* createMallard() = 0;
    virtual Woodduck* createWoodduck() = 0;
    virtual Rubberduck* createRubberduck() = 0;
};

class MNFactory : public IFactory {
  public:
    MNFactory() {};
    Mallard* createMallard() {
      return new MinnesotanMallard();
    }
    Woodduck* createWoodduck() {
      return new MinnesotanWoodduck();
    }
    Rubberduck* createRubberduck() {
      return new MinnesotanRubberduck();
    }
};

class NYFactory : public IFactory {
  public:
    NYFactory() {};
    Mallard* createMallard() {
      return new NYMallard();
    }
    Woodduck* createWoodduck() {
      return new NYWoodduck();
    }
    Rubberduck* createRubberduck() {
      return new NYRubberduck();
    }
};

class CAFactory : public IFactory {
  public:
    CAFactory() {};
    Mallard* createMallard() {
      return new CalifornianMallard();
    }
    Woodduck* createWoodduck() {
      return new CalifornianWoodduck();
    }
    Rubberduck* createRubberduck() {
      return new CalifornianRubberduck();
    }
};

class Facade {
  private:
    MNFactory* mnf;
    CAFactory* caf;
    NYFactory* nyf;
    std::string state;
    std::string type;
  public:
    Facade() {
        this->mnf = new MNFactory();
        this->caf = new CAFactory();
        this->nyf = new NYFactory();
        this->run();
    }
    ~Facade() {
        delete mnf;
        delete caf;
        delete nyf;
    }
  private:
    void run() {
        query();
        Duck* d = createDuck();
        
        std::cout << "The total cost for a " << 
        this->type << " duck from " << this->state << 
          " is: $" << d->getTotalCost() << std::endl;
    }
    
    Duck* createDuck()
    {
      Duck* duck;
      if(this->state=="MN" && this->type=="Mallard") {
          duck = mnf->createMallard();
          duck->Identify();
      }
      else if(this->state=="MN" && this->type=="Wood") {
          duck = mnf->createWoodduck();
          duck->Identify();
      }
      else if(this->state=="MN" && this->type=="Rubber") {
          duck = mnf->createRubberduck();
          duck->Identify();
      }
      else if(this->state=="NY" && this->type=="Mallard") {
          duck = nyf->createMallard();
          duck->Identify();
      }
      else if(this->state=="NY" && this->type=="Wood") {
          duck = nyf->createWoodduck();
      }
      else if(this->state=="NY" && this->type=="Rubber") {
          duck = nyf->createRubberduck();
      }
      else if(this->state=="CA" && this->type=="Mallard") {
          duck = caf->createMallard();
          duck->Identify();
      }
      else if(this->state=="CA" && this->type=="Wood") {
          duck = caf->createWoodduck();
          duck->Identify();
      }
      else if(this->state=="CA" && this->type=="Rubber") {
          duck = caf->createRubberduck();
          duck->Identify();
      }
      else {
        std::cerr << "I have no idea how you got here" << std::endl;
        duck = nullptr;
      }
      return duck;
    }
    
    void query() {
        Duck* duck;
        std::string state;
        std::cout << "What state are you ordering from? (MN, NY, CA): " << std::endl;
        std::cin >> state;
        while (state.compare("MN") != 0 && state.compare("NY") != 0 && state.compare("CA") != 0) {
            std::cout << "Invalid Response. What state are you ordering from? (MN, NY, CA): " << std::endl;
            std::cin >> state;
        }
        std::string type;
        std::cout << "What kind of duck do you want? (Mallard, Wood, Rubber)" << std::endl;
        std::cin >> type;
        while (type.compare("Mallard") != 0 && type.compare("Wood") != 0 && type.compare("Rubber") != 0) {
          std::cout << "Invalid Response. What kind of duck do you want? (Mallard, Wood, Rubber): " << std::endl;
          std::cin >> type;
        }
        this->state = state;
        this->type = type;
        return;
    }
};

int main() {
    Facade* f = new Facade();
    delete f;
    return 0;
}

/*
Example Output 1:
What state are you ordering from? (MN, NY, CA): 
MN
What kind of duck do you want? (Mallard, Wood, Rubber):
Mallard
I am a Mallard duck from MN //this should come from createDuck()
The total cost for a Mallard duck from MN is: $13.4769 // this should come from run()

Example Output 2:
What state are you ordering from? (MN, NY, CA): 
CA
What kind of duck do you want? (Mallard, Wood, Rubber)
Wood
I am a Wood duck from CA //this should come from createDuck()
The total cost for a Wood duck from CA is: $160.875 // this should come from run()
*/