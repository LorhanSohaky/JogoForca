#ifndef INTERACAO_ARQUIVO_H
#define INTERACAO_ARQUIVO_H

#include <dstring.h>

struct st_partida {
    String *palavra;

    unsigned int fk_dica;

    String *dica;
};

typedef struct st_partida Partida;

void sortear_partida( Partida *partida, char *arquivo_palavra, char *arquivo_dica );

#endif
