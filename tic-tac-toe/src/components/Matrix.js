import React,{useState} from 'react';
import Block from './Block';
import _ from "lodash";

const  Matrix = (props)=>{
  const [playerToggle,setPlayerToggle] = useState(true);
  const [endGame,setEndGame] = useState(true);

  return(
    <div className="Matrix">
        {_.times(3, (i) => (
          <div className="row">
            {_.times(3, (j) => (
              <div className="column">
                  <Block
                  row={i}
                  col={j}
                  endGame={endGame}
                  setEndGame={setEndGame}
                  playerToggle={playerToggle}
                  setPlayerToggle={setPlayerToggle}
                  rowState={props.rowState}
                  setRowState={props.setRowState}
                  colState={props.colState}
                  setColState={props.setColState}
                  />
              </div>
            ))}
          </div>
        ))}
    </div>

  )
}


export default Matrix;
