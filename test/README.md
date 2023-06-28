Para compilar os arquivos de teste, com o compilador g++ devidamente instalado no dispositivo Windows, basta colar no prompt o respectivo comando, e executar o arquivo gerado.

Para testar as funções de construção de árvore binária:

    g++ -o test_tree.exe .\test_tree.cpp ..\src\tree\tree.cpp

Arquivo gerado: `test_tree.exe`

Para testar as funções de interação do usuário:

    g++ -o test_user.exe .\test_user.cpp ..\src\tree\tree.cpp ..\src\user\user.cpp

Arquivo gerado: `test_user.exe`
