/*
 * blocks.c
 *
 *  Created on: Jun 20, 2021
 *      Author: utnso
 */
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netdb.h>
#include<commons/log.h>
#include<commons/collections/list.h>
#include<string.h>
#include<semaphore.h>
#include<commons/config.h>
#include<commons/bitarray.h>


#include <dirent.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
 #include <sys/mman.h> //mmap()

#include <sys/mman.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <netdb.h> //uint32_t
#include <string.h>
#include <commons/string.h>
#include <commons/config.h>

//#include <node.h> // diccionarios
#include <stdbool.h>

	void* block_copia;
	int tam_clusters = 64;
	int cant_clauster= 3;
	int fd;

void create_file_with_size(char* path,int size) {

		block_copia =malloc(size);// esto es la copia del memcpy no el mmap
	       fd = open(path, O_RDWR | O_CREAT | O_TRUNC, 0777);
	       if (fd < 0)
	       {

	          exit(EXIT_FAILURE);
	       }
	       ftruncate(fd, size);
	       block_copia = mmap(NULL, size, PROT_WRITE, MAP_SHARED, fd, 0);


	       if(block_copia == MAP_FAILED) //check mapping successful
	       	  {
	       		perror("Error  mapping \n");
	       		exit(1);
	       	  }

}

char* leerBlock(int nroBlock){

	int posicion = nroBlock * tam_clusters; // cambiar en el tp
	char* lectura=malloc(tam_clusters);
	memcpy(lectura, (block_copia +posicion) , tam_clusters);
	return lectura;
}

void borrarBlock(int bloque,int posicion){
	int posicionReal = tam_clusters * bloque + posicion;

	memcpy(block_copia /*+posicionReal*/, " ",  sizeof(char));
}



void escrbirblock(int bloque, char caracter, int posicion){
	int posicionReal = tam_clusters * bloque + posicion ;

	memcpy((block_copia +posicionReal),(&caracter), sizeof(char));



}



int main(){

	char* path= "/home/utnso/workspace/Prueba/ejemplo";

	create_file_with_size(path, tam_clusters * cant_clauster);

	for(int i =0 ; i < 5; i ++){    //------------------> ir escribirendo revisando si me quede sin espacio

	//if(espacioLibre > 0){ // lo comento xq es del tp pero es dificil mostrarlo aca
	escrbirblock(0,'H',i);
	//espacioLibre --;
	//		}

	}

//hola
	for(int i =0 ; i < 5; i ++){    //------------------> ir escribirendo revisando si me quede sin espacio

		escrbirblock(1,'J',i);

		}

	char* lectura;
	lectura = leerBlock(0);
	printf(" la lectura del block 0 es : %s \n", lectura);
	lectura = leerBlock(1);
	printf("la lectura del block 1 es: %s \n", lectura);
	munmap(block_copia, tam_clusters * cant_clauster);
	close(fd); // NO VA Aca , ver bien donde cerrar

}

