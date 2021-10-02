const GRID_SIZE = 31

export function randomGridPosition(){
    return{
        x: Math.floor(Math.random()*GRID_SIZE) + 1,
        y: Math.floor(Math.random()*GRID_SIZE) + 1

    }
}

export function outsideGrid(position){
    
    if(position.x<1||position.x>GRID_SIZE || 
        position.y<1||position.y>GRID_SIZE)
        return true
    else 
        return false
    
}