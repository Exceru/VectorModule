#include "vektor.h"

#include "stdlib.h"
#include "math.h"

struct Vektor {
    int groesse;
    float * eintraege;
};

Vektor *vektorErstellen(int eintraege) {
    if(eintraege > 0) {
        Vektor * vektor = malloc(sizeof(Vektor));

        if (vektor == NULL) {
            fprintf(stderr, "Kein Speicher mehr\n");
            exit(EXIT_FAILURE);
        }

        vektor->groesse = eintraege;

        // Heap Speicherallokation für die Vektoreinträge
        vektor->eintraege = (float*) calloc(eintraege, sizeof(float));

        if (vektor->eintraege == NULL) {
            fprintf(stderr, "Kein Speicher mehr\n");
            exit(EXIT_FAILURE);
        }

        // Einträge initialisieren
        for(int i = 0; i < vektor->groesse; i++){
            vektor->eintraege[i] = 0.0f;
        }

        return vektor;

    } else {
        fprintf(stderr,
                "Vektor muss bei Erstellung mindestens einen Eintrag besitzen. \n");
        exit(EXIT_FAILURE);
    }

}

void vektorfreigeben(Vektor *vektor) {
    free(vektor->eintraege);
    free(vektor);
}

void setzeEintrag(Vektor *vektor, float eintrag, int stelle) {
    if((stelle > (vektor->groesse - 1)) || (stelle < 0)) {
        fprintf(stderr, "Eintrag kann nicht gesetzt werden. Index invalide.\n");
        exit(EXIT_FAILURE);
    }

    vektor->eintraege[stelle] = eintrag;
}

float leseEintrag(Vektor *vektor, int stelle) {
    if((stelle > (vektor->groesse - 1)) || (stelle < 0)) {
        fprintf(stderr, "Eintrag kann nicht gelesen werden. Index invalide.\n");
        exit(EXIT_FAILURE);
    }

    return *(vektor->eintraege + stelle);
}

float inneresProdukt(Vektor *v1, Vektor *v2) {
    if(v1->groesse != v2->groesse){
        fprintf(stderr, "Vektoren haben nicht die gleiche Länge. "
                        "Inneres Produkt kann nicht berechnet werden.\n");
        exit(EXIT_FAILURE);
    } else {
        float inneresProdukt = 0.0f;

        for(int i = 0; i < v1->groesse; i++) {
            inneresProdukt += (v1->eintraege[i] * v2->eintraege[i]);
        }

        return inneresProdukt;
    }
}

float norm(Vektor *vektor) {
    float produkt = inneresProdukt(vektor, vektor);
    return sqrtf(produkt);
}
