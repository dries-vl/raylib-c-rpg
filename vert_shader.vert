#version 330 core
layout (location = 0) in vec2 vertexPosition;  // Raylib defines position at location 0
layout (location = 1) in vec2 vertexTexCoord;  // TexCoord at location 1 (if used)
layout (location = 2) in vec4 vertexColor;     // Color at location 2 (if used)

out vec2 fragTexCoord;
out vec4 fragColor;

uniform mat4 mvp;  // Raylib typically passes ModelViewProjection matrix as uniform

void main()
{
    gl_Position = mvp * vec4(vertexPosition, 0.0, 1.0);
    fragTexCoord = vertexTexCoord;
    fragColor = vec4(vertexTexCoord, 0.0, 1.0);
}
