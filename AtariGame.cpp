#include "raylib.h"

int main(void)
{
    InitWindow(800, 450, "raylib [core] example - basic window");

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
        Rectangle r;
        r.x = 190;
        r.y = 190;
        r.width = 50;
        r.height = 50;
        DrawRectangleRec(r, LIGHTGRAY);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}