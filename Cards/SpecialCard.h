#ifndef Special_Card_H
#define Special_Card_H

#include "Card.h"


class SpecialCard : public Card {

public:
    SpecialCard(std::string name);
    //-------------------------Methods---------------------------
    virtual void printInfo(ostream& os) const override;
    //-----------------------------------------------------------
    virtual ~SpecialCard()= default;
};

#endif