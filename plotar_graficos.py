import json
import matplotlib.pyplot as plt
import matplotlib.patches as patches

try:
    with open('pontos_brutos.json', 'r') as f:
        pontos_brutos = json.load(f)
    with open('mapa_final.json', 'r') as f:
        mapa_final = json.load(f)
except FileNotFoundError:
    print("Erro: Execute o programa em C++ primeiro para gerar os arquivos JSON.")
    exit()

x_bruto = [p['x'] for p in pontos_brutos]
y_bruto = [p['y'] for p in pontos_brutos]

x_final = [b['x'] for b in mapa_final]
y_final = [b['y'] for b in mapa_final]

plt.style.use('seaborn-v0_8-whitegrid')

# GRÁFICO 1: DADOS BRUTOS (TODAS AS COORDENADAS)
plt.figure(figsize=(8, 8))
plt.scatter(x_bruto, y_bruto, color='#e74c3c', alpha=0.7, s=50, label='Sinais do Drone')
plt.title('Gráfico 1: Todas as Coordenadas Recebidas (Dados Brutos)', fontsize=14, fontweight='bold', pad=15)
plt.xlabel('Eixo X (metros)', fontsize=12)
plt.ylabel('Eixo Y (metros)', fontsize=12)
plt.xlim(-0.5, 8.5)
plt.ylim(-0.5, 8.5)
plt.gca().set_aspect('equal', adjustable='box')
plt.legend(loc='upper right')
plt.savefig('grafico_1_pontos_brutos.png', dpi=300, bbox_inches='tight')
plt.show()

# GRÁFICO 2: MAPA FINAL PROCESSADO (COORDENADAS VÁLIDAS)
fig, ax = plt.subplots(figsize=(8, 8))
ax.scatter(x_final, y_final, color='#2c3e50', marker='X', s=120, zorder=3, label='Centros das Bases')

for b in mapa_final:
    retangulo_base = patches.Rectangle(
        (b['x'] - 0.5, b['y'] - 0.5), 1.0, 1.0, 
        linewidth=2, edgecolor='#3498db', facecolor='#d6eaf8', alpha=0.6, zorder=2
    )
    ax.add_patch(retangulo_base)

ax.set_title('Gráfico 2: Coordenadas Finais Processadas (Mapa de Bases)', fontsize=14, fontweight='bold', pad=15)
ax.set_xlabel('Eixo X (metros)', fontsize=12)
ax.set_ylabel('Eixo Y (metros)', fontsize=12)
ax.set_xlim(-0.5, 8.5)
ax.set_ylim(-0.5, 8.5)
ax.set_aspect('equal', adjustable='box')
ax.legend(loc='upper right')
plt.savefig('grafico_2_mapa_final.png', dpi=300, bbox_inches='tight')
plt.show()
