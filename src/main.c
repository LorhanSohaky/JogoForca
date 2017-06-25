#include "jogo_forca.h"
#include <stdio.h>

int main( int argc, char *argv[] ) {
    if( argc < 3 ) {
        printf( "Argumentos invalidos\n" );
        printf( "Voce deve passar o arquivo com as palavras e o arquivo com as dicas\n" );
        return 1;
    } else {
        return jogar( argv[1], argv[2] );
    }
}
