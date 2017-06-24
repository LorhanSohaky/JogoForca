#include "interacao_arquivo.h"
#include <dstring.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned int sortear_linha( unsigned int quantidade_linhas ) {
    srand( time( NULL ) );
    return rand() % quantidade_linhas;
}

unsigned int pegar_total_linhas( char *arquivo_palavra ) {
    FILE *arquivo;
    unsigned int quantidade_linhas = 0;

    arquivo = fopen( arquivo_palavra, "r" );
    if( !arquivo ) {
        return -1;
    }

    while( EOF != fscanf( arquivo, "%*[^\n]" ) ) {
        fscanf( arquivo, "%*c" );
        quantidade_linhas++;
    }

    fclose( arquivo );

    return quantidade_linhas;
}

void ir_para_linha( FILE *arquivo, unsigned int linha ) {
    unsigned int i = 0;

    while( linha != i ) {
        fscanf( arquivo, "%*[^\n]" );
        fscanf( arquivo, "%*c" );
        i++;
    }
}

String *ler_string( FILE *arquivo ) {
    char tmp[101];

    String *string = string_new();

    if( !string ) {
        return NULL;
    }

    while( fscanf( arquivo, "%100[^\n]", tmp ) ) {
        string_concat_char_array( string, tmp );
    }

    return string;
}
