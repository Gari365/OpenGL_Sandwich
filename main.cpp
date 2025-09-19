// main.cpp
#include <iostream>
#include <cstddef>            // for offsetof
#include <vector>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb/stb_image.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Texture.h"
#include "shaderClass.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"
#include "Camera.h"

const unsigned int width = 1200;
const unsigned int height = 900;
float scaleFactor = 0.75f;


// Vertex type: use glm::vec3 fields so offsetof works nicely
struct Vertex {
    glm::vec3 position;
    glm::vec3 color;
    glm::vec3 normal;
};


// Helper: add a colored cube (24 vertices, 36 indices)
static void addCube(std::vector<Vertex>& vertices,
    std::vector<GLuint>& indices,
    glm::vec3 pos,
    glm::vec3 size,
    glm::vec3 color)
{
    glm::vec3 half = size * 0.5f;
    glm::vec3 corners[8] = {
        pos + glm::vec3(-half.x, -half.y, -half.z),
        pos + glm::vec3(half.x, -half.y, -half.z),
        pos + glm::vec3(half.x,  half.y, -half.z),
        pos + glm::vec3(-half.x,  half.y, -half.z),
        pos + glm::vec3(-half.x, -half.y,  half.z),
        pos + glm::vec3(half.x, -half.y,  half.z),
        pos + glm::vec3(half.x,  half.y,  half.z),
        pos + glm::vec3(-half.x,  half.y,  half.z),
    };

    glm::vec3 normals[6] = {
        { 0.0f,  0.0f, -1.0f}, // back
        { 0.0f,  0.0f,  1.0f}, // front
        {-1.0f,  0.0f,  0.0f}, // left
        { 1.0f,  0.0f,  0.0f}, // right
        { 0.0f, -1.0f,  0.0f}, // bottom
        { 0.0f,  1.0f,  0.0f}  // top
    };

    GLuint faceIndices[6][4] = {
        {0,1,2,3}, // back
        {4,5,6,7}, // front
        {0,4,7,3}, // left
        {1,5,6,2}, // right
        {0,1,5,4}, // bottom
        {3,2,6,7}  // top
    };

    // base vertex index for this cube
    GLuint base = static_cast<GLuint>(vertices.size());

    for (int f = 0; f < 6; ++f) {
        glm::vec3 n = normals[f];
        // push 4 verts for this face
        for (int v = 0; v < 4; ++v) {
            glm::vec3 p = corners[faceIndices[f][v]];
            vertices.push_back(Vertex{ p, color, n });
        }
        // two triangles per face
        indices.push_back(base + f * 4 + 0);
        indices.push_back(base + f * 4 + 1);
        indices.push_back(base + f * 4 + 2);

        indices.push_back(base + f * 4 + 0);
        indices.push_back(base + f * 4 + 2);
        indices.push_back(base + f * 4 + 3);
    }
}

// Light cube vertices & indices (unchanged)
GLfloat lightVertices[] = {
    -0.1f, -0.1f,  0.1f,
    -0.1f, -0.1f, -0.1f,
     0.1f, -0.1f, -0.1f,
     0.1f, -0.1f,  0.1f,
    -0.1f,  0.1f,  0.1f,
    -0.1f,  0.1f, -0.1f,
     0.1f,  0.1f, -0.1f,
     0.1f,  0.1f,  0.1f
};

GLuint lightIndices[] = {
    0,1,2, 0,2,3,
    0,4,7, 0,7,3,
    3,7,6, 3,6,2,
    2,6,5, 2,5,1,
    1,5,4, 1,4,0,
    4,5,6, 4,6,7
};


int main()
{
    // create geometry vectors (MUST be after Vertex definition)
    std::vector<Vertex> vertices;
    std::vector<GLuint> indices;

    // Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "glfwInit failed\n";
        return -1;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(width, height, "OpenGL Lighting", NULL, NULL);
    if (!window) {
        std::cout << "Failed to create GLFW window\n";
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // Load GLAD
    if (!gladLoadGL()) {
        std::cerr << "Failed to initialize GLAD\n";
        return -1;
    }
    glViewport(0, 0, width, height);

    // Shaders
    Shader shaderProgram("default.vert", "default.frag");


    // --- Build Sandwich Geometry ---

    float baseY = 0.0f;

    // Bread (bottom)
    addCube(vertices, indices,
        glm::vec3(0.0f, -0.2f, 0.0f),
        glm::vec3(2.0f, 0.2f, 2.0f),
        glm::vec3(0.96f, 0.87f, 0.70f));

    // Lettuce (thin, slightly rotated)
    addCube(vertices, indices,
        glm::vec3(0.0f, 0.0f, 0.0f),
        glm::vec3(2.1f, 0.05f, 2.1f),
        glm::vec3(0.3f, 0.8f, 0.3f)); // green

    // Ham
    addCube(vertices, indices,
        glm::vec3(0.0f, 0.1f, 0.0f),
        glm::vec3(1.75f, 0.1f, 1.75f),
        glm::vec3(0.8f, 0.4f, 0.4f)); // pinkish

    // Pickles (3 small square slices)
    addCube(vertices, indices,
        glm::vec3(-0.6f, 0.17f, 0.0f),
        glm::vec3(0.5f, 0.06f, 0.5f),
        glm::vec3(0.4f, 0.8f, 0.4f));

    addCube(vertices, indices,
        glm::vec3(0.0f, 0.17f, 0.7f),
        glm::vec3(0.5f, 0.06f, 0.5f),
        glm::vec3(0.4f, 0.8f, 0.4f));

    addCube(vertices, indices,
        glm::vec3(0.6f, 0.17f, -0.4f),
        glm::vec3(0.5f, 0.06f, 0.5f),
        glm::vec3(0.4f, 0.8f, 0.4f));

    // Bread (top)
    addCube(vertices, indices,
        glm::vec3(0.0f, 0.3f, 0.0f),
        glm::vec3(2.0f, 0.2f, 2.0f),
        glm::vec3(0.96f, 0.87f, 0.70f));



    // Create VAO / VBO / EBO for the sandwich
    VAO VAO1;
    VAO1.Bind();

    VBO VBO1(vertices.data(), vertices.size() * sizeof(Vertex));
    EBO EBO1(indices.data(), indices.size() * sizeof(GLuint));

    // Link attributes: pos (0), color (1), normal (2)
    VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, sizeof(Vertex), (void*)offsetof(Vertex, position));
    VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, sizeof(Vertex), (void*)offsetof(Vertex, color));
    VAO1.LinkAttrib(VBO1, 2, 3, GL_FLOAT, sizeof(Vertex), (void*)offsetof(Vertex, normal));

    VAO1.Unbind();
    VBO1.Unbind();
    EBO1.Unbind();

    // Light cube setup (small separate VAO)
    Shader lightShader("light.vert", "light.frag");
    VAO lightVAO;
    lightVAO.Bind();
    VBO lightVBO(lightVertices, sizeof(lightVertices));
    EBO lightEBO(lightIndices, sizeof(lightIndices));
    lightVAO.LinkAttrib(lightVBO, 0, 3, GL_FLOAT, 3 * sizeof(float), (void*)0);
    lightVAO.Unbind();
    lightVBO.Unbind();
    lightEBO.Unbind();

    // Light & camera initial config
    glm::vec4 lightColor = glm::vec4(1.0f);
    glm::vec3 lightPos = glm::vec3(0.7f, 1.0f, 1.0f);
    glm::mat4 lightModel = glm::translate(glm::mat4(1.0f), lightPos);

    glm::vec3 sandwichPos = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::mat4 sandwichModel = glm::translate(glm::mat4(1.0f), sandwichPos);

    lightShader.Activate();
    glUniformMatrix4fv(glGetUniformLocation(lightShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(lightModel));
    glUniform4f(glGetUniformLocation(lightShader.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);

    shaderProgram.Activate();
    glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "model"), 1, GL_FALSE, glm::value_ptr(sandwichModel));
    glUniform4f(glGetUniformLocation(shaderProgram.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
    glUniform3f(glGetUniformLocation(shaderProgram.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);

    Camera camera(width, height, glm::vec3(0.0f, 0.35f, 2.0f));
    glEnable(GL_DEPTH_TEST);

    float rotation = 0.0f;
    double prevTime = glfwGetTime();

    // Main loop
    while (!glfwWindowShouldClose(window))
    {
        double crntTime = glfwGetTime();

        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        camera.Inputs(window);
        camera.updateMatrix(45.0f, 0.1f, 100.0f);

        if (crntTime - prevTime >= 1.0 / 60.0) {
            if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) rotation -= 2.0f;
            if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) rotation += 2.0f;
            if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) scaleFactor += 0.02f;
            if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) scaleFactor -= 0.02f;
            prevTime = crntTime;
        }

        // Update shader (sandwich)
        shaderProgram.Activate();

        // Global model for whole sandwich (if you want to rotate the entire sandwich)
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, sandwichPos);
        model = glm::rotate(model, glm::radians(rotation), glm::vec3(0.0f, 1.0f, 0.0f));
        model = glm::scale(model, glm::vec3(scaleFactor));
        glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "model"), 1, GL_FALSE, glm::value_ptr(model));

        // Pass camera position to fragment shader if it expects it (common name: viewPos)
        GLint locView = glGetUniformLocation(shaderProgram.ID, "viewPos");
        if (locView != -1) {
            glUniform3f(locView, camera.Position.x, camera.Position.y, camera.Position.z);
        }

        camera.Matrix(shaderProgram, "camMatrix");

        // Draw sandwich (all parts batched in one VAO)
        VAO1.Bind();
        glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(indices.size()), GL_UNSIGNED_INT, 0);
        VAO1.Unbind();

        // Draw light cube
        lightShader.Activate();
        glUniformMatrix4fv(glGetUniformLocation(lightShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(lightModel));
        glUniform4f(glGetUniformLocation(lightShader.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
        camera.Matrix(lightShader, "camMatrix");

        lightVAO.Bind();
        glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(sizeof(lightIndices) / sizeof(lightIndices[0])), GL_UNSIGNED_INT, 0);
        lightVAO.Unbind();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // cleanup
    VAO1.Delete(); VBO1.Delete(); EBO1.Delete();
    lightVAO.Delete(); lightVBO.Delete(); lightEBO.Delete();
    shaderProgram.Delete(); lightShader.Delete();
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
