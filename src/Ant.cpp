//
//  Ant.cpp
//  squareModel
//
//  Created by sonir on 9/3/15.
//
//

#include "Ant.h"

using namespace std;

//function prototypes
int edgeCheck(int position,int max);

Ant::Ant(Model *m){
    
    model = m;
    color.red = ofRandom(255.0);
    color.green = ofRandom(255.0);
    color.blue = ofRandom(255.0);
    position = ofRandom(model->grids.size()-1);
    
}

void Ant::move(){

    int left_grid = edgeCheck(position-1, model->grids.size());
    int right_grid = edgeCheck(position+1, model->grids.size());

    //Avoid now position by edgeLimitter
    if(left_grid==position){
        move(RIGHT);
        return;
    }else if(right_grid==position){
        move(LEFT);
        return;
    }else {
    
        Grid *left = &model->grids[left_grid];
        Grid *right = &model->grids[right_grid];
        
        if( (left->resource) > (right->resource) ){
            
            move(LEFT);
            
        }else if( (left->resource) < (right->resource) ){
            
            move(RIGHT);
            
        }else { // If left and right is same
            
           int dice = ofRandom(2);
            if(dice)move(LEFT);
            else move(RIGHT);
            
        }
        
    
        //Move Limitter
        position = edgeCheck(position, model->grids.size());
        return;
        
    }
}

void Ant::move(direction_e d){
    
    if(d==LEFT)position--;
    if(d==RIGHT)position++;
    position = edgeCheck(position, model->grids.size());
}


void Ant::eat(){
    
    if(model->grids[position].resource >= take){
        pool+=take;
    }else{
        pool += model->grids[position].resource;
    }
    model->grids[position].decrease(take);
    
    pool-=appetite;
    
    
}


//C Functions
int edgeCheck(int position,int grid_num){
    
    int posi =position;
    if(position>=grid_num) posi = grid_num-1;
    else if(position<0) posi = 0;
    return posi;
    
}
