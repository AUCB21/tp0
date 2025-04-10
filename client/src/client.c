#include "client.h"
#include <commons/config.h>
#define TP0_LOG "tp0.log"

int main(void)
{
	/*---------------------------------------------------PARTE 2-------------------------------------------------------------*/

	int conexion;
	char *ip;
	char *puerto;
	char *valor;

	t_log *logger;
	t_config *config;

	/* ---------------- LOGGING ---------------- */

	logger = iniciar_logger();

	logger = log_create(
			TP0_LOG,
			"LogProcess",
			1,
			LOG_LEVEL_INFO);

	log_info(
			logger,
			"Test Log msj!");

	log_destroy(logger);

	/* ---------------- ARCHIVOS DE CONFIGURACION ---------------- */

	config = iniciar_config();

	config = config_create("cliente.config");
	
	valor = config_get_string_value(config, "CLAVE");
	


	logger = log_create(
		TP0_LOG,
		"ConfigProcess",
		1,
		LOG_LEVEL_INFO
	);

	log_info(
		logger,
		"Config Cargado"
	);
	
	log_destroy(logger);

	logger = log_create(
		TP0_LOG,
		"Config Process",
		1,
		LOG_LEVEL_INFO
	);
// Loggeamos el valor de config
	log_info(logger,
	"Clave Cargada de 'cliente.config'");

	log_info(
		logger,
		valor
	);

	log_destroy(logger);

	/* ---------------- LEER DE CONSOLA ---------------- */

	leer_consola(logger);

	/*---------------------------------------------------PARTE 3-------------------------------------------------------------*/

	// ADVERTENCIA: Antes de continuar, tenemos que asegurarnos que el servidor esté corriendo para poder conectarnos a él

	// Creamos una conexión hacia el servidor
	conexion = crear_conexion(ip, puerto);

	// Enviamos al servidor el valor de CLAVE como mensaje

	// Armamos y enviamos el paquete
	paquete(conexion);

	terminar_programa(conexion, logger, config);

	/*---------------------------------------------------PARTE 5-------------------------------------------------------------*/
	// Proximamente
}

t_log *iniciar_logger(void)
{
	t_log *nuevo_logger;

	return nuevo_logger;
}

t_config *iniciar_config(void)
{
	t_config *nuevo_config;

	return nuevo_config;
}

void leer_consola(t_log *logger)
{
	char* linea;

	while(1){
		linea = readline("Ingrese un mensaje(exit para salir): ");
		if (strcmp(linea, "exit") == 0) {
			free(linea);
			break;
		}
		log_create(
			TP0_LOG,
			"ConsolaProcess",
			1,
			LOG_LEVEL_INFO
		);
		log_info(logger, "Mensaje ingresado: %s", linea);
		log_destroy(logger);
		free(linea);
	};
}

void paquete(int conexion)
{
	// Ahora toca lo divertido!
	char *leido;
	t_paquete *paquete;

	// Leemos y esta vez agregamos las lineas al paquete

	// ¡No te olvides de liberar las líneas y el paquete antes de regresar!
}

void terminar_programa(int conexion, t_log *logger, t_config *config)
{
	/* Y por ultimo, hay que liberar lo que utilizamos (conexion, log y config)
		con las funciones de las commons y del TP mencionadas en el enunciado */
}
