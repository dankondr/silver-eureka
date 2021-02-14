#include "PortConfigCoder.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int *pcc_getPortsFromConfig() {
  int *ports = malloc(CONFIG_PORTS_NUMBER * sizeof(int));
  FILE *file = fopen(config_file_path, "r");
  if (file == NULL) {
    printf("No %s file found.\n", config_file_path);
    exit(1);
  }

  for (int i = 0; i != CONFIG_PORTS_NUMBER; ++i) {
    int ch;
    while ((ch = fgetc(file)) != EOF) {
      if (ch == ':') break;// Пропускаем все символы до двоеточия
    }
    if (ch == EOF) {
      printf("Port config file is incorrect.\n");
      exit(1);
    }
    fgetc(file);// Пропускаем пробельный символ
    char port_string[5 +1]; // длина порта + \0
    fgets(port_string, sizeof(port_string), file);
    char *pEnd;
    int port = (int) strtol(port_string, &pEnd, 10);
    ports[i] = port;
  }

  fclose(file);
  return ports;
}
