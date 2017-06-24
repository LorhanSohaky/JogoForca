#ifndef VIEWER_H
#define VIEWER_H

#include <stdbool.h>

void exibir_jogo( unsigned int quantidade_erros, char *dica, char *mascara, char *letras_tentadas );

void exibir_resultado_e_palavra( char *palavra, bool ganhou );

void limpar_tela();

#endif
