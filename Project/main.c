        
        
        /***********************************************************************************/
        /*                                                                                 */
        /*                                                                                 */
        /*                  Projeto CCP130 -> Jogo da Forca com dicionário                 */
        /*                        Nome: Lucas Ricardo Moraes Lagoeiro                      */
        /*                                                                                 */
        /*                                                                                 */
        /***********************************************************************************/



#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <time.h>   
#include <unistd.h> 

#define MAX 200

// Função para funcionamento do delay() -> time.h.
// Adicionei esse sleep(usando a biblioteca unistd.h) pois, não funciona essa função em outros sistemas operacionais alem do Windows.
void delay(int number_of_seconds)
{
    // Convertendo tempo para mili segundos
    // int milli_seconds = 1000 * number_of_seconds;

    // Armazenamento do tempo do começo
    // clock_t start_time = clock();

    // Looping até o tempo requerido não ser alcançado
    // while (clock() < start_time + milli_seconds);
    sleep(number_of_seconds);
}

// Funções para centralizar o texto (no terminal)
void first_center_menu(const char *s, int width)
{
    int length = sizeof(s) - 1; // Discount the terminal '\0'
    int pad = (length >= width) ? 0 : (width - length) / 2;

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n%*.*s%s", pad, pad, " ", s);
}

void first_center(const char *s, int width)
{
    int length = sizeof(s) - 1; // Discount the terminal '\0'
    int pad = (length >= width) ? 0 : (width - length) / 2;

    printf("\n\n\n\n\n\n\n\n\n%*.*s%s", pad, pad, " ", s);
}

void center(const char *s, int width)
{
    int length = sizeof(s) - 1; // Discount the terminal '\0'
    int pad = (length >= width) ? 0 : (width - length) / 2;

    printf("%*.*s%s", pad, pad, " ", s);
}

// Função do menu principal.

void Menu()
{
    system("cls");
    char projeto_ccp130_0[] = {" ------------------------------------------------------------------------------------------------------------------------------------------ \n"};
    char projeto_ccp130_1[] = {"|  --------------------------------------------------------------------------------------------------------------------------------------  |\n"};
    char projeto_ccp130_2[] = {"| | ########  ########   #######        ## ######## ########  #######             ######   ######  ########     ##    #######    #####   | |\n"};
    char projeto_ccp130_3[] = {"| | ##     ## ##     ## ##     ##       ## ##          ##    ##     ##           ##    ## ##    ## ##     ##  ####   ##     ##  ##   ##  | |\n"};
    char projeto_ccp130_4[] = {"| | ##     ## ##     ## ##     ##       ## ##          ##    ##     ##           ##       ##       ##     ##    ##          ## ##     ## | |\n"};
    char projeto_ccp130_5[] = {"| | ########  ########  ##     ##       ## ######      ##    ##     ##  ######## ##       ##       ########     ##    #######  ##     ## | |\n"};
    char projeto_ccp130_6[] = {"| | ##        ##   ##   ##     ## ##    ## ##          ##    ##     ##           ##       ##       ##           ##          ## ##     ## | |\n"};
    char projeto_ccp130_7[] = {"| | ##        ##    ##  ##     ## ##    ## ##          ##    ##     ##           ##    ## ##    ## ##           ##   ##     ##  ##   ##  | |\n"};
    char projeto_ccp130_8[] = {"| | ##        ##     ##  #######   ######  ########    ##     #######             ######   ######  ##         ######  #######    #####   | |\n"};
    char projeto_ccp130_9[] = {"|  --------------------------------------------------------------------------------------------------------------------------------------  |\n"};
    char projeto_ccp130_10[] = {" ------------------------------------------------------------------------------------------------------------------------------------------ \n\n\n"};

    char menu0[] = {"Selecione umas das opções a seguir:\n\n"};
    char menu1[] = {"01 - Jogo Da Forca\n"};
    char menu2[] = {"02 - Dicionário\n"};
    char menu3[] = {"03 - Créditos\n"};
    char menu4[] = {"99 - Sair\n\n"};

    first_center_menu(projeto_ccp130_0, 40);
    center(projeto_ccp130_1, 40);
    center(projeto_ccp130_2, 40);
    center(projeto_ccp130_3, 40);
    center(projeto_ccp130_4, 40);
    center(projeto_ccp130_5, 40);
    center(projeto_ccp130_6, 40);
    center(projeto_ccp130_7, 40);
    center(projeto_ccp130_8, 40);
    center(projeto_ccp130_9, 40);
    center(projeto_ccp130_10, 40);

    center(menu0, 134);
    center(menu1, 148);
    center(menu2, 148);
    center(menu3, 148);
    center(menu4, 148);
}

// Função do menu forca (principal)
void Menu_Principal_jogoForca()
{
    system("cls");

    // Apresentação do jogo.
    char hangman_game_0[] = {" ---------------------------------------------------------------------------------------------------------------------------- \n"};
    char hangman_game_1[] = {"|  ------------------------------------------------------------------------------------------------------------------------  |\n"};
    char hangman_game_2[] = {"| | ##     ##    ###    ##    ##  ######   ##     ##    ###    ##    ##              ######      ###    ##     ## ######## | |\n"};
    char hangman_game_3[] = {"| | ##     ##   ## ##   ###   ## ##    ##  ###   ###   ## ##   ###   ##             ##    ##    ## ##   ###   ### ##       | |\n"};
    char hangman_game_4[] = {"| | ##     ##  ##   ##  ####  ## ##        #### ####  ##   ##  ####  ##             ##         ##   ##  #### #### ##       | |\n"};
    char hangman_game_5[] = {"| | ######### ##     ## ## ## ## ##   #### ## ### ## ##     ## ## ## ##   ########  ##   #### ##     ## ## ### ## ######   | |\n"};
    char hangman_game_6[] = {"| | ##     ## ######### ##  #### ##    ##  ##     ## ######### ##  ####             ##    ##  ######### ##     ## ##       | |\n"};
    char hangman_game_7[] = {"| | ##     ## ##     ## ##   ### ##    ##  ##     ## ##     ## ##   ###             ##    ##  ##     ## ##     ## ##       | |\n"};
    char hangman_game_8[] = {"| | ##     ## ##     ## ##    ##  ######   ##     ## ##     ## ##    ##              ######   ##     ## ##     ## ######## | |\n"};
    char hangman_game_9[] = {"|  ------------------------------------------------------------------------------------------------------------------------  |\n"};
    char hangman_game_10[] = {" --------------------------------------------------------------------------------------------------------------------------- \n\n\n"};

    char menu_Forca1[] = {"01 - Jogar\n\n"};
    char menu_Forca2[] = {"02 - Ajuda\n\n"};
    char menu_Forca3[] = {"03 - Voltar\n\n\n"};

    // Centralizar "HANGMAN - GAME" no terminal
    first_center_menu(hangman_game_0, 55);
    center(hangman_game_1, 55);
    center(hangman_game_2, 55);
    center(hangman_game_3, 55);
    center(hangman_game_4, 55);
    center(hangman_game_5, 55);
    center(hangman_game_6, 55);
    center(hangman_game_7, 55);
    center(hangman_game_8, 55);
    center(hangman_game_9, 55);
    center(hangman_game_10, 55);

    center(menu_Forca1, 158);
    center(menu_Forca2, 158);
    center(menu_Forca3, 158);
}

// Função do menu da forca (ajuda).
void Ajuda()
{
    system("cls");

    char hangman_game_0[] = {" ---------------------------------------------------------------------------------------------------------------------------- \n"};
    char hangman_game_1[] = {"|  ------------------------------------------------------------------------------------------------------------------------  |\n"};
    char hangman_game_2[] = {"| | ##     ##    ###    ##    ##  ######   ##     ##    ###    ##    ##              ######      ###    ##     ## ######## | |\n"};
    char hangman_game_3[] = {"| | ##     ##   ## ##   ###   ## ##    ##  ###   ###   ## ##   ###   ##             ##    ##    ## ##   ###   ### ##       | |\n"};
    char hangman_game_4[] = {"| | ##     ##  ##   ##  ####  ## ##        #### ####  ##   ##  ####  ##             ##         ##   ##  #### #### ##       | |\n"};
    char hangman_game_5[] = {"| | ######### ##     ## ## ## ## ##   #### ## ### ## ##     ## ## ## ##   ########  ##   #### ##     ## ## ### ## ######   | |\n"};
    char hangman_game_6[] = {"| | ##     ## ######### ##  #### ##    ##  ##     ## ######### ##  ####             ##    ##  ######### ##     ## ##       | |\n"};
    char hangman_game_7[] = {"| | ##     ## ##     ## ##   ### ##    ##  ##     ## ##     ## ##   ###             ##    ##  ##     ## ##     ## ##       | |\n"};
    char hangman_game_8[] = {"| | ##     ## ##     ## ##    ##  ######   ##     ## ##     ## ##    ##              ######   ##     ## ##     ## ######## | |\n"};
    char hangman_game_9[] = {"|  ------------------------------------------------------------------------------------------------------------------------  |\n"};
    char hangman_game_10[] = {" --------------------------------------------------------------------------------------------------------------------------- \n\n\n"};

    first_center_menu(hangman_game_0, 55);
    center(hangman_game_1, 55);
    center(hangman_game_2, 55);
    center(hangman_game_3, 55);
    center(hangman_game_4, 55);
    center(hangman_game_5, 55);
    center(hangman_game_6, 55);
    center(hangman_game_7, 55);
    center(hangman_game_8, 55);
    center(hangman_game_9, 55);
    center(hangman_game_10, 55);

    center("    Hangman is a guessing game. The program catch a random word in the dictionary and\n", 95);
    center("the player(s) tries to guess it by suggesting letters within a certain number of guesses.\n\n\n", 95);

    char menu_Forca_Ajuda0[] = {"01 - Voltar\n\n"};

    center(menu_Forca_Ajuda0, 155);
}

// Função do menu principal do dicionário
void Dicionario_menuPrincipal()
{

    system("cls");

    char dicionario_0[] = {" ---------------------------------------------------------------------------------------- \n"};
    char dicionario_1[] = {"|  ------------------------------------------------------------------------------------  |\n"};
    char dicionario_2[] = {"| | ########  ####  ######  ####  #######  ##    ##    ###    ########  ####  #######  | |\n"};
    char dicionario_3[] = {"| | ##     ##  ##  ##    ##  ##  ##     ## ###   ##   ## ##   ##     ##  ##  ##     ## | |\n"};
    char dicionario_4[] = {"| | ##     ##  ##  ##        ##  ##     ## ####  ##  ##   ##  ##     ##  ##  ##     ## | |\n"};
    char dicionario_5[] = {"| | ##     ##  ##  ##        ##  ##     ## ## ## ## ##     ## ########   ##  ##     ## | |\n"};
    char dicionario_6[] = {"| | ##     ##  ##  ##        ##  ##     ## ##  #### ######### ##   ##    ##  ##     ## | |\n"};
    char dicionario_7[] = {"| | ##     ##  ##  ##    ##  ##  ##     ## ##   ### ##     ## ##    ##   ##  ##     ## | |\n"};
    char dicionario_8[] = {"| | ########  ####  ######  ####  #######  ##    ## ##     ## ##     ## ####  #######  | |\n"};
    char dicionario_9[] = {"|  ------------------------------------------------------------------------------------  |\n"};
    char dicionario_10[] = {" --------------------------------------------------------------------------------------- \n\n\n"};

    char menu_dicionario0[] = {"01 - Cadastrar uma palavra no dicionário\n\n"};
    char menu_dicionario1[] = {"02 - Consultar uma palavra no dicionário\n\n"};
    char menu_dicionario2[] = {"03 - Consultar o dicionário inteiro\n\n"};
    char menu_dicionario3[] = {"04 - Voltar\n\n"};

    first_center_menu(dicionario_0, 85);
    center(dicionario_1, 85);
    center(dicionario_2, 85);
    center(dicionario_3, 85);
    center(dicionario_4, 85);
    center(dicionario_5, 85);
    center(dicionario_6, 85);
    center(dicionario_7, 85);
    center(dicionario_8, 85);
    center(dicionario_9, 85);
    center(dicionario_10, 85);

    center(menu_dicionario0, 148);
    center(menu_dicionario1, 148);
    center(menu_dicionario2, 148);
    center(menu_dicionario3, 148);
}

// Função do menu do dicionario (adicionar/pesquisar)
void Dicionario_Adicionar_Pesquisar_Palavra()
{

    system("cls");

    char dicionario_0[] = {" ---------------------------------------------------------------------------------------- \n"};
    char dicionario_1[] = {"|  ------------------------------------------------------------------------------------  |\n"};
    char dicionario_2[] = {"| | ########  ####  ######  ####  #######  ##    ##    ###    ########  ####  #######  | |\n"};
    char dicionario_3[] = {"| | ##     ##  ##  ##    ##  ##  ##     ## ###   ##   ## ##   ##     ##  ##  ##     ## | |\n"};
    char dicionario_4[] = {"| | ##     ##  ##  ##        ##  ##     ## ####  ##  ##   ##  ##     ##  ##  ##     ## | |\n"};
    char dicionario_5[] = {"| | ##     ##  ##  ##        ##  ##     ## ## ## ## ##     ## ########   ##  ##     ## | |\n"};
    char dicionario_6[] = {"| | ##     ##  ##  ##        ##  ##     ## ##  #### ######### ##   ##    ##  ##     ## | |\n"};
    char dicionario_7[] = {"| | ##     ##  ##  ##    ##  ##  ##     ## ##   ### ##     ## ##    ##   ##  ##     ## | |\n"};
    char dicionario_8[] = {"| | ########  ####  ######  ####  #######  ##    ## ##     ## ##     ## ####  #######  | |\n"};
    char dicionario_9[] = {"|  ------------------------------------------------------------------------------------  |\n"};
    char dicionario_10[] = {" --------------------------------------------------------------------------------------- \n"};

    first_center_menu(dicionario_0, 85);
    center(dicionario_1, 85);
    center(dicionario_2, 85);
    center(dicionario_3, 85);
    center(dicionario_4, 85);
    center(dicionario_5, 85);
    center(dicionario_6, 85);
    center(dicionario_7, 85);
    center(dicionario_8, 85);
    center(dicionario_9, 85);
    center(dicionario_10, 85);
}

// Função para imprimir os Creditos
void Creditos()
{
    system("cls");

    printf("\n\n\n");

    char credits_00[] = {" '||'''|,              '||                                     '||                                                     \n"};
    char credits_01[] = {"  ||   ||               ||                                      ||                                   ''                \n"};
    char credits_02[] = {"  ||;;;;   '||  ||`     ||     '||  ||` .|'',  '''|.  (''''     ||      '''|.  .|''|, .|''|, .|''|,  ||  '||''| .|''|, \n"};
    char credits_03[] = {"  ||   ||   `|..||      ||      ||  ||  ||    .|''||   `'')     ||     .|''||  ||  || ||  || ||..||  ||   ||    ||  || \n"};
    char credits_04[] = {" .||...|'       ||     .||...|  `|..'|. `|..' `|..||. `...'    .||...| `|..||. `|..|| `|..|' `|...  .||. .||.   `|..|' \n"};
    char credits_05[] = {"            ,  |'                                                                 ||                                   \n"};
    char credits_06[] = {"             ''                                                                `..|'                                   \n"};

    first_center_menu(credits_00, 55);
    center(credits_01, 55);
    center(credits_02, 55);
    center(credits_03, 55);
    center(credits_04, 55);
    center(credits_05, 55);
    center(credits_06, 55);
    printf("\n");

    delay(3);
}

// Funções de escolha do que o usuário deseja acessar de cada menu.
char leitor()
{
    int opcao;
    printf("\t\t\t\t\t\t\t\tOpção escolhida: ");
    scanf("%d", &opcao);
    setbuf(stdin, 0);
    printf("\n");

    return opcao;
}

char leitor_forca()
{
    int opcao_forca;
    printf("\t\t\t\t\t\t\t\tOpção escolhida: ");
    scanf("%d", &opcao_forca);
    setbuf(stdin, 0);
    printf("\n");

    return opcao_forca;
}

char leitor_forca_ajuda()
{
    int opcao_forca_ajuda;
    printf("\n\t\t\t\t\t\t\t\tOpção escolhida: ");
    scanf("%d", &opcao_forca_ajuda);
    setbuf(stdin, 0);
    printf("\n");

    return opcao_forca_ajuda;
}

char leitor_dicionario()
{
    int opcao_dicionario;
    printf("\n\t\t\t\t\t\t\t\tOpção escolhida: ");
    scanf("%d", &opcao_dicionario);
    setbuf(stdin, 0);
    printf("\n");

    return opcao_dicionario;
}

char leitor_dicionario_cadastro()
{
    int opcao_dicionario_cadastro;
    printf("\n\t\t\t\t\t\t\t\tOpção escolhida: ");
    scanf("%d", &opcao_dicionario_cadastro);
    setbuf(stdin, 0);
    printf("\n");

    return opcao_dicionario_cadastro;
}

char leitor_dicionario_consulta_palavra()
{
    int opcao_dicionario_consulta_palavra;
    printf("\n\t\t\t\t\t\t\t\tOpção escolhida: ");
    scanf("%d", &opcao_dicionario_consulta_palavra);
    setbuf(stdin, 0);
    printf("\n");

    return opcao_dicionario_consulta_palavra;
}

char leitor_dicionario_consulta_inteiro()
{
    int opcao_dicionario_consulta_inteiro;
    printf("\n\n\t\t\t\t\t\t\t\tOpção escolhida: ");
    scanf("%d", &opcao_dicionario_consulta_inteiro);
    setbuf(stdin, 0);
    printf("\n");

    return opcao_dicionario_consulta_inteiro;
}

// Função de leitura de todas as linhas do dicionario e mostra no terminal.
int dicionarioInteiro()
{
    system("cls");
    FILE *dicionario;
    char linha[256];
    dicionario = fopen("dicionario.txt", "r"); 
    first_center(" \n", 100);
    while (fgets(linha, 256, dicionario) != NULL)
    {
        center(linha, 100);
    }
    printf("\n\n");

    center("01 - Voltar", 155);
    leitor_dicionario_consulta_inteiro();
    fclose(dicionario); 

    return 0;
}

// Função de contar quantas linhas do dicionário (para usar o rand e pegar uma palavra aleatórias).
int dicionarioLinhas()
{
    FILE *dicionario;
    char linha[256];
    int count = 0; 
    dicionario = fopen("dicionario.txt", "r");
    while (fgets(linha, 256, dicionario) != NULL)
    {
        count++;
    }
    fclose(dicionario);
    return count; 
}

// Função de adicionar uma palavra nova junto com seu significado no dicionário.
void palavraNova()
{
    system("cls");

    Dicionario_Adicionar_Pesquisar_Palavra();

    // declaração de variáveis.
    char palavra[MAX], significado[MAX], *palavra_separada;
    char linhas_dicionario[256];
    int n, m, i, j, line;

    first_center("Digite a palavra: ", 155);
    scanf("%s", palavra);
    center("Agora seu significado: ", 155);
    getchar(); 
    fgets(significado, 100, stdin);
    significado[strcspn(significado, "\n")] = 0; 
    FILE *dicionario;
    dicionario = fopen("dicionario.txt", "r+"); // abrir o arquivo para leitura(verificar se a palavra existe) + append (adicionar a palavra).
    m = strlen(palavra);                        

    // Leitura das linhas para fins de comparação da palavra digitada com as do dicionário, para caso tenha a palavra no dicionário, imprimir uma mensagem de erro.
    while (fgets(linhas_dicionario, 256, dicionario) != NULL)
    {
        i = 0;
        n = strlen(linhas_dicionario); 

        
        while (i < n)
        {

            j = 0;
            while (i < n && j < m && linhas_dicionario[i] == palavra[j])
            {
                ++i, ++j;
            }
            if ((i == n || linhas_dicionario[i] == ' ' || linhas_dicionario[i] == '\n') && j == m)
            {
                palavra_separada = strtok(linhas_dicionario, ":"); 
                printf("\n");
                center("Já existe essa palavra cadastrada no dicionário.", 135);
                printf("\n\n");
                fclose(dicionario);
                delay(3);        
                system("cls");
            }

            while (i < n && linhas_dicionario[i] != ' ')
            {
                ++i;
            }
            ++i;
        }

        ++line;
    }

    // Imprimir a palavra com seu significado no arquivo "dicionario.txt".
    fprintf(dicionario, "\n%s : %s", palavra, significado);
    fclose(dicionario); 
    system("cls");    
}

// Função de pesquisa de palavras no dicionário
void pesquisarPalavra()
{
    system("cls"); 

    Dicionario_Adicionar_Pesquisar_Palavra();

    // declaração de variáveis.
    char palavra[MAX], linhas_dicionario[256];
    int n, m, i, j, line, count = 0;

    first_center("Digite a palavra que deseja saber o seu significado:  ", 125);
    scanf("%s", palavra);
    FILE *dicionario;
    dicionario = fopen("dicionario.txt", "r"); 
    printf("\n");
    m = strlen(palavra); 
    line = 0;

    // Looping para comparação de palavras para pesquisa
    while (fgets(linhas_dicionario, 256, dicionario) != NULL)
    {

        i = 0;
        n = strlen(linhas_dicionario);

        while (i < n)
        {

            j = 0;
            while (i < n && j < m && linhas_dicionario[i] == palavra[j])
            {
                ++i, ++j;
            }

            if ((i == n || linhas_dicionario[i] == ' ' || linhas_dicionario[i] == '\n') && j == m)
            {
                center(linhas_dicionario, 115);
                count++; 
                break;
            }

            while (i < n && linhas_dicionario[i] != ' ')
            {
                ++i;
            }
            ++i;
        }

        ++line;
    }

    // Se não houver a palavra pesquisada, imprimir mensagem de erro.
    if (count == 0)
    {
        center("Não existe essa palavra no dicionário.\n\n", 125);
        fclose(dicionario);
    }
    fclose(dicionario);
    printf("\n\n");
    delay(3);
    system("cls"); 

}

// Função para o Hangman - Game (jogo da Forca).
void jogoForca()
{
    system("cls");
    time_t t; // declaração da variavel para srand(aleatorio).
    FILE *dicionario;
    dicionario = fopen("dicionario.txt", "r");
    srand((unsigned)time(&t));
    int linha_aleatoria = rand() % dicionarioLinhas(); // variavel que armazena a linha aleatória.
    int linha_dicionario = 0;
    char *palavra_forca, palavra_inteira[256];

    // Leitura da linha aleatória (palavra + significado).
    while (fgets(palavra_inteira, 100, dicionario) != NULL)
    {
        
        // Separar palavra do seu significado (para jogo da forca).
        if (linha_aleatoria == linha_dicionario)
        {
            fflush(stdout);
            palavra_forca = strtok(palavra_inteira, ":"); 
            break;
        }
        linha_dicionario++;
    }
    fclose(dicionario); 

    int N = strlen(palavra_forca) - 1; // tamanho da palavra escondida (-1 por conta do espaço).

    // Substituir a string toda por 0 palavra_secreta = {'0','0','0','0','0','0'}.
    int palavra_secreta[N];
    for (int i = 0; i < N; ++i)
    {
        palavra_secreta[i] = 0;
    }

    // Declaração das variaveis para jogo da forca.
    int gameover = 0;
    int tentativas = 6;
    int pontuacao = 0;
    char aux[1] = {'0'};
    char letras_c[] = {'0'};
    char letras_e[] = {'0'};
    char letras_digitadas[100] = {'\0'};
    char zero[1] = {'0'}, c[] = {" "};

    // o Jogo! (caso ganhe o gameover irá ser = 0, assim sairá do looping)
    while (!gameover)
    {

        printf("\n\n");
        if (tentativas == 6 && pontuacao == 0)
        {
            char forca1[] = {"Chances: "};
            first_center_menu(forca1, 158);
            printf("%d\n", tentativas);

            char forca2[] = {"  _______\n"};
            char forca3[] = {"  |/\n"};
            char forca4[] = {"  |\n"};
            char forca5[] = {"  |\n"};
            char forca6[] = {"  |\n"};
            char forca7[] = {"  |\n"};
            char forca8[] = {"__|_________\n\n"};

            center(forca2, 158);
            center(forca3, 158);
            center(forca4, 158);
            center(forca5, 158);
            center(forca6, 158);
            center(forca7, 158);
            center(forca8, 158);
        }

        // A palavra secreta será substituida por ------- quando palavra_secreta = 0, caso contrario ira substituir o "-" pela letra da palavra secreta.
        char guess_palavra[] = {"A palavra é: "};
        center(guess_palavra, 148);

        for (int j = 0; j < N; ++j)
        {
            if (palavra_secreta[j])
            {
                printf("%c", palavra_forca[j]);
            }
            else
            {
                printf("-");
            }
        }
        printf("\n\n");

        // Mostrar as letras certas digitadas.
        char palavras_digitadas[] = {"Palavras digitadas: "};
        center(palavras_digitadas, 188);
        printf("%s   ", letras_digitadas);
        printf("\n\n\n");

        // Proxima letra que o jogador digitar.
        char guess = {'\0'};
        int count_e = 0;
        int igual = 0;
        char letra_dig[] = {"Digite uma letra: "};
        center(letra_dig, 118);
        fflush(stdout);
        scanf(" %c", &guess);
        system("cls"); 
        printf("\n\n");

        // Teste para ver se o usuário digitou alguma letra repetida
        int count_igual = 0;
        int M = strlen(letras_digitadas);
        for (int i = 0; i < M; i++)
            {
                if (guess == letras_digitadas[i])
                {
                    count_igual++;
                }
            }
        if (count_igual == 0)
        {
            strcat(letras_digitadas, &guess);
            strcat(letras_digitadas, c);
        }

        // Teste da letra digitada com a palavra escondida (substitui '-' pela letra, caso não aumenta a contagem do count_e (count_e++)).
        for (int k = 0; k < N; ++k)
        {
            if (palavra_forca[k] == guess)
            {
                palavra_secreta[k] = 1;
            }
            else if (palavra_forca[k] != guess)
            {
                count_e++;
            }
        }
        // Se count_e = N (tamanho da string digitada) diminui a tentativa (tentativa --).
        if (count_e == N)
        {
            if (count_igual == 0 )
            {
            tentativas--;
            }

            // Conforme as tentativas forem diminuindo, vai se formando o desenho do boneco na forca
            
            if (tentativas > 0){
                char voce_errou[] = {"Você errou!!!!\n"};
                first_center_menu(voce_errou, 155);
            }
            if (tentativas == 6)
            {
                char forca9[] = {"Chances: "};
                center(forca9, 158);
                printf("%d\n", tentativas);

                char forca10[] = {"  _______     \n"};
                char forca11[] = {"  |/   |      \n"};
                char forca12[] = {"  |           \n"};
                char forca13[] = {"  |           \n"};
                char forca14[] = {"  |           \n"};
                char forca15[] = {"  |           \n"};
                char forca16[] = {"__|_________\n\n"};

                center(forca10, 158);
                center(forca11, 158);
                center(forca12, 158);
                center(forca13, 158);
                center(forca14, 158);
                center(forca15, 158);
                center(forca16, 158);
            }
            if (tentativas == 5)
            {
                char forca9[] = {"Chances: "};
                center(forca9, 158);
                printf("%d\n", tentativas);

                char forca10[] = {"  _______     \n"};
                char forca11[] = {"  |/   |      \n"};
                char forca12[] = {"  |    O      \n"};
                char forca13[] = {"  |           \n"};
                char forca14[] = {"  |           \n"};
                char forca15[] = {"  |           \n"};
                char forca16[] = {"__|_________\n\n"};

                center(forca10, 158);
                center(forca11, 158);
                center(forca12, 158);
                center(forca13, 158);
                center(forca14, 158);
                center(forca15, 158);
                center(forca16, 158);
            }
            else if (tentativas == 4)
            {
                char forca17[] = {"Chances: "};
                center(forca17, 158);
                printf("%d\n", tentativas);

                char forca18[] = {"  _______     \n"};
                char forca19[] = {"  |/   |      \n"};
                char forca20[] = {"  |    O      \n"};
                char forca21[] = {"  |    |      \n"};
                char forca22[] = {"  |           \n"};
                char forca23[] = {"  |           \n"};
                char forca24[] = {"__|_________\n\n"};

                center(forca18, 158);
                center(forca19, 158);
                center(forca20, 158);
                center(forca21, 158);
                center(forca22, 158);
                center(forca23, 158);
                center(forca24, 158);
            }
            else if (tentativas == 3)
            {
                char forca25[] = {"Chances: "};
                center(forca25, 158);
                printf("%d\n", tentativas);

                char forca26[] = {"  _______      \n"};
                char forca27[] = {"  |/   |       \n"};
                char forca28[] = {"  |    O       \n"};
                char forca29[] = {"  |    |       \n"};
                char forca30[] = {"  |     \\     \n"};
                char forca31[] = {"  |            \n"};
                char forca32[] = {"__|_________ \n\n"};

                center(forca26, 158);
                center(forca27, 158);
                center(forca28, 158);
                center(forca29, 158);
                center(forca30, 158);
                center(forca31, 158);
                center(forca32, 158);
            }
            else if (tentativas == 2)
            {
                char forca33[] = {"Chances: "};
                center(forca33, 158);
                printf("%d\n", tentativas);

                char forca34[] = {"  _______      \n"};
                char forca35[] = {"  |/   |       \n"};
                char forca36[] = {"  |    O       \n"};
                char forca37[] = {"  |    |       \n"};
                char forca38[] = {"  |   / \\     \n"};
                char forca39[] = {"  |            \n"};
                char forca40[] = {"__|_________ \n\n"};

                center(forca34, 158);
                center(forca35, 158);
                center(forca36, 158);
                center(forca37, 158);
                center(forca38, 158);
                center(forca39, 158);
                center(forca40, 158);
            }
            else if (tentativas == 1)
            {
                char forca41[] = {"Chances: "};
                center(forca41, 158);
                printf("%d\n", tentativas);

                char forca42[] = {"  _______      \n"};
                char forca43[] = {"  |/   |       \n"};
                char forca44[] = {"  |    O       \n"};
                char forca45[] = {"  |   /|       \n"};
                char forca46[] = {"  |   / \\     \n"};
                char forca47[] = {"  |            \n"};
                char forca48[] = {"__|_________ \n\n"};

                center(forca42, 158);
                center(forca43, 158);
                center(forca44, 158);
                center(forca45, 158);
                center(forca46, 158);
                center(forca47, 158);
                center(forca48, 158);
            }
        }

        // Caso você acerte a letra se mantêm o desenho e as tentativas
        else
        {
            pontuacao++;
            char voce_acertou[] = {"Você acertou!!!\n"};
            first_center_menu(voce_acertou, 155);

            if (tentativas == 6 && pontuacao > 0)
            {
                char forca99[] = {"Chances: "};
                center(forca99, 158);
                printf("%d\n", tentativas);

                char forca100[] = {"  _______     \n"};
                char forca101[] = {"  |/   |      \n"};
                char forca102[] = {"  |           \n"};
                char forca103[] = {"  |           \n"};
                char forca104[] = {"  |           \n"};
                char forca105[] = {"  |           \n"};
                char forca106[] = {"__|_________\n\n"};

                center(forca100, 158);
                center(forca101, 158);
                center(forca102, 158);
                center(forca103, 158);
                center(forca104, 158);
                center(forca105, 158);
                center(forca106, 158);
            }

            if (tentativas == 5)
            {
                char forca49[] = {"Chances: "};
                center(forca49, 158);
                printf("%d\n", tentativas);

                char forca50[] = {"  _______     \n"};
                char forca51[] = {"  |/   |      \n"};
                char forca52[] = {"  |    O      \n"};
                char forca53[] = {"  |           \n"};
                char forca54[] = {"  |           \n"};
                char forca55[] = {"  |           \n"};
                char forca56[] = {"__|_________\n\n"};

                center(forca50, 158);
                center(forca51, 158);
                center(forca52, 158);
                center(forca53, 158);
                center(forca54, 158);
                center(forca55, 158);
                center(forca56, 158);
            }
            else if (tentativas == 4)
            {
                char forca57[] = {"Chances: "};
                center(forca57, 158);
                printf("%d\n", tentativas);

                char forca58[] = {"  _______     \n"};
                char forca59[] = {"  |/   |      \n"};
                char forca60[] = {"  |    O      \n"};
                char forca61[] = {"  |    |      \n"};
                char forca62[] = {"  |           \n"};
                char forca63[] = {"  |           \n"};
                char forca64[] = {"__|_________\n\n"};

                center(forca58, 158);
                center(forca59, 158);
                center(forca60, 158);
                center(forca61, 158);
                center(forca62, 158);
                center(forca63, 158);
                center(forca64, 158);
            }
            else if (tentativas == 3)
            {
                char forca65[] = {"Chances: "};
                center(forca65, 158);
                printf("%d\n", tentativas);

                char forca66[] = {"  _______      \n"};
                char forca67[] = {"  |/   |       \n"};
                char forca68[] = {"  |    O       \n"};
                char forca69[] = {"  |    |       \n"};
                char forca70[] = {"  |     \\     \n"};
                char forca71[] = {"  |            \n"};
                char forca72[] = {"__|_________ \n\n"};

                center(forca66, 158);
                center(forca67, 158);
                center(forca68, 158);
                center(forca69, 158);
                center(forca70, 158);
                center(forca71, 158);
                center(forca72, 158);
            }
            else if (tentativas == 2)
            {
                char forca73[] = {"Chances: "};
                center(forca73, 158);
                printf("%d\n", tentativas);

                char forca74[] = {"  _______      \n"};
                char forca75[] = {"  |/   |       \n"};
                char forca76[] = {"  |    O       \n"};
                char forca77[] = {"  |    |       \n"};
                char forca78[] = {"  |   / \\     \n"};
                char forca79[] = {"  |            \n"};
                char forca80[] = {"__|_________ \n\n"};

                center(forca74, 158);
                center(forca75, 158);
                center(forca76, 158);
                center(forca77, 158);
                center(forca78, 158);
                center(forca79, 158);
                center(forca80, 158);
            }
            else if (tentativas == 1)
            {
                char forca81[] = {"Chances: "};
                center(forca81, 158);
                printf("%d\n", tentativas);

                char forca82[] = {"  _______      \n"};
                char forca83[] = {"  |/   |       \n"};
                char forca84[] = {"  |    O       \n"};
                char forca85[] = {"  |   /|       \n"};
                char forca86[] = {"  |   / \\     \n"};
                char forca87[] = {"  |            \n"};
                char forca88[] = {"__|_________ \n\n"};

                center(forca82, 158);
                center(forca83, 158);
                center(forca84, 158);
                center(forca85, 158);
                center(forca86, 158);
                center(forca87, 158);
                center(forca88, 158);
            }
        }

        // Se a tentativa chegar a zero, você perdeu!!!
        if (tentativas == 0)
        {

            {
                char forca89[] = {"Chances: "};
                first_center(forca89, 158);
                printf("%d\n", tentativas);

                char forca90[] = {"  _______      \n"};
                char forca91[] = {"  |/   |       \n"};
                char forca92[] = {"  |    X       \n"};
                char forca93[] = {"  |   /|\\     \n"};
                char forca94[] = {"  |   / \\     \n"};
                char forca95[] = {"  |            \n"};
                char forca96[] = {"__|_________ \n\n"};

                center(forca90, 158);
                center(forca91, 158);
                center(forca92, 158);
                center(forca93, 158);
                center(forca94, 158);
                center(forca95, 158);
                center(forca96, 158);
            }

            center("Você perdeu! A palavra é ", 140);
            printf("\" %s\".\n", palavra_forca);

            delay(3);
            system("cls");
            break;
        }
        // Caso acerte a palavra antes das tentativas zerarem, você ganhou!!!
        gameover = 1;
        for (int m = 0; m < N; ++m)
        {
            if (!palavra_secreta[m])
            {
                gameover = 0;
                break;
            }
        }
    }

    // Vitoria!!!!
    if (tentativas > 0)
    {
        center("Vitoria! A palavra é ", 140);
        printf("\" %s\".\n", palavra_forca);
        delay(3);
    }
    system("cls"); 
}

void menu_jogoForca_ajuda()
{
    int opcaoEscolhida_Ajuda_Forca;
    do
    {
        Ajuda();
        opcaoEscolhida_Ajuda_Forca = leitor_forca_ajuda();
        switch (opcaoEscolhida_Ajuda_Forca)
        {
        case 1:
            Menu_Principal_jogoForca();
            break;
        default:
            printf("Opção inválida\n\n");
            Ajuda();
            opcaoEscolhida_Ajuda_Forca = leitor_forca_ajuda();
        }
    } while (opcaoEscolhida_Ajuda_Forca != 1);
}

void menu_opcao_jogoForca()
{
    int opcaoEscolhida_Forca;
    do
    {
        Menu_Principal_jogoForca();
        opcaoEscolhida_Forca = leitor_forca();
        switch (opcaoEscolhida_Forca)
        {
        case 1:
            jogoForca();
            break;
        case 2:
            menu_jogoForca_ajuda();
            break;
        case 3:
            Menu();
            break;
        default:
            printf("Opção inválida\n\n");
            Menu_Principal_jogoForca();
            opcaoEscolhida_Forca = leitor_forca();
        }
    } while (opcaoEscolhida_Forca != 3);
}

void menu_opcao_Dicionario()
{
    int opcaoEscolhida_Dicionario;
    do
    {
        Dicionario_menuPrincipal();
        opcaoEscolhida_Dicionario = leitor_dicionario();
        switch (opcaoEscolhida_Dicionario)
        {
        case 1:
            palavraNova();
            break;
        case 2:
            pesquisarPalavra();
            break;
        case 3:
            dicionarioInteiro();
            break;
        case 4:
            Menu();
            break;
        default:
            printf("Opção inválida\n\n");
            Dicionario_menuPrincipal();
            opcaoEscolhida_Dicionario = leitor_dicionario();
        }
    } while (opcaoEscolhida_Dicionario != 4);
}

// 
void menu_opcao_Dicionario_Inteiro()
{
    int opcaoEscolhida_Dicionario_Inteiro;
    do
    {
        opcaoEscolhida_Dicionario_Inteiro = leitor_dicionario_consulta_inteiro();
        switch (opcaoEscolhida_Dicionario_Inteiro)
        {
        case 1:
            Dicionario_menuPrincipal();
            break;
        default:
            printf("Opção inválida\n\n");
            Dicionario_menuPrincipal();
            opcaoEscolhida_Dicionario_Inteiro = leitor_dicionario_consulta_inteiro();
        }
    } while (opcaoEscolhida_Dicionario_Inteiro != 1);
}

int main()
{

     system("cls");
    FILE *dicionario;
    int opcaoEscolhida;
    dicionario = fopen("dicionario.txt", "r"); 

    // Caso não consiga abrir o arquivo imprimir erro.
    if (dicionario == NULL)
    {
        printf("Nao foi possivel abrir o arquivo");
        exit(1);
    }

    // Menu do jogador
    do
    {
        Menu();
        opcaoEscolhida = leitor();
        switch (opcaoEscolhida)
        {
        case 1:
            menu_opcao_jogoForca();
            break;
        case 2:
            menu_opcao_Dicionario();
            break;
        case 3:
            Creditos();
            break;
        case 99:
            printf("Saindo...\n\n");
            break;
        default:
            center("Opção inválida!\n\n", 155);
            delay(1);
            break;
        }
    } while (opcaoEscolhida != 99);
    delay(2);
    system("cls");

    return 0;
}