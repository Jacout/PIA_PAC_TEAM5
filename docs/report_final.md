# PIA: Reporte Final — Team 5

Fecha: (rellenar)

## Resumen

Breve descripción del objetivo, alcance y limitaciones. Herramienta educativa modular para análisis defensivo: lectura binaria, hashing (SHA256), captura controlada con libpcap, enumeración pasiva de procesos.

## Diseño

- Arquitectura modular: `FileReader`, `HashGenerator`, `Sniffer`, `ProcessEnumerator`, `Logger`, `main`.
- Decisiones: separación de I/O, uso de OpenSSL EVP, uso de libpcap en modo no promiscuo y captura limitada.

## Implementación

- Resumen de cada módulo y decisiones técnicas (ver comentarios en `src/`).

## Pruebas

- Comandos exactos para compilar y ejecutar (ver README.md y docs/tests.md). Resultados y logs deben estar en `docs/tests.md` y `/evidence`.

## Análisis estático

- Resultados de `strings`, `nm -C`, `objdump` y observaciones principales.

## Análisis dinámico

- Descripción de ejecuciones: hash, sniff en loopback (lab), enumeración de procesos. Incluir capturas y observaciones.

## Ingeniería inversa

- Hallazgos al cargar binario debug en Ghidra/Radare2: funciones relevantes, cadenas, dependencias.

## Riesgos y mitigaciones

- Riesgos (exposición de tráfico, uso de sudo) y medidas mitigantes (usar `lo`, limitar paquetes, avisos en README).

## Conclusiones

- Resumen de lo aprendido, usos educativos y trabajo futuro.
