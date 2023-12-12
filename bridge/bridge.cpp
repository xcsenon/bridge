#include <iostream>

// Implementor
class Implementor {
public:
    virtual void operationImpl() const = 0;
};

// ConcreteImplementorA
class ConcreteImplementorA : public Implementor {
public:
    void operationImpl() const override {
        std::cout << "Concrete Implementor A operation" << std::endl;
    }
};

// ConcreteImplementorB
class ConcreteImplementorB : public Implementor {
public:
    void operationImpl() const override {
        std::cout << "Concrete Implementor B operation" << std::endl;
    }
};

// Abstraction
class Abstraction {
protected:
    Implementor* implementor;

public:
    Abstraction(Implementor* implementor) : implementor(implementor) {}

    virtual void operation() const = 0;
};

// RefinedAbstraction
class RefinedAbstraction : public Abstraction {
public:
    RefinedAbstraction(Implementor* implementor) : Abstraction(implementor) {}

    void operation() const override {
        implementor->operationImpl();
    }
};

int main() {
    ConcreteImplementorA implementorA;
    ConcreteImplementorB implementorB;

    RefinedAbstraction abstractionA(&implementorA);
    RefinedAbstraction abstractionB(&implementorB);

    abstractionA.operation();
    abstractionB.operation();

    return 0;
}
