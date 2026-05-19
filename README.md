PIA Team 5 — Segundo Avance
===========================

Objetivo del proyecto
---------------------
Herramienta educativa modular para análisis defensivo en laboratorio: lectura segura de archivos, generación de hashes SHA256, captura controlada de paquetes con libpcap y enumeración pasiva de procesos via /proc. Diseñado para prácticas de reversing y análisis estático/dinámico en entornos controlados.

Dependencias
------------
- build-essential (g++)
- libpcap-dev
- libssl-dev

Instalación (Debian/Ubuntu)
---------------------------
```bash
sudo apt update
sudo apt install -y build-essential libpcap-dev libssl-dev
```

Cómo compilar (comando exacto)
----------------------------
Desde la raíz del repositorio:
```bash
make debug
make stripped
```

Cómo ejecutar (comandos exactos)
--------------------------------
- Hash de archivo:
```bash
./bin/pia_team5_debug hash path/to/file
```
- Sniff (laboratorio, puede requerir sudo):
```bash
sudo ./bin/pia_team5_debug sniff lo
```
- Enumerar procesos:
```bash
./bin/pia_team5_debug processes
```

Enlace al reporte final
-----------------------
docs/report_final.md (convertir a PDF: see docs/report_final.md)

Enlace al video (si aplica)
-------------------------
- (Añadir enlace aquí una vez subido)

Qué se evalúa aquí
-------------------
- Reproducibilidad total: pasos exactos para compilar y ejecutar.
- Claridad técnica: documentación y comentarios en el código.

Licencia y uso
--------------
Uso educativo únicamente. Realizar pruebas solo en entornos controlados.
# PIA_PAC_TEAM5


## Objetivo
Revisar los puntos, temas y tecnicas vistas en la materia relacionadas a la programación avanzada en la ciberseguridad, viendo temas tecnicos como uso de memoria, punteros y herramientas de los diferentes sistemas operativos.

## Descripción técnica

## Alcance y límites


## Compilación


## Ejecución

## Integrantes
**Jacob Misael Rodríguez Morales**
**Matthew Rosas Lailson**
**Cruz Eduardo Patiño Zuñiga**
**Jahir Guadalupe Salazar Esparza**
