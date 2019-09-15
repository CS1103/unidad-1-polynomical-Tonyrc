//
// Created by ruben on 9/12/2019.
//

#ifndef POLINOMIO_POLINOMIO_H
#define POLINOMIO_POLINOMIO_H

#include <vector>
using namespace std;

struct Monomio {
    int coeficiente;
    int grado;
};

bool comp(Monomio a,Monomio b){
    return (a.grado<b.grado);
}

class Polynomial {
private:
    vector<Monomio> items;
    int grado;
public:
    Polynomial();
    int degree();

    Polynomial& operator=(int a[n][2]);
    Polynomial operator+(Polynomial p);
    Polynomial operator*(Polynomial p);

    Polynomial operator+(int n);
    Polynomial operator*(int n);

    Polynomial operator^(int n);

    Polynomial operator+=(Polynomial p);
    Polynomial operator+=(int n);

    string get_expression(Polynomial p);

    ~Polynomial()=default;


};

#endif //POLINOMIO_POLINOMIO_H
