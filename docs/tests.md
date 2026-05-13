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
