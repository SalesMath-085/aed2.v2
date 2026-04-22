import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

# Dados extraídos da tua saída em C
dados_q3 = {
    "Ordenação por Bolha (Bubble Sort)": [19.498990, 19.473273, 19.491078, 19.431497, 19.509383, 19.511955, 19.494988, 19.486636, 19.518133, 19.473328],
    "Ordenação por Inserção Direta (Insertion Sort)": [2.576209, 2.566996, 2.559414, 2.561989, 2.549986, 2.564167, 2.574613, 2.563384, 2.558883, 2.556928],
    "Ordenação por Seleção Direta (Selection Sort)": [4.007367, 4.002913, 4.003231, 4.002880, 4.002841, 4.001405, 4.005003, 4.002289, 4.001825, 4.002607],
    "Ordenação Quicksort": [0.009234, 0.009407, 0.009467, 0.009259, 0.009081, 0.009381, 0.009139, 0.009523, 0.009220, 0.009241],
    "Ordenação Merge Sort": [0.013821, 0.014019, 0.013779, 0.013721, 0.013756, 0.013675, 0.013835, 0.013547, 0.013823, 0.014026]
}

# Estatísticas informadas
stats_q3 = {
    "Algoritmo": [
        "Ordenação por Bolha (Bubble Sort)",
        "Ordenação por Inserção Direta (Insertion Sort)",
        "Ordenação por Seleção Direta (Selection Sort)",
        "Ordenação Quicksort",
        "Ordenação Merge Sort"
    ],
    "Média (s)": [19.488926, 2.563257, 4.003236, 0.009295, 0.013800],
    "Desvio Padrão (s)": [0.025246, 0.007911, 0.001739, 0.000143, 0.000145]
}

# Formatação e criação de tabelas
df_rodadas = pd.DataFrame(dados_q3)
df_rodadas.insert(0, 'Rodada', range(1, 11))
df_stats = pd.DataFrame(stats_q3)

# Aplicar 8 casas decimais
df_rodadas_fmt = df_rodadas.copy()
for col in df_rodadas_fmt.columns[1:]:
    df_rodadas_fmt[col] = df_rodadas_fmt[col].apply(lambda x: f"{x:.8f}")

df_stats_fmt = df_stats.copy()
df_stats_fmt['Média (s)'] = df_stats_fmt['Média (s)'].apply(lambda x: f"{x:.8f}")
df_stats_fmt['Desvio Padrão (s)'] = df_stats_fmt['Desvio Padrão (s)'].apply(lambda x: f"{x:.8f}")

def save_table_img(df, filename, title, figsize=(18, 8)):
    fig, ax = plt.subplots(figsize=figsize)
    ax.axis('tight')
    ax.axis('off')
    table = ax.table(cellText=df.values, colLabels=df.columns, loc='center', cellLoc='center')
    table.auto_set_font_size(False)
    table.set_fontsize(10)
    table.scale(1.1, 2)
    plt.title(title, pad=30, fontweight='bold', fontsize=14)
    plt.savefig(filename, bbox_inches='tight', dpi=300)
    plt.close()

# Gerar imagens
save_table_img(df_rodadas_fmt, 'tabela_q3_execucoes.png', 'Questão 3: Tempos de Execução (10 Rodadas)')
save_table_img(df_stats_fmt, 'tabela_q3_estatisticas.png', 'Questão 3: Estatísticas de Ordenação', figsize=(14, 4))