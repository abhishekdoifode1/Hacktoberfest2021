'use strict';

const player0EL = document.querySelector('.player--0');
const player1EL = document.querySelector('.player--1');
const score0EL = document.getElementById('score--0');
const score1EL = document.getElementById('score--1');
const currentScore0El = document.getElementById('current--0');
const currentScore1El = document.getElementById('current--1');
let currentScore = 0;
score0EL.textContent = 0;
score1EL.textContent = 0;
let scores = [0, 0];
let activePlayer = 0;
let playing = true;

const diceEL = document.querySelector('.dice');
const btnEL = document.querySelectorAll('.btn');
for (let i = 0; i < btnEL.length; i++) {
  btnEL[i].addEventListener('click', function () {
    if (btnEL[i].classList.contains('btn--new')) {
      console.log('new game detected');
      activePlayer = 0;
      playing = true;
      player0EL.classList.remove('player--winner');
      player1EL.classList.remove('player--winner');
      player0EL.classList.add('player--active');
      player1EL.classList.remove('player--active');
      diceEL.classList.add('hidden');
      scores = [0, 0];
      currentScore = 0;
      document.getElementById(`score--0`).textContent = 0;
      document.getElementById(`score--1`).textContent = 0;
    }
    if (playing) {
      if (btnEL[i].classList.contains('btn--roll')) {
        console.log('roll detected');
        const dice = parseInt(Math.random() * 6 + 1);
        diceEL.classList.remove('hidden');
        diceEL.src = `dice-${dice}.png`;
        if (dice !== 1) {
          currentScore += dice;
          document.getElementById(
            `current--${activePlayer}`
          ).textContent = currentScore;
        } else {
          document.getElementById(`current--${activePlayer}`).textContent = 0;
          activePlayer = activePlayer === 0 ? 1 : 0;
          currentScore = 0;
          player0EL.classList.toggle('player--active');
          player1EL.classList.toggle('player--active');
        }
        console.log(dice);
      } else if (btnEL[i].classList.contains('btn--hold')) {
        console.log('hold detetcted');
        scores[activePlayer] += currentScore;
        document.getElementById(`score--${activePlayer}`).textContent =
          scores[activePlayer];
        if (scores[activePlayer] >= 100) {
          playing = false;
          diceEL.classList.add('hidden');
          document
            .querySelector(`.player--${activePlayer}`)
            .classList.add('player--winner');
          document
            .querySelector(`.player--${activePlayer}`)
            .classList.remove('player--active');
        }
        document.getElementById(`current--${activePlayer}`).textContent = 0;
        activePlayer = activePlayer === 0 ? 1 : 0;
        currentScore = 0;
        player0EL.classList.toggle('player--active');
        player1EL.classList.toggle('player--active');
      }
    }
  });
}
