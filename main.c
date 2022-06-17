/***********************************************************************************/
/*                                                                                 */
/*                                                                                 */
/*                  Projeto CCP130 -> Jogo da Forca com dicionário                 */
/*                        Nome: Lucas Ricardo Moraes Lagoeiro                      */ 
/*                                  RA: 11.120.316-2                               */
/*                                                                                 */
/***********************************************************************************/





#include <stdio.h> 
#include <stdlib.h> //Biblioteca para poder usar o rand (palavras aleatórias).
#include <string.h>
#include <time.h> // Biblioteca que inclui o delay().
#include <unistd.h> // biblioteca que inclui o sleep para funcionamento do delay.

#define MAX 200

// Função para funcionamento do delay() -> time.h (o que esta comentado).
// Adicionei esse sleep(usando a biblioteca unistd.h) pois, não funciona essa função em outros sistemas operacionais alem do windows.
void delay(int number_of_seconds)
{
    // Convertendo tempo para mili segundos
    //int milli_seconds = 1000 * number_of_seconds;

    // Armazenamento do tempo do começo
    //clock_t start_time = clock();

    // Looping até o tempo requerido não ser alcançado
    //while (clock() < start_time + milli_seconds);
    sleep(number_of_seconds); 

}

// Função do menu principal.
void Menu()
{
    printf("\n\tSelecione umas das opções a seguir:\n");
    printf("\t01 - Cadastrar uma palavra nova no dicionário\n"
           "\t02 - Consultar a definição de uma palavra\n"
           "\t03 - Jogar o Jogo da Forca\n"
           "\t04 - Dicionário inteiro\n"
           "\t99 - Sair\n\n");
}

//Função de escolha do que o usuário deseja acessar.
char leitor()
{
    int opcao;
    printf("\n\tOpção escolhida: ");
    scanf("%d", &opcao);
    setbuf(stdin, 0);
    printf("\n");

    return opcao;
}

// Função de leitura de todas as linhas do dicionario e mostra no terminal.
int dicionarioInteiro()
{
    system("clear"); // limpa o terminal.
    FILE *dicionario;
    char linha[256];
    dicionario = fopen("dicionario.txt", "r"); // abrindo o arquivo para leitura (read).
    while (fgets(linha, 256, dicionario) != NULL)
    {
        printf("%s\n", linha);
    }
    return 0;
    fclose(dicionario);// fechar o arquivo.
}
// Função de contar quantas linhas do dicionário (para usar o rand e pegar uma palavra aleatórias).
int dicionarioLinhas()
{
    FILE *dicionario;
    char linha[256];
    int count = 0; // declaração da variavel de contagem.
    dicionario = fopen("dicionario.txt", "r");
    while (fgets(linha, 256, dicionario) != NULL)
    {
        count++;
    }
    fclose(dicionario);
    return count; // retorna o valor da contagem (total de linhas).
}

// Função de adicionar uma palavra nova junto com seu significado no dicionário.
void palavraNova()
{
    system("clear"); // limpar o terminal
    // declaração de variáveis.
    char palavra[MAX], significado[MAX], *palavra_separada; 
    char linhas_dicionario[256];
    int n, m, i, j, line;

    printf("Digite a palavra: ");
    scanf("%s", palavra);
    printf("Agora seu significado: ");
    getchar();// para caso vaze algum char (\n).
    fgets(significado, 100, stdin);
    significado[strcspn(significado, "\n")] = 0; // para o fgets não pular linha
    FILE *dicionario;
    dicionario = fopen("dicionario.txt", "r+"); // abrir o arquivo para leitura(verificar se a palavra existe) + append (adicionar a palavra).
    m = strlen(palavra); // variavei para saber o tamanho da string(palavra).

    // Leitura das linhas para fins de comparação da palavra digitada com as do dicionário, para caso tenha a palavra no dicionário, imprimir uma mensagem de erro.
    while (fgets(linhas_dicionario, 256, dicionario) != NULL)
    {
        i = 0;
        n = strlen(linhas_dicionario); // variavel para medir o tamanho da linha do dicionário.

        // teste linha por linha com a palavra digitada (palavra==buffer).
        while (i < n)
        {

            j = 0;
            while (i < n && j < m && linhas_dicionario[i] == palavra[j])
            {
                ++i, ++j;
            }
            if ((i == n || linhas_dicionario[i] == ' ' || linhas_dicionario[i] == '\n') && j == m)
            {
                palavra_separada = strtok(linhas_dicionario, ":"); // palavra do dicionário separada do seu significado (tudo antes do ":").
                printf("\n\n");
                printf("Já existe essa palavra cadastrada no dicionário.");
                printf("\n\n");
                fclose(dicionario);
                delay(3); // espera 3 segundos.
                system("clear"); // limpa o terminal.
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
    fclose(dicionario); // fechar o arquivo.
    system("clear");

}

// Função de pesquisa de palavras no dicionário
void pesquisarPalavra()
{
    system("clear"); 
    // declaração de variáveis.
    char palavra[MAX], linhas_dicionario[256];
    int n, m, i, j, line, count = 0;

    printf("Digite a palavra que deseja saber o seu significado:  ");
    scanf("%s", palavra);
    FILE *dicionario;
    dicionario = fopen("dicionario.txt", "r"); // abrindo o arquivo apenas para leitura (comparar a palavra digitada com o resto do dicionário).
    printf("\n\n");
    m = strlen(palavra); // variavel para medir o tamanho da palavra pesquisada
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
                printf("%s", linhas_dicionario);
                count++; // contagem caso essa palavra tenha no dicionário (count=1).
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
        printf("Não existe essa palavra no dicionário.\n\n");
        fclose(dicionario);
    }
    fclose(dicionario); // fechando o arquivo "dicionario.txt".
    printf("\n\n");
    delay(5);
    system("clear");
}

// Função para o Hangman - Game (jogo da Forca).
void jogoForca()
{
    system("clear");
    time_t t; // declaração da variavel para srand(aleatorio).
    FILE *dicionario;
    dicionario = fopen("dicionario.txt", "r"); // abrindo o arquivo para leitura (ler as linhas e pegar uma palavra aleatória).
    srand((unsigned)time(&t));
    int linha_aleatoria = rand() % dicionarioLinhas(); // variavel que armazena a linha aleatória.
    int linha_dicionario = 0;
    char *palavra_forca, palavra_inteira[256];

    // Leitura da linha aleatória (palavra + significado).
    while (fgets(palavra_inteira, 100, dicionario) != NULL)
    {   
        // linha lida pelo fgets for igual a linha aleatória gerada
        if (linha_aleatoria == linha_dicionario)
        {
            fflush(stdout);
            palavra_forca = strtok(palavra_inteira, ":"); // Separar palavra do seu significado (para jogo da forca).
            break;
        }
        linha_dicionario++;
    }
    fclose(dicionario); // fechar arquivo.

    int N = strlen(palavra_forca) - 1; // tamanho da palavra escondida (-1 por conta do espaço).
    
    // Substituir a string toda por 0 ex = {'0','0','0','0','0','0'}.
    int palavra_secreta[N];
    for (int i = 0; i < N; ++i)
    {
        palavra_secreta[i] = 0;
    }

    // Declaração das variaveis para jogo da forca.
    int gameover = 0;
    int tentativas = 6;
    char aux[1] = {'\0'};
    char letras_c[100] = {'\0'};
    char letras_e[100] = {'\0'};
    char zero[1] = {'\0'};
    char *ptr;

    // Apresentação do jogo.
    printf("\t\t\t\t\t\t\t----------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t\t| #  #   #   #   #  #### #   #   #   #   #           ####   #   #   # #### |\n");
    printf("\t\t\t\t\t\t\t| #  #  # #  ##  # #     ## ##  # #  ##  #          #      # #  ## ## #    |\n");
    printf("\t\t\t\t\t\t\t| #### ##### # # # #  ## # # # ##### # # #  ######  #  ## ##### # # # #### |\n");
    printf("\t\t\t\t\t\t\t| #  # #   # #  ## #   # #   # #   # #  ##          #   # #   # #   # #    |\n");
    printf("\t\t\t\t\t\t\t| #  # #   # #   #  ###  #   # #   # #   #           ###  #   # #   # #### |\n");
    printf("\t\t\t\t\t\t\t----------------------------------------------------------------------------\n\n");

    delay(5);// 5 segundos para desaparecer do terminal.

    system("clear");

    // o Jogo!
    while (!gameover)
    {

        // A palavra secreta será substituida por -------.
        printf("\t\t\t\t\t\tA palavra é: ");
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
        printf("\t\t\t\t\t\t\t\t\t\t\t\t");

        // Mostrar as palavras certas digitadas.
        printf("Palavras digitadas: ");
        for (int i = 0; i < N; i++)
        {
            printf("%c ", letras_c[i]);
        }
        printf("\n\n");

        printf("\n");

        // Proxima palavra que o jogador digitar.
        char guess;
        int count_e = 0;
        printf("Digite uma letra: ");
        fflush(stdout);
        scanf(" %c", &guess);
        system("clear");
        printf("\n\n");

        // Teste da letra digitada com a palavra escondida (substitui '-' pela letra, caso não aumenta a contagem do count_e (count_e++)).
        for (int k = 0; k < N; ++k)
        {
            if (palavra_forca[k] == guess)
            {
                palavra_secreta[k] = 1;
                letras_c[k] = guess;
            }
            else
            {
                count_e++;
            }
        }

        //Se count_e = N (tamanho da string digitada) diminui a tentativa (tentativa --).
        if (count_e == N)
        {
            tentativas--;

            //Conforme as chances forem diminuindo, vai se formando o desenho do boneco na forca
            if (tentativas > 0){
            printf("\t\t\t\t\t\t\tVocê errou!!!!\n");
            }
            if (tentativas == 6)
            {
                printf("\n\t\t\t\t\t\t\tChances: %d\n\n", tentativas);
                printf("\t\t\t\t\t\t\t  _______\n");
                printf("\t\t\t\t\t\t\t  |\n");
                printf("\t\t\t\t\t\t\t  |\n");
                printf("\t\t\t\t\t\t\t  |\n");
                printf("\t\t\t\t\t\t\t  |\n");
                printf("\t\t\t\t\t\t\t  |\n");
                printf("\t\t\t\t\t\t\t__|_________\n\n");
            }
            else if (tentativas == 5)
            {
                printf("\n\t\t\t\t\t\t\tChances: %d\n\n", tentativas);
                printf("\t\t\t\t\t\t\t  _______\n");
                printf("\t\t\t\t\t\t\t  |/   | \n");
                printf("\t\t\t\t\t\t\t  |    O \n");
                printf("\t\t\t\t\t\t\t  |\n");
                printf("\t\t\t\t\t\t\t  |\n");
                printf("\t\t\t\t\t\t\t  |\n");
                printf("\t\t\t\t\t\t\t__|_________\n\n");
            }
            else if (tentativas == 4)
            {
                printf("\n\t\t\t\t\t\t\tChances: %d\n\n", tentativas);
                printf("\t\t\t\t\t\t\t  _______\n");
                printf("\t\t\t\t\t\t\t  |/   | \n");
                printf("\t\t\t\t\t\t\t  |    O \n");
                printf("\t\t\t\t\t\t\t  |    |\n");
                printf("\t\t\t\t\t\t\t  |     \n");
                printf("\t\t\t\t\t\t\t  |\n");
                printf("\t\t\t\t\t\t\t__|_________\n\n");

            }
            else if (tentativas == 3)
            {
                printf("\n\t\t\t\t\t\t\tChances: %d\n\n", tentativas);
                printf("\t\t\t\t\t\t\t  _______\n");
                printf("\t\t\t\t\t\t\t  |/   | \n");
                printf("\t\t\t\t\t\t\t  |    O \n");
                printf("\t\t\t\t\t\t\t  |    | \n");
                printf("\t\t\t\t\t\t\t  |     \\\n");
                printf("\t\t\t\t\t\t\t  |   \n");
                printf("\t\t\t\t\t\t\t__|_________\n\n");

            }
            else if (tentativas == 2)
            {
                printf("\n\t\t\t\t\t\t\tChances: %d\n\n", tentativas);
                printf("\t\t\t\t\t\t\t  _______\n");
                printf("\t\t\t\t\t\t\t  |/   | \n");
                printf("\t\t\t\t\t\t\t  |    O \n");
                printf("\t\t\t\t\t\t\t  |    | \n");
                printf("\t\t\t\t\t\t\t  |   / \\\n");
                printf("\t\t\t\t\t\t\t  |   \n");
                printf("\t\t\t\t\t\t\t__|_________\n\n");

            }
            else if (tentativas == 1)
            {
                printf("\n\t\t\t\t\t\t\tChances: %d\n\n", tentativas);
                printf("\t\t\t\t\t\t\t  _______\n");
                printf("\t\t\t\t\t\t\t  |/   | \n");
                printf("\t\t\t\t\t\t\t  |    O \n");
                printf("\t\t\t\t\t\t\t  |   /| \n");
                printf("\t\t\t\t\t\t\t  |   / \\\n");
                printf("\t\t\t\t\t\t\t  |   \n");
                printf("\t\t\t\t\t\t\t__|_________\n\n");
            }
        }
        else
        {
            printf("\t\t\t\t\t\t\tVocê acertou!!!\n\n");
            if (tentativas == 6)
            {
                printf("\n\t\t\t\t\t\t\tChances: %d\n\n", tentativas);
                printf("\t\t\t\t\t\t\t  _______\n");
                printf("\t\t\t\t\t\t\t  |\n");
                printf("\t\t\t\t\t\t\t  |\n");
                printf("\t\t\t\t\t\t\t  |\n");
                printf("\t\t\t\t\t\t\t  |\n");
                printf("\t\t\t\t\t\t\t  |\n");
                printf("\t\t\t\t\t\t\t__|_________\n\n");

            }
            else if (tentativas == 5)
            {
                printf("\n\t\t\t\t\t\t\tChances: %d\n\n", tentativas);
                printf("\t\t\t\t\t\t\t  _______\n");
                printf("\t\t\t\t\t\t\t  |/   | \n");
                printf("\t\t\t\t\t\t\t  |    O \n");
                printf("\t\t\t\t\t\t\t  |\n");
                printf("\t\t\t\t\t\t\t  |\n");
                printf("\t\t\t\t\t\t\t  |\n");
                printf("\t\t\t\t\t\t\t__|_________\n\n");

            }
            else if (tentativas == 4)
            {
                printf("\n\t\t\t\t\t\t\tChances: %d\n\n", tentativas);
                printf("\t\t\t\t\t\t\t  _______\n");
                printf("\t\t\t\t\t\t\t  |/   | \n");
                printf("\t\t\t\t\t\t\t  |    O \n");
                printf("\t\t\t\t\t\t\t  |    |\n");
                printf("\t\t\t\t\t\t\t  |     \n");
                printf("\t\t\t\t\t\t\t  |\n");
                printf("\t\t\t\t\t\t\t__|_________\n\n");

            }
            else if (tentativas == 3)
            {
                printf("\n\t\t\t\t\t\t\tChances: %d\n\n", tentativas);
                printf("\t\t\t\t\t\t\t  _______\n");
                printf("\t\t\t\t\t\t\t  |/   | \n");
                printf("\t\t\t\t\t\t\t  |    O \n");
                printf("\t\t\t\t\t\t\t  |    | \n");
                printf("\t\t\t\t\t\t\t  |     \\\n");
                printf("\t\t\t\t\t\t\t  |   \n");
                printf("\t\t\t\t\t\t\t__|_________\n\n");

            }
            else if (tentativas == 2)
            {
                printf("\n\t\t\t\t\t\t\tChances: %d\n\n", tentativas);
                printf("\t\t\t\t\t\t\t  _______\n");
                printf("\t\t\t\t\t\t\t  |/   | \n");
                printf("\t\t\t\t\t\t\t  |    O \n");
                printf("\t\t\t\t\t\t\t  |    | \n");
                printf("\t\t\t\t\t\t\t  |   / \\\n");
                printf("\t\t\t\t\t\t\t  |   \n");
                printf("\t\t\t\t\t\t\t__|_________\n\n");

            }
            else if (tentativas == 1)
            {
                printf("\n\t\t\t\t\t\t\tChances: %d\n\n", tentativas);
                printf("\t\t\t\t\t\t\t  _______\n");
                printf("\t\t\t\t\t\t\t  |/   | \n");
                printf("\t\t\t\t\t\t\t  |    O \n");
                printf("\t\t\t\t\t\t\t  |   /| \n");
                printf("\t\t\t\t\t\t\t  |   / \\\n");
                printf("\t\t\t\t\t\t\t  |   \n");
                printf("\t\t\t\t\t\t\t__|_________\n\n");
            }
        }
        
        // Se a tentativa chegar a zero, você perdeu!!!
        if (tentativas == 0)
        {  
            printf("\t\t\t\t\t\t\tVocê perdeu!!!\n");
            printf("\t\t\t\t\t\t     Palavra era: %s\n", palavra_forca);
            {
                printf("\n\t\t\t\t\t\t\tChances: %d\n\n", tentativas);
                printf("\t\t\t\t\t\t\t  _______\n");
                printf("\t\t\t\t\t\t\t  |/   | \n");
                printf("\t\t\t\t\t\t\t  |    X \n");
                printf("\t\t\t\t\t\t\t  |   /|\\ \n");
                printf("\t\t\t\t\t\t\t  |   / \\\n");
                printf("\t\t\t\t\t\t\t  |   \n");
                printf("\t\t\t\t\t\t\t__|_________\n\n");


            }
            delay(3);
            system("clear");
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

    //Vitoria!!!!
    if (tentativas > 0)
    {
        printf("Vitoria! A palavra é \"%s\".\n", palavra_forca);
        delay(3);
    }
    system("clear");
}

int main()
{
    // Declaração de variaveis
    FILE *dicionario;
    int opcaoEscolhida;
    dicionario = fopen("dicionario.txt", "r"); // abrindo  o arquivo para leitura (read).

    // Caso não consiga abrir o arquivo imprimir erro.
    if (dicionario == NULL)
    {
        printf("Nao foi possivel abrir o arquivo");
        exit(1);
    }
    
    //Menu do jogador
    do
    {
        Menu();
        opcaoEscolhida = leitor();
        switch (opcaoEscolhida)
        {
        case 1:
            palavraNova();
            break;
        case 2:
            pesquisarPalavra();
            break;
        case 3:
            jogoForca();
            break;
        case 4:
            dicionarioInteiro();
            break;
        case 99:
            printf("Saindo...\n\n");
            break;
        default:
            printf("Opção inválida\n\n");
            Menu();
            opcaoEscolhida = leitor();
        }
    } while (opcaoEscolhida != 99);

    return 0;
}