#version 330 core

in vec3 vColor;
in vec3 vNormal;
in vec3 vFragPos;

out vec4 FragColor;

uniform vec3 lightPos;   // light position in world space
uniform vec3 viewPos;    // camera position in world space

void main()
{
    // Normalize normals
    vec3 norm = normalize(vNormal);

    // Light direction
    vec3 lightDir = normalize(lightPos - vFragPos);

    // Ambient
    float ambientStrength = 0.3;
    vec3 ambient = ambientStrength * vColor;

    // Diffuse
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * vColor;

    // Final color
    vec3 result = ambient + diffuse;
    FragColor = vec4(result, 1.0);
}