# Reversing notes

Comandos sugeridos:
- strings bin/pia_team5_debug > analysis/strings.txt
- nm -C bin/pia_team5_debug > analysis/functions.txt
- objdump -d bin/pia_team5_debug > analysis/objdump.txt

Puntos a revisar:
- Llamadas a pcap_open_live / pcap_loop
- Uso de OpenSSL SHA256
- Lectura de /proc/*/comm
- Flujo del CLI en main

Checklist:
1. Identificar cadenas relevantes.
2. Mapear llamadas externas.
3. Anotar funciones de interés.
