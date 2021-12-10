#include <stdio.h>

// Estrutura de um pedido
struct Pedido {
    int produto;
    int quantidade;
    int localidade;
    int pesoDosProdutos;
};

// Estrutura do cliente
struct Cliente {
    struct Pedido pedidos[10];
    int quantPedidos;
    int pesoTotalPedido;
};

int main() {
    int const quantClient = 5;
    struct Cliente cliente[quantClient];

//    Facilitar em mostrar os dados
    char locais[2][19] = {{"Palmas - TO"}, {"Porto Nacional - TO"}};
    int pesos[3] = {20, 20, 5};
    char produtos[3][21] = {{"Argamassa AC3 20kg"}, {"Argamassa AC2 20kg"}, {"Rejunte 5kg"}};

    for (int clienteIndex = 0; clienteIndex <= quantClient; clienteIndex++) {
        printf("Bem vindo cliente %d\n", clienteIndex);
        printf("========== Vamos para as compras!! ==========\n");
        int keepBuying = 0;
        int pedidoIndex = 0;
        int tipoProduto, quantProduto, localProduto = 0;

        while ((keepBuying == 0) && (pedidoIndex <= 10)) {
            printf("O que você deseja levar? \n"
                   "1 - Argamassa AC3 20kg\n"
                   "2 - Argamassa AC2 20kg\n"
                   "3 - Rejunte 5kg\n"
                   "Opção: ");
            scanf("%d", &tipoProduto);
            cliente[clienteIndex].pedidos[pedidoIndex].produto = tipoProduto;

            printf("Quantos pacotes você deseja levar: ");
            scanf("%d", &quantProduto);
            cliente[clienteIndex].pedidos[pedidoIndex].quantidade = quantProduto;

            printf("O produto vai ser entregue em qual cidade?\n"
                   "1 - Palmas - TO\n"
                   "2 - Porto Nacional - TO\n"
                   "Opção: ");
            scanf("%d", &localProduto);
            cliente[clienteIndex].pedidos[pedidoIndex].localidade = localProduto;

            printf("Ótima compra! Deseja continuar comprando?\n"
                   "0 - sim\n"
                   "1 - não\n"
                   "Opção: ");
            scanf("%d", &keepBuying);
            cliente[clienteIndex].pedidos[pedidoIndex].pesoDosProdutos = cliente[clienteIndex].pedidos[pedidoIndex].quantidade * pesos[cliente[clienteIndex].pedidos[pedidoIndex].produto - 1];
            cliente[clienteIndex].pesoTotalPedido = cliente[clienteIndex].pedidos[pedidoIndex].pesoDosProdutos;
            pedidoIndex++;
        }
        cliente[clienteIndex].quantPedidos = pedidoIndex;
    }

    int continuar = 0 ;
    while ( continuar == 0 ) {
        int op;
        int clienteID, pedidoID, clienteTemp, pedidoTemp;
        printf("===== Menu =====\n");
        printf("1 - Relatório por pedido\n2 - Relatório por cliente\n3 - Relatório geral\nOpção: ");
        scanf("%d", &op);

        int somaPesoGeral = 0;

        switch (op) {
            case 1 :
                printf("Insira o número do cliente: ");
                scanf("%d", &clienteTemp);
                clienteID = clienteTemp - 1;

                printf("Você possue %d pedidos, Qual deseja ver o relatório: ", cliente[clienteID].quantPedidos);
                scanf("%d", &pedidoTemp);
                pedidoID = pedidoTemp - 1;

                int pesoTotalPedido =  cliente[clienteID].pedidos[pedidoID].pesoDosProdutos;

                printf("%d", cliente[clienteID].pedidos[pedidoID].quantidade);
                printf(" - %21s - ", produtos[cliente[clienteID].pedidos[pedidoID].produto - 1]);
                printf("%dkg\n",  pesoTotalPedido);
                printf("Destino - %19s\n", locais[cliente[clienteID].pedidos[pedidoID].localidade - 1]);

                if ( pesoTotalPedido < 1000) {
                    printf("Frete grátis\n");
                } else if ( pesoTotalPedido < 2000) {
                    if (cliente[clienteID].pedidos[pedidoID].localidade == 1) {
//                        Plamas
                        printf("Frete de 100R$\n");
                    } else {
//                        porto
                        printf("Frete de 200R$\n");
                    }
                } else {
                    printf("Frete de %dR$\n", cliente[clienteID].pedidos[pedidoID].quantidade * 2);
                }
                break;
            case 2:
                printf("Insira o número do cliente: ");
                scanf("%d", &clienteTemp);
                clienteID = clienteTemp - 1;

                printf("A média de pesos é %dkg - ", cliente[clienteID].pesoTotalPedido/cliente[clienteID].quantPedidos);
                printf("Você vez %d pedidos.", cliente[clienteID].quantPedidos);
                break;
            case 3:
                for (int clienteIndex = 0; clienteIndex <= quantClient; ++clienteIndex) {
                    printf("%d\n", cliente[clienteIndex].pesoTotalPedido);
                    somaPesoGeral += cliente[clienteIndex].pesoTotalPedido;
                }
                printf("Foram vendidos %dkg de produtos.\n", somaPesoGeral);
                // for (int clienteIndex = 0; clienteIndex < quantClient; ++clienteIndex) {
                //     for (int pedidoIndex = 0; pedidoIndex < cliente[clienteIndex].quantPedidos; pedidoIndex++) {
                //         if ( cliente[clienteIndex].pedidos[pedidoIndex].pesoDosProdutos < 1000) {
                //             cliente = clienteIndex + 1;
                //             pedido = pedidoIndex + 1;
                //             cliente[clienteIndex].pedidos[pedidoIndex].
                //         };
                //     }
                // }
                break;
        }
        printf("Deseja continuar?\n"
               "0 - Sim\n"
               "1 - Não\n"
               "Opçõa: ");
        scanf("%d", &continuar);
    };

    return 0;
};

