/*
The MIT License (MIT)
Copyright (c) 2017 Lorhan Sohaky
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "viewer.h"
#include <stdio.h>
#include <string.h>

static void exibir_boneco( const unsigned int quantidade_erros );
static void exibir_dica( const char *dica );
static void exibir_mascara( const char *mascara );
static void exibir_letras_erradas( const char *letras_tentadas );

void exibir_jogo( const unsigned int quantidade_erros,
                  const char *dica,
                  const char *mascara,
                  const char *letras_tentadas ) {
    exibir_boneco( quantidade_erros );
    exibir_dica( dica );
    exibir_mascara( mascara );
    exibir_letras_erradas( letras_tentadas );
}

static void exibir_letras_erradas( const char *letras_tentadas ) {
    static unsigned int i;

    printf( "\n" );
    printf( "LETRAS ERRADAS: " );
    for( i = 0; i < strlen( letras_tentadas ); i++ ) {
        printf( "%c ", *( letras_tentadas + i ) ); //É mais rápido que indexação
    }
    printf( "\b\n" );
}

static void exibir_mascara( const char *mascara ) {
    static unsigned int i;

    for( i = 0; i < strlen( mascara ); i++ ) {
        printf( "%c ", *( mascara + i ) ); //É mais rápido que indexação
    }

    printf( "\b\n" );
}

static void exibir_dica( const char *dica ) {
    printf( "Dica: %s\n", dica );
}

static void exibir_boneco( const unsigned int quantidade_erros ) {
    switch( quantidade_erros ) {
        case 0:
            printf( "┏━━━━━━━━━━━━━┓\n" );
            printf( "┃             ┇\n" );
            printf( "┃\n" );
            printf( "┃\n" );
            printf( "┃\n" );
            printf( "┃\n" );
            printf( "┃\n" );
            printf( "┃\n" );
            printf( "┃\n" );
            printf( "┃\n" );
            printf( "┃\n" );
            printf( "┃\n" );
            printf( "┃\n" );
            break;
        case 1:
            printf( "┏━━━━━━━━━━━━━┓\n" );
            printf( "┃             ┇\n" );
            printf( "┃            ***\n" );
            printf( "┃           *   *\n" );
            printf( "┃            ***\n" );
            printf( "┃\n" );
            printf( "┃\n" );
            printf( "┃\n" );
            printf( "┃\n" );
            printf( "┃\n" );
            printf( "┃\n" );
            printf( "┃\n" );
            printf( "┃\n" );
            break;
        case 2:
            printf( "┏━━━━━━━━━━━━━┓\n" );
            printf( "┃             ┇\n" );
            printf( "┃            ***\n" );
            printf( "┃           *   *\n" );
            printf( "┃            ***\n" );
            printf( "┃             │\n" );
            printf( "┃             │\n" );
            printf( "┃             │\n" );
            printf( "┃             │\n" );
            printf( "┃\n" );
            printf( "┃\n" );
            printf( "┃\n" );
            printf( "┃\n" );
            break;
        case 3:
            printf( "┏━━━━━━━━━━━━━┓\n" );
            printf( "┃             ┇\n" );
            printf( "┃            ***\n" );
            printf( "┃           *   *\n" );
            printf( "┃            ***\n" );
            printf( "┃             │\n" );
            printf( "┃            /│\n" );
            printf( "┃           / │\n" );
            printf( "┃             │\n" );
            printf( "┃\n" );
            printf( "┃\n" );
            printf( "┃\n" );
            printf( "┃\n" );
            break;
        case 4:
            printf( "┏━━━━━━━━━━━━━┓\n" );
            printf( "┃             ┇\n" );
            printf( "┃            ***\n" );
            printf( "┃           *   *\n" );
            printf( "┃            ***\n" );
            printf( "┃             │\n" );
            printf( "┃            /│\\\n" );
            printf( "┃           / │ \\\n" );
            printf( "┃             │\n" );
            printf( "┃\n" );
            printf( "┃\n" );
            printf( "┃\n" );
            printf( "┃\n" );
            break;
        case 5:
            printf( "┏━━━━━━━━━━━━━┓\n" );
            printf( "┃             ┇\n" );
            printf( "┃            ***\n" );
            printf( "┃           *   *\n" );
            printf( "┃            ***\n" );
            printf( "┃             │\n" );
            printf( "┃            /│\\\n" );
            printf( "┃           / │ \\\n" );
            printf( "┃             │\n" );
            printf( "┃            /\n" );
            printf( "┃           /\n" );
            printf( "┃\n" );
            printf( "┃\n" );
            break;
        case 6:
            printf( "┏━━━━━━━━━━━━━┓\n" );
            printf( "┃             ┇\n" );
            printf( "┃            ***\n" );
            printf( "┃           *   *\n" );
            printf( "┃            ***\n" );
            printf( "┃             │\n" );
            printf( "┃            /│\\\n" );
            printf( "┃           / │ \\\n" );
            printf( "┃             │\n" );
            printf( "┃            / \\\n" );
            printf( "┃           /   \\\n" );
            printf( "┃\n" );
            printf( "┃\n" );
            break;
        default:
            printf( "\n" );
    }
}

void exibir_resultado_e_palavra( const char *palavra, const bool ganhou ) {
    printf( "Palavra: %s\n", palavra );
    if( ganhou ) {
        printf( "PARABÉNS!\n" );
    } else {
        printf( "QUE PENA! :(\n" );
    }
}

void limpar_tela() {
    unsigned int i;

    for( i = 0; i < 50; i++ ) {
        printf( "\n" );
    }
}
