/*******************************************************************************************
*
*   3D迷路ゲーム
*
*   raylibを使用したシンプルな一人称視点の3D迷路ゲーム
*
*   機能:
*     - 一人称視点でのナビゲーション
*     - WASDキーによる移動操作
*     - マウスによる視点操作
*     - ゴール到達判定
*
*   ライセンス: MIT
*
********************************************************************************************/

#include "raylib.h"
#include <math.h>

// 画面サイズ
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

// 迷路サイズ
#define MAZE_SIZE 10
#define CELL_SIZE 2.0f

// プレイヤーがゴールに到達したかチェックする関数
bool CheckGoal(Vector3 playerPos, Vector3 goalPos) {
    float dx = playerPos.x - goalPos.x;
    float dz = playerPos.z - goalPos.z;
    float distance = sqrtf(dx * dx + dz * dz);
    return distance < 1.5f;
}

int main(void) {
    // 迷路レイアウト (1 = 壁, 0 = 通路)
    // S = スタート地点 (1,1), G = ゴール地点 (8,8)
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

    // ウィンドウ初期化
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "3D Maze Game");

    // 目標FPSを設定
    SetTargetFPS(60);

    // カメラ定義（一人称視点）
    Camera3D camera = { 0 };
    camera.position = (Vector3){ 3.0f, 1.5f, 3.0f };  // スタート位置
    camera.target = (Vector3){ 4.0f, 1.5f, 3.0f };    // 視線方向
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };        // 上方向ベクトル
    camera.fovy = 60.0f;                              // 視野角
    camera.projection = CAMERA_PERSPECTIVE;

    // ゴール位置
    Vector3 goalPos = { 17.0f, 0.5f, 17.0f };

    // ゲーム状態
    bool gameCleared = false;

    // メインゲームループ
    while (!WindowShouldClose()) {
        // ゲームクリア後でなければカメラを更新
        if (!gameCleared) {
            UpdateCamera(&camera, CAMERA_FIRST_PERSON);

            // プレイヤーがゴールに到達したかチェック
            if (CheckGoal(camera.position, goalPos)) {
                gameCleared = true;
            }
        }

        // 描画
        BeginDrawing();

            ClearBackground(RAYWHITE);

            BeginMode3D(camera);

                // 迷路の壁を描画
                for (int z = 0; z < MAZE_SIZE; z++) {
                    for (int x = 0; x < MAZE_SIZE; x++) {
                        Vector3 position = { x * CELL_SIZE, 0.5f, z * CELL_SIZE };

                        // 床を描画
                        DrawCube((Vector3){ x * CELL_SIZE, -0.5f, z * CELL_SIZE },
                                 CELL_SIZE, 0.1f, CELL_SIZE, DARKGRAY);

                        // 壁を描画
                        if (maze[z][x] == 1) {
                            DrawCube(position, CELL_SIZE, 3.0f, CELL_SIZE, GRAY);
                            DrawCubeWires(position, CELL_SIZE, 3.0f, CELL_SIZE, DARKGRAY);
                        }
                    }
                }

                // ゴールを描画
                DrawCube(goalPos, 1.0f, 1.0f, 1.0f, GREEN);
                DrawCubeWires(goalPos, 1.0f, 1.0f, 1.0f, DARKGREEN);

            EndMode3D();

            // UIを描画
            DrawText("WASD: Move | Mouse: Look | ESC: Exit", 10, 10, 20, DARKGRAY);
            DrawFPS(SCREEN_WIDTH - 100, 10);

            // クリアメッセージを描画
            if (gameCleared) {
                DrawText("GOAL! Press ESC to exit",
                        SCREEN_WIDTH/2 - 150, 50, 30, GREEN);
            }

        EndDrawing();
    }

    // 終了処理
    CloseWindow();

    return 0;
}
