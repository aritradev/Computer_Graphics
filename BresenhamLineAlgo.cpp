#include <graphics.h>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x1, y1, x2, y2;
    cout << "Enter starting point (x1, y1): ";
    cin >> x1 >> y1;
    cout << "Enter ending point (x2, y2): ";        
    cin >> x2 >> y2;
    int gd= DETECT,gm;
    initgraph(&gd,&gm,NULL);
    int dx=x2-x1;
    int dy=y2-y1;
    int p = 2*dy-dx;
    while(x1<=x2 && y1<=y2)
    {
        putpixel(x1,y1,WHITE);
        if(p<0){
            x1++;
            p+=2*dy;
        }
        else{
            x1++;
            y1++;
            p+=2*dy-2*dx;
        }
    }
    delay(100);
    getch();
    closegraph();
}
