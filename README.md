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

