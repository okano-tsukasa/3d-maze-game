/*******************************************************************************************
*
*   3D Maze Game
*
*   A simple first-person 3D maze game using raylib
*
*   Features:
*     - First-person view navigation
*     - WASD movement controls
*     - Mouse look controls
*     - Goal detection
*
*   License: MIT
*
********************************************************************************************/

#include "raylib.h"
#include <math.h>

// Screen dimensions
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

// Maze dimensions
#define MAZE_SIZE 10
#define CELL_SIZE 2.0f

// Function to check if player reached the goal
bool CheckGoal(Vector3 playerPos, Vector3 goalPos) {
    float dx = playerPos.x - goalPos.x;
    float dz = playerPos.z - goalPos.z;
    float distance = sqrtf(dx * dx + dz * dz);
    return distance < 1.5f;
}

int main(void) {
    // Maze layout (1 = wall, 0 = path)
    // S = Start (1,1), G = Goal (8,8)
    int maze[MAZE_SIZE][MAZE_SIZE] = {
        {1,1,1,1,1,1,1,1,1,1},
        {1,0,0,0,1,0,0,0,0,1},
        {1,0,1,0,1,0,1,1,0,1},
        {1,0,1,0,0,0,0,1,0,1},
        {1,0,1,1,1,1,0,1,0,1},
        {1,0,0,0,0,0,0,1,0,1},
        {1,1,1,1,1,1,0,1,0,1},
        {1,0,0,0,0,0,0,1,0,1},
        {1,0,1,1,1,1,1,1,0,1},
        {1,1,1,1,1,1,1,1,1,1}
    };

    // Initialize window
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "3D Maze Game");

    // Set target FPS
    SetTargetFPS(60);

    // Define the camera (first person)
    Camera3D camera = { 0 };
    camera.position = (Vector3){ 3.0f, 1.5f, 3.0f };  // Start position
    camera.target = (Vector3){ 4.0f, 1.5f, 3.0f };    // Looking direction
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };        // Up vector
    camera.fovy = 60.0f;                              // Field of view
    camera.projection = CAMERA_PERSPECTIVE;

    // Goal position
    Vector3 goalPos = { 17.0f, 0.5f, 17.0f };

    // Game state
    bool gameCleared = false;

    // Main game loop
    while (!WindowShouldClose()) {
        // Update camera only if game is not cleared
        if (!gameCleared) {
            UpdateCamera(&camera, CAMERA_FIRST_PERSON);

            // Check if player reached the goal
            if (CheckGoal(camera.position, goalPos)) {
                gameCleared = true;
            }
        }

        // Draw
        BeginDrawing();

            ClearBackground(RAYWHITE);

            BeginMode3D(camera);

                // Draw maze walls
                for (int z = 0; z < MAZE_SIZE; z++) {
                    for (int x = 0; x < MAZE_SIZE; x++) {
                        Vector3 position = { x * CELL_SIZE, 0.5f, z * CELL_SIZE };

                        // Draw floor
                        DrawCube((Vector3){ x * CELL_SIZE, -0.5f, z * CELL_SIZE },
                                 CELL_SIZE, 0.1f, CELL_SIZE, DARKGRAY);

                        // Draw walls
                        if (maze[z][x] == 1) {
                            DrawCube(position, CELL_SIZE, 3.0f, CELL_SIZE, GRAY);
                            DrawCubeWires(position, CELL_SIZE, 3.0f, CELL_SIZE, DARKGRAY);
                        }
                    }
                }

                // Draw goal
                DrawCube(goalPos, 1.0f, 1.0f, 1.0f, GREEN);
                DrawCubeWires(goalPos, 1.0f, 1.0f, 1.0f, DARKGREEN);

            EndMode3D();

            // Draw UI
            DrawText("WASD: Move | Mouse: Look | ESC: Exit", 10, 10, 20, DARKGRAY);
            DrawFPS(SCREEN_WIDTH - 100, 10);

            // Draw clear message
            if (gameCleared) {
                DrawText("GOAL! Press ESC to exit",
                        SCREEN_WIDTH/2 - 150, 50, 30, GREEN);
            }

        EndDrawing();
    }

    // Cleanup
    CloseWindow();

    return 0;
}
