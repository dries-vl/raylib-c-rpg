#include "raylib/raylib.h"

int main() {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Raylib 2D Shader Example");

    Shader shader = LoadShader("shaders/vert_shader.vert", "shaders/frag_shader.frag");
    SetTargetFPS(60);

    Rectangle rec = { screenWidth/2 - 50, screenHeight/2 - 50, 100, 100 };

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        BeginShaderMode(shader);
        DrawRectangleRec(rec, RED);
        EndShaderMode();

        DrawText("Hello, 2D shaders!", 10, 10, 20, DARKGRAY);
        
        EndDrawing();
    }

    UnloadShader(shader);
    CloseWindow();

    return 0;
}
