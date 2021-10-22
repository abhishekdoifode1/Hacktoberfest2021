import React, {useState,useEffect} from 'react';
import { store } from 'react-notifications-component';
import 'react-notifications-component/dist/theme.css';

const Block = (props)=>{


  const [value,setValue] = useState("");
  const [usedFlag,setUsedFlag] = useState(false);
  useEffect(() => console.log('value changed!'), [props.rowState]);


  const setRowCol = (rowState,colState)=>{
    props.setRowState(rowState);
    props.setColState(colState);
  }

  const increaseResults =(row,col)=>{
    props.rowState[row] +=1;
    props.colState[col] +=1;
    setRowCol(props.rowState,props.colState);
    checkWinner(props.rowState[row],props.colState[col]);
  }

  const decreaseResults = (row,col)=>{
    props.rowState[row] -=1;
    props.colState[col] -=1;
    setRowCol(props.rowState,props.colState);
    checkWinner(props.rowState[row],props.colState[col]);
  }

  const updateResult = (row,col)=>{
    if(props.playerToggle){
      increaseResults(row,col);
      if(row===col){
        increaseResults(3,3);
      }
      if((parseInt(row)+parseInt(col))===2){
        increaseResults(4,4);
      }

    }
    else{
      decreaseResults(row,col);
      if(row===col){
          decreaseResults(3,3);
      }
      if((parseInt(row)+parseInt(col))===2){
          decreaseResults(4,4);
      }

    }

  }

  const valueHandler = (e)=>{
    if(!usedFlag && props.endGame){
      if(props.playerToggle){
        setValue('X');

      }
      else{
        setValue('O');
      }
      props.setPlayerToggle(!props.playerToggle);
      console.log(e.target)
      let row = e.target.attributes['row']['nodeValue'];
      let col = e.target.attributes['col']['nodeValue']
      updateResult(row,col);
      setUsedFlag(!usedFlag);
    }

  }
  const compareValues = (value,place)=>{

    if(value === 3 && props.endGame){
      props.setEndGame(!props.endGame)
      console.log(`X Wins`);
       showNotify('X is the Winner','success')

    }
    if(value===-3 && props.endGame ){
        props.setEndGame( !props.endGame)
        console.log(`O Wins`)
         showNotify('O is the Winner','danger')
    }

  }
  const checkWinner = (currentRowVal,currentColVal)=>{
    compareValues(currentRowVal);
    compareValues(currentColVal);
  }

    const showNotify = (message,type)=>{
      store.addNotification({
          title: 'Winner',
          message: message,
          type: type,                         // 'default', 'success', 'info', 'warning'
          container: 'top-right',                // where to position the notifications
          animationIn: ["animated", "fadeIn"],     // animate.css classes that's applied
          animationOut: ["animated", "fadeOut"],   // animate.css classes that's applied
          dismiss: {
            duration: 5000
          }
        })

    }





  return(
    <div className="block-container">
        <div className="square"
        key={props.key}
        row={props.row}
        col={props.col}
        onClick={valueHandler}>
        <span className="move">{value}</span>
        </div>
    </div>
  )
}
export default Block;
