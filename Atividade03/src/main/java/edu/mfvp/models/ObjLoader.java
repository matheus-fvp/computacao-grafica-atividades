package edu.mfvp.models;

import java.io.*;
import java.util.ArrayList;
import java.util.List;

/**
 * The {@code ObjLoader} class is responsible for loading and saving Wavefront OBJ
 * files, which define 3D models by specifying vertices, normals, and faces.
 */
public class ObjLoader {

    /** List to store the vertices of the loaded 3D model. */
    private List<Vertex> vertices = new ArrayList<>();

    /** List to store the normals of the loaded 3D model. */
    private List<Vertex> normals = new ArrayList<>();

    /** List to store the faces of the loaded 3D model. */
    private List<Face> faces = new ArrayList<>();

    /**
     * Retrieves the list of vertices of the loaded 3D model.
     *
     * @return The list of vertices.
     */
    public List<Vertex> getVertices() {
        return vertices;
    }

    /**
     * Retrieves the list of faces of the loaded 3D model.
     *
     * @return The list of faces.
     */
    public List<Face> getFaces() {
        return faces;
    }

    /**
     * Retrieves the list of normals of the loaded 3D model.
     *
     * @return The list of normals.
     */
    public List<Vertex> getNormals() {
        return normals;
    }


    /**
     * Loads a Wavefront OBJ file and populates the vertices, normals, and faces lists.
     *
     * @param filename The path to the OBJ file.
     */
    public void loadObj(String filename) {
        try (BufferedReader reader = new BufferedReader(new FileReader(filename))) {
            String line;
            while ((line = reader.readLine()) != null) {
                String[] parts = line.split(" ");
                switch (parts[0]) {
                    case "v":
                        vertices.add(parseVertex(parts));
                        break;
                    case "vn":
                        normals.add(parseVertex(parts));
                        break;
                    case "f":
                        faces.add(parseFace(parts));
                        break;
                }
            }
        } catch (IOException e) {
            System.out.println("Erro to load the file! " + e.getMessage());
        }
    }

    /**
     * Parses a line representing a vertex and returns a Vertex object.
     *
     * @param parts The array of strings representing the line components.
     * @return The parsed Vertex object.
     */
    private static Vertex parseVertex(String[] parts) {
        double x = Double.parseDouble(parts[1]);
        double y = Double.parseDouble(parts[2]);
        double z = Double.parseDouble(parts[3]);
        return new Vertex(x, y, z);
    }

    /**
     * Parses a line representing a face and returns a Face object.
     *
     * @param parts The array of strings representing the line components.
     * @return The parsed Face object.
     */
    private static Face parseFace(String[] parts) {
        int v1 = Integer.parseInt(parts[1].split("/")[0]);
        int v2 = Integer.parseInt(parts[2].split("/")[0]);
        int v3 = Integer.parseInt(parts[3].split("/")[0]);

        return new Face(v1, v2, v3);
    }

    /**
     * Saves the loaded 3D model as a Wavefront OBJ file.
     *
     * @param filename The path to save the OBJ file.
     */
    public void saveObj(String filename) {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(filename))) {
            for (Vertex vertex : vertices) {
                writer.write(String.format("v %.8f %.8f %.8f\n", vertex.getX(), vertex.getY(), vertex.getZ()));
            }

            for (Face face : faces) {
                writer.write(String.format("f %d %d %d\n", face.getV1(), face.getV2(), face.getV3()));
            }
        } catch (IOException e) {
            System.out.println("Error to save the file! " + e.getMessage());
        }
    }

}
