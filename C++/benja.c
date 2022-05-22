#include <locale.h>
#include <stdio.h>
#include <string.h>

#define red "\033[1;31m"
#define normal "\033[0m"

char Nombre[50], Rcase5[50], Rcase3[50], Rcase9[50], RFinal[50];
int respuesta = 78;

int Rcase1 = 0;
int Rcase7 = 0;
int Puntuacion = 0;

int Prueba1 = 0;
int Prueba3 = 0;
int Prueba5 = 0;
int Prueba7 = 0;
int Prueba9 = 0;

void upper(char *str) {
  for (int i = 0; str[i] != '\0'; i++)
    if (str[i] >= 'a' && str[i] <= 'z')
      str[i] -= 32;
}

int checker(char input[], char check[]) {
  int i, result = 1;
  for (i = 0; input[i] != '\0' || check[i] != '\0'; i++) {
    if (input[i] != check[i]) {
      result = 0;
      break;
    }
  }
  return result;
}

void C1() {
  if (Prueba1 == 0) {
    printf("La puerta esta cerrada y para entrar tienes que decir cuanto "
           "es 46 + 57: ");
    scanf("%i", &Rcase1);
    if (Rcase1 == 103) {
      printf("Felicidades has conseguido abrir la puerta y has encontrado un "
             "cuchillo de cocina con sangre, probablemente el arma homicida\n");
      Prueba1 = 1;
      Puntuacion++;
      printf("Has conseguido %i de los 5 acertijos para descubrir al asesino\n",
             Puntuacion);
    } else {
      printf("Se abre una compuerta debajo de la puerta y caes al vacio y "
             "mueres vuelve a intentarlo\n");
    }
  } else {
    printf("Ya has realizado esta prueba\n");
  }
};
void C2() { printf("Se esccuhan cascabeles sera mejor no entrar aqui\n"); };
void C3() {
  if (Prueba3 == 0) {
    printf("La cerradura esta hecha de una figura de tres lados puedes "
           "adivinar que figura es?: ");
    gets(Rcase3);
    upper(Rcase3);
    if (checker(Rcase3, "TRIANGULO")) {
      printf("Felicidades has conseguido abrir la puerta y has encontrado "
             "un liston negro con cabello de la victima\n");
      Prueba3 = 1;
      Puntuacion++;
      printf("Has conseguido %i de los 5 acertijos para descubrir al asesino\n",
             Puntuacion);
    } else {
      printf("Introduces la llave con la figura equivocada y esta te da "
             "una descarga electrica, vuelve aintentarlo\n");
    }
  } else {
    printf("Ya has realizado esta prueba\n");
  }
};
void C4() {
  printf("escuchas arañasos y rugidos dentro del cuarto, sera mejor que "
         "vayamos a otra habitacion\n");
};
void C5() {
  if (Prueba5 == 0) {
    printf("Encuentras un reloj y una operacion 11+3=2 a que se referira?: ");
    gets(Rcase5);
    upper(Rcase5);
    if (checker("LA HORA",Rcase5)) {
      printf("Exacto, cambias la hora del reloj y se abre la puerta y en "
             "el interior del cuarto encuentras un plumero humedo pero "
             "aparentemente no es agua, son lagrimas\n");
      Prueba5 = 1;
      Puntuacion++;
      printf("Has conseguido %i de los 5 acertijos para descubrir al asesino \n",Puntuacion);
    } else {
      printf("Introduces la llave con la figura equivocada y esta te da "
             "una descarga electrica, vuelve aintentarlo \n");
    }
  } else {
    printf("Ya has realizado esta prueba\n");
  }
};
void C6() {
  printf("Escuchas a alguien afilando un cuchillo acercandose asi que "
         "decides no entrar \n");
};
void C7(){
    if (Prueba7 == 0) {
        printf("Ahora la puerta tienen una pantalla con los siguientes "
               "numeros, que numero crees que falta: ");
        printf(" 6  2  12 ");
        printf(" 4  5  20 ");
        printf(" 24 10    ");
        scanf("%i",&Rcase7);
        if (Rcase7 == 240) {
          printf("Muy bien, abres la puerta y encuentras un papel escrito con "
                 "tinta roja (te matare por jugar conmigo)\n");
          Prueba7 = 1;
          Puntuacion++;
          printf("Has conseguido %i de los 5 acertijos para descubrir al asesino\n",Puntuacion);
        } else {
          printf(
              "Introduces el numero equivcado y la pantalla abre una compuerta "
              "por donde ves salir mucho fuego, vuelve a intentarlo\n");
        }
      } else {
        printf("Ya has realizado esta prueba \n");
      }
};
void C8() {
  printf("Observas mucho humo salir de la habitacion, (como alguien no se "
         "dio cuenta antes)\n");
};
void C9(){
    if (Prueba9 == 0) {
        printf("Para esta puerta hay una nota escrita en la pared con un "
               "acertijo: ¿Cuántas veces puede restarse el número 1 del número "
               "1.111?: ");
        gets(Rcase9);
        upper(Rcase9);
        if (checker("UNA",Rcase9)) {
          printf("Dices la respuesta en voz alta y la puerta se abre, ves un "
                 "sobre tirado en el piso con una carta y empiezas a leerla "
                 "(Perdon Maria mi intencion no era lastimarte ni ilusionarte "
                 "pero prefiero terminar las cosas antes de morir ya que tengo "
                 "cancer y solo me quedan 3 meses) \n");
          Prueba9 = 1;
          Puntuacion++;
          printf("Has conseguido %i de los 5 acertijos para descubrir al asesino\n",Puntuacion);
        } else {
          printf("De la puerta sale un humo morado con un olor extraño y te "
                 "desmayas, vuelve a intentarlo\n");
        }
      } else {
        printf("Ya has realizado esta prueba \n");
      }
};
void C10() {
  printf("La puerta esta rota, la abre y das un paso sin darte cuenta que "
         "no hay piso y encuentras una caida gratis al vacio, intentalo de "
         "nuevo\n");
};

void (*habitacion[])() = {C1, C2, C3, C4, C5, C6, C7, C8, C9, C10};

int main() {
  setlocale(LC_ALL, "");
  printf("Es una noche fria en la ciudad y acaban de cometer un asesinato, vas "
         "a la casa donde se cometio el crimen y tienes tres sospechosos el "
         "jardinero, el mayordomo y la mucama, hay 10 cuartos dentro de la "
         "mansion y tendras que investigar cada uno de ellos para saber cual "
         "es el asesino.\n");
  printf("Hola detective ..... \n");
  printf("¿Cual es su nombre?: %s", red);
  gets(Nombre);
  printf("%s", normal);

  while (respuesta == 78) {
    // system("clear");
    printf("Okey detective %s%s%s a que habitacion desea entrar ahora: %s", red,
           Nombre, normal, red);
    scanf("%i", &respuesta);
    printf("%s", normal);
    if (respuesta >= 1 && respuesta <= 10) {
      habitacion[respuesta - 1]();
    } else {
      gets();
      break;
    }
    printf("¿Ya sabes quien es el asesino? %s", red);
    gets();
    scanf("%c", &respuesta);
    printf("%s", normal);

    gets();
  }
  printf(
      "Veamos Quien es el asesino? el jardinero, el mayordomo o la mucama: %s",
      red);
  gets(RFinal);
  printf("%s", normal);
  upper(RFinal);
  if (checker("LA MUCAMA", RFinal) == 1) {
    printf("Señalas a la mucama y le enseñas la carta que encontraste, ella "
           "comienza a llorar y a pedir perdon al cadaver que ahora se "
           "encontraba en una bolsa negra, la mucama confiesa el crimen y es "
           "llevada a juicio.%s Felicidades has completado el juego%s",
           red, normal);

  } else {
    printf("Mandas a la carcel a la persona equivocada y saliendo de la escena "
           "del crimen te encuentras con el verdadero asesino y este acaba "
           "contigo, %sPerdiste%s ",
           red, normal);
  }
}