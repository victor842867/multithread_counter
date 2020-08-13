#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int quantidade_de_primos;

/*Funcoes que serao utilizadas ao longo do programa*/
int verifica_primo(int x);
void* funcao_thread(void *args);

int main() {

  pthread_t thread1;
  pthread_t thread2;
  pthread_t thread3;
  pthread_t thread4;

  int i,j; /*contadores*/
  int primo;
  int entrada_atual;
  char descarte = NULL;
  void *args;

  for(i=0;descarte != '\n';i++){

    scanf("%d",&entrada_atual); /*Lendo o proximo numero que será verificado*/
    scanf("%c",&descarte);      /*Verificando se a entrada lida é final de linha*/

    pthread_create(&(thread1), NULL, funcao_thread, &entrada_atual);
    for(j=0;j<8000000;j++);

    if(descarte != '\n'){
      scanf("%d",&entrada_atual); /*Lendo o proximo numero que será verificado*/
      scanf("%c",&descarte);      /*Verificando se a entrada lida é final de linha*/

      pthread_create(&(thread2), NULL, funcao_thread, &entrada_atual);
      for(j=0;j<8000000;j++);

      if(descarte != '\n'){
        scanf("%d",&entrada_atual); /*Lendo o proximo numero que será verificado*/
        scanf("%c",&descarte);      /*Verificando se a entrada lida é final de linha*/

        pthread_create(&(thread3), NULL, funcao_thread, &entrada_atual);
        for(j=0;j<8000000;j++);

        if(descarte != '\n'){
          scanf("%d",&entrada_atual); /*Lendo o proximo numero que será verificado*/
          scanf("%c",&descarte);      /*Verificando se a entrada lida é final de linha*/

          pthread_create(&(thread4), NULL, funcao_thread, &entrada_atual);
          for(j=0;j<8000000;j++);
        }
      }
    }

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
    pthread_join(thread4, NULL);

  }

  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);
  pthread_join(thread3, NULL);
  pthread_join(thread4, NULL);

  printf("%d\n", quantidade_de_primos);
  return 0;
}


int verifica_primo(int x){
  int i; /*contador*/
  int resto;
  int resto_zero = 0;

  for(i=1;i<=x;i++){
    resto = x%i;
    if(resto == 0){
      resto_zero++;
    }
  }

  if(resto_zero == 2){
    return 1;
  }

  return 0;
}

void* funcao_thread(void *args) {
  int *x = (int*) args;
  int y = (*x);
  int primo;
  printf("Estou na thread para o valor %d!\n", y);
  primo = verifica_primo(y);
  if(primo == 1)
    quantidade_de_primos++;
  printf("Saindo da thread para o valor %d!\n", y);
  return NULL;
}
