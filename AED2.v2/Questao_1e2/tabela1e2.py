import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

# =========================================================
# 1. DADOS DAS EXECUÇÕES (Baseados na tua última saída)
# =========================================================

# Dados da Questão 1
q1_seq = [
    0.00060870, 0.00026843, 0.00061092, 0.00001953, 0.00033166, 
    0.00023502, 0.00061163, 0.00046804, 0.00034282, 0.00043260, 
    0.00008953, 0.00011252, 0.00000403, 0.00024275, 0.00035080, 
    0.00066374, 0.00061711, 0.00062934, 0.00062407, 0.00060135, 
    0.00059757, 0.00060045, 0.00060098, 0.00059867, 0.00059906, 
    0.00059737, 0.00061593, 0.00061084, 0.00060608, 0.00060170
]

q1_bin = [
    0.00000028, 0.00000048, 0.00000015, 0.00000165, 0.00000021, 
    0.00000034, 0.00000019, 0.00000019, 0.00000018, 0.00000015, 
    0.00000039, 0.00000048, 0.00000039, 0.00000046, 0.00000092, 
    0.00000009, 0.00000006, 0.00000006, 0.00000005, 0.00000005, 
    0.00000005, 0.00000005, 0.00000005, 0.00000005, 0.00000005, 
    0.00000005, 0.00000005, 0.00000005, 0.00000005, 0.00000005
]

# Dados da Questão 2
q2_vetor = [
    0.00024754, 0.00017216, 0.00014781, 0.00022541, 0.00019357, 
    0.00018378, 0.00016382, 0.00050614, 0.00036780, 0.00051155, 
    0.00002350, 0.00045408, 0.00032068, 0.00002921, 0.00039192, 
    0.00062429, 0.00063504, 0.00064113, 0.00064182, 0.00063575, 
    0.00063908, 0.00063299, 0.00063657, 0.00063914, 0.00063506, 
    0.00064116, 0.00063968, 0.00063583, 0.00063517, 0.00063766
]

q2_lista = [
    0.00106297, 0.00062944, 0.00039978, 0.00062655, 0.00049007, 
    0.00047045, 0.00041446, 0.00167330, 0.00108870, 0.00152822, 
    0.00007473, 0.00137580, 0.00095995, 0.00007102, 0.00106908, 
    0.00197068, 0.00197935, 0.00203346, 0.00193965, 0.00199030, 
    0.00193120, 0.00198117, 0.00195742, 0.00196592, 0.00204211, 
    0.00204704, 0.00197504, 0.00202031, 0.00192322, 0.00190769
]

# Nomes completos para as colunas
nomes_colunas = [
    "Rodada",
    "Busca Sequencial no Vetor (Questão 1)",
    "Busca Binária no Vetor (Questão 1)",
    "Busca Sequencial no Vetor (Questão 2)",
    "Busca Sequencial na Lista (Questão 2)"
]

# =========================================================
# 2. CRIAÇÃO E FORMATAÇÃO DAS TABELAS
# =========================================================

# Tabela detalhada das 30 rodadas
df_rodadas = pd.DataFrame({
    nomes_colunas[0]: range(1, 31),
    nomes_colunas[1]: q1_seq,
    nomes_colunas[2]: q1_bin,
    nomes_colunas[3]: q2_vetor,
    nomes_colunas[4]: q2_lista
})

# Tabela de Estatísticas (Média e Desvio Padrão)
df_stats = pd.DataFrame({
    'Algoritmo / Estrutura': nomes_colunas[1:],
    'Média (segundos)': [np.mean(q1_seq), np.mean(q1_bin), np.mean(q2_vetor), np.mean(q2_lista)],
    'Desvio Padrão (segundos)': [np.std(q1_seq, ddof=1), np.std(q1_bin, ddof=1), np.std(q2_vetor, ddof=1), np.std(q2_lista, ddof=1)]
})

# Formatação: Remover notação científica e fixar 8 casas decimais para as imagens
df_rodadas_fmt = df_rodadas.copy()
for col in nomes_colunas[1:]:
    df_rodadas_fmt[col] = df_rodadas_fmt[col].apply(lambda x: f"{x:.8f}")

df_stats_fmt = df_stats.copy()
df_stats_fmt['Média (segundos)'] = df_stats_fmt['Média (segundos)'].apply(lambda x: f"{x:.8f}")
df_stats_fmt['Desvio Padrão (segundos)'] = df_stats_fmt['Desvio Padrão (segundos)'].apply(lambda x: f"{x:.8f}")

# =========================================================
# 3. GERAÇÃO DE IMAGENS E ARQUIVOS CSV
# =========================================================

def exportar_tabela_imagem(df, nome_ficheiro, titulo, tam_fonte=10):
    # Ajuste dinâmico do tamanho da figura com base nos dados
    fig_width = 18 
    fig_height = len(df) * 0.5 + 2
    fig, ax = plt.subplots(figsize=(fig_width, fig_height))
    ax.axis('tight')
    ax.axis('off')
    
    tabela = ax.table(cellText=df.values, colLabels=df.columns, loc='center', cellLoc='center')
    tabela.auto_set_font_size(False)
    tabela.set_fontsize(tam_fonte)
    tabela.scale(1.2, 1.8) # Escala para melhor leitura
    
    plt.title(titulo, pad=30, fontweight='bold', fontsize=16)
    plt.savefig(nome_ficheiro, bbox_inches='tight', dpi=300)
    plt.close()

# Gerar as imagens finais sem simplificação (8 casas decimais)
exportar_tabela_imagem(df_rodadas_fmt, 'tabela_30_rodadas_final.png', 'Tempos de Execução (Questões 1 e 2)')
exportar_tabela_imagem(df_stats_fmt, 'tabela_estatisticas_final.png', 'Resumo Estatístico: Média e Desvio Padrão', tam_fonte=12)

# Guardar os dados brutos em CSV (útil para o Excel)
df_rodadas.to_csv('dados_rodadas.csv', index=False)
df_stats.to_csv('dados_estatisticas.csv', index=False)

print("Sucesso! Os ficheiros foram gerados:")
print("- tabela_30_rodadas_final.png")
print("- tabela_estatisticas_final.png")
print("- dados_rodadas.csv")
print("- dados_estatisticas.csv")