1. Arquitectura General

El proyecto consiste en una aplicación modular desarrollada en C++ orientada al análisis básico de comportamiento en sistemas y redes dentro de un entorno controlado. La arquitectura sigue el principio de separación de responsabilidades, permitiendo que cada módulo opere de forma independiente pero coordinada.

El sistema se divide en tres capas principales:

Capa de adquisición de datos: encargada de recolectar información del sistema y de la red (por ejemplo, captura de paquetes).
Capa de procesamiento: analiza los datos obtenidos y aplica lógica básica de interpretación.
Capa de salida: registra los resultados en archivos para su posterior análisis.

La ejecución del programa se realiza en una máquina virtual aislada, lo que permite simular escenarios de análisis sin comprometer el sistema anfitrión.

2. Módulos Planeados
2.1 Packet Capture Module
Función: Capturar tráfico de red en tiempo real desde una interfaz específica.
Tecnología: libpcap

Descripción técnica:

Inicializa la interfaz de red en modo promiscuo.
Captura paquetes a bajo nivel.
Identifica protocolos básicos (IP, TCP, UDP).
Entradas: Interfaz de red seleccionada.
Salidas: Estructuras de datos con información del paquete (headers, tamaño, tipo).
Objetivo educativo: Comprender cómo funcionan los sniffers y cómo se intercepta tráfico en redes.
2.2 Process Enumeration Module
Función: Obtener información de los procesos activos en el sistema.

Descripción técnica:

Accede a estructuras del sistema operativo para listar procesos.
Recupera identificadores (PID) y nombres.
Entradas: Sistema operativo.
Salidas: Lista de procesos activos.
Objetivo educativo: Entender cómo se monitorea la actividad del sistema desde bajo nivel.
2.3 File Analysis Module
Función: Analizar archivos mediante generación de hashes.
Tecnología: OpenSSL

Descripción técnica:

Lectura de archivos en modo binario.
Generación de hashes MD5 o SHA256.
Entradas: Ruta de archivo.
Salidas: Hash generado.
Objetivo educativo: Introducción a técnicas de integridad y detección de cambios.
2.4 Logger Module
Función: Registrar toda la información generada por el sistema.

Descripción técnica:

Escritura en archivos de texto estructurados.
Registro de eventos relevantes (paquetes, procesos, hashes).
Entradas: Datos procesados por los módulos.
Salidas: Archivos de log.
Objetivo educativo: Implementar trazabilidad y análisis posterior.
3. Flujo General del Programa

El flujo del sistema está diseñado para ejecutar tareas de monitoreo de forma secuencial:

Inicialización del programa
Configuración de parámetros (interfaz de red, rutas, etc.)
Inicio del módulo de captura de paquetes
Recepción y análisis básico de paquetes
Ejecución de módulos complementarios:
Enumeración de procesos
Análisis de archivos
Registro de toda la información en logs
Finalización controlada del programa
4. Dependencias Técnicas

El proyecto utiliza librerías y herramientas estándar del entorno de desarrollo en C++:

libpcap
Permite la captura de paquetes a nivel de red.
OpenSSL
Utilizado para generación de hashes criptográficos.
Compilador C++:
g++ (Linux)
MSVC (Windows)
Sistema operativo recomendado:
Linux (mayor compatibilidad con captura de paquetes)
5. Consideraciones Técnicas y de Seguridad
El sistema está diseñado exclusivamente con fines educativos.
Todas las pruebas se realizan en una máquina virtual aislada.
No se implementarán técnicas ofensivas ni explotación activa.
El módulo de captura de paquetes no realizará inspección profunda (Deep Packet Inspection) en esta fase.
