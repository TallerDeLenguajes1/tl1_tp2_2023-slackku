# tl1_tp2_2023-slackku

Desarrollo de las actividades planteadas para en el Trabajo Practico N° 2 de Taller de Lenguajes 1

## Notas
Notas de la resolucion de los puntos de este trabajo practico para el futuro.

### Punto 4
Todos los datos de la estructura PC/compu, seran pseudo-aleatorios, tanto los datos numericos como el tipo de procesador.

En el desarrollo del punto 4, surgieron ciertos problemas a la hora del planteo, con respecto al desarrollo de este mismo. Especificamente con el setteo de los valores del tipo del procesador dentro de la estructura que se entrega explicitamente en el apartado `iii` como se ve a continuación:

```C
struct compu {
    int velocidad;
    int anio;
    int cantidad;
    char *tCPU;
}
```
Esta estructura me dificulto el acercamiento a la resolucion del problema. Especificamente el tipo de dato  `char *tCPU`.
#### Solucion
Redefinir `char *tCPU` como `char tCPU[10]`. 
A la hora de la carga de datos, se obtiene de forma pseudo-aleatoria un numero del 0 al 5, que luego se multiplica por 10, para de esta forma obtener el indice del primer caracter de las opciones dentro de la matriz tipos.

`char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};`

Para luego con un bucle guardar los proximos 9 caracteres en `tCPU` caracter por caracter.

### Aclaraciones
Se tiene constancia de la existencia de algun otro metodo de resolucion de la problematica, sin embargo, este fue el que pude desarrollar por mi cuenta para completar el punto. 

## Autor

- José Ignacio Lorenzo - _Alumno_ - [slackku](https://github.com/slackku)
