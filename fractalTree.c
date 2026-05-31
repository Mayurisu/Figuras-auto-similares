// Actividad 1:

#include "turtlec.h"

void fractalTree(Turtle *turtle, float length, int depth) {
    if(depth == 0 || length < 5)
        return;

    turtleForward(turtle, length);

    turtleLeft(turtle, 30);
    fractalTree(turtle, length * 0.7 ,depth - 1);

    turtleRight(turtle, 60);
    fractalTree(turtle, length * 0.7, depth - 1);

    turtleLeft(turtle, 30);
    turtleBackward(turtle, length);
}

int main(void){
    TurtleApp *app = turtleAppCreate(700, 700, "fractalTree");

    if(app == NULL)
        return 1;

    Turtle *t = turtleAppGetTurtle(app);

    turtlePenUp(t);
    turtleGoTo(t, 350, 650);
    turtlePenDown(t);

    turtleLeft(t, 90);
    fractalTree(t, 150, 5);
  
    turtleAppRun(app);
    turtleAppDestroy(app);

    return 0;
} 
