#include <iostream>
using namespace std;

class Language {
    public:
        virtual void define() {
            cout << "I am an instance of language" << endl;
        }

        virtual void greet() = 0;
};

class Spanish : public Language {
    public:
        void define() {
            cout << "Yo soy una instancia de Spanish, derivada de Language" << endl;
        }

        void greet() {
            cout << "Hola" << endl;
        }
};

class English : public Language {
public:
    void greet() { cout << "Hello" << endl; }

};

int main() {

    Language *x = new Spanish;
    Language *y = new English;

    x->define();
    x->greet();
    y->define();
    y->greet();
}