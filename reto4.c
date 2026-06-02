//Reto 4: Modifique la curva de Levy C para que use colores diferentes en distintos niveles de recursion.

#include <stdio.h>
#include <math.h>
#include "turtlec.h"

void levy(Turtle* turtle, float length, int depth) {
    if(depth == 0) {
        turtleForward(turtle, length);
        return;
    }
    
    turtleLeft(turtle, 45);
    levy(turtle, length / sqrt(2), depth - 1);
    
    uint8_t r = (depth * 155) % 256;
    uint8_t g = (depth * 55) % 256;
    uint8_t b = (depth * 95) % 256;
    turtleSetColor(turtle, r, g, b);

    turtleRight(turtle, 90);
    levy(turtle, length / sqrt(2), depth - 1);
    
    turtleLeft(turtle, 45);
}

int main(void){
    float length;
    int depth;

    printf("ingresar longitud inicial: ");
    scanf("%f", &length);

    printf("Ingresa profundidad: ");
    scanf("%d", &depth);

    TurtleApp *app = turtleAppCreate(1000, 700, "curva de Levy C");

    if(app == NULL)
        return 1;

    Turtle *t = turtleAppGetTurtle(app);

    turtlePenUp(t);
    turtleGoTo(t, 200, 550);
    turtlePenDown(t);

    //turtleLeft(t, 90);
    levy(t, length, depth);
  
    turtleAppRun(app);
    turtleAppDestroy(app);

    return 0;
} 
