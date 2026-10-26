#include <graphics.h>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int x1, y1, x2, y2;
    cout << "Enter starting point (x1, y1): ";
    cin >> x1 >> y1;
    cout << "Enter ending point (x2, y2): ";
    cin >> x2 >> y2;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int dx = x2 - x1;
    int dy = y2 - y1;

    int steps = max(abs(dx), abs(dy));
    float x_increment = (float)dx / steps;
    float y_increment = (float)dy / steps;
    float x = x1;
    float y = y1;

    for (int i = 0; i <= steps; i++) {
        putpixel(round(x), round(y), WHITE);
        x += x_increment;
        y += y_increment;
    }

    delay(100);
    getch();
    closegraph();
    return 0;
}
