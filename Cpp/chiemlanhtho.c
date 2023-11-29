#include <stdio.h>
#define BLUE_WIN "BLUE"
#define RED_WIN "RED"
#define DRAW_GAME "DRAW"

void solve(int width, int height, int x_blue, int y_blue, char p) {
    int center_x = width / 2, center_y = height / 2;
    const char* result;
    switch (p) {
    case 'D':
        result = (height % 2 == 0) ? ((y_blue == center_y) ? DRAW_GAME : (y_blue < center_y) ? RED_WIN : BLUE_WIN) : ((y_blue == center_y) ? BLUE_WIN : (y_blue < center_y) ? RED_WIN : BLUE_WIN);
        break;
    case 'U':
        ++center_y;
        result = (height % 2 == 0) ? ((y_blue == center_y) ? DRAW_GAME : (y_blue < center_y) ? BLUE_WIN : RED_WIN) : ((y_blue == center_y || y_blue < center_y) ? BLUE_WIN : RED_WIN);
        break;
    case 'R':
        result = (width % 2 == 0) ? ((x_blue == center_x) ? DRAW_GAME : (x_blue < center_x) ? RED_WIN : BLUE_WIN) : ((x_blue == (center_x + 1)) ? BLUE_WIN : (x_blue < (center_x + 1)) ? RED_WIN : BLUE_WIN);
        break;
    default:
        ++center_x;
        result = (width % 2 == 0) ? ((x_blue == center_x) ? DRAW_GAME : (x_blue > center_x) ? RED_WIN : BLUE_WIN) : ((x_blue == center_x || x_blue < center_x) ? BLUE_WIN : RED_WIN);
    }
    printf("%s\n", result);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int w, h, x, y;
        char p;
        scanf("%d %d %d %d %c", &w, &h, &x, &y, &p);
        solve(w, h, x, y, p);
    }
    return 0;
}
