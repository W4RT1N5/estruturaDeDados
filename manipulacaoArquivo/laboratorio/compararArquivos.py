# Abra os arquivos
with open(r'C:\Users\lucas\git\estruturaDeDados\manipulacaoArquivo\laboratorio\texto_Vocabulo.txt', 'r') as arquivo1, open(r'C:\Users\lucas\git\estruturaDeDados\manipulacaoArquivo\laboratorio\texto_Vocabulo2.txt', 'r') as arquivo2:
    # Leia as linhas dos arquivos em listas
    linhas1 = arquivo1.readlines()
    linhas2 = arquivo2.readlines()

# Compare as listas de linhas
if linhas1 == linhas2:
    print("Os arquivos são iguais.")
else:
    print("Os arquivos são diferentes.")