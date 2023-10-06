#include <Magick++.h>
#include <iostream>

using namespace Magick;
using namespace std;

class ImageManager
{
private:
    
public:
    ImageManager() {
        InitializeMagick("");
    }

    void saveSquareImage(const string& fileName, int width, int height, const string& backgroundColor, const string& squareColor) {
        try {

            //define the degrade with the color1 and color2
            Image squareImage(Geometry(width, height), Color(backgroundColor));

            //object that is used to create a square
            DrawableRectangle rectangle = DrawableRectangle(40, 40, width - 40, height - 40);

            squareImage.fillColor(squareColor);
            squareImage.draw(rectangle);

            squareImage.write(fileName);

        }catch(Exception& ex) {
            cerr << "Error to save the square image: " << ex.what() << endl;
        }
    } 

    void saveDegradeImage(const string& fileName, int width, int height, const string& color1,  const string& color2) {
        try {

            //define the degrade with the color1 and color2
            string degradeColor = "gradient:" + color1 + "-" + color2;

            //Create a image with the degrade 
            Image degradeImage(Geometry(width, height), "white");
            degradeImage.read(degradeColor);

            // Save the image in the file
            degradeImage.write(fileName);
        }
        catch (Exception& ex) {
            cerr << "Error to save the degrade image: " << ex.what() << endl;
        }
    }

    void saveCircleImage(const string& fileName, int width, int height, const string& backgroundColor, const string& circleColor) {
        try {
            // Create a blank image 
            Image circleImage(Geometry(width, height), backgroundColor);

            // Draw a circle in the image
            circleImage.fillColor(circleColor);
            circleImage.draw(DrawableCircle(width / 2, height / 2, width / 2 + 20 , 100));

            // Save the image in the file
            circleImage.write(fileName);
        }
        catch (Magick::Exception& ex) {
            std::cerr << "Error to save the circle image: " << ex.what() << std::endl;
        }

    }

};


int main()
{
    ImageManager imageManager = ImageManager();
    imageManager.saveSquareImage("./images/square.png", 640, 480, "green", "red");
    imageManager.saveDegradeImage("./images/gradiente.png", 640, 480, "blue", "orange");
    imageManager.saveCircleImage("./images/circle.png", 640, 480, "blue", "orange");
    return 0;
}



