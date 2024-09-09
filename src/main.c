#include "raylib/raylib.h"

int main() {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Raylib 2D Shader Example");

    Shader shader = LoadShader("vert_shader.vert", "frag_shader.frag");
    SetTargetFPS(60);

    Rectangle rec = { screenWidth/2 - 50, screenHeight/2 - 50, 100, 100 };

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawRectangleRec(rec, RED);
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
