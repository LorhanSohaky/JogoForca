#include "viewer.h"
#include <stdio.h>
#include <string.h>

void exibir_mascara( char *mascara ) {
    static unsigned int i;

    for( i = 0; i < strlen( mascara ); i++ ) {
        printf( "%c ", *( mascara + i ) ); //É mais rápido que indexação
    }

    printf( "\b\n" );
}

void exibir_dica( char *dica ) {
    printf( "Dica: %s\n", dica );
}

void exibir_boneco( unsigned int quantidade_erros ) {
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

void exibir_resultado_e_palavra( char *palavra, bool ganhou ) {
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

