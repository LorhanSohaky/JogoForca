#include "interacao_arquivo.h"
#include <dstring.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void pegar_palavra( Partida *partida, char *arquivo_palavra, unsigned int linha_palavra );
void pegar_dica( Partida *partida, char *arquivo_dica, unsigned int linha_dica );

void ir_para_linha( FILE *arquivo, unsigned int linha );
String *ler_string( FILE *arquivo );

int pegar_total_linhas( char *arquivo_palavra );
unsigned int sortear_linha( unsigned int quantidade_linhas );

void sortear_partida( Partida *partida, char *arquivo_palavra, char *arquivo_dica ) {
    int total_linhas;

    total_linhas = pegar_total_linhas( arquivo_palavra );

    if( total_linhas == -1 ) {
        return;
    }

    pegar_palavra( partida, arquivo_palavra, sortear_linha( total_linhas ) );

    if( partida->palavra ) {
        pegar_dica( partida, arquivo_dica, partida->fk_dica );
    }
}

void pegar_palavra( Partida *partida, char *arquivo_palavra, unsigned int linha_palavra ) {
    FILE *arquivo;

    arquivo = fopen( arquivo_palavra, "r" );
    if( !arquivo ) {
        return;
    }

    ir_para_linha( arquivo, linha_palavra );

    fscanf( arquivo, "%d", &partida->fk_dica );

    fscanf( arquivo, "%*c" );

    partida->palavra = ler_string( arquivo );

    fclose( arquivo );
}

void pegar_dica( Partida *partida, char *arquivo_dica, unsigned int linha_dica ) {
    FILE *arquivo;

    arquivo = fopen( arquivo_dica, "r" );
    if( !arquivo ) {
        return;
    }

    ir_para_linha( arquivo, linha_dica );
    partida->dica = ler_string( arquivo );

    fclose( arquivo );
}

unsigned int sortear_linha( unsigned int quantidade_linhas ) {
    srand( time( NULL ) );
    return rand() % quantidade_linhas;
}

int pegar_total_linhas( char *arquivo_palavra ) {
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
        if( !string_concat_char_array( string, tmp ) ) {
            return NULL;
        }
    }

    return string;
}
