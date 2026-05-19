#!/bin/bash

cd /home/supercapish/Documents/PIA/PIA_PAC_TEAM5

echo "=== Instalando dependencias ==="
sudo apt update
sudo apt install -y build-essential libpcap-dev libssl-dev

echo "=== Compilando (debug y stripped) ==="
make clean
make debug
make stripped

echo "=== Prueba 1: Hash de archivo ==="
./bin/pia_team5_debug hash /etc/hostname

echo "=== Prueba 2: Listar procesos ==="
./bin/pia_team5_debug processes | head -20

echo "=== Prueba 3: Sniff en loopback (10 paquetes) ==="
sudo ./bin/pia_team5_debug sniff lo

echo "=== Prueba 4: Help ==="
./bin/pia_team5_debug help

echo "=== Generando artefactos de análisis ==="
strings bin/pia_team5_debug > analysis/strings.txt
nm -C bin/pia_team5_debug > analysis/functions.txt
objdump -d bin/pia_team5_debug > analysis/objdump.txt

echo "=== Artefactos generados ==="
ls -lh analysis/

echo "=== Log de ejecución ==="
cat pia_team5.log

echo "=== Tests completados ==="
