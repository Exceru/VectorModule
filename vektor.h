#ifndef VEKTORUEBUNG_VEKTOR_H
#define VEKTORUEBUNG_VEKTOR_H

#include <stdio.h>

typedef struct Vektor Vektor;

Vektor * vektorErstellen(int eintraege);
void vektorfreigeben(Vektor *vektor);

void setzeEintrag(Vektor * vektor, float eintrag, int stelle);
float leseEintrag(Vektor * vektor, int stelle);
float inneresProdukt(Vektor * v1, Vektor * v2);
float norm(Vektor * vektor);

#endif //VEKTORUEBUNG_VEKTOR_H
