import React, { useState } from 'react';
import ReactNotification from 'react-notifications-component'
import 'react-notifications-component/dist/theme.css'
import './App.css';
import Matrix from './components/Matrix';
import Block from './components/Block';

const App = function(){
  const [rowState,setRowState] = useState([0,0,0,0,0]);
  const [colState,setColState] = useState([0,0,0,0,0]);
  const [endGame,setEndGame] = useState(true);

    return(
      <div className="AppContainer">
        <div className="notification-container">
            <ReactNotification />
        </div>
          <div className="layout">
              <Matrix
              rowState={rowState}
              setRowState={setRowState}
              colState={colState}
              setColState={setColState}
              />
          </div>
      </div>

    )
}

export default App;
