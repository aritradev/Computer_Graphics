#include <graphics.h>
#include <bits/stdc++.h>

using namespace std;

void plot(int xc, int yc, int x, int y) {
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
}

void drawEllipse(int xc, int yc, long long rx, long long ry) {
    long long x = 0, y = ry;
    long long rx2 = rx * rx, ry2 = ry * ry;
    long long dx = 2 * ry2 * x, dy = 2 * rx2 * y;

    double p1 = ry2 - (rx2 * ry) + (0.25 * rx2);
    while (dx < dy) {
        plot(xc, yc, x, y);
        x++;
        dx += 2 * ry2;
        p1 += (p1 < 0) ? (dx + ry2) : (dx - (dy -= 2 * rx2) + ry2);
        if (p1 >= 0 && dy == 2 * rx2 * y) y--;
    }

    double p2 = ry2 * (x + 0.5) * (x + 0.5) + rx2 * (y - 1) * (y - 1) - rx2 * ry2;
    while (y >= 0) {
        plot(xc, yc, x, y);
        y--;
        dy -= 2 * rx2;
        p2 += (p2 > 0) ? (rx2 - dy) : (rx2 + (dx += 2 * ry2) - dy);
        if (p2 <= 0) x++;
    }
}

int main() {
    int xc, yc, rx, ry;
    cout << "Enter xc yc rx ry: ";
    cin >> xc >> yc >> rx >> ry;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    drawEllipse(xc, yc, rx, ry);

    setfontcolor(YELLOW);
    outtextxy(20, 20, (char *)"Midpoint Ellipse Algorithm");

    setfontcolor(GREEN);
    outtextxy(20, 50, (char *)"Font Color: Green");

    setfontcolor(CYAN);
    outtextxy(20, 80, (char *)"Font Color: Cyan");

    setfontcolor(RED);
    outtextxy(20, 110, (char *)"Font Color: Red");

    setfontcolor(WHITE);
    outtextxy(20, 140, (char *)"Font Color: White");

    delay(100);
    getch();
    closegraph();
    return 0;
}
