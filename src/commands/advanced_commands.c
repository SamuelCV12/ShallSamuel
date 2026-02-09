/**
 * @file advanced_commands.c
 * @brief Implementación de comandos avanzados del sistema.
 */

#include <stdio.h>  // printf
#include <stdlib.h> // fopen, fclose
#include <string.h>  // Para usar strcmp
#include "commands.h"

/**
 * @brief Comando CREAR UN ARCHIVO NUEVO
 * 
 * Crea un archivo vacío con el nombre que especifique el usuario.
 * Si el archivo ya existe, no se sobrescribirá.
 * 
 * @param args Argumentos del comando. args[1] es el nombre del archivo a crear.
 */

void cmd_crear(char **args) {
    if (args[1] == NULL) {
        printf("Error: Se debe especificar el nombre del archivo.\n");
        return;
    }

    FILE *archivo = fopen(args[1], "w");  // Crea el archivo en modo escritura (vacío)
    if (archivo == NULL) {
        perror("Error al crear el archivo");
    } else {
        printf("Archivo '%s' creado exitosamente.\n", args[1]);
        fclose(archivo);
    }
}

 /**
  * @brief Comando ELIMINAR ARCHIVO
  * 
  * Elimina el archivo especificado por el usuario después de confirmar la operación.
  * 
  * @param args Argumentos del comando. args[1] es el nombre del archivo a eliminar.
  */
 
 void cmd_eliminar(char **args) {
     if (args[1] == NULL) {
         printf("Error: Se debe especificar el archivo a eliminar.\n");
         return;
     }
 
     printf("¿Estás seguro de que deseas eliminar el archivo '%s'? (y/n): ", args[1]);
     char confirmacion;
     scanf(" %c", &confirmacion);
 
     if (confirmacion == 'y' || confirmacion == 'Y') {
         if (remove(args[1]) == 0) {
             printf("Archivo '%s' eliminado exitosamente.\n", args[1]);
         } else {
             perror("Error al eliminar el archivo");
         }
     } else {
         printf("Operación cancelada.\n");
     }
 }
 
/**
 * @brief Comando RENOMBRAR ARCHIVO
 * 
 * Renombra el archivo especificado por el usuario de 'viejo' a 'nuevo'.
 * 
 * @param args Argumentos del comando. args[1] es el nombre del archivo viejo y args[2] es el nuevo nombre.
 */
void cmd_renombrar(char **args) {
    if (args[1] == NULL || args[2] == NULL) {
        printf("Error: Se deben especificar el archivo antiguo y el nuevo nombre.\n");
        return;
    }

    // Verificar si el nombre viejo y el nuevo son iguales
    if (strcmp(args[1], args[2]) == 0) {
        printf("Error: El nuevo nombre es el mismo que el antiguo. No se puede renombrar el archivo.\n");
        return;
    }

    if (rename(args[1], args[2]) == 0) {
        printf("Archivo '%s' renombrado a '%s' exitosamente.\n", args[1], args[2]);
    } else {
        perror("Error al renombrar el archivo");
    }
}