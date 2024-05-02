#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int diaSemanaI;    // Dia da semana em que o 1º de janeiro cai
int anoBi;         // Indica se o ano é bissexto (1 Verdadeiro | 0 Falso)
int ano, mes, dia; // Ano atual

int mesDias[] = {31, 28, 31, 30, 31, 30,
                 31, 31, 30, 31, 30, 31}; // Número de dias em cada mês
char *days[] = {"dom", "seg", "ter", "qua",
                "qui", "sex", "sab"}; // Dias da semana

char *months[] = {"Janeiro",  "Feveiro", "Março\t",  "Abril",
                  "Maio",     "Junho",   "Julho",    "Agosto",
                  "Setembro", "Outubro", "Novembro", "Dezembro"};

int agendamentos[12][31]; // Array que irá armazenar os agendamentos

void inicializarAgendamentos() {
  for (int i = 0; i < 12; i++) {
    for (int j = 0; j < mesDias[i]; j++) {
      agendamentos[i][j] = 0; // Inicialmente não há agendamentos
    }
  }
}

int calcularDiaSemana(int mes) {
  int totalDias = 0;
  // Somar o número de dias de todos os meses anteriores
  for (int i = 0; i < mes; i++) {
    totalDias += mesDias[i];
  }
  // Considerar o ano bissexto, se aplicável
  if (mes > 1 && anoBi)
    totalDias++;
  // Adicionar o deslocamento do dia da semana inicial
  return (diaSemanaI + totalDias) % 7;
}

// função que mostra os o calendário
void mostrarCalendario() {
  printf("\nCalendário do ano %d\n", ano);
  for (int i = 0; i < 12; i++) { // Para cada mês
    printf("|-----------------------------|\n");
    printf("|%-29s|\n", months[i]);
    printf("|-----------------------------|\n");
    printf("| dom seg ter qua qui sex sab |\n");
    printf("|");
    int diaDaSemana =
        calcularDiaSemana(i); // Dia da semana do primeiro dia do mês
    int linhasImpressas = 1;  // Quantidade de linhas que já foram impressas
    // Pular dias vazios do início do mês
    for (int j = 0; j < diaDaSemana; j++) {
      printf("  --");
    }

    // Dias do mês
    for (int diaDoMes = 1; diaDoMes <= mesDias[i]; diaDoMes++) {
      printf("  %02d", diaDoMes);
      if (diaDaSemana >= 6 &&
          anoBi == 1) { // alterar fevereiro caso ano Bissexto
        printf(" |\n|");
        diaDaSemana = 0;
        linhasImpressas++;
        mesDias[1] = 28 + 1;
        mesDias[2] = 31;
      } else if (diaDaSemana >= 6) { // Chegou no sábado, começar nova linha
        printf(" |\n|");
        // printf("teste");
        diaDaSemana = 0;
        linhasImpressas++;
      } else
        // printf("despois");
        diaDaSemana++;
    }
    dia = diaDaSemana + 1;

    if (linhasImpressas == 5) {
      // Preencher o que falta na quinta linha
      while (diaDaSemana <= 6) {
        printf("  --");
        diaDaSemana++;
      }
      // Imprimir a sexta linha
      printf(" |\n|  --  --  --  --  --  --  -- |\n");
    } else if (linhasImpressas == 6) {
      // preencher o que falta na sexta linha
      for (int x = dia - 1; x <= 6; x++)
        printf("  --");
      printf(" |\n");
    }
  }
}

// Função que insere os agendamentos
void inserirAgendamento() {
  int mes, diaInicio, duracao;

  printf("\nDigite o mês (1-12): ");
  scanf("%d", &mes);
  printf("Digite o dia de inícial do agendamento: ");
  scanf("%d", &diaInicio);
  printf("Digite a duração do agendamento (em dias): ");
  scanf("%d", &duracao);

  // Verifica se há conflito com outros agendamentos
  int conflito = 0;
  for (int d = diaInicio - 1; d < diaInicio - 1 + duracao; d++) {
    if (agendamentos[mes - 1][d] >= 5) {
      conflito = 1;
      break;
    }
  }

  if (conflito) {
    printf("Não foi possível agendar neste dia, aconteceu um conflito nos "
           "agendamentos.\n");
  } else {
    // Realiza o agendamento
    for (int d = diaInicio - 1; d < diaInicio - 1 + duracao; d++) {
      agendamentos[mes - 1][d]++;
    }
    printf("O seu agendamento foi realizado com sucesso!\n");
  }
}

// calendario apenas com os dias agendados
void mostrarCalendarioAgendado() {
  printf("\nCalendário Agendado do ano: %d\n", ano);
  // laço para os dias agendados
  for (int i = 0; i < 12; i++) {
    printf("|----------------|\n");
    printf("%-29s|\n", months[i]);
    printf("|----------------|\n");
    printf("| dom seg ter qua qui sex sab |\n");
    printf("|");
    // dias agendados
    for (int j = 0; j < mesDias[i]; j++) {
      if (agendamentos[i][j] > 0)
        printf(" %3d", j + 1);
      else
        printf("    ");
      if ((j + 1) % 7 == 0)
        printf(" |\n|");
    }
    printf("                     |\n");
  }
}

int main() {
  printf("Digite o dia que o 1º de janeiro cai (0-6, onde 0 é domingo): ");
  scanf("%d", &diaSemanaI);
  printf("Digite o ano: ");
  scanf("%d", &ano);
  // verifica se o ano é bissexto
  if (ano % 2 == 0) {
    printf("O ano é bissexto? (1 sim, 0 não): ");
    scanf("%d", &anoBi);
    // corrige erro do usuario
    if (anoBi != 1) {
      printf("O ano é bissexto.");
      anoBi = 1;
    }
  } else if (ano % 2 != 0) {
    printf("O ano é bissexto? (1 sim, 0 não): ");
    scanf("%d", &anoBi);
    if (anoBi != 0) {
      printf("O ano não é bissexto.");
      anoBi = 0;
    }
  }

  inicializarAgendamentos();
  // geração do menu
  int opcao;
  do {
    printf("\nMenu:\n");
    printf("1. Mostrar Calendário\n");
    printf("2. Inserir Agendamento\n");
    printf("3. Mostrar Calendário com Agendamentos\n");
    printf("4. Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);
    // verifica a escolha do menu
    switch (opcao) {
    case 1:
      mostrarCalendario();
      break;
    case 2:
      inserirAgendamento();
      break;
    case 3:
      mostrarCalendarioAgendado();
      break;
    case 4:
      printf("Saindo...\n");
      break;
    default:
      printf("Opção inválida. Tente novamente mais tarde.\n");
    }
  } while (opcao != 4);

  return 0;
}
