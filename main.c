#include <stdio.h>

#include "vektor.h"

int main() {
    Vektor *a = vektorErstellen(5);
    Vektor *b = vektorErstellen(5);

    setzeEintrag(a,9.0f,0);
    setzeEintrag(a,47.0f,1);
    setzeEintrag(a,3.0f,2);
    setzeEintrag(a,395.0f,3);
    setzeEintrag(a,2.0f,4);

    setzeEintrag(b,26.0f,0);
    setzeEintrag(b,465.0f,1);
    setzeEintrag(b,73.0f,2);
    setzeEintrag(b,2.0f,3);
    setzeEintrag(b,9.0f,4);

    printf("Die Norm von a: %f\n", norm(a));
    printf("Die Norm von b: %f\n", norm(b));
    printf("Das innere Produkt von a und b: %f\n", inneresProdukt(a, b));
    return 0;
}
