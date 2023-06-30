Para compilar os arquivos de teste, com o compilador g++ devidamente instalado no dispositivo Windows, 
coloque cd test e depois basta colar no prompt o respectivo comando, e executar o arquivo gerado como administrador.

Para testar as funções de construção de árvore binária:

    g++ -o test_tree.exe .\test_tree.cpp ..\src\tree\tree.cpp ..\src\list\list.cpp 

Arquivo gerado: `test_tree.exe`

Para testar as funções de interação do usuário:

    g++ -o test_user.exe .\test_user.cpp ..\src\tree\tree.cpp ..\src\user\user.cpp ..\src\list\list.cpp 

Arquivo gerado: `test_user.exe`

Para testar as funções de listas:

    g++ -o test_list.exe .\test_list.cpp ..\src\list\list.cpp 

Arquivo gerado: `test_list.exe`

Para testar as funções que convertem árvorem em listas: 

    g++ -o test_tree_to_list.exe .\test_tree_to_list.cpp ..\src\tree\tree.cpp ..\src\list\list.cpp

Arquivo gerado: `test_tree_to_list.exe`

Para testar as funções de análise:

    g++ -o test_analysis.exe .\test_analysis.cpp ..\src\tree\tree.cpp ..\src\analysis\analysis.cpp ..\src\list\list.cpp

Arquivo gerado: `test_analysis.exe`
