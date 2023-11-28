from unidecode import unidecode

def remove_acentos(input_file, output_file):
    with open(input_file, 'r', encoding='utf-8') as f_in:
        with open(output_file, 'w+', encoding='utf-8') as f_out:
            for line in f_in:
                line_sem_acentos = unidecode(line)
                f_out.write(line_sem_acentos)

    # print(f"Processamento concluído. Arquivo de saída: {output_file}")

if __name__ == "__main__":
    input_file = r"C:\Users\lucas\git\estruturaDeDados\6_algoritmos_buscas\listaMunicipiosPadronizada.csv"
    output_file = r"C:\Users\lucas\git\estruturaDeDados\6_algoritmos_buscas\semAcentos.csv"
    remove_acentos(input_file, output_file)
