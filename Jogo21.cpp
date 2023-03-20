#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int jogo();
int compra_carta();
void recorde(int);
void mostrar_regras();
int verifica_soma(int);

int main()
{
    setlocale(LC_ALL, "portuguese");
    char escolha;
    while (escolha != 'n' && escolha != 'N')
    {
        jogo();
        cout << "\nDeseja continuar jogando ? (s/n) : ";
        cin >> escolha;
    }
}

int compra_carta()
{
    int monte = 1 + rand() % 13;
    if (monte > 10)
    {
        monte = 10;
    }
    return monte;
}

void recorde(int n)
{
    static int recorde = 0;
    cout << "Sua pontuação = " << n << endl;
    cout << "Seu recorde = " << recorde << endl;

    if (n > recorde)
    {
        cout << "Voce obteve um novo recorde." << endl;
        recorde = n;
    }
}

void mostrar_regras()
{
    char escolha;
    cout << "Seja Bem-Vindo(a), ao jogo do 21 ou BlackJack. Antes de começar a jogar, deseja ver as regras ? (S/N) => ";
    cin >> escolha;

    if (escolha == 's')
    {
        cout << "Certo, vamos as regras." << endl;
        cout << "(1) - Valor das cartas: todas as cartas com figura (valete, dama e rei) valem 10 pontos; o ás, vale 1; e as demais cartas valem o seu próprio número." << endl;
        cout << "(2) - Incialmente, o jogador recebe 3 cartas (e calcula a soma de pontos)." << endl;
        cout << "(3) - Se a soma de seus pontos der 21, ele já vence no início." << endl;
        cout << "(4) - Se ele ultrapassar os 21 pontos, já perde no início." << endl;
        cout << "(5) - Se passar do início, para formar os 21 pontos, o jogador pode “comprar” uma carta do monte, quantas vezes quiser, e somar os pontos desta carta aos seus pontos atuais. Mas ele deve fazer isso com cautela. Se em algum momento seus pontos ultrapassarem 21, ele perde o jogo." << endl;
        cout << "(6) - O jogador deve informar quando quiser para de comprar cartas e encerrar a rodada (caso não tenha atingido (vence) ou ultrapassado (perde) os 21 pontos. Se ele parar sem atingir os 21." << endl;
        cout << "\nPronto, agora que viu as regras vamos dar inicio ao jogo.\n";
    }
}

int verifica_soma(int soma)
{
    if (soma == 21)
    {
        cout << "Parabéns, você venceu de inicio." << endl;
        return 0;
    }
    else if (soma > 21)
    {
        cout << "Infelizmente, você perdeu no inicio." << endl;
        return 0;
    }

    return 1;
}

int jogo()
{
    int primeira_carta = compra_carta();
    int segunda_carta = compra_carta();
    int terceira_carta = compra_carta();
    char opcao;

    mostrar_regras();

    int soma_cartas = primeira_carta + segunda_carta + terceira_carta;
    cout << "\nA soma de suas três primeiras cartas = " << soma_cartas << endl;

    if (verifica_soma(soma_cartas) == 0)
    {
        return 0;
    }

    cout << "\nDeseja comprar mais cartas ? (S/N): ";
    cin >> opcao;

    while (opcao != 'N' && opcao != 'n')
    {

        soma_cartas += compra_carta();

        if (soma_cartas == 21)
        {
            cout << "Parabéns, você venceu." << endl;
            break;
        }
        else if (soma_cartas > 21)
        {
            cout << "Infelizmente, você perdeu. A soma de suas cartas deu : " << soma_cartas << endl;
            break;
        }

        cout << "\nDeseja comprar mais cartas ou vai parar de jogar ? " << endl;
        cout << "Soma das cartas: " << soma_cartas << endl;
        cout << "Sua resposta (S/N) =>  ";
        cin >> opcao;
    }

    if (soma_cartas <= 21)
    {
        cout << "\nA soma de suas cartas foi igual ou menor que 21. Parabéns, você venceu !!! " << endl;
        recorde(soma_cartas);
    }

    return 0;
}