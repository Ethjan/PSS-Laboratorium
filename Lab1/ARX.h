#pragma once
#include "SISO.h"
#include <vector>
#include <deque>
#include <iostream>

class ARX : public SISO {
private:
    unsigned int s_k;
    double s_var;
    std::vector<double> s_A, s_B;
    std::deque<double> s_u, s_y;
public:    
    //Kontruktor
    ARX(std::vector<double> A = { -0.5 }, std::vector<double> B = { 1 }, unsigned int nk = 1, double var = 0.0):
        s_A(A), s_B(B), s_k(nk), s_var(var), s_y(std::deque<double>(1, 0)),s_u (std::deque<double>(1, 0)) {
        // Dopisanie odpowiedniej iloœci zer do wielomianu B zwi¹zanych z opoznieniem
        for (int i = 0; i < s_k; i++) {
            s_B.insert(s_B.begin() + i, 0);
        }
        s_y = (std::deque<double>(s_A.size(), 0));
        s_u = (std::deque<double>(s_B.size(), 0));
    };
 
    double symuluj(double we) override;

    std::ostream& WypiszParametry(std::ostream& strumien);

    void ZapisKonfiguracji();

};