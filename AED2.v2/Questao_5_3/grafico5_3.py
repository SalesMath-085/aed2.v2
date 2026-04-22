import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

# Dados extraídos da tua execução
tamanhos = [10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000, 90000, 100000]
bubble = [0.123099, 0.630250, 1.568140, 2.906739, 4.645915, 6.781767, 9.326891, 12.304131, 15.670924, 19.413041]
insertion = [0.028774, 0.106415, 0.237979, 0.423567, 0.659488, 0.949106, 1.318571, 1.695391, 2.128089, 2.671351]
selection = [0.040421, 0.160840, 0.361563, 0.642080, 1.001338, 1.442898, 1.960325, 2.559196, 3.236824, 3.998817]
quick = [0.000785, 0.001616, 0.002611, 0.003474, 0.004378, 0.005351, 0.006225, 0.007334, 0.008127, 0.009231]
merge = [0.001169, 0.002454, 0.003752, 0.005050, 0.006351, 0.007777, 0.009146, 0.010472, 0.012023, 0.013339]

# Criação da tabela
df_q5_sort = pd.DataFrame({
    'Tamanho': tamanhos,
    'Bubble Sort (s)': bubble,
    'Insertion Sort (s)': insertion,
    'Selection Sort (s)': selection,
    'Quick Sort (s)': quick,
    'Merge Sort (s)': merge
})

# Formatação para 8 casas decimais
df_fmt = df_q5_sort.copy()
for col in df_fmt.columns[1:]:
    df_fmt[col] = df_fmt[col].apply(lambda x: f"{x:.8f}")

# (Código de plotagem igual ao usado acima para as imagens)