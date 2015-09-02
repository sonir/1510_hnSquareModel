//
//  Ant.h
//  squareModel
//
//  Created by sonir on 9/3/15.
//
//

#ifndef __squareModel__Ant__
#define __squareModel__Ant__

#include <stdio.h>
#include "ofMain.h"
#include "config.h"
#include "Model.h"
class Model;

typedef struct color_t{
    
    int red;
    int green;
    int blue;
    
} color_t;


typedef enum direction_e {LEFT,RIGHT} direction_e;


class Ant {
    
public:
    
    Ant(Model *m);
    void move();
    void move(direction_e d);
    void eat();
    
    Model *model;
    color_t color;
    bool death = false;
    int view = VIEW_INIT;
    int take = TAKE_INIT;
    int appetite = APPETITE_INIT;
    int pool = POOL_INIT;
    int position;
};


#endif /* defined(__squareModel__Ant__) */
