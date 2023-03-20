/**************************************
* Calendario del año 1600 al año 3000
***************************************/

#include <stdio.h>

/*==================================
Funcion para calcular los espacios
que hay en la primera semana del
primer mes del a�o
====================================*/
int primeraSemana(int anyo){

  if(anyo == 2400){
    return 6;
  } else {
    return (((anyo - 1) * 365) + ((anyo - 1) / 4) - ((anyo - 1) / 100) + ((anyo / 400) + 1)) %7;
  }

}

/*============================================
Funcion para calcular la cantidad de dias
que hay en el mes
==============================================*/
int cantidadDeDias(int mes, int anyo){

  if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12){
    return 31;
  } else if(mes == 2){
    /* bisiesto cualquier a�o que es divisible por 4 y no entre 100
        bisiesto si es divisible por 400 y tambien si es divisible entre 100 y 400
    */
    if(((anyo % 4 == 0) && (anyo % 100 != 0)) || (anyo % 400 == 0)){
      return 29;
    } else {
      return 28;
    }
  } else {
    return 30;
  }

}

/*==============================
Funcion para crear el calendario
================================*/
void calendario(char mesNom[], int mes, int anyo){

  int semana = 7;   /* semana */
  int dia = 1;      /* indice dia */
  int diasDelMes;   /* total de dias en el mes */
  int espacios;     /* espacios para la primera semana del mes */

  espacios = primeraSemana(anyo) - 1; /* obtener primeros espacios del primer mes */
  //printf("\n\nespacios %d\n\n", espacios);

  /* Alineacion de mes y a�o */
  if(mesNom == "MAYO"){
    printf("%s %22d\n", mesNom, anyo);
  } else if(mesNom == "ENERO" || mesNom == "MARZO" || mesNom == "ABRIL" || mesNom == "JUNIO" || mesNom == "JULIO"){
    printf("%s %21d\n", mesNom, anyo);
  } else if(mesNom == "AGOSTO"){
    printf("%s %20d\n", mesNom, anyo);
  } else if(mesNom == "FEBRERO" ||mesNom == "OCTUBRE"){
    printf("%s %19d\n", mesNom, anyo);
  } else if(mesNom == "NOVIEMBRE" || mesNom == "DICIEMBRE"){
    printf("%s %17d\n", mesNom, anyo);
  } else {
    printf("%s %16d\n", mesNom, anyo); /* septiembre */
  }

  printf("===========================\n");
  printf("LU  MA  MI  JU  VI | SA  DO\n");
  printf("===========================\n");


  for(int i = 1; i <= mes; i++){

    /* Imprimir los espacios de la primera semana, solo por el mes ingresado */
    for(int j = 0; j < espacios; j++){
      if(semana == 3){
        semana = semana - 1;
        if(i == mes){
          printf(" . | ");
        }
      }else {
        if(i == mes){
          printf(" .  ");
        }
        semana = semana - 1;
      }
    }

    /* Obtener la cantidad de dias en el mes */
    diasDelMes = cantidadDeDias(i, anyo);

    /* Imprimir la cantidad de dias del mes, solo por el mes ingresado */
    while(dia <= diasDelMes){
      if(semana == 3){
        semana = semana - 1;
        if(i == mes){
          printf("%2.1d | ", dia);
        }
      } else if(semana == 1){
        if(i == mes){
          printf("%2.1d  \n", dia);
        }
        semana = 7;
      } else {
        semana = semana - 1;
        if(i == mes){
          printf("%2.1d  ", dia);
        }
      }
      dia++;



    }

    /* Espacios para el proximo mes */
      if(semana == 6){
        espacios = 1;
      } else if (semana == 5){
        espacios = 2;
      } else if (semana == 4){
        espacios = 3;
      } else if (semana == 3){
        espacios = 4;
      } else if (semana == 2){
        espacios = 5;
      } else if(semana == 1){
        espacios = 6;
      } else if(semana == 7){
        espacios = 0;
      }
     // printf("\n\nSemana: %d Espacios: %d\n\n", semana, espacios);

    /* Espacios para el final del mes */
    if(i == mes){
      if(semana != 7){
        while(semana != 0){
          if(semana == 3){
            printf(" . | ");
          }else {
            printf(" .  ");
          }
          semana--;
        }
      }
    }

    /* Reiniciar para el proximo mes */
    semana = 7;
    dia = 1;
  }

  printf("\n");
}


/*================
Programa principal
==================*/
int main(){

  int mes = 0;  /* Mes */
  int anyo = 0; /* A�o */

  /* Ingresar el mes y a�o */ {
    printf("Mes (1..12)? ");
    scanf("%d", &mes);
    printf("A�o (1601..3000)? ");
    scanf("%d", &anyo);
  }

  printf("\n");

  /* Mes y a�o son validos? */
  if((mes >= 1 && mes <= 12) && (anyo >= 1601 && anyo <= 3000)){
    if(mes == 1){
      calendario("ENERO", mes, anyo);
    } else if(mes == 2){
      calendario("FEBRERO", mes, anyo);
    }
    else if(mes == 3){
      calendario("MARZO", mes, anyo);
    }
    else if(mes == 4){
      calendario("ABRIL", mes, anyo);
    }
    else if(mes == 5){
      calendario("MAYO", mes, anyo);
    }
    else if(mes == 6){
      calendario("JUNIO", mes, anyo);
    }
    else if(mes == 7){
      calendario("JULIO", mes, anyo);
    }
    else if(mes == 8){
      calendario("AGOSTO", mes, anyo);
    }
    else if(mes == 9){
      calendario("SEPTIEMBRE", mes, anyo);
    }
    else if(mes == 10){
      calendario("OCTUBRE", mes, anyo);
    }
    else if(mes == 11){
      calendario("NOVIEMBRE", mes, anyo);
    }
    else {
      calendario("DICIEMBRE", mes, anyo);
    }
  }

}
