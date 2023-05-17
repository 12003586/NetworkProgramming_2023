#include "kaarten.h"

Kaarten::Kaarten()
{
    waarde = 1+(rand()%13);
    teken  = 1+(rand()%4);


    switch(teken)
    {
        case 1:
            kaartTeken = "Hearts";
        break;
        case 2:
            kaartTeken = "Clubs";
        break;
        case 3:
            kaartTeken = "Diamonds";
        break;
        case 4:
            kaartTeken = "Spades";
        break;

    }

    kaartWaarde = QString::number(waarde);

    kaart = kaartWaarde + " of " + kaartTeken;

}
