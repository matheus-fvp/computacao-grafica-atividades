package edu.mfvp.models;

/**
 * The {@code Vertex} class represents a three-dimensional point in space.
 * Each point is defined by its x, y, and z coordinates.
 */
public class Vertex {

    /** The x-coordinate of the three-dimensional point. */
    private double x;

    /** The y-coordinate of the three-dimensional point. */
    private double y;

    /** The z-coordinate of the three-dimensional point. */
    private double z;

    /**
     * Default constructor that initializes a {@code Vertex} object with
     * coordinates (0.0, 0.0, 0.0).
     */
    public Vertex() {
    }

    /**
     * Constructor that allows the creation of a {@code Vertex} object with
     * specific coordinates.
     *
     * @param x The x-coordinate of the point.
     * @param y The y-coordinate of the point.
     * @param z The z-coordinate of the point.
     */
    public Vertex(double x, double y, double z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    /**
     * Gets the x-coordinate of the point.
     *
     * @return The x-coordinate of the point.
     */
    public double getX() {
        return x;
    }

    /**
     * Gets the y-coordinate of the point.
     *
     * @return The y-coordinate of the point.
     */
    public double getY() {
        return y;
    }

    /**
     * Gets the z-coordinate of the point.
     *
     * @return The z-coordinate of the point.
     */
    public double getZ() {
        return z;
    }

}
