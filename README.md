# Computacao Gráfica - Atividades
<details>
  <summary><h2>Atividade 01</h2></summary>

  A `ImageManager` é uma classe C++ que oferece métodos para criar e salvar imagens com diferentes formas e estilos usando a biblioteca ImageMagick++. A classe fornece três principais funcionalidades:

  1. **Salvar uma Imagem Quadrada**:</br>
  O método `saveSquareImage` permite criar e salvar uma imagem quadrada com cores de fundo personalizadas e um quadrado colorido dentro dela.
      ```cpp
      void saveSquareImage(const string& fileName, int width, int height, const string& backgroundColor, const string& squareColor)
      ```
      - `fileName`: O nome do arquivo de saída.
      - `width e height`: As dimensões da imagem quadrada.
      - `backgroundColor`: A cor de fundo da imagem.
      - `squareColor`: A cor do quadrado dentro da imagem. 
  2. **Salvar uma Imagem em Degradê**:</br>
  O método `saveDegradeImage` permite criar e salvar uma imagem com um degradê de cores entre duas cores especificadas.
      ```cpp
      void saveDegradeImage(const string& fileName, int width, int height, const string& color1,  const string& color2)
      ```
      - `fileName`: O nome do arquivo de saída.
      - `width e height`: As dimensões da imagem degradê.
      - `color1 e color2`: As cores que definem o degradê.
  3. **Salvar uma imagem com um circulo**: </br>
  O método `saveCircleImage` permite criar e salvar uma imagem com um círculo desenhado dentro dela. Você pode personalizar a cor de fundo da imagem e a cor do círculo.
      ```cpp
      void saveCircleImage(const string& fileName, int width, int height, const string& backgroundColor, const string& circleColor)
      ```
      - `fileName`: O nome do arquivo de saída.
      - `width e height`: As dimensões da imagem.
      - `backgroundColor`: A cor de fundo da imagem.
      - `circleColor`: A cor do círculo desenhado na imagem.
    
  Para usar a classe `ImageManager`, você deve instanciá-la e, em seguida, chamar os métodos relevantes para criar e salvar as imagens desejadas. Certifique-se de ter o ImageMagick++ configurado e instalado em seu ambiente antes de usar essa classe. 
</details>

<details>
  <summary><h2>Atividade 02</h2></summary>

  O objetivo desta atividade é desenvolver classes para manipulação de vetores e matrizes. Ao todo forma desenvolvidas 5 classes sendo elas:
  - `mat2` - A classe `mat2` representa uma matriz 2x2, comumente utilizada em transformações bidimensionais. Fornece operações básicas, como adição, subtração, multiplicação e divisão. A classe também inclui funções utilitárias para transposição e inversão da matriz.
  - `mat3` - A classe `mat3` é uma implementação de matriz 3x3, estendendo a funcionalidade da mat2 para suportar transformações tridimensionais. Suporta operações fundamentais e funções utilitárias para transposição e inversão.
  - `mat4` - A classe `mat4` é uma matriz 4x4 projetada para aplicações gráficas tridimensionais. Inclui operações para translação, rotação, escala e projeção perspectiva. Suporta operações básicas e funções utilitárias.
  - `vec2` - A classe `vec2` representa um vetor 2D, frequentemente utilizado em operações geométricas em espaço bidimensional. Inclui operadores para adição, subtração, multiplicação, divisão e produto escalar. A classe também fornece funções para calcular o comprimento e normalização do vetor.
  - `vec4` - A classe `vec4` estende a funcionalidade da vec2 para um vetor 4D, útil em gráficos 3D e coordenadas homogêneas. Inclui operadores e funções semelhantes, proporcionando uma representação conveniente para pontos ou direções em quatro dimensões.
</details>

</details>

<details>
  <summary><h2>Atividade 03</h2></summary>
  
  # 3D Model Loader
  Este projeto contém uma aplicação Java simples para carregar e salvar modelos 3D no formato de arquivo Wavefront OBJ. A aplicação é composta por três classes principais: `Vertex`, `Face` e `ObjLoader`. Essas classes fornecem funcionalidades para representar e carregar modelos 3D.

  ## Classes
  
  ### Vertex
  A classe `Vertex` representa um ponto no espaço tridimensional. Ela contém três atributos (`x`, `y` e `z`) para armazenar as coordenadas do ponto. Essa classe é utilizada para definir os vértices de um modelo 3D.

  ### Face
  A classe `Face` representa uma face triangular em um modelo 3D. Ela é definida por três índices de vértices (`v1`, `v2` e `v3`). Esses índices correspondem aos vértices que compõem a face triangular.

  ### ObjLoader
  A classe `ObjLoader` é responsável por carregar e salvar modelos 3D no formato de arquivo Wavefront OBJ. Ela contém listas para armazenar vértices, normais e faces. O método `loadObj` lê um arquivo OBJ e popula essas listas, enquanto o método `saveObj` salva o modelo carregado como um arquivo OBJ. Essa classe atua como um carregador simples de modelos 3D e é o ponto principal para utilizar a funcionalidade.
</details>
