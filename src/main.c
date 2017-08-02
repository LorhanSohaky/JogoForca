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

#include "jogo_forca.h"
#include <locale.h>
#include <stdio.h>

int main( int argc, const char *argv[] ) {
    setlocale( LC_ALL, "Portuguese" );

    if( argc < 3 ) {
        printf( "Argumentos inválidos\n" );
        printf( "Voce deve passar o arquivo com as palavras e o arquivo com as dicas\n" );
        printf( "Tente: %s arquivo_palavra arquivo_dica\n", argv[0] );
        return 1;
    } else {
        return jogar( argv[1], argv[2] );
    }
}
