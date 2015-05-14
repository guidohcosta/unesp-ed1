#include <stdlib.h>
#include <stdio.h>

#define MAX 100
#define TAMANHO_BUSCA 100

int dispo = 0;

struct lista {
  char nome[10];
  int chave;
};
struct lista L[MAX];

struct no {
  int info, prox;
};
struct no lista[MAX];

int busca_binaria(int x);

int busca(int x) {
  for (int i = 0; i < TAMANHO_BUSCA; i++) {
    if (x == L[i].chave) {
      return i;
    }
  }
  return -1;
};

int busca_ordenada(int x) {
  for (int i = 0; L[i].chave <= x && i < TAMANHO_BUSCA; i++) {
    if (x == L[i].chave) {
      return i;
    }
  }
  return -1;
};

void encadear_nos() {
  for (int i = 0; i < MAX - 1; i++) {
    lista[i].prox = i + 1;
  }
  lista[MAX - 1].prox = -1;
}

int pega_no() {
  int p;

  if (dispo == -1) {
    printf("Overflow");
    exit(1);
  }
  p = dispo;
  dispo = lista[dispo].prox;

  return p;
}

void libera_no(int p) {
  lista[p].prox = dispo;
  dispo = p;
}

// TODO: EXTRAIR EXEMPLO PRA FUNCAO
//  As operações de inserção e remoção de nós utilizam a função
// de busca. Considerando listas não ordenadas e a proibição de inserir chaves repetidas, temos:

// INSERCAO
/*
  if (n < MAX) {
    if (busca(x) == -1) {
      L[n] = <novo_registro>;
      n++;
    } else {
      printf("No ja existe");
    }
  } else {
    printf("Overflow");
  }
*/

// REMOCAO

/*
  if (n != 0) {
    indice = busca(x);
    if (indice != -1) {
      <reg> = L[indice];
      for (i = indice; i < n; i++) {
        L[i] = L[i + 1];
      }
      n--;
    } else {
      printf("no nao existe");
    }
  } else {
    printf("undefined");
  }
*/



int main() {
  L[0].chave = 0;
  L[1].chave = 1;
  L[2].chave = 2;
  L[3].chave = 8;
  L[4].chave = 4;
  L[5].chave = 5;
  L[6].chave = 6;

  printf("%d", busca_ordenada(8));

  return 0;
}
