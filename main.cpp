#include <iostream>
#include "class/mapatrem.h"
#include "class/threads/thread.h"
#include <vector>

using namespace std;

int main(int argc, char **argv) {
    MapaTrem trens; 
    
    // posições para os trens
    vector<Point> pt1;
    pt1.push_back(Point(25, 158));
    pt1.push_back(Point(67, 158));
    pt1.push_back(Point(180, 158));
    pt1.push_back(Point(304, 242));
    pt1.push_back(Point(435, 242));
    pt1.push_back(Point(475, 242));
    
    vector<Point> pt2;
    pt2.push_back(Point(25, 326));
    pt2.push_back(Point(67, 326));
    pt2.push_back(Point(180, 326));
    pt2.push_back(Point(304, 242));
    pt2.push_back(Point(435, 242));
    pt2.push_back(Point(475, 242));
    
    //trens.Trem1Pos(200,200);
    //trens.Trem2Pos(100,200);
    //trens.Trem1Txt("Mensagem trem 1.");
    //trens.Trem2Txt("Mensagem trem 2.");
    
    trens.Gate(1);
    for(Point p : pt1)
    {
        trens.Trem1Pos(p.x,p.y);
        Thread::SleepMS(3000);
        
        int key = trens.GetLastKey();
        cout << "LastKey = " << key << endl;
        if(key == 27)
            return 1;
    }
    
    trens.Gate(0);
    for(Point p : pt2)
    {
        trens.Trem2Pos(p.x,p.y);
        Thread::SleepMS(3000);
        
        int key = trens.GetLastKey();
        cout << "LastKey = " << key << endl;
        if(key == 27)
            return 1;
    }
    
    return 0;
}
