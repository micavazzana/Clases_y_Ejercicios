/*
 * Envio.h
 *
 *  Created on: 13 nov. 2020
 *      Author: micavazzana
 */
#ifndef ENVIO_H_
#define ENVIO_H_
#define NAME_LEN 51
#define ZONE_LEN 51

typedef struct {
	int idEnvio;
	char nombreProducto[NAME_LEN];
	int idCamion;
	char zonaDestinos[ZONE_LEN];
	float kmRecorridos;
	int tipoEntrega;
	float costoEnvio;
}Envio;

typedef struct{
	char zonaDestinos[ZONE_LEN];
}Zona;

Envio* envio_new(void);
Envio* envio_newParametros(char* idEnvio, char* nombreProducto, char* idCamion, char* zonaDestinos, char* kmRecorridos, char* tipoEntrega);
void envio_delete(Envio* this);

int envio_setId(Envio* this, int id);
int envio_getId(Envio* this, int* id);
int envio_setIdTxt(Envio* this, char* id);
int envio_getIdTxt(Envio* this, char* id);

int envio_setNombreProducto(Envio *this, char* name);
int envio_getNombreProducto(Envio* this, char* name);

int envio_setIdCamion(Envio* this, int id);
int envio_getIdCamion(Envio* this, int* id);
int envio_setIdCamionTxt(Envio* this, char* id);
int envio_getIdCamionTxt(Envio* this, char* id);

int envio_setZonaDestinos(Envio *this, char* zona);
int envio_getZonaDestinos(Envio* this, char* zona);

int envio_setKmRecorridos(Envio* this, float kmRecorridos);
int envio_getKmRecorridos(Envio* this, float* kmRecorridos);
int envio_setKmRecorridosTxt(Envio* this, char* kmRecorridos);
int envio_getKmRecorridosTxt(Envio* this, char* kmRecorridos);

int envio_setTipoEntrega(Envio* this, int tipoEntrega);
int envio_getTipoEntrega(Envio* this, int* tipoEntrega);
int envio_setTipoEntregaTxt(Envio* this, char* tipoEntrega);
int envio_getTipoEntregaTxt(Envio* this, char* tipoEntrega);

int envio_setCostoEnvio(Envio* this, float costoEnvio);
int envio_getCostoEnvio(Envio* this, float* costoEnvio);
int envio_setCostoEnvioTxt(Envio* this, char* costoEnvio);
int envio_getCostoEnvioTxt(Envio* this, char* costoEnvio);

float envio_calcularCosto(float kmRecorridos, int tipoEntrega);
int envio_compararZona(void* this, void* arg);

Zona* zona_new(void);
int zona_setZonaDestinos(Zona *this, char* zona);
int zona_getZonaDestinos(Zona* this, char* zona);

#endif /* ENVIO_H_ */
