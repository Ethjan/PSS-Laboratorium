#pragma once

///Klasa SISo
class SISO {
public:
    virtual double symuluj(double we) = 0;
    inline virtual ~SISO(){};
};
