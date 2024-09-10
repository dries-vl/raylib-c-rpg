#include "raylib/raylib.h"

int main() {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Raylib 2D Shader Example");

    Shader shader = LoadShader("shaders/vert_shader.vert", "shaders/frag_shader.frag");
    SetTargetFPS(60);

    Rectangle rec = { screenWidth/2 - 50, screenHeight/2 - 50, 100, 100 };

    // Load texture for the sprite
    Texture2D texture = LoadTexture("test.png");
    
    // Define the position where you want to draw the sprite
    Vector2 position = {0, 0};
        

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Draw the sprite
        DrawTextureV(texture, position, WHITE);

        BeginShaderMode(shader);
        DrawRectangleRec(rec, RED);
        EndShaderMode();

        DrawText("Hello, 2D shaders!", 10, 10, 20, DARKGRAY);
        
        EndDrawing();
    }

    UnloadTexture(texture);
    UnloadShader(shader);
    CloseWindow();

    return 0;
}
