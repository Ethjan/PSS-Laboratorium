#pragma once
#include "SISO.h"
#include <vector>

class ARX : public SISO {
private:
    int s_dA, s_dB, s_k;
    double s_var;
    std::vector<double> s_A, s_B, s_u = {1 , 4 }, s_y = {0};
public:    
    ARX(std::vector<double> A = { 1,1 }, std::vector<double> B = { 2 }, int nk = 1, double var = 0.0) {
        s_A = A;
        s_B = B;
        s_k = nk;
        s_var = var;
        for (int i = 0; i < s_k; i++) {
            s_B.push_back(i);
        }
        s_y = std::vector<double>(s_A.size(), 0);
        s_u = std::vector<double>(s_B.size(), 0);
    };
 
    double symuluj(double we);

    void WypiszParametry();

    void WypiszWeWy();
};