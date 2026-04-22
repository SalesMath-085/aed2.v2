import matplotlib.pyplot as plt
import pandas as pd
import numpy as np

# =========================================================
# 1. GRÁFICO DA QUESTÃO 5 (Já com seus dados certinhos!)
# =========================================================
tamanhos_busca = [100000, 200000, 300000, 400000, 500000, 600000, 700000, 800000, 900000, 1000000]

# Seus tempos reais do terminal
tempo_seq_vetor = [0.00021714, 0.00047291, 0.00067367, 0.00091720, 0.00133731, 0.00137618, 0.00193779, 0.00184906, 0.00205195, 0.00220610]
tempo_bin_vetor = [0.00000023, 0.00000051, 0.00000039, 0.00000029, 0.00000079, 0.00000112, 0.00000051, 0.00000061, 0.00000065, 0.00000046]
tempo_seq_lista = [0.00087181, 0.00078908, 0.00115799, 0.00183440, 0.00225767, 0.00500326, 0.00345812, 0.00377828, 0.00332360, 0.00525572]

plt.figure(figsize=(10, 6))
plt.plot(tamanhos_busca, tempo_seq_vetor, label='Busca Sequencial (Vetor)', marker='o', color='blue', linewidth=2)
plt.plot(tamanhos_busca, tempo_bin_vetor, label='Busca Binária (Vetor Ordenado)', marker='s', color='green', linewidth=2)
plt.plot(tamanhos_busca, tempo_seq_lista, label='Busca Sequencial (Lista)', marker='^', color='red', linewidth=2)

plt.title('Questão 5: Tempo de Execução x Tamanho da Estrutura', fontsize=14, fontweight='bold')
plt.xlabel('Tamanho da Estrutura', fontsize=12)
plt.ylabel('Tempo (Segundos)', fontsize=12)
plt.legend()
plt.grid(True, linestyle='--', alpha=0.7)
plt.ticklabel_format(style='plain', axis='x')
plt.show() # Mostra o gráfico da Q5


# =========================================================
# 2. TABELAS DAS QUESTÕES 1 E 2
# =========================================================
# ATENÇÃO: Substitua esses [0] pelos 30 tempos que o seu programa C 
# calculou nas questões 1 e 2! Separe os números por vírgula.

tempos_seq_vetor_q1 = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
tempos_bin_vetor_q1 = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
tempos_seq_lista_q2 = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]

# Montando a tabela das 30 rodadas
df_tempos = pd.DataFrame({
    'Rodada': range(1, 31),
    'Seq. Vetor (Q1)': tempos_seq_vetor_q1,
    'Binária Vetor (Q1)': tempos_bin_vetor_q1,
    'Seq. Lista (Q2)': tempos_seq_lista_q2
})

# Montando a tabela de Estatísticas (Média e Desvio Padrão)
# O Python já calcula a média e desvio padrão para você direto daqui!
df_estatisticas = pd.DataFrame({
    'Algoritmo': ['Busca Sequencial no Vetor (Q1)', 'Busca Binária no Vetor (Q1)', 'Busca Sequencial na Lista (Q2)'],
    'Média (s)': [np.mean(tempos_seq_vetor_q1), np.mean(tempos_bin_vetor_q1), np.mean(tempos_seq_lista_q2)],
    'Desvio Padrão (s)': [np.std(tempos_seq_vetor_q1), np.std(tempos_bin_vetor_q1), np.std(tempos_seq_lista_q2)]
})

# Exibindo as tabelas formatadas no Colab
print("\n" + "="*50)
print("TABELA 1: Tempos das 30 Execuções (Questões 1 e 2)")
print("="*50)
display(df_tempos)

print("\n" + "="*50)
print("TABELA 2: Média e Desvio Padrão (Questões 1 e 2)")
print("="*50)
display(df_estatisticas)