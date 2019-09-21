//
// Created by ruben on 9/12/2019.
//

#ifndef POLINOMIO_POLINOMIO_H
#define POLINOMIO_POLINOMIO_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Monomio {
    int coeficiente;
    int grado;
};


class Polynomial {
private:
    vector<Monomio> items;
    int grado;
public:
    Polynomial();
    int degree();

    Polynomial operator=(Polynomial p);
    Polynomial operator+(Polynomial p);
    Polynomial operator*(Polynomial p);
    Polynomial operator+(int n);
    Polynomial operator*(int n);
    friend Polynomial operator+(int n,Polynomial p);
    friend Polynomial operator*(int n,Polynomial p);

    Polynomial operator^(int n);

    Polynomial operator+=(Polynomial p);
    Polynomial operator+=(int n);

    string get_expression();

    void add(Monomio a);

    friend ostream& operator<<(ostream &a, Polynomial b);
    ~Polynomial()=default;


};

#endif //POLINOMIO_POLINOMIO_H
