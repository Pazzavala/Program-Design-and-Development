#include <string>
#include <iostream>
using namespace std;

class Pizza {
    protected:
        float cost;
        float rate;
    
    public:
        float getTotalCost() {
            return cost * rate;
        }
};

class OneTop : public Pizza {
    public:
        OneTop() {
            this->cost = 8.99;
        }
};

class TwoTop : public Pizza {
    public:
        TwoTop() {
            this->cost = 9.99;
        }
};

class BuildYourOwn : public Pizza {
    public:
        BuildYourOwn() {
            this->cost = 10.99;
        }
};

class HR1 : public OneTop {
    public:
        HR1() {
            this->rate = 1.0;
        }
};

class TH1 : public OneTop {
    public:
        TH1() {
            this->rate = 0.8;
        }
};

class CO1 : public OneTop {
    public:
        CO1() {
            this->rate = 1.2;
        }
};

class HR2 : public TwoTop {
    public:
        HR2() {
            this->rate = 1.0;
        }
};

class TH2 : public TwoTop {
    public:
        TH2() {
            this->rate = 0.8;
        }
};

class CO2 : public TwoTop {
    public:
        CO2() {
            this->rate = 1.2;
        }
};

class HRB : public BuildYourOwn {
    public:
        HRB() {
            this->rate = 1.0;
        }
};

class THB : public BuildYourOwn {
    public:
        THB() {
            this->rate = 0.8;
        }
};

class COB : public BuildYourOwn {
    public:
        COB() {
            this->rate = 1.2;
        }
};

class IPizzaFactory {
    public:
        virtual OneTop* createOneTopping() = 0;
        virtual TwoTop* createTwoTopping() = 0;
        virtual BuildYourOwn* createBuildYourOwn() = 0;
};

class HighriseFactory : public IPizzaFactory {
    public:
        OneTop* createOneTopping() {
            return new HR1();
        }

        TwoTop* createTwoTopping() {
            return new HR2();
        }

        BuildYourOwn* createBuildYourOwn() {
            return new HRB();
        }
};

class ThinFactory : public IPizzaFactory {
    public:
        OneTop* createOneTopping() {
            return new TH1();
        }

        TwoTop* createTwoTopping() {
            return new TH2();
        }

        BuildYourOwn* createBuildYourOwn() {
            return new THB();
        }
};

class CauliflowerFactory : public IPizzaFactory {
    public:
        OneTop* createOneTopping() {
            return new CO1();
        }

        TwoTop* createTwoTopping() {
            return new CO2();
        }

        BuildYourOwn* createBuildYourOwn() {
            return new COB();
        }
};

class Facade {
    private:
        HighriseFactory* hrf;
        ThinFactory* thf;
        CauliflowerFactory* cof;
        string crust;
        string pizzaOption;
        int amount;

        void run() {
            query();

            // create pizza
            Pizza* pizza = createPizza();

            // print amount
            cout << "The Total is: " << amount * pizza->getTotalCost() << endl;
        }

        void query() {
            // ask for crust, amount pizza
            cout << "What kind of pizza would you like? ";
            getline(cin, pizzaOption);

            cout << "What kind of crust would you like? ";
            getline(cin, crust);

            cout << "How many would you like? ";
            cin >> amount;

        }

        Pizza* createPizza() {
            Pizza* pizza;
            if (pizzaOption == "One Topping") {
                if (crust == "High Rise") {
                    pizza = hrf->createOneTopping();
                } else if (crust == "Thin Crust") {
                    pizza = thf->createOneTopping();
                } else if (crust == "Cauliflower") {
                    pizza = thf->createOneTopping();
                }
            } else if (pizzaOption == "Two topping") {
                if (crust == "High Rise") {
                    pizza = hrf->createTwoTopping();
                } else if (crust == "Thin Crust") {
                    pizza = thf->createTwoTopping();
                } else if (crust == "Cauliflower") {
                    pizza = thf->createTwoTopping();
                }
            } else if(pizzaOption == "Build Your Own") {
                if (crust == "High Rise") {
                    pizza = hrf->createBuildYourOwn();
                } else if (crust == "Thin Crust") {
                    pizza = thf->createBuildYourOwn();
                } else if (crust == "Cauliflower") {
                    pizza = thf->createBuildYourOwn();
                }
            }
            return pizza;
        }

    public:
        Facade() {
            hrf = new HighriseFactory;
            thf = new ThinFactory;
            cof = new CauliflowerFactory;
            run();
        }

        ~Facade() {
            delete hrf;
            delete thf;
            delete cof;
        }
};

int main() {
    Facade* f = new Facade();
    delete f;
    return 0;
}