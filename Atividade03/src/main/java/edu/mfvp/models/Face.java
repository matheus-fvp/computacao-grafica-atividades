package edu.mfvp.models;

/**
 * The {@code Face} class represents a face in a three-dimensional model.
 * A face is defined by three vertex indices (v1, v2, v3) corresponding to the
 * vertices that make up the triangular face.
 */
public class Face {

    /** The index of the first vertex in the face. */
    private int v1;

    /** The index of the second vertex in the face. */
    private int v2;

    /** The index of the third vertex in the face. */
    private int v3;

    /**
     * Default constructor that initializes a {@code Face} object with
     * vertex indices (0, 0, 0).
     */
    public Face() {
    }

    /**
     * Constructor that allows the creation of a {@code Face} object with
     * specific vertex indices.
     *
     * @param v1 The index of the first vertex in the face.
     * @param v2 The index of the second vertex in the face.
     * @param v3 The index of the third vertex in the face.
     */
    public Face(int v1, int v2, int v3) {
        this.v1 = v1;
        this.v2 = v2;
        this.v3 = v3;
    }

    public int getV1() {
        return v1;
    }

    public int getV2() {
        return v2;
    }

    public int getV3() {
        return v3;
    }

}
