/*
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

int main()
{
	  uint32_t cantidad_clusters = 3;
	  uint32_t tam_cluster = 4;

	  //uint32_t tamSuperBloque = 2 * sizeof(uint32_t)+ sizeof(uint32_t) * cantidad_clusters;

	  /*uint32_t bitmap[cantidad_clusters];
	  for(int i = 0; i < cantidad_clusters; i++){
		  bitmap[i]= 0; //inicializo en 0
	  }*/
/*
	  char* cant_clusters = string_itoa(cantidad_clusters);
	  char* taman_cluster = string_itoa(tam_cluster);
	  char* bitmapChar =  string_new();

	  string_append(&bitmapChar, "[");
	  for(int i = 0; i < cantidad_clusters -1; i++){ //hice "-1" para que al ultimo no le agregue la ,
		  string_append(&bitmapChar, "0,");
	  }
	  string_append(&bitmapChar, "0"); //agrego el ultimo sin ,
	  string_append(&bitmapChar, "]");


	  char* todoElContenidoDelArchivo = string_new();
	  string_append(&todoElContenidoDelArchivo, "Block_size=");
	  string_append(&todoElContenidoDelArchivo, taman_cluster);

	  string_append(&todoElContenidoDelArchivo, "\nBlocks=");
	  string_append(&todoElContenidoDelArchivo, cant_clusters);

	  string_append(&todoElContenidoDelArchivo, "\nBitmap=");
	  string_append(&todoElContenidoDelArchivo, bitmapChar);

	  uint32_t tamContenido = string_length(todoElContenidoDelArchivo) + 1; // por el /0 de los strings

	  void* addr = malloc(tamContenido);
	  char* path;
	  int fd;

	  //path = "/home/utnso/Desktop/TP-SO/tp-2021-1c-GrupoChicasSistOp2021/SuperBloque.ims";
	  path = "testing.ims";

	  fd = open(path, O_RDWR | O_CREAT | O_TRUNC, 0777); // el ultimo parametro son permisos
	  if (fd < 0)
	  {
	      printf("fallo abrir/crear el archivo");
	      exit(EXIT_FAILURE);
	  }
	  // O_CREAT significa que si el archivo no existe, lo crea --> puede llegar a fallar si esta esto (sin el TRUNC) y el archivo ya existe :(
	  // O_RDONLY significa read only
	  // O_WRONLY significa write only
	  // O_RDWR significa reading and writing
	  // O_TRUNC dice: If the file exists and is a regular file, and the file is successfully opened O_RDWR or O_WRONLY, its length is truncated to 0 and the mode and owner are unchanged.

	  printf("contenido que deberia tener el archivo si sale bien: \n%s\n(%d caracteres)", todoElContenidoDelArchivo, tamContenido);

	  ftruncate(fd, tamContenido);
	  // en stack overflow lei esto:

	  //When you create the destination file as a new file, its size is 0 bytes.
	   //memcpy crashes because it tries to write data beyond the end of the file.
	//You can make this work by pre-sizing the destination file to the size of the source file (using ftruncate()) before you mmap() it

	  addr = mmap(NULL, tamContenido, PROT_WRITE, MAP_SHARED, fd, 0); // map file


	  if(addr == MAP_FAILED) // check mapping successful
	  {
		perror("Error  mapping \n");
		exit(1);
	  }


	memcpy(addr, todoElContenidoDelArchivo, tamContenido);

	//printf("\nfile contents after:\n%s \n", addr); // write file contents after modification

	msync(fd, tamContenido, MS_SYNC); // entiendo que como que persiste en el archivo lo que cambiamos,
	// pero no termine de entender (la consigna decia que investiguemos msync)


	munmap(addr, string_length(todoElContenidoDelArchivo)); // creo que es como el free, libera lo que ocupo mmap

	close(fd);

	printf("\nAHORA VOY A PROBAR LEERLO COMO SI FUERA UN CONFIG:\n");

	t_config* superBloqueConfig = config_create(path);

	//printf("la cantidad de configs es de %d", config_keys_amount(superBloqueConfig));


	int blocksConfig, blocksSizeConfig;

	char* blocksConfig2;
	char* blocksSizeConfig2;

	blocksConfig2 = strdup(config_get_string_value(superBloqueConfig,"Blocks"));
	blocksSizeConfig2 = strdup(config_get_string_value(superBloqueConfig,"Block_size"));

	//blocksConfig = strdup(config_get_int_value(superBloqueConfig,"Blocks")); //ESTO NO ME FUNCIONA :(
	//blocksSizeConfig = strdup(config_get_int_value(superBloqueConfig,"Block_size"));

	blocksConfig = atoi(blocksConfig2);
	blocksSizeConfig = atoi(blocksSizeConfig2);

	printf("Los valores leidos de la config: \n");
	printf("blocks: %d\n", blocksConfig);
	printf("blocks size: %d\n", blocksSizeConfig);

	char** arrayDeBitmapConfig = config_get_array_value(superBloqueConfig, "Bitmap");

	printf("valores del bitmap: \n");
	for(int i = 0; i < blocksConfig; i++){
		printf("%d,", atoi(arrayDeBitmapConfig[i]));
	}

	return 0;
}
*/
