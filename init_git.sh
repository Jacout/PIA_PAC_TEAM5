# Ir a la carpeta del proyecto (ajusta si hace falta)
cd /home/supercapish/Documents/PIA/PIA_PAC_TEAM5

# Inicializar repo y configurar usuario si es necesario
git init
git config user.name "Tu Nombre" || true
git config user.email "tu@correo" || true

# Añadir archivos y primer commit
git add .
git commit -m "PIA: segundo avance — Team 5"

# Añadir remote y subir (ajusta URL si es distinta)
git remote add origin https://github.com/Jacout/PIA_PAC_TEAM5.git
git branch -M main
git push -u origin main

# Crear y subir tag
git tag -a "PIA-segundo-avance-team5" -m "PIA: segundo avance — Team 5"
git push origin "PIA-segundo-avance-team5"
