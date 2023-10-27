package edu.mfvp;

import edu.mfvp.models.Face;
import edu.mfvp.models.ObjModel;
import edu.mfvp.models.Vertex;


public class App 
{
    public static void main(String[] args) {
        ObjModel model = new ObjModel();
        model.loadModel("./src/assets/Male.obj");

        for (Vertex vertex : model.getVertices()) {
            System.out.println("Vertex: (" + vertex.getX() + ", " + vertex.getY() + ", " + vertex.getZ() + ")");
        }

        for (Face face : model.getFaces()) {
            System.out.println("Face: (" + face.getV1() + ", " + face.getV2() + ", " + face.getV3() + ")");
        }

        //model.saveModel("assets/result.obj");
    }
}
