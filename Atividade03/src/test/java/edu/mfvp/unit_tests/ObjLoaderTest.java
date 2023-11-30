package edu.mfvp.unit_tests;

import edu.mfvp.models.ObjLoader;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class ObjLoaderTest {

    @Test
    void should_read_a_obj_file() {
        ObjLoader objLoader = new ObjLoader();
        objLoader.loadObj("assets/cubes.obj");
        Assertions.assertEquals(8, objLoader.getVertices().size());
        Assertions.assertEquals(12, objLoader.getFaces().size());
        Assertions.assertEquals(6, objLoader.getNormals().size());
    }

}
