/**************************************
* Rombo hasta 20 lados 
***************************************/


/*==========================*/
/* DIRECTIVA DE COMPILACION */
/*==========================*/

#include <stdio.h>

/*===================*/
/* CREAMOS EL ROMBO  */
/*===================*/
void tamanoDelRombo(int lado) {

  int espacios;           /* cantidad de espacios para cada linea */
  int num = 0;            /* cantidad de simbolos para cada linea */
  int mitad = 0;          /* mitad del rombo */
  char simbolo1 = '@';    /* simbolo @ */
  char simbolo2 = '.';    /* simbolo . */
  char simbolo3 = 'o';    /* simbolo o */
  char ultimoSim = '@';   /* ultimo simbolo creado */
  char penultimo = ' ';   /* ultimo sim antes que llega a la mitad del rombo */
  bool imparSim = false;  /* false si es @ true si es o */

  printf("\n");
  /*-- Primera parte Superior del Rombo --*/
  for (int i = 0; i < lado; i++) {

    /*-- calcular cantidad de espacios antes de imprimir simbolos --*/
    espacios = lado - i - 1;

    /*-- calcular cuantos simbolos que crear --*/
    num = i + 1;
    if (num != 1) {
      num = num + i;
    }

    /*-- Calcular la mitad del rombo --*/
    mitad = num / 2 + 1;

    /*-- Imprimir los espacios --*/
    for (int j = 0; j < espacios; j++) {
      printf(" ");
    }

    /*-- for loop para imprimir los simbolos --*/
    for (int j = 1; j <= num; j++) {

      /*-- Imprimir el rombo por 2 partes --*/
      /*-- Primera mitad Superior--*/
      if (j <= mitad) {
        /*-- si j es 1 entonces @ --*/
        if (j == 1) {
          printf("%c", simbolo1);
          imparSim = true;
        }
        /*-- si j es multiple de 2 imprime . --*/
        else if (j % 2 == 0) {
          printf("%c", simbolo2);
          penultimo = ultimoSim;
          ultimoSim = simbolo2;

        }
        /*-- Si imparSim es False entonces imprime @ --*/
        else if (imparSim == false) {
          printf("%c", simbolo1);
          imparSim = true;
          ultimoSim = simbolo1;
        }
        /*-- Si imparSim es verdadero entonces imprime o --*/
        else {
          printf("%c", simbolo3);
          imparSim = false;
          ultimoSim = simbolo3;
        }
      }
      /*-- Segunda mitad superior --*/
      else {
        /*-- Si j es multiple de 2 imprime . --*/
        if (j % 2 == 0) {
          printf("%c", simbolo2);
        }
        /*-- Si ultimo simbolo fue . y penultimo fue @ imprime @ --*/
        else if (ultimoSim == '.' && penultimo == '@') {
          printf("%c", simbolo1);
          ultimoSim = simbolo1;
          /*-- Si ultimo simbolo fue . y penultimo fue o imprime o --*/
        } else if (ultimoSim == '.' && penultimo == 'o') {
          printf("%c", simbolo3);
          ultimoSim = simbolo3;
        }
        /*-- si ultimo simbolo fue @ imprime o --*/
        else if (ultimoSim == '@') {
          printf("%c", simbolo3);
          ultimoSim = simbolo3;
        }
        /*-- si ultimo simbolo fue o imprime @ --*/
        else if (ultimoSim == 'o') {
          printf("%c", simbolo1);
          ultimoSim = simbolo1;
        }
      }
    }
    printf("\n");
  }


  /*-- Segunda parte inferior --*/
  espacios = 1;     /* Espacios empesando en 1*/
  num = lado - 1;   /* lados menos 1 */
  ultimoSim = '@';  /* ultimo simbolo*/
  penultimo = ' ';  /* penultimo simbolo */
  imparSim = false; /* false si es @ true si es o */

  for (int i = 1; i <= lado-1; i++) {

    /*-- Imprimir espacios --*/
    for (int j = 0; j < espacios; j++) {
      printf(" ");
    }
    espacios++;

    /*-- for loop para imprimir los simbolos --*/
    for (int j = 1; j <= (2*num-1); j++) {

      /*-- Primera mitad Inferior--*/
      if (j <= num) {
        /*-- si j es 1 entonces @ --*/
        if (j == 1) {
          printf("%c", simbolo1);
          imparSim = true;
        }
        /*-- Si j es multiple de 2 imprime . --*/
        else if (j % 2 == 0) {
          printf("%c", simbolo2);
          penultimo = ultimoSim;
          ultimoSim = simbolo2;

        }
        /*-- Si imparSim es False entonces imprime @ --*/
        else if (imparSim == false) {
          printf("%c", simbolo1);
          imparSim = true;
          ultimoSim = simbolo1;
        }
        /*-- Si imparSim es verdaderp entonces imprime o --*/
        else {
          printf("%c", simbolo3);
          imparSim = false;
          ultimoSim = simbolo3;
        }
      }
      /*-- Segunda mitad Inferior--*/
      else {
        /*-- Si j es multiple de 2 imprime . --*/
        if (j % 2 == 0) {
          printf("%c", simbolo2);
        }
        /*-- Si ultimo simbolo fue . y penultimo fue @ imprime @ --*/
        else if (ultimoSim == '.' && penultimo == '@') {
          printf("%c", simbolo1);
          ultimoSim = simbolo1;
          /*-- Si ultimo simbolo fue . y penultimo fue o imprime o --*/
        } else if (ultimoSim == '.' && penultimo == 'o') {
          printf("%c", simbolo3);
          ultimoSim = simbolo3;
        }
        /*-- si ultimo simbolo fue @ imprime o --*/
        else if (ultimoSim == '@') {
          printf("%c", simbolo3);
          ultimoSim = simbolo3;
        }
        /*-- si ultimo simbolo fue o imprime @ --*/
        else if (ultimoSim == 'o') {
          printf("%c", simbolo1);
          ultimoSim = simbolo1;
        }
      }
    }
    printf("\n");
    num--; /* numero de linea dicrementa */
  }
}


/*====================*/
/* INICIO DEL PRORAMA */
/*====================*/

int main() {
  int lado; /* cantidad de lados para crear */

  printf ("Lado del Rombo? ");
  scanf ("%d", &lado);

  /*-- El lado solo del 1 al 20 si no pide el lado otra vez --*/
  if (lado > 0 && lado < 21) {
    tamanoDelRombo(lado); /* Invocamos tamanoDelRombo */
  }

}

