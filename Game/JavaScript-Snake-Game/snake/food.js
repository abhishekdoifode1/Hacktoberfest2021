import {onSnake, expandSnake} from './snake.js'
import { randomGridPosition } from './grid.js'
let food = getRandomFoodposition()
const EXPANSION_RATE = 5


export function update() {
    if (onSnake(food)) {
        expandSnake(EXPANSION_RATE)
        food = getRandomFoodposition()
     }
}
export function draw(gameBoard) {

    const foodElement = document.createElement('div')
    foodElement.style.gridRowStart = food.y
    foodElement.style.gridColumnStart = food.x
    foodElement.classList.add('food')
    gameBoard.appendChild(foodElement)

}

function getRandomFoodposition(){
    let newFoodPosition
    while (newFoodPosition == null || onSnake(newFoodPosition)){
        newFoodPosition =randomGridPosition()
    }
    return newFoodPosition
}