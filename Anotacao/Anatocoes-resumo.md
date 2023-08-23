# Estrutura de dados em C

[Material fonte.](http://each.usp.br/digiampietri/ed/ "Material fonte.")

Usando a linguagem C pois, a linguagem C não é orientada a objetos, é uma linguagem imperativa e estruturada.
Ou seja, ela permite de maneira mais explicita a alocação e desalocação de memória, gerenciamento de ponteiros e estruturas.

- Necessário ter instalado o [GCC](https://gcc.gnu.org/)
- Necessário um editor de código (vscode, sublime, notepad++)
- Recomendado não usar uma IDE. Pois irá diminui a quantidade de interferência que uma IDE causa.

Diferença entre um código Java e um C

Java 
```java
class HelloWorld {
    public static void main(String[] args) {
		System.out.println("Hello World!");
    }
}
```

Compilar e executar: 
`$ javac HelloWorld.Java`
`$ java HelloWorld`

Saída esperada:
`$ Hello World!`

C
```c
#include <stdio.h>
int main() {
	printf("Hello World!\n");
	return 0;
}
```

Compilar e executar: 

`$ gcc HelloWorld.c -o HelloWorld`

`$ ./HelloWorld`

Saída esperada:

`$ Hello World!`

## Criando uma estrutura simples

Uma estrutura de dados é uma maneira de organizar um conjunto de dados.

Queremos criar uma estrutura para guardar algumas informações.

Ao criar a primeira estrutura surgem algumas dúvidas, como: 
- Como modelamos essa estrutura?
- Como instanciamos essa estrutura?
- Como acessamos seus campos?

Em Java e outras linguagens orientadas a objetos criamos uma classe com atributos e depois instanciamos.
Depois fazemos outra classe para estarmos utilizando esse classe.

Em C temos uma sintaxe própria para definir estruturas. A sintaxe `struct { ... }` define uma estrutura com os campos definidos dentro das chaves. a sintaxe `typedef ... NameStruct` define o nome para a estrutura que foi criada.

Ex.: 
```c
typedef struct { 
	int var1; 
	int var2; 
} VarStruct;
```

Podemos definir um variável para declarar um tipo simples. 

Ex.: 
```c
typedef int CHAVE
```
Poderemos utilizar no código a palavra CHAVE para representar o tipo int.

#### Uso de memória em Java:

O Java é uma linguagem de programação que utiliza um sistema de gerenciamento de memória bastante eficiente e automatizado, conhecido como "*Garbage Collection*" (Coleta de Lixo).

Em Java temos algumas divisões no processo de gerenciamento de memória.
- *Heap Memory* (Memória Heap): É a região onde os objetos Java são alocados dinamicamente durante a execução do programa. O *heap* é dividido em duas áreas principais: a área *Young* e a área *Old*. A área *Young* é onde os objetos recém-criados são alocados. Com o tempo, alguns objetos sobrevivem e são movidos para a área *Old*.
- *Garbage Collection*: O Java utiliza um processo de coleta de lixo para identificar e liberar automaticamente a memória ocupada por objetos que não são mais referenciados pelo programa. Isso evita vazamentos de memória, onde a memória é ocupada por objetos inacessíveis.
- *Memória Stack*: A memória da pilha é onde as variáveis locais e referências a objetos são armazenadas. Métodos em execução e seus respectivos parâmetros também residem na pilha. A memória da pilha é organizada em frames, que são empilhados à medida que os métodos são chamados e desempilhados quando os métodos retornam.
- *Permanent Generation* (ou Metaspace no Java 8 em diante): Nesta região, o Java armazena informações internas da classe, como constantes e estruturas de dados relacionadas a classes. O tamanho desta região é fixo, mas pode variar de acordo com a aplicação.
- *Métodos e Variáveis Estáticas*: Eles são armazenados em uma área separada da memória e não são associados a instâncias específicas de classes.

O processo de alocação e liberação de memória no Java é em grande parte automatizado pelo compilador.

No exemplo de código em Java, a alocação de memória ocorre da seguinte maneira durante a execução:
- As classes PesoAltura e EstruturaSimples são carregadas na memória. Isso inclui qualquer variável de classe, estruturas e métodos estáticos definidos nas classes.
- Dentro do método main, uma instância da classe PesoAltura chamada pessoa1 é criada usando o operador new. Isso alocará memória no heap para armazenar os dados da instância.
- Atributos da instância pessoa1 (peso e altura) são preenchidos com os valores 80 e 185, respectivamente.
- A impressão dos valores de peso e altura é realizada usando System.out.print.
- A comparação if verifica se a altura da pessoa está acima da altura máxima definida na classe EstruturaSimples.
- Quando o programa termina, a memória alocada para a instância pessoa1 será liberada automaticamente pelo sistema de gerenciamento de memória Java, no processo de Garbage Collection.
- A memória alocada para variáveis locais (como os atributos da classe PesoAltura) reside na pilha, enquanto a memória alocada para objetos (instâncias de classes) reside no heap. O Java cuida da alocação e liberação de memória para objetos, garantindo que objetos não referenciados sejam coletados pelo processo de Garbage Collection para evitar vazamentos de memória.

Em C, o uso de memória é mais manual e direto em comparação com linguagens de programação de alto nível, como Java.
Quando você declara uma variável em C, a memória necessária para essa variável é alocada. As variáveis locais são geralmente alocadas uma área específica da memória conhecida como *pilha de execução*, enquanto as variáveis globais são armazenadas em uma área de memória separada.

No exemplo em C a alocação de memória ocorre da seguinte maneira durante a execução:
- A memória para a estrutura PesoAltura pessoa1 é alocada na pilha.
- As variáveis peso e altura dentro da estrutura são preenchidas com os valores 80 e 185.
- Os valores são impressos usando printf.
- Não há alocação dinâmica de memória no heap neste exemplo.
- Assim que a função main é concluída, a memória alocada para pessoa1 é automaticamente liberada, já que está na pilha. A constante alturaMaxima é substituída diretamente pelo pré-processador e não ocupa espaço de memória em si.

O uso de memória é diferente entre Java e C principalmente devido às suas diferenças em relação à alocação e desalocação de memória, gerenciamento de memória e abstração.

As diferenças no uso de memória entre Java e C refletem as abordagens das linguagens em relação ao equilíbrio entre controle, automação, portabilidade e desempenho. C oferece um maior controle, mas com mais responsabilidade, enquanto Java busca automatizar muitos aspectos do gerenciamento de memória em prol da simplicidade e da prevenção de erros comuns.

## Ponteiros

Em C há um distinção explícita entre um tipo(ou estrutura) e um endereço:
 - int x; - significa que x é uma variável do tipo inteiro.
 - int\* y; significa que y é uma variável do tipo endereço para o inteiro.
O asterisco (\*) após o tipo int indica que estamos falando de um endereço para inteiro e não mais de um inteiro, ou seja, aponta para a posição de memória onde é armazenado o int.

### Ponteiros para alocação de memória

Em C há uma função para alocação de memória:
malloc ( memory allocation)
- Recebe como parâmetro o número de bytes que se deseja alocar.
- Retorna o endereço inicial do bloco de bytes que foi alocado, porém tem o tipo void\* (ponteiro para void).
- Há um operador chamado sizeof que recebe como parâmetro um tipo (simples ou composto) e retorna a quantidade de bytes ocupada por esse tipo.

## Lista linear sequencial

A lista é uma estrutura de dados na qual cada elemento é procedido por um elemento e sucedido por outro (exceto o primeiro que não tem um predecessor e o último que não tem um sucessor).

Os elementos estão em uma dada ordem.
Ex.: A ordem de inclusão ou ordenados por uma chave.

Uma lista linear sequencial é uma lista linear na qual a ordem lógica dos elementos é a mesma ordem física (em memória) dos elementos. Ou seja, os elementos vizinhos na lista estarão em posições vizinhas na memória.

#### Modelagem

Modelaremos uma lista linear sequencial usando um arranjo de registro, os registros conterão as informações de interesse do usuário, nosso arranjo terá um tamanho fixo e controlaremos o número de elementos com uma variável adicional.

#### Funções de gerenciamento

Será implementado funções para:

- Inicializar a Estrutura;
- Retornar a quantidade de elementos válidos;
- Exibir os elementos da estrutura;
- Buscar por um elemento na estrutura;
- Inserir elementos na estrutura;
- Excluir elementos da estrutura;
- Reinicializar a estrutura;

#### Inicialização

Para inicializar uma estrutura, precisamos pensar nos valores adequados para cada um dos campos de nossa estrutura. 

```c
#define MAX 50

typedef int TIPOCHAVE;

typedef struct {
    TIPOCHAVE chave;
    // Outros campos...
} REGISTRO;

typedef struct {
    REGISTRO A[MAX];
    int nroElem;
} LISTA;
```

Para inicalizarmos uma lista sequencial já criada pelo usuário, só se faz necessário colocar o valor 0 (zero) no número de elementos válidos.

```c
void inicializarLista(LISTA l) {
    l.nroElem = 0;
}
```

- Nessa função ao ser executada ela faz uma cópia da lista original e suas alterações não intereferem na lista original. Ou seja, após a execução teremos duas listas, uma com valores vázios e sem inicialização e outra com valores vázio e inicializada.

```c
void inicializarLista(LISTA* l) {
    l->nroElem = 0;
}
```

- Nessa função ao ser executada ela faz uma referencia ao endereço de memória da lista original e suas alterações substituem os valores da lista original. Portanto, após a execução teremos apenas uma lista na memória com valores vázios e inicializada.

#### Retorno números de elementos

Para essa estrutura basta retornar o valor do campo nroElem.

```c
int tamanho(LISTA* l) {
    return l->nroElem;
}
```

#### Exibir os elementos

Para exibir os elementos da estrutura precisaremos percorrer todos os elementos válidos e imprimir suas chaves.

```c
void exibirLista(LISTA* l) {
    int i;
    printf("Lista: \" ");
    for (i = 0; i < l->nroElem; i++) {
        printf("%i ", l->A[i].chave);
    }
    printf("\"\n");
}
```

#### Buscar por elementos

A função de buscar deverá:
- Receber uma chave do usuário;
- Caso seja encontrado retornará a posição em este elemento se encontra na lista;
- Retornar -1 caso não haja um registro com essa chave na lista;

```c
int buscaSequencial(LISTA* l, TIPOCHAVE ch) {
    int i = 0;
    while (i < l->nroElem) {
        if(ch == l->A[i].chave) return i;
        else i++;
    }
    return -1;
}
```

#### Inserção de um elemento

O usuário passa como parâmetro um registro a ser inserido na lista.

Há diferentes possibilidades de inserção:

- No início;
- No meio;
- No fim;
- Ordenada pela chave;
- Numa posição indicada pelo usuário;

No exemplo abaixo o usuário indicará qual será a posição, lembrando que as posições vão de 0 à `MAX - 1`.

Como inserir?

Se a lista não estiver cheia e o indice passado pelo usuário for válido:
- Desloca todos os elementos posteriores para uma posição a direita;
- Insere o elemento na posição desejada;
- Soma 1 no campo `nroElem` e retorna `true`;
- caso contrário retorna `false`;

```c
bool insereElemLista(LISTA* l, REGISTRO reg, int i) {
    int j;
    if ((l->nroElem == MAX) || (i < 0) || (i > l->nroElem))
        return false;
    for (j = l->nroElem; j > i; j--) l->A[j] = l->A[j-1];
    l->A[i] = reg;
    l->nroElem++;
    return true;
}
```

#### Exclusão de um elemento

O usuário passa a chava do elemento que ele quer excluir e se houver um elemento com esta chave na lista, "Exclui este elemento", desloca todos os elementos posteriores para a esquerda, diminui em um o campo `nroElem` e retorna `true`, caso contrário retornará `false`.

```c
bool excluiElemLista(TIPOCHAVE ch, LISTA* l) {
    int pos, j;
    pos = buscaSequencial(l,ch);
    if (pos == -1) return false;
    for (j = pos; j < l->nroElem - 1; j++)
        l->A[j] = l->A[j+1];
    l->nroElem--;
    return true;
}
```

#### Reinicialização da estrutura

Para reinicializarmos esta estrutura basta passar 0 (zero) no campo nroElem.

```c
void reinicializarLista(LISTA* l) {
    l->nroElem = 0;
}
```