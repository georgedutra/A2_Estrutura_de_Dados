/*Este arquivo conterá a chamada principal do programa, e será a base para a compilação do programa

E no terminal, na pasta \src, rodaríamos o comando:

> cd src
> g++ -o main.exe main.cpp menu\menu.cpp tree\tree.cpp analysis\analysis.cpp user\user.cpp list\list.cpp
> main.exe

Esse arquivo deve ser o ÚNICO com uma função main() no projeto
*/

#include "menu\menu.h"

int main()
{
    menuConstruction();
    return 0;
}