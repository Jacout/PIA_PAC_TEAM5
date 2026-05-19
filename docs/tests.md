# Tests y pasos de ejecución

## 1) Dependencias (Debian/Ubuntu)
```bash
sudo apt update
sudo apt install -y build-essential libpcap-dev libssl-dev
```

## 2) Compilar (desde la raíz del repositorio)
```bash
make clean
make debug
```

## 3) Generar binario stripped
```bash
make stripped
```

## 4) Ejecutar (ejemplos exactos)

# 4.1 Hash de archivo
```bash
./bin/pia_team5_debug hash src/main.cpp
```

# 4.2 Sniff (usar interfaz local en laboratorio, requiere sudo)
```bash
sudo ./bin/pia_team5_debug sniff lo
```

# 4.3 Enumerar procesos
```bash
./bin/pia_team5_debug processes
```

# 4.4 Ayuda
```bash
./bin/pia_team5_debug help
```

## 5) Ejemplos de salidas (pegue sus salidas reales aquí)

### Hash
```
SHA256(src/main.cpp) = <pegue_aqui>
```

### Sniff (ejemplo)
```
[*] Captured 1 packet on lo
	-> caplen: 74 bytes
	-> len: 74 bytes
	-> prefix (hex): 450000...
```

### Processes (ejemplo)
```
1 - systemd
2 - kthreadd
...
```

## 6) Generación de artefactos de análisis (ejecutar tras make debug)
```bash
strings bin/pia_team5_debug > analysis/strings.txt
nm -C bin/pia_team5_debug > analysis/functions.txt
objdump -d bin/pia_team5_debug > analysis/objdump.txt
```

## 7) Evidencias a agregar en /evidence
- evidence/run_hash.png — captura del resultado del comando `hash` y `pia_team5.log`
- evidence/run_sniff.png — captura de la ejecución `sniff` y/o captura pcap
- evidence/static_analysis.png — captura de Ghidra o Radare2 mostrando funciones/strings
- evidence/demo_video.mp4 — video demo 2–5 min (opcional)

Colocar los archivos anteriores en `/evidence` y referenciarlos en este documento.

# Tests y comandos

## Dependencias (Debian/Ubuntu)
sudo apt update
sudo apt install -y build-essential libpcap-dev libssl-dev

## Compilar
make debug

## Binaries generados
bin/pia_team5_debug
bin/pia_team5_stripped

## Comandos de ejecución

1) Hash de archivo
./bin/pia_team5_debug hash /etc/hosts
# Copiar salida aquí

2) Sniff (usar interfaz de laboratorio, e.g., lo)
sudo ./bin/pia_team5_debug sniff lo
# Copiar líneas capturadas aquí

3) Listar procesos
./bin/pia_team5_debug processes
# Copiar salida aquí

## Generar artefactos de análisis
strings bin/pia_team5_debug > analysis/strings.txt
nm -C bin/pia_team5_debug > analysis/functions.txt
objdump -d bin/pia_team5_debug > analysis/objdump.txt

## Evidencias (colocar archivos en /evidence)
- evidence/run_hash.png
- evidence/run_sniff.png
- evidence/static_analysis.png
- evidence/traffic.png
