package apps;

import models.Face;
import models.ObjModel;
import models.Vertex;

public class Application {

    public static void main(String[] args) {
        ObjModel model = new ObjModel();
        model.loadModel("assets/Male.obj");

        for (Vertex vertex : model.getVertices()) {
            System.out.println("Vertex: (" + vertex.getX() + ", " + vertex.getY() + ", " + vertex.getZ() + ")");
        }

        for (Face face : model.getFaces()) {
            System.out.println("Face: (" + face.getV1() + ", " + face.getV2() + ", " + face.getV3() + ")");
        }

        model.saveModel("assets/result.obj");
    }

}
