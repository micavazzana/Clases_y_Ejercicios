typedef struct
{
    char apellido[20];
    int legajo;
    float sueldo;
    int antiguedad;

} eEmpleado;

eEmpleado CargarEmpleado();
void CargarListadoEmpleados(eEmpleado[], int);
void MostrarEmpleado(eEmpleado);
void MostrarListadoEmpleado(eEmpleado[], int);
float CalcularSueldoNeto(eEmpleado);
float Porcentaje(float, float);
