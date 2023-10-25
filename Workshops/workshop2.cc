#include <iostream>

using namespace std;

class MotorizedVehicle {
    public:
        virtual void throttle() {
            cout << "Speed up\n";
        }

        virtual void brake() {
            cout << "Slows down\n";
        }

        virtual void refule() {
            cout << "Refules\n";
        }

        virtual void display() {
            cout << "Motorized Vehicle\n";
        }
};

class Gas : public virtual MotorizedVehicle {
    public:

        void display() override {
            cout << "Gas\n";
        }
};

class Electric : public virtual MotorizedVehicle {
    public:

        void brake() {
            cout << "battery changes + Slows\n";
        }

        void refule() {
            cout << "Charging\n";
        }

        void display() override {
            cout << "Electric\n";
        }
};

class Hybrid : public Gas, public Electric {
    public:

        void brake() override {
            cout << "Hybrid brake\n";
        }

        void display() override {
            cout << "Hybrid\n";
        }
};

class Shape3D {
    public:
        float getW() {
            return width;
        }

        float getH() {
            return height;
        }

        float getL() {
            return length;
        }

        void setW(float width) {
            this->width = width;
        }

        void setH(float height) {
            this->height = height;
        }

        void setL(float length) {
            this->length = length;
        }

        virtual float getVolume() = 0;

    protected:
        float width;
        float height;
        float length;
};

class Sphear : public Shape3D {
    public:
        float getVolume() override {
            return 3/4 * 3.14 * width * width * width;
        }
};

class Cube : public Shape3D {
    public:
        float getVolume() override {
            return width * width * width;
        }
};

class RectPrism : public Shape3D {
    public:
        float getVolume() override {
            return length * width * height;
        }
};


int main() {
    MotorizedVehicle* motorizedV1 = new Electric();
    Hybrid* hybridV1 = new Hybrid();

    cout << endl;
    motorizedV1->display();
    motorizedV1->brake();
    motorizedV1->refule();
    motorizedV1->throttle();
    cout << endl;

    hybridV1->display();
    hybridV1->brake();
    hybridV1->refule();
    hybridV1->throttle();

    delete motorizedV1;
    delete hybridV1;

    return 0;
}