#include "jogo_forca.h"
#include "interacao_arquivo.h"
#include "viewer.h"
#include <dstring.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX_ERRO 6

typedef struct {
    bool ganhou;

    Palavra palavra;

    unsigned int quantidade_erros;
    String *letras_erradas;
    String *mascara;

    char *arquivo_dica;
    char *arquivo_palavra;
} Jogo;

void init_configuracoes( Jogo *jogo, char *arquivo_palavra, char *arquivo_dica ) {
    jogo->quantidade_erros = 0;
    jogo->ganhou = false;

    jogo->palavra = sortear_palavra( arquivo_palavra, arquivo_dica );

    jogo->letras_erradas = string_new();
    jogo->mascara = string_new_with_size( string_get_length( jogo->palavra.palavra ) );

    init_mascarara( string_get_text( jogo->mascara ),
                    string_get_text( jogo->palavra.palavra ),
                    string_get_length( jogo->palavra.palavra ) );
}

void init_mascarara( char *mascara, char *palavra, unsigned int tamanho_palavra ) {
    unsigned int i;

    for( i = 0; i < tamanho_palavra; i++ ) {
        if( palavra[i] == '_' || palavra[i] == '-' || palavra[i] == ' ' ) {
            palavra[i] = '-';
            mascara[i] = '-';
        } else {
            mascara[i] = '_';
        }
    }
    mascara[i] = '\0';
}

bool existe_letra_na_palavra( char carac, char *palavra ) {
    unsigned int i;

    for( i = 0; i < strlen( palavra ); i++ ) {
        if( carac == palavra[i] ) {
            return true;
        }
    }
    return false;
}

void substituir_letra_na_mascara( char carac, char *palavra, char *mascara ) {
    unsigned int i;

    for( i = 0; i < strlen( palavra ); i++ ) {
        if( palavra[i] == carac ) {
            mascara[i] = carac;
        }
    }
}

int comparar_mascara_palavra( char *mascara, char *palavra ) {
    return strcmp( mascara, palavra );
}


