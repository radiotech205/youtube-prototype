#include <iostream>
#include <string>
using namespace std;

class Animal
{
public:
    virtual void SetName(string* name) = 0;
    virtual string GetName() = 0;
    virtual Animal* Clone() const = 0;
};

class Sheep : public Animal
{
private:
    string* name;
    Sheep(const Sheep& donor) {this->name = donor.name;}
public:
    Sheep() {}
    ~Sheep() {delete name;}
    void SetName(string* name) {this->name = name;}
    string GetName() {return *name;}
    Sheep* Clone() const {return new Sheep(*this);}
};

int main()
{
    Sheep* sheepDonor = new Sheep();
    string name = "Dolly";
    sheepDonor->SetName(&name);

    Sheep* sheepClone = sheepDonor->Clone();

    cout << sheepDonor->GetName() << endl;
    cout << sheepClone->GetName() << endl;

    cout << "Hello World!" << endl;
    return 0;
}
