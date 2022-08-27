// switch para cadastrar usuario, alterar, remover, mostrar cadastrados,
// cancelar cadastro: nome , idade, vacinas, login, senha.

//  scanf("%80[^\n]",nome);

#include <stdio.h>
#include <string.h>

// define usado para o switch case
#define CADASTRAR 1
#define ALTERAR 2
#define REMOVER 3
#define MOSTRAR 4
#define FIM 0

#define qtdUSER 2
#define qtdLETRAS 50
#define qtdLOGIN 20
#define qtdSENHA 8

// criaçao de um struct que tera em todo usuario
typedef struct {
  char nome[qtdLETRAS];
  char login[qtdLOGIN];
  char senha[qtdSENHA];
  int idade[qtdUSER];
  int vacinas[qtdUSER];
} usuario;

// criando uma variavel com o struct criado anteriormente
usuario users[qtdUSER];

// funcao feita para deixar os dados de cada var nulo, se existir algo lá
void zerarDados() {
  // laço para repetir a qtd total de user existentes
  for (int i = 0; i < qtdUSER; i++) {
    // colocar valor em branco na var na qual o n° do laço
    //é necessario que coloque:
    // o nome da variavel struct em questao,
    // o n° (que nesse caso e [i]) ,e
    // o caminho (qual das variaveis dentro do struct é)
    strcpy(users[i].nome, "");
    strcpy(users[i].login, "");
    strcpy(users[i].senha, "");
    users[i].idade[i] = 0;
    users[i].vacinas[i] = 0;
  }
}

int funcaoMenu() {
  int escolha;
  printf("\nxxxx..CHATBOT..xxxx");
  printf("\n--------------------\n");
  printf("\n [1] - Cadastrar");
  printf("\n [2] - Alterar");
  printf("\n [3] - Remover");
  printf("\n [4] - Mostrar Cadastrados");
  printf("\n [0] - FIM");
  printf("\nOpção:");
  scanf(" %i", &escolha);
  
  return escolha;
}

void funcaoCadastro() {
  printf("x-------------x");
  // o "j" é como se fosse um "contagemUser"
  for (int j = 0; j < qtdUSER; j++) {
    printf("\n Entrar com nome [%i°]:", j + 1);
    scanf("%s", users[j].nome);
    printf("\n Entrar nome de usuário [%i°]:", j + 1);
    scanf("%s", users[j].login);
    printf("\n Entrar com senha [%i°]:", j + 1);
    scanf("%s", users[j].senha);
    printf("\n Entrar com idade [%i°]:", j + 1);
    scanf("%i", users[j].idade);
    printf("\n Entrar com quantidade de vacinas tomadas [%i°]:", j + 1);
    scanf("%i", users[j].vacinas);
    printf("------\n");
  }
  //LEMBRAR DE COLOCAR TREQUINHO QUE APAGA A TELA
}

void funcaoAlterar() {
  printf("x-------------x");
  /*ESCOLHER QUAL CADASTRADO QUER ALTERAR*/
  printf("\n Escolha qual dos cadastrados deseja Alterar:\n");

  // laço para exibir e poder escolher
  for (int l = 0; l < qtdUSER; l++) {
    printf("\nNome [%i°]: %s", l + 1, users[l].nome);
  }

  // verificar se a ESCOLHA for um número maior que a quantidade existente de
  // cadastrados
  int escolhaUm = !0;
  printf("\nEscolha:");
  scanf("%i", &escolhaUm);

  if (escolhaUm > qtdUSER) {
    while (escolhaUm > qtdUSER) {
      printf("\nNúmero inválido. Digite outro:");
      scanf("%i", &escolhaUm);
    }
  } else if (escolhaUm <= qtdUSER) {
    printf("\nVocê escolheu %i: %s", escolhaUm, users[escolhaUm - 1].nome);

    // subtrair -1 do valor inserido pelo usuario, que sera equivalete ao dado
    --escolhaUm;
  }
  printf("\n------\n");
  printf("Nome:");
  scanf("%s", users[escolhaUm].nome);
  printf("User:");
  scanf("%s", users[escolhaUm].login);
  printf("Senha:");
  scanf("%s", users[escolhaUm].senha);
  printf("Idade:");
  scanf("%i", users[escolhaUm].idade);
  printf("Vacinas:");
  scanf("%i", users[escolhaUm].vacinas);

  /*
    Como que faço para apenas chamar uma linha de um vetor dentro de um struct,
sem que chame em seguida os outros, (consequentemente)??
-> posso apontar em especifico um
  */
  printf("\n------");
}

void funcaoRemover() {
  printf("x-------------x");
  /*ESCOLHER QUAL CADASTRADO QUER REMOVER*/
  printf("\n Escolha qual dos cadastrados deseja Remover:\n");

  // laço para exibir e poder escolher
  for (int l = 0; l < qtdUSER; l++) {
    printf("\nNome [%i°]: %s", l + 1, users[l].nome);
  }

  int escolhaDois = !0;
  printf("\nEscolha:");
  scanf("%i", &escolhaDois);

  if (escolhaDois > qtdUSER) {
    while (escolhaDois > qtdUSER) {
      printf("\nNúmero inválido. Digite outro:");
      scanf("%i", &escolhaDois);
    }
  } else if (escolhaDois <= qtdUSER) {
    printf("\nVocê escolheu %i: %s", escolhaDois, users[escolhaDois - 1].nome);

    // subtrair -1 do valor inserido pelo usuario, que sera equivalete ao dado
    --escolhaDois;

    // zerar apenas a pessoa escolhida
    strcpy(users[escolhaDois].nome, "");
    strcpy(users[escolhaDois].login, "");
    strcpy(users[escolhaDois].senha, "");
    users[escolhaDois].idade[escolhaDois] = 0;
    users[escolhaDois].vacinas[escolhaDois] = 0;
  }
  printf("\n------");
}

void funcaoMostrar() {
  printf("x-------------x");
  for (int c = 0; c < qtdUSER; c++) {
    printf("\n Nome [%i°]: %s", c + 1, users[c].nome);
    printf("\n User [%i°]: %s", c + 1, users[c].login);
    printf("\n Senha [%i°]: %s", c + 1, users[c].senha);
    printf("\n Idade [%i°]: %i", c + 1, *users[c].idade);
    printf("\n Vacinas [%i°]: %i", c + 1, *users[c].vacinas);
    printf("\n------\n");
  }
}

int main() {
  zerarDados();

  // valor da variavel é diferente de Zero
  int OP = !0;

  // enquanto OP for diferente de Zero
  while (OP != 0) {
    // chama a funcaoMenu e retonar o numero escolhido pelo user, na variavel OP
    OP = funcaoMenu();
    switch (OP) {

    case CADASTRAR: // 1
      funcaoCadastro();
      break;

    case ALTERAR: // 2
      funcaoAlterar();
      break;

    case REMOVER: // 3
      funcaoRemover();
      break;

    case MOSTRAR: // 4
      funcaoMostrar();
      break;

    case FIM: // 0
      break;

    default: // erro
      printf("Opção inválida !");
      break;
    }
  }
  return 0;
}

