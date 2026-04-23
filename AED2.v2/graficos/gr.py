import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

# Configuração de estilo global
pd.options.display.float_format = '{:.8f}'.format

# =========================================================
# DADOS (Mantendo a fidelidade total aos teus números)
# =========================================================
q1_seq = [0.00060870, 0.00026843, 0.00061092, 0.00001953, 0.00033166, 0.00023502, 0.00061163, 0.00046804, 0.00034282, 0.00043260, 0.00008953, 0.00011252, 0.00000403, 0.00024275, 0.00035080, 0.00066374, 0.00061711, 0.00062934, 0.00062407, 0.00060135, 0.00059757, 0.00060045, 0.00060098, 0.00059867, 0.00059906, 0.00059737, 0.00061593, 0.00061084, 0.00060608, 0.00060170]
q1_bin = [0.00000028, 0.00000048, 0.00000015, 0.00000165, 0.00000021, 0.00000034, 0.00000019, 0.00000019, 0.00000018, 0.00000015, 0.00000039, 0.00000048, 0.00000039, 0.00000046, 0.00000092, 0.00000009, 0.00000006, 0.00000006, 0.00000005, 0.00000005, 0.00000005, 0.00000005, 0.00000005, 0.00000005, 0.00000005, 0.00000005, 0.00000005, 0.00000005, 0.00000005, 0.00000005]
q2_vet = [0.00024754, 0.00017216, 0.00014781, 0.00022541, 0.00019357, 0.00018378, 0.00016382, 0.00050614, 0.00036780, 0.00051155, 0.00002350, 0.00045408, 0.00032068, 0.00002921, 0.00039192, 0.00062429, 0.00063504, 0.00064113, 0.00064182, 0.00063575, 0.00063908, 0.00063299, 0.00063657, 0.00063914, 0.00063506, 0.00064116, 0.00063968, 0.00063583, 0.00063517, 0.00063766]
q2_lis = [0.00106297, 0.00062944, 0.00039978, 0.00062655, 0.00049007, 0.00047045, 0.00041446, 0.00167330, 0.00108870, 0.00152822, 0.00007473, 0.00137580, 0.00095995, 0.00007102, 0.00106908, 0.00197068, 0.00197935, 0.00203346, 0.00193965, 0.00199030, 0.00193120, 0.00198117, 0.00195742, 0.00196592, 0.00204211, 0.00204704, 0.00197504, 0.00202031, 0.00192322, 0.00190769]
q3_bub = [19.498990, 19.473273, 19.491078, 19.431497, 19.509383, 19.511955, 19.494988, 19.486636, 19.518133, 19.473328]
q3_ins = [2.576209, 2.566996, 2.559414, 2.561989, 2.549986, 2.564167, 2.574613, 2.563384, 2.558883, 2.556928]
q3_sel = [4.007367, 4.002913, 4.003231, 4.002880, 4.002841, 4.001405, 4.005003, 4.002289, 4.001825, 4.002607]
q3_qui = [0.009234, 0.009407, 0.009467, 0.009259, 0.009081, 0.009381, 0.009139, 0.009523, 0.009220, 0.009241]
q3_mer = [0.013821, 0.014019, 0.013779, 0.013721, 0.013756, 0.013675, 0.013835, 0.013547, 0.013823, 0.014026]

tam_busca = [100000, 200000, 300000, 400000, 500000, 600000, 700000, 800000, 900000, 1000000]
q5_b_seq_v = [0.00019851, 0.00011970, 0.00018361, 0.00024204, 0.00030095, 0.00036078, 0.00042055, 0.00048285, 0.00055553, 0.00060295]
q5_b_bin_v = [0.00000017, 0.00000015, 0.00000028, 0.00000012, 0.00000011, 0.00000011, 0.00000022, 0.00000015, 0.00000020, 0.00000017]
q5_b_seq_l = [0.00024604, 0.00042318, 0.00071586, 0.00092615, 0.00129330, 0.00142629, 0.00168669, 0.00229130, 0.00214753, 0.00237170]

tam_ord = [10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000, 90000, 100000]
q5_o_bub = [0.123099, 0.630250, 1.568140, 2.906739, 4.645915, 6.781767, 9.326891, 12.304131, 15.670924, 19.413041]
q5_o_ins = [0.028774, 0.106415, 0.237979, 0.423567, 0.659488, 0.949106, 1.318571, 1.695391, 2.128089, 2.671351]
q5_o_sel = [0.040421, 0.160840, 0.361563, 0.642080, 1.001338, 1.442898, 1.960325, 2.559196, 3.236824, 3.998817]
q5_o_qui = [0.000785, 0.001616, 0.002611, 0.003474, 0.004378, 0.005351, 0.006225, 0.007334, 0.008127, 0.009231]
q5_o_mer = [0.001169, 0.002454, 0.003752, 0.005050, 0.006351, 0.007777, 0.009146, 0.010472, 0.012023, 0.013339]

# =========================================================
# FUNÇÃO DE GERAÇÃO MELHORADA
# =========================================================
def salvar_tabela_bonita(df, nome_arquivo, titulo):
    # Formatação de números
    df_fmt = df.copy()
    for col in df_fmt.columns:
        if df_fmt[col].dtype == 'float64':
            df_fmt[col] = df_fmt[col].apply(lambda x: f"{x:.8f}")

    # Ajuste de tamanho dinâmico (mais altura para tabelas longas)
    num_rows = len(df)
    fig_height = max(4, num_rows * 0.45 + 1.5)
    fig, ax = plt.subplots(figsize=(12, fig_height))
    
    ax.axis('tight')
    ax.axis('off')
    
    # Criar tabela
    table = ax.table(
        cellText=df_fmt.values,
        colLabels=df_fmt.columns,
        cellLoc='center',
        loc='center'
    )
    
    # Estilização
    table.auto_set_font_size(False)
    table.set_fontsize(11)
    table.scale(1.1, 2.2) # Espaçamento maior entre linhas para legibilidade
    
    # Cabeçalho em negrito e cor diferente
    for (row, col), cell in table.get_celld().items():
        if row == 0:
            cell.set_text_props(weight='bold', color='white')
            cell.set_facecolor('#2c3e50')
        elif row % 2 == 0:
            cell.set_facecolor('#f2f2f2') # Zebra stripes

    # Título com pad maior para não sobrepor
    plt.title(titulo, pad=50, fontweight='bold', fontsize=15, color='#2c3e50')
    
    plt.savefig(nome_arquivo, bbox_inches='tight', dpi=300)
    plt.close()

# --- 1. TABELAS DE RODADAS ---
salvar_tabela_bonita(pd.DataFrame({'Rodada': range(1,31), 'Seq. Vetor (s)': q1_seq, 'Bin. Vetor (s)': q1_bin}), 'Tabela_Q1_Rodadas_v2.png', 'Questão 1: Tempos de Execução (30 Rodadas)')
salvar_tabela_bonita(pd.DataFrame({'Rodada': range(1,31), 'Seq. Vetor (s)': q2_vet, 'Seq. Lista (s)': q2_lis}), 'Tabela_Q2_Rodadas_v2.png', 'Questão 2: Tempos de Execução (30 Rodadas)')
salvar_tabela_bonita(pd.DataFrame({'Rodada': range(1,11), 'Bubble': q3_bub, 'Insertion': q3_ins, 'Selection': q3_sel, 'Quick': q3_qui, 'Merge': q3_mer}), 'Tabela_Q3_Rodadas_v2.png', 'Questão 3: Tempos de Ordenação (10 Rodadas)')

# --- 2. TABELAS DE ESTATÍSTICAS ---
def get_stats_df(nomes, listas):
    return pd.DataFrame({
        'Algoritmo': nomes,
        'Média (s)': [np.mean(l) for l in listas],
        'Desvio Padrão (s)': [np.std(l, ddof=1) for l in listas]
    })

salvar_tabela_bonita(get_stats_df(['Busca Seq. Vetor', 'Busca Bin. Vetor'], [q1_seq, q1_bin]), 'Tabela_Q1_Estatisticas_v2.png', 'Questão 1: Resumo Estatístico')
salvar_tabela_bonita(get_stats_df(['Busca Seq. Vetor', 'Busca Seq. Lista'], [q2_vet, q2_lis]), 'Tabela_Q2_Estatisticas_v2.png', 'Questão 2: Resumo Estatístico')
salvar_tabela_bonita(get_stats_df(['Bubble', 'Insertion', 'Selection', 'Quick', 'Merge'], [q3_bub, q3_ins, q3_sel, q3_qui, q3_mer]), 'Tabela_Q3_Estatisticas_v2.png', 'Questão 3: Resumo Estatístico')

# --- 3. GRÁFICOS Q5 (REGERADOS PARA GARANTIR SEPARAÇÃO) ---
plt.figure(figsize=(10,6))
plt.plot(tam_busca, q5_b_seq_v, label='Seq. Vetor', marker='o', linewidth=2)
plt.plot(tam_busca, q5_b_bin_v, label='Bin. Vetor', marker='s', linewidth=2)
plt.plot(tam_busca, q5_b_seq_l, label='Seq. Lista', marker='^', linewidth=2)
plt.title('Questão 5: Desempenho de Buscas (100k a 1M)', fontweight='bold', pad=20)
plt.xlabel('Tamanho da Estrutura'); plt.ylabel('Tempo (s)'); plt.legend(); plt.grid(True, alpha=0.3)
plt.savefig('Grafico_Q5_Buscas_v2.png', bbox_inches='tight', dpi=300); plt.close()

plt.figure(figsize=(10,6))
plt.plot(tam_ord, q5_o_bub, label='Bubble', marker='o', linewidth=2)
plt.plot(tam_ord, q5_o_ins, label='Insertion', marker='s', linewidth=2)
plt.plot(tam_ord, q5_o_sel, label='Selection', marker='^', linewidth=2)
plt.plot(tam_ord, q5_o_qui, label='Quick', marker='x', linewidth=2)
plt.plot(tam_ord, q5_o_mer, label='Merge', marker='d', linewidth=2)
plt.title('Questão 5: Desempenho de Ordenação (10k a 100k)', fontweight='bold', pad=20)
plt.xlabel('Tamanho do Vetor'); plt.ylabel('Tempo (s)'); plt.legend(); plt.grid(True, alpha=0.3)
plt.savefig('Grafico_Q5_Ordenacao_v2.png', bbox_inches='tight', dpi=300); plt.close()