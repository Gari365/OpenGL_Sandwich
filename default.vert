#version 330 core

layout (location = 0) in vec3 aPos;     // vertex position
layout (location = 1) in vec3 aColor;   // vertex color
layout (location = 2) in vec3 aNormal;  // vertex normal

out vec3 vColor;
out vec3 vNormal;
out vec3 vFragPos;

uniform mat4 model;
uniform mat4 camMatrix;  // view * projection

void main()
{
    vColor = aColor;

    // Position in world space
    vec4 worldPos = model * vec4(aPos, 1.0);
    vFragPos = worldPos.xyz;

    // Normal (world space)
    vNormal = mat3(transpose(inverse(model))) * aNormal;

    gl_Position = camMatrix * worldPos;
}