import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

# Tamanhos definidos no enunciado para a Questão 5 (Buscas)
tamanhos = [100000, 200000, 300000, 400000, 500000, 600000, 700000, 800000, 900000, 1000000]

# Dados da nova saída fornecida
seq_vetor = [0.00019851, 0.00011970, 0.00018361, 0.00024204, 0.00030095, 0.00036078, 0.00042055, 0.00048285, 0.00055553, 0.00060295]
bin_vetor = [0.00000017, 0.00000015, 0.00000028, 0.00000012, 0.00000011, 0.00000011, 0.00000022, 0.00000015, 0.00000020, 0.00000017]
seq_lista = [0.00024604, 0.00042318, 0.00071586, 0.00092615, 0.00129330, 0.00142629, 0.00168669, 0.00229130, 0.00214753, 0.00237170]

# 1. Criar Tabela Formatada
df_q5 = pd.DataFrame({
    'Tamanho da Estrutura': tamanhos,
    'Busca Sequencial no Vetor (s)': seq_vetor,
    'Busca Binária no Vetor Ordenado (s)': bin_vetor,
    'Busca Sequencial na Lista Encadeada (s)': seq_lista
})

# Formatação para 8 casas decimais
df_fmt = df_q5.copy()
for col in df_fmt.columns[1:]:
    df_fmt[col] = df_fmt[col].apply(lambda x: f"{x:.8f}")

def save_table_img(df, filename, title):
    fig, ax = plt.subplots(figsize=(14, 8))
    ax.axis('tight')
    ax.axis('off')
    table = ax.table(cellText=df.values, colLabels=df.columns, loc='center', cellLoc='center')
    table.auto_set_font_size(False)
    table.set_fontsize(10)
    table.scale(1.1, 2)
    plt.title(title, pad=30, fontweight='bold', fontsize=14)
    plt.savefig(filename, bbox_inches='tight', dpi=300)
    plt.close()

save_table_img(df_fmt, 'tabela_q5_buscas_final.png', 'Questão 5: Tempo de Execução das Buscas por Tamanho')

# 2. Criar Gráfico de Linhas (Obrigatório pela Q5)
plt.figure(figsize=(12, 7))
plt.plot(tamanhos, seq_vetor, label='Busca Sequencial (Vetor)', marker='o', linewidth=2)
plt.plot(tamanhos, bin_vetor, label='Busca Binária (Vetor Ordenado)', marker='s', linewidth=2)
plt.plot(tamanhos, seq_lista, label='Busca Sequencial (Lista)', marker='^', linewidth=2)

plt.title('Questão 5: Desempenho das Buscas (Tempo vs Tamanho)', fontsize=14, fontweight='bold')
plt.xlabel('Tamanho da Estrutura', fontsize=12)
plt.ylabel('Tempo (Segundos)', fontsize=12)
plt.legend()
plt.grid(True, linestyle='--', alpha=0.7)
plt.ticklabel_format(style='plain', axis='x')
plt.savefig('grafico_q5_buscas_final.png', bbox_inches='tight', dpi=300)
plt.close()