#include <iostream>
#include <vector>

class SISO {
public:
    virtual double symuluj(double we)=0;
};

class ARX: public SISO{
private:
    int s_dA, s_dB, s_k;
    double s_var;
    std::vector<double> s_A, s_B;
public:
    ARX(int ndA, int ndB, int nk, double var=0.0){
        s_dA=ndA;
        s_dB=ndB;
        s_k=nk;
        s_var=var;
    };
    ARX(std::vector<double> A={1,1}, std::vector<double> B={2}){
        s_A=A;
        s_B=B;
    };
    ~ARX(){};
    double symuluj(double we){
        return we;
    }

    void Wypisz(){
        std::cout<<"Wielomian A:"<<std::endl;
        std::cout<<"Wielomian B:"<<std::endl;
    }
};
//iner product

int main(){
    double wyjscie;
    ARX obiekt(1,1,1,0);
    wyjscie=obiekt.symuluj(5);
    std::cout<<"Wyjscie wynosi: "<<wyjscie<<std::endl;
    obiekt.Wypisz();
    return 0;
};




