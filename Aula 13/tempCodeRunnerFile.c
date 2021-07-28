int main(){
    FILE *entrada;
    Estrutura Teste;
    Teste.nome[20] = "teste";

    FILE *saida;
    saida = fopen("arquivotextosaida", "a+b");

    fseek(saida, 0, SEEK_SET);
    fwrite(&Teste, sizeof(Estrutura), 1, saida); 

    Estrutura p;
    fseek(saida, 0, SEEK_SET);
    fread(&p, sizeof(Estrutura), 1, saida);

    printf("%ss", p.nome);
}