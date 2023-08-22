Estrutura de dados em C

http://each.usp.br/digiampietri/ed/

Usando a linguagem C pois, a linguagem C não é orientada a objetos, é uma linguagem imperativa e estruturada.
Ou seja, ela permite de maneira mais explicita a alocação e desalocação de memória, gerenciamento de ponteiros e estruturas.

necessário ter instalado o GCC (https://gcc.gnu.org/)
necessário um editor de código (vscode, sublime, notepad++)

Não usar uma IDE diminui a quantidade de interferência que uma IDE causa.

Diferença entre um código Java e um C

Java 
class HelloWorld {
    public static void main(String[] args) {
		System.out.println("Hello World!");
    }
}

Compilar e executar: 
$ javac HelloWorld.Java
$ java HelloWorld

Saída esperada:
$ Hello World!

C
#include <stdio.h>
int main() {
	printf("Hello World!\n");
	return 0;
}

Compilar e executar: 
$ gcc HelloWorld.c -o HelloWorld
$ ./HelloWorld

Saída esperada:
$ Hello World!

Criando uma estrutura simples

Uma estrutura de dados é uma maneira de organizar um conjunto de dados.

Queremos criar uma estrutura para guardar algumas informações.

Como modelamos essa estrutura?
Como instanciamos essa estrutura?
Como acessamos seus campos?

Em Java e outras linguagens orientadas a objetos criamos uma classe com atributos e depois instanciamos.
Depois fazemos outra classe para estarmos utilizando esse classe.

Em C temos uma sintaxe própria para definir estruturas. A sintaxe struct { ... } define uma estrutura com os campos definidos dentro das chaves. a sintaxe typedef ... NameStruct define o nome para a estrutura que foi criada.
Ex.: typedef struct { int var1; int var2; } VarStruct;

Podemos definir um variável para declarar um tipo simples. 
Ex.: typedef int CHAVE 
Poderemos utilizar no código a palavra CHAVE para representar o tipo int.

Uso de memória em Java:
O Java é uma linguagem de programação que utiliza um sistema de gerenciamento de memória bastante eficiente e automatizado, conhecido como "Garbage Collection" (Coleta de Lixo).
Em Java temos algumas divisões no processo de gerenciamento de memória.
- Heap Memory (Memória Heap): É a região onde os objetos Java são alocados dinamicamente durante a execução do programa. O heap é dividido em duas áreas principais: a área Young e a área Old. A área Young é onde os objetos recém-criados são alocados. Com o tempo, alguns objetos sobrevivem e são movidos para a área Old.
- Garbage Collection: O Java utiliza um processo de coleta de lixo para identificar e liberar automaticamente a memória ocupada por objetos que não são mais referenciados pelo programa. Isso evita vazamentos de memória, onde a memória é ocupada por objetos inacessíveis.
- Memória Stack: A memória da pilha é onde as variáveis locais e referências a objetos são armazenadas. Métodos em execução e seus respectivos parâmetros também residem na pilha. A memória da pilha é organizada em frames, que são empilhados à medida que os métodos são chamados e desempilhados quando os métodos retornam.
- Permanent Generation (ou Metaspace no Java 8 em diante): Nesta região, o Java armazena informações internas da classe, como constantes e estruturas de dados relacionadas a classes. O tamanho desta região é fixo, mas pode variar de acordo com a aplicação.
- Métodos e Variáveis Estáticas: Eles são armazenados em uma área separada da memória e não são associados a instâncias específicas de classes.

O processo de alocação e liberação de memória no Java é em grande parte automatizado pelo compilador.

No exemplo de código, a alocação de memória ocorre da seguinte maneira durante a execução:
- As classes PesoAltura e EstruturaSimples são carregadas na memória. Isso inclui qualquer variável de classe, estruturas e métodos estáticos definidos nas classes.
- Dentro do método main, uma instância da classe PesoAltura chamada pessoa1 é criada usando o operador new. Isso alocará memória no heap para armazenar os dados da instância.
- Atributos da instância pessoa1 (peso e altura) são preenchidos com os valores 80 e 185, respectivamente.
- A impressão dos valores de peso e altura é realizada usando System.out.print.
- A comparação if verifica se a altura da pessoa está acima da altura máxima definida na classe EstruturaSimples.
- Quando o programa termina, a memória alocada para a instância pessoa1 será liberada automaticamente pelo sistema de gerenciamento de memória Java, no processo de Garbage Collection.
A memória alocada para variáveis locais (como os atributos da classe PesoAltura) reside na pilha, enquanto a memória alocada para objetos (instâncias de classes) reside no heap. O Java cuida da alocação e liberação de memória para objetos, garantindo que objetos não referenciados sejam coletados pelo processo de Garbage Collection para evitar vazamentos de memória.

Em C, o uso de memória é mais manual e direto em comparação com linguagens de programação de alto nível, como Java.
Quando você declara uma variável em C, a memória necessária para essa variável é alocada. As variáveis locais são geralmente alocadas uma área específica da memória conhecida como pilha de execução, enquanto as variáveis globais são armazenadas em uma área de memória separada.
No exemplo em C a alocação de memória ocorre da seguinte maneira durante a execução:
A memória para a estrutura PesoAltura pessoa1 é alocada na pilha.
As variáveis peso e altura dentro da estrutura são preenchidas com os valores 80 e 185.
Os valores são impressos usando printf.
Não há alocação dinâmica de memória no heap neste exemplo.
Assim que a função main é concluída, a memória alocada para pessoa1 é automaticamente liberada, já que está na pilha. A constante alturaMaxima é substituída diretamente pelo pré-processador e não ocupa espaço de memória em si.

O uso de memória é diferente entre Java e C principalmente devido às suas diferenças em relação à alocação e desalocação de memória, gerenciamento de memória e abstração.
As diferenças no uso de memória entre Java e C refletem as abordagens das linguagens em relação ao equilíbrio entre controle, automação, portabilidade e desempenho. C oferece um maior controle, mas com mais responsabilidade, enquanto Java busca automatizar muitos aspectos do gerenciamento de memória em prol da simplicidade e da prevenção de erros comuns.

Ponteiros
Em C há um distinção explícita entre um tipo(ou estrutura) e um endereço:
 - int x; - significa que x é uma variável do tipo inteiro.
 - int* y; significa que y é uma variável do tipo endereço para o inteiro.
O asterisco (*) após o tipo int indica que estamos falando de um endereço para inteiro e não mais de um inteiro, ou seja, aponta para a posição de memória onde é armazenado o int.