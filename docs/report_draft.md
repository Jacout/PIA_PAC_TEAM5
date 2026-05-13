# PIA: segundo avance — Team 5

1. Descripción del Payload

El proyecto es una herramienta modular desarrollada en C++ orientada al análisis básico de comportamiento de archivos, procesos y tráfico de red en un entorno controlado. El objetivo principal es demostrar técnicas defensivas relacionadas con lectura binaria, generación de hashes SHA256, captura controlada de tráfico mediante libpcap y enumeración pasiva de procesos utilizando el sistema de archivos /proc.

La aplicación no contiene funcionalidades ofensivas ni mecanismos de explotación. Todas las operaciones realizadas son de carácter local, permitiendo realizar prácticas académicas relacionadas con ciberseguridad, análisis defensivo y reversing básico.
Las funcionalidades principales del proyecto son:
•	Lectura binaria de archivos locales. 
•	Generación de hashes SHA256 usando OpenSSL. 
•	Captura limitada de paquetes de red mediante libpcap. 
•	Enumeración pasiva de procesos activos. 
•	Registro de eventos y errores mediante logs. 

2. Diseño
La arquitectura del proyecto sigue un enfoque modular con separación de responsabilidades para facilitar mantenimiento, depuración y pruebas.
Módulos principales
FileReader
Se encarga de abrir archivos binarios y cargar su contenido en memoria utilizando vectores de bytes (std::vector<unsigned char>). Este módulo funciona como base para el cálculo de hashes y análisis de archivos.
HashGenerator
Utiliza la librería OpenSSL para generar hashes SHA256 tanto de archivos como de datos binarios almacenados en memoria. Los hashes se devuelven en formato hexadecimal.

Sniffer
Implementa captura limitada de paquetes utilizando la librería libpcap. La herramienta trabaja en modo no promiscuo por defecto y limita la cantidad de paquetes capturados para reducir riesgos y mantener un comportamiento controlado.
ProcessEnumerator
Realiza enumeración pasiva de procesos leyendo información desde /proc. El módulo únicamente consulta información disponible en el sistema y no interactúa ni modifica procesos activos.

Logger
Permite registrar eventos y errores tanto en consola como en archivos de log. También utiliza mecanismos básicos de sincronización mediante mutex para evitar problemas de concurrencia.
Main
Actúa como punto central de ejecución y permite seleccionar las funcionalidades disponibles mediante argumentos de línea de comandos.

3. Pruebas Realizadas
Durante el desarrollo se realizaron diferentes pruebas funcionales para validar el comportamiento de cada módulo.
Compilación del proyecto
La herramienta fue compilada utilizando g++ junto con las librerías libpcap y OpenSSL en un entorno Linux.
Prueba de hashing
Se realizaron pruebas generando hashes SHA256 de archivos locales para validar la correcta lectura binaria y el funcionamiento de OpenSSL.
Prueba de captura de tráfico
Se ejecutaron pruebas de sniffing sobre la interfaz loopback (lo) dentro de un entorno controlado. La captura se limitó a pocos paquetes para evitar exposición innecesaria de tráfico.

Enumeración de procesos
Se verificó la lectura correcta de procesos activos mediante consultas pasivas al directorio /proc.
Registro de eventos
Se comprobó el funcionamiento del sistema de logging tanto en consola como en archivos externos.

4. Hallazgos Iniciales del Análisis
Durante el análisis preliminar del binario y del comportamiento del programa se identificaron distintos aspectos relevantes.
Uno de los hallazgos principales fue que la compilación con símbolos de depuración facilita significativamente el análisis estático del binario, ya que funciones, nombres de módulos y estructuras internas permanecen visibles. 
También se observó que las dependencias externas como libpcap y OpenSSL pueden identificarse fácilmente durante el análisis mediante herramientas de reversing, lo cual permite inferir parte de las funcionalidades del programa.
En el caso del módulo de sniffing, se identificó que el uso de captura limitada y modo no promiscuo reduce considerablemente el alcance de monitoreo y ayuda a mantener un comportamiento más seguro en entornos de laboratorio.

5. Riesgos y Mitigaciones
Riesgo: exposición de tráfico de red
Si la herramienta se ejecuta sobre interfaces reales de red podría capturar tráfico sensible o información no destinada al análisis.
Mitigación
Se recomienda utilizar exclusivamente la interfaz loopback (lo) y mantener límites estrictos en la cantidad de paquetes capturados.
Riesgo: ejecución con privilegios elevados
El módulo de captura de tráfico puede requerir permisos de administrador (sudo), lo cual representa un riesgo si la herramienta se utiliza incorrectamente.


Mitigación
Se agregaron advertencias en la documentación indicando que la ejecución debe realizarse únicamente en entornos controlados y educativos.
Riesgo: exposición de información del sistema
La enumeración de procesos puede revelar nombres de aplicaciones y servicios activos del sistema local.
Mitigación
El módulo trabaja únicamente en modo lectura y no interactúa con los procesos detectados.

6. Trabajo Pendiente
El proyecto aún cuenta con varias mejoras planeadas para futuras versiones.
Entre las tareas pendientes se encuentran:
•	Implementar pruebas unitarias para el módulo HashGenerator. 
•	Mejorar el sistema de logging.
•	Agregar manejo adecuado de señales y cierre seguro del programa. 
•	Preparar muestras y escenarios específicos para prácticas de reversing. 
•	Mejorar validaciones de entrada y manejo de errores en todos los módulos.

