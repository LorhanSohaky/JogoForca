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

bool existe_letra_na_palavra( char carac, char *palavra );
bool existe_letra_nas_erradas( char carac, char *letras_erradas );

int comparar_mascara_palavra( char *mascara, char *palavra );
void substituir_letra_na_mascara( char carac, char *palavra, char *mascara );
void init_mascarara( char *mascara, char *palavra, unsigned int tamanho_palavra );
void finalizar( Jogo *jogo );

int jogar( char *arquivo_palavra, char *arquivo_dica ) {
    Jogo jogo;

    char tmp[2];

    char *palavra, *mascara, *dica, *letras_erradas;
    char carac;

    init_configuracoes( &jogo, arquivo_palavra, arquivo_dica );

    palavra = string_get_text( jogo.palavra.palavra );
    mascara = string_get_text( jogo.mascara );
    dica = string_get_text( jogo.palavra.dica.dica );
    letras_erradas = string_get_text( jogo.letras_erradas );

    do {
        limpar_tela();

        exibir_jogo( jogo.quantidade_erros, dica, mascara, letras_erradas );

        printf( "\nDigite uma letra:" );
        scanf( " %c", &carac );

        if( !existe_letra_na_palavra( carac, palavra ) ) {
            if( !existe_letra_nas_erradas( carac, letras_erradas ) ) {
                jogo.quantidade_erros++;
                sprintf( tmp, "%c", carac );
                string_concat_char_array( jogo.letras_erradas, tmp );
            }
        } else {
            substituir_letra_na_mascara( carac, palavra, mascara );
        }

        if( !comparar_mascara_palavra( mascara, palavra ) ) {
            jogo.ganhou = true;
        }
    } while( !jogo.ganhou && jogo.quantidade_erros < MAX_ERRO );

    limpar_tela();
    exibir_resultado_e_palavra( palavra, jogo.ganhou );

    finalizar( &jogo );

    return !jogo.ganhou;
}

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

bool existe_letra_nas_erradas( char carac, char *letras_erradas ) {
    unsigned int i;

    for( i = 0; i < strlen( letras_erradas ); i++ ) {
        if( carac == letras_erradas[i] ) {
            return true;
        }
    }
    return false;
}

void finalizar( Jogo *jogo ) {
    string_free( jogo->palavra.palavra );
    string_free( jogo->palavra.dica.dica );
    string_free( jogo->mascara );
    string_free( jogo->letras_erradas );
}
