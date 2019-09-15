//
// Created by rudri on 9/12/2019.
//

#include <stdexcept>
#include <iostream>
#include <vector>
#include <algorithm>
#include "Polynomial.h"

Polynomial::Polynomial():grado(0){}

int Polynomial::degree()
{
    return grado;
}

Polynomial& Polynomial::operator=(int a[n][2])
{
    this->items.clear();
    Monomio temp={0,0};
    for(int i = 0; i < n; i++)
    {
        temp.coeficiente = a[i][0];
        temp.grado = a[i][1];
        this->items.push_back(temp);
        if(temp.grado > this->grado)
        {
            this->grado = temp.grado;
        }
    }
    sort(this->items.begin(),this->items.end(),comp);
    return *this;
}

Polynomial Polynomial::operator+(Polynomial p)
{
    Polynomial temp=*this;
    Monomio temp2={0,0};
    for(int i = 0; i < p.items.size(); i++)
    {
        for(int j = 0; j < this->items.size(); j++)
        {
            if(p.items[i].grado == this->items[j].grado)
            {
                temp2.grado = p.items[i].grado;
                temp2.coeficiente = p.items[i].coeficiente + this->items[j].coeficiente;
                temp.items.push_back(temp2);
            }
            else
            {
                temp2.grado = p.items[i].grado;
                temp2.coeficiente = p.items[i].coeficiente;
                temp.items.push_back(temp2);
            }
        }
    }
    sort(temp.items.begin(),temp.items.end(),comp);
    return temp;
}

Polynomial Polynomial::operator*(Polynomial p)
{
    Polynomial temp;
    Monomio temp2{0,0};
    sort(p.items.begin(),p.items.end(),comp);
    int tam=p.items.size()+this->items.size()+1;
    int coefi[tam];
    for(int i = 0; i < tam; i++){
         coefi[i]=0;
    }
    for(int i = 0; i < p.items.size(); i++)
    {
        for(int j = 0; j < this->items.size(); j++)
        {
            coefi[(p.items[i].grado)+(this->items[j].grado)]+=p.items[i].coeficiente*this->items[j].coeficiente;
        }
    }
    for(int i=0; i < tam; i++){
        if(coefi[i]!=0){
            temp2.coeficiente=coefi[i];
            temp2.grado=i;
            temp.items.push_back(temp2);
        }
    }
    return temp;
}

Polynomial Polynomial::operator^(int n){
    Polynomial p=*this;
    for(int i = 0; i < n; i++){
         p=p*p;
    }
    return p;
}

Polynomial Polynomial::operator+(int n)
{
   Monomio temp2{n,0};
   if(this->items[0].coeficiente != 0 && this->items[0].grado == 0){
       this->items[0].coeficiente += n;
   }
   else
       this->items.push_back(temp2);

   sort(this->items.begin(),this->items.end(),comp);
   return *this;
}
Polynomial Polynomial::operator*(int n)
{
   for(int i = 0; i < this->items.size(); i++){
        this->items[i].coeficiente*=n;
   }
   return *this;
}

Polynomial Polynomial::operator+=(Polynomial p)
{
    *this = *this + p;
    return *this;
}
Polynomial Polynomial::operator+=(int n)
{
    *this = *this + n;
    return *this;
}

string Polynomial::get_expression(Polynomial p){
    string pol="";
    for(auto monomio : p.items){
        if(monomio.grado == 0){
            pol += to_string(monomio.coeficiente);
        }
        else{
            if(monomio.coeficiente > 0){
                pol += "+"+to_string(monomio.coeficiente)+"x^"+to_string(monomio.grado);
            }
            else{
                pol += "-"+to_string(monomio.coeficiente)+"x^"+to_string(monomio.grado);
            }
        }
    }
    return pol;
}



