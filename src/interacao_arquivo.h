#ifndef INTERACAO_ARQUIVO_H
#define INTERACAO_ARQUIVO_H

#include <dstring.h>

struct st_dica {
    String *dica;
};

typedef struct st_dica Dica;

struct st_palavra {
    String *palavra;

    unsigned int fk_dica;

    Dica dica;
};

typedef struct st_palavra Palavra;

Palavra sortear_palavra( char *arquivo_palavra, char *arquivo_dica );

#endif
