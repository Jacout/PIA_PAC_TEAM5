# PIA: segundo avance — Team 5

Resumen:
Herramienta educativa modular que demuestra técnicas defensivas: lectura binaria, hashing SHA256, captura controlada con libpcap y enumeración pasiva de procesos via /proc. Diseñada para laboratorio; no contiene funciones ofensivas.

Diseño:
- Módulos: FileReader, HashGenerator, Sniffer, ProcessEnumerator, Logger, main.
- Límites: captura limitada (10 paquetes por defecto), no promiscuo por defecto, solo lectura de /proc.

Pruebas:
- Compilación con g++ y librerías libpcap/libssl.
- Hash sobre archivos locales.
- Sniff en interfaz loopback en ambiente controlado.
- Enumeración de procesos local.

Hallazgos:
- Binario con símbolos facilita análisis estático; el stripping reduce visibilidad.
- Componentes externos detectables (pcap, OpenSSL).

Riesgos y mitigaciones:
- Riesgo: exposición de tráfico si se usa interfaz real. Mitigación: usar 'lo' y limitar paquetes.
- Riesgo: ejecución con sudo. Mitigación: avisos en documentación.

Trabajo pendiente:
- Unit tests para HashGenerator.
- Logging rotativo y manejo de señales.
- Preparar muestras para prácticas de reversing.

