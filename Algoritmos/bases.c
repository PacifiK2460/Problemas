#include <stdio.h>

int main(void) {
  char digitos[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A',
                    'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
                    'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
                    'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
                    'i', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't',
                    'u', 'v', 'w', 'x', 'y', 'z'};

  int num_convertido[256];
  long int num_a_convertir;
  int sig, base, i = 0;

  printf("Numero, Base: ");
  scanf("%ld %i", &num_a_convertir, &base);

  while (num_a_convertir != 0) {
    num_convertido[i] = num_a_convertir % base;
    num_a_convertir = num_a_convertir / base;
    ++i;
  }

  --i;
  for (; i >= 0; i--) {
    printf("%c", digitos[num_convertido[i]]);
  }
  printf("\n");
}