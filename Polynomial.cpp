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

bool comp(Monomio a,Monomio b){
    return (a.grado<=b.grado);
}

Polynomial Polynomial::operator=(Polynomial p)
{
    this->items.clear();
    Monomio temp={0,0};
    int n=p.items.size();
    for(int i = 0; i < n; i++)
    {
        temp.coeficiente = p.items[i].coeficiente;
        temp.grado = p.items[i].grado;
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
    for(int i = 0; i < p.items.size(); i++)
    {
        bool t=true;
        for(int j = 0; j < temp.items.size(); j++)
        {
            if(p.items[i].grado == temp.items[j].grado)
            {
                temp.items[j].coeficiente+=p.items[i].coeficiente;
                t=false;
                break;
            }
        }
        if(t){
            temp.items.push_back(p.items[i]);
        }
    }
    sort(temp.items.begin(),temp.items.end(),comp);
    temp.grado=temp.items[items.size()-1].grado;
    return temp;
}

Polynomial Polynomial::operator*(Polynomial p)
{
    Polynomial temp;
    Monomio temp2{0,0};
    //sort(p.items.begin(),p.items.end(),comp);
    int tam=p.degree()+this->degree()+1;
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
    temp.grado=tam-1;
    return temp;
}

Polynomial Polynomial::operator^(int n){
    Polynomial p=*this;
    for(int i = 0; i < n-1; i++){
         p=p*(*this);
    }
    return p;
}

Polynomial Polynomial::operator+(int n)
{
   Polynomial temp=*this;
   Monomio temp2{n,0};
   if(temp.items[0].coeficiente != 0 && temp.items[0].grado == 0){
       temp.items[0].coeficiente += n;
   }
   else
       temp.items.push_back(temp2);

   sort(temp.items.begin(),temp.items.end(),comp);
   return temp;
}
Polynomial Polynomial::operator*(int n)
{
   Polynomial temp=*this;
   for(int i = 0; i < temp.items.size(); i++){
        temp.items[i].coeficiente*=n;
   }
   return temp;
}

Polynomial operator+(int n,Polynomial pol)
{
    Polynomial pol2;
    pol2= pol + n;
    return pol2;
}

Polynomial operator*(int n,Polynomial pol)
{
    Polynomial pol2;
    pol2= pol * n;
    return pol2;
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

string Polynomial::get_expression(){
    string pol="";
    for(auto monomio : items){
        if(monomio.grado == 0){
            pol += to_string(monomio.coeficiente);
        }
        else{
            if(monomio.coeficiente > 0 ){
                pol += ((pol.length() == 0)? "" : "+") +to_string(monomio.coeficiente)+"x^"+to_string(monomio.grado);
            }
            else{
                pol += to_string(monomio.coeficiente)+"x^"+to_string(monomio.grado);
            }
        }
    }
    return pol;
}

void Polynomial::add(Monomio m){
    this->items.push_back(m);
    if(m.grado>grado){
        grado=m.grado;
    }
}

ostream& operator<<(ostream &a, Polynomial b)
{
    a << b.get_expression();
    return a;
}



