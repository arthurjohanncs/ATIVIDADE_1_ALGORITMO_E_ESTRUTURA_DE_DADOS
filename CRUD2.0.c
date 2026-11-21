#include <stdio.h>
#include <locale.h>

int main() {
    // Discentes: Arthur Johann Costa Silva e Albert Nonato Costa Albuquerque
    setlocale(LC_ALL, ".UTF-8");

    int notas[100];
    // Variaveis de controle
    int quantidade = 0;
    int opcao = 0;
    int nota;
    int posicao;
    int i;
    int soma;
    int maior;
    int menor;
    float media;
    int aprovados;
    int recuperacao;
    int reprovados;
    int nota_busca;
    int encontrados;

    // MENU
    while (opcao != 8) {
        printf("\n===== GESTÃO DE NOTAS DA DISCIPLINA =====\n");
        printf("1. Inserir nota (0 a 10)\n");
        printf("2. Listar notas\n");
        printf("3. Atualizar nota\n");
        printf("4. Deletar nota\n");
        printf("5. Ver resumo da turma (média, maior e menor)\n");
        printf("6. Situação da turma (aprovados, recuperação e reprovados)\n");
        printf("7. Buscar ocorrências de uma nota específica\n");
        printf("8. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        // CREATE
        if (opcao == 1) {
            if (quantidade < 100) {
                printf("Digite a nota (0 a 10): ");
                scanf("%d", &nota);

                if (nota >= 0 && nota <= 10) {
                    notas[quantidade] = nota;
                    quantidade++;
                    printf("Nota inserida com sucesso!\n");
                } else {
                    printf("Nota inválida! Digite um valor entre 0 e 10.\n");
                }
            } else {
                printf("Limite de 100 notas atingido!\n");
            }
        }

        // READ
        else if (opcao == 2) {
            if (quantidade == 0) {
                printf("Nenhuma nota cadastrada.\n");
            } else {
                printf("\nNotas cadastradas (%d de 100):\n", quantidade);
                for (i = 0; i < quantidade; i++) {
                    printf("Avaliação do aluno %d (índice %d): %d\n", i + 1, i, notas[i]);
                }
            }
        }

        // UPDATE
        else if (opcao == 3) {
            if (quantidade == 0) {
                printf("Nenhuma nota para atualizar.\n");
            } else {
                printf("Digite o índice da nota (0 ate %d): ", quantidade - 1);
                scanf("%d", &posicao);

                if (posicao >= 0 && posicao < quantidade) {
                    printf("Digite a nova nota (0 a 10): ");
                    scanf("%d", &nota);

                    if (nota >= 0 && nota <= 10) {
                        notas[posicao] = nota;
                        printf("Nota atualizada com sucesso!\n");
                    } else {
                        printf("Nota inválida! Digite um valor entre 0 e 10.\n");
                    }
                } else {
                    printf("Índice inválido!\n");
                }
            }
        }

        // DELETE
        else if (opcao == 4) {
            if (quantidade == 0) {
                printf("Nenhuma nota para deletar.\n");
            } else {
                printf("Digite o índice da nota (0 ate %d): ", quantidade - 1);
                scanf("%d", &posicao);

                if (posicao >= 0 && posicao < quantidade) {
                    for (i = posicao; i < quantidade - 1; i++) {
                        notas[i] = notas[i + 1];
                    }
                    quantidade--;
                    printf("Nota deletada com sucesso!\n");
                } else {
                    printf("Índice inválido!\n");
                }
            }
        }

        // MÉDIA DA TURMA
        else if (opcao == 5) {
            if (quantidade == 0) {
                printf("Nenhuma nota cadastrada para calcular estatísticas.\n");
            } else {
                soma = 0;
                maior = notas[0];
                menor = notas[0];

                for (i = 0; i < quantidade; i++) {
                    soma += notas[i];
                    if (notas[i] > maior) {
                        maior = notas[i];
                    }
                    if (notas[i] < menor) {
                        menor = notas[i];
                    }
                }

                media = (float)soma / quantidade;

                printf("\n--- Média da Turma ---\n");
                printf("Total de notas: %d\n", quantidade);
                printf("Média da turma: %.2f\n", media);
                printf("Maior nota: %d\n", maior);
                printf("Menor nota: %d\n", menor);
            }
        }

        // SITUAÇÃO DA TURMA
        else if (opcao == 6) {
            if (quantidade == 0) {
                printf("Nenhuma nota cadastrada para verificar situação.\n");
            } else {
                aprovados = 0;
                recuperacao = 0;
                reprovados = 0;

                for (i = 0; i < quantidade; i++) {
                    if (notas[i] >= 7) {
                        aprovados++;
                    } else if (notas[i] >= 4) {
                        recuperacao++;
                    } else {
                        reprovados++;
                    }
                }

                printf("\n--- Situação da Turma ---\n");
                printf("Aprovados (nota >= 7): %d\n", aprovados);
                printf("Em recuperação (nota entre 4 e 6): %d\n", recuperacao);
                printf("Reprovados (nota < 4): %d\n", reprovados);
            }
        }

        // BUSCAR NOTA ESPECÍFICA
        else if (opcao == 7) {
            if (quantidade == 0) {
                printf("Nenhuma nota cadastrada para buscar.\n");
            } else {
                printf("Digite a nota que deseja buscar (0 a 10): ");
                scanf("%d", &nota_busca);

                if (nota_busca >= 0 && nota_busca <= 10) {
                    encontrados = 0;
                    printf("\n--- Resultados para a nota %d ---\n", nota_busca);

                    for (i = 0; i < quantidade; i++) {
                        if (notas[i] == nota_busca) {
                            printf("Avaliação do aluno %d (índice %d)\n", i + 1, i);
                            encontrados++;
                        }
                    }

                    if (encontrados == 0) {
                        printf("Nenhuma avaliação com nota %d foi encontrada.\n", nota_busca);
                    } else {
                        printf("Total de ocorrências: %d\n", encontrados);
                    }
                } else {
                    printf("Nota inválida! Digite um valor entre 0 e 10.\n");
                }
            }
        }

        // SAIR
        else if (opcao == 8) {
            printf("Encerrando o sistema de notas...\n");
        } else {
            printf("Opção inválida! Escolha de 1 a 8.\n");
        }
    }

    return 0;
}