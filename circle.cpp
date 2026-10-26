#include <graphics.h>
#include <bits/stdc++.h>
using namespace std;
void drawCirclePoints(int xc, int yc, int x, int y)
{
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
    putpixel(xc + y, yc + x, WHITE);
    putpixel(xc - y, yc + x, WHITE);
    putpixel(xc + y, yc - x, WHITE);
    putpixel(xc - y, yc - x, WHITE);
}

int main()
{
    int xc, yc, r;
    cout << "Enter center coordinates (xc, yc): ";
    cin >> xc >> yc;
    cout << "Enter radius: ";
    cin >> r;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    int x = 0;
    int y = r;
    int p = 1 - r;
    drawCirclePoints(xc, yc, x, y);
    while (x < y)
    {
        x++;
        if (p < 0)
        {
            p += 2 * x + 1;
        }
        else
        {
            y--;
            p += 2 * (x - y) + 1;
        }
        drawCirclePoints(xc, yc, x, y);
    }

    getch();
    closegraph();
    return 0;
}
