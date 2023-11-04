#include <iostream>

class IMovementStrategy {
    public:
        virtual ~IMovementStrategy() {}
        virtual std::string Move() const = 0;
};

class Triathlete {
    private:
        IMovementStrategy* movement;
    public:
        Triathlete(IMovementStrategy* s) {
            this->movement = s;
        }
        ~Triathlete() { delete movement; }
        void set_strategy(IMovementStrategy* s) {
            delete this->movement;
            this->movement = s;
        }
        void UseStrategy() const {
            std::string result = this->movement->Move();
            std::cout << result << std::endl;
        }
};

class Swim : public IMovementStrategy {
    public:
        std::string Move() const override {
            std::string result = "I'm swimming.";
            return result;
        }
};

class Cycle : public IMovementStrategy {
    public:
        std::string Move() const override {
            std::string result = "I'm cycling.";
            return result;
        }
};

class Biking : public IMovementStrategy {
    public:
        std::string Move() const override {
            std::string result = "I'm biking.";
            return result;
        }
};

class Facade {
    public:
        Facade(IMovementStrategy* ms) {
            this->triathlete = new Triathlete(ms);
        };
        ~Facade() { delete triathlete; }
        void ChangeStrategy(IMovementStrategy* newStrategy) {
            this->triathlete->set_strategy(newStrategy);
        }
        void PerformActivity() {
            this->triathlete->UseStrategy();
        }
    private:
        Triathlete* triathlete;
};

int main() {
    Swim* swimStrategy = new Swim();
    Cycle* cycleStrategy = new Cycle();
    Biking* bikingStrategy = new Biking();

    Facade triathleteFacade(swimStrategy);
    triathleteFacade.PerformActivity();

    triathleteFacade.ChangeStrategy(cycleStrategy);
    triathleteFacade.PerformActivity();

    triathleteFacade.ChangeStrategy(bikingStrategy);
    triathleteFacade.PerformActivity();

    return 0;
}