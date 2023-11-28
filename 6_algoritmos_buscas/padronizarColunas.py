import pandas as pd

# Substitua 'seu_arquivo.csv' pelo caminho do seu arquivo CSV
nome_arquivo = r"C:\Users\lucas\git\estruturaDeDados\6_algoritmos_buscas\listaMunicipios.csv"

# Carregar o arquivo CSV em um DataFrame pandas
df = pd.read_csv(nome_arquivo, header=None, names=["Município", "Código1", "Código2", "UF", "Descrição", "Região", "Valor", "Tamanho"])

# Remover espaços em branco à direita de cada valor nas células
df = df.applymap(lambda x: str(x).rstrip())

# Encontrar o comprimento máximo em cada coluna
column_lengths = df.applymap(lambda x: len(str(x))).max()

# Ajustar todas as strings para o comprimento máximo preenchendo com espaços em branco
df = df.apply(lambda x: x.astype(str).str.ljust(column_lengths[x.name]))

# Obter o comprimento máximo global entre todas as colunas
max_length = column_lengths.max()

# Preencher todas as células com espaços em branco para atingir o comprimento máximo
df = df.applymap(lambda x: str(x).ljust(max_length))

# Substitua 'arquivo_saida.csv' pelo caminho desejado para o novo arquivo CSV
arquivo_saida = r"C:\Users\lucas\git\estruturaDeDados\6_algoritmos_buscas\listaMunicipiosPadronizada.csv"

# Salvar o DataFrame resultante em um novo arquivo CSV
df.to_csv(arquivo_saida, index=False)

# Imprimir o DataFrame resultante
# print(df)

# Calcular e imprimir o tamanho em bytes das primeiras três linhas
# for i in range(3):
#     tamanho_bytes_linha = df.iloc[i].astype(str).map(lambda x: len(x.encode('utf-8'))).sum()
#     print(f"Tamanho em bytes da linha {i + 1}: {tamanho_bytes_linha} bytes")
