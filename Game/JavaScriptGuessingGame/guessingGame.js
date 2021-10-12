const choice = process.argv[2];

var utils = require('./utils.js');

let tablicaOdp = './odp.json'; //DO NOT DELETE THIS FILE!!!



if (choice == 'START_INSTRUCTION'){
    console.log(' ')
    console.log('-----------------------------------------------')
    console.log('Hello, this is short instruction to my first simple guessing game')
    console.log('-----------------------------------------------')
    console.log('To start and see all the questions, run command: node akinator.js SHOW_ALL_QUESTIONS')
    console.log(' ')
    console.log('After reading all the questions, please answer those questions')
    console.log(' ')
    console.log('Use command: node akinator.js ANSWER_QUESTIONS "answer1" "answer2"...')
    console.log(' ')
    console.log('There are 10 questions, and you have to answer to all of them')
    console.log(' ')
    console.log("Your answers can be only 'true' or 'false'")
    console.log(' ')
    console.log('True and false have to be written starting from small letter, and also they have to be in single quotation marks!!!')
    console.log(' ')
    console.log('Have a nice game :)')
    console.log(' ')
}

if (choice == 'ADD_QUESTION') {
    const index = parseInt(process.argv[3]);
    const contents = process.argv[4];
    const answer = process.argv[5];
    
    let odpowiedziTab = utils.readDb(tablicaDoTestow);
    let indexFound = -1;
    for (let i = 0; i < odpowiedziTab.length; i++) {
        const odpowiedz = odpowiedziTab[i];
        if (odpowiedz.index === index) {
            indexFound = i;
            console.log("Question with this index number already exists!!!");
        }   
    }

    if (indexFound == -1) {
        odp = utils.generateNewQuestion(index, contents, answer)
        odpowiedziTab.push(odp);
        utils.saveToDb(tablicaDoTestow, odpowiedziTab);
        console.log('Question added successfully. Your question id is ' + odp.getId());
    }

}else if (choice == 'SHOW_ALL_QUESTIONS') { // node guessingGame.js SHOW_ALL_QUESTIONS
    let odpowiedziTab = utils.readDb(tablicaOdp);
    console.log("QUESTIONS: ");
    console.log("````````````````````````")
    for (let index = 0; index < odpowiedziTab.length; index++) {
        const que = odpowiedziTab[index];
        console.log("Question No.: " + que.index);
        console.log("Content: " + que.contents);
        console.log("Default answer: " + que.answer)
        console.log("````````````````````````")
    }

} else if (choice == 'ANSWER_QUESTIONS') { // node guessingGame.js ANSWER_QUESTIONS 'false' 'true' 'false' 'false' 'false' 'true' 'true' 'false' 'true' 'false' - will return "Beyonce"
    const answer1 = process.argv[3];
    const answer2 = process.argv[4];
    const answer3 = process.argv[5];
    const answer4 = process.argv[6];
    const answer5 = process.argv[7];
    const answer6 = process.argv[8];
    const answer7 = process.argv[9];
    const answer8 = process.argv[10];
    const answer9 = process.argv[11];
    const answer10 = process.argv[12];

    let odpowiedziTab = utils.readDb(tablicaOdp);
    for (let i = 0; i < odpowiedziTab.length; i++) {
        const odpowiedz = odpowiedziTab[i];
        if (odpowiedz.index = 1 && odpowiedz.answer === answer1) {
            if (odpowiedz.index = 2 && odpowiedz.answer != answer2){
                if (odpowiedz.index = 3 && odpowiedz.answer === answer3){
                    if (odpowiedz.index = 4 && odpowiedz.answer != answer4){
                        if (odpowiedz.index = 5 && odpowiedz.answer === answer5){
                            if (odpowiedz.index = 6 && odpowiedz.answer != answer6){
                                if (odpowiedz.index = 7 && odpowiedz.answer != answer7){
                                    if (odpowiedz.index = 8 && odpowiedz.answer === answer8){
                                        if (odpowiedz.index = 9 && odpowiedz.answer != answer9){
                                            if (odpowiedz.index = 10 && odpowiedz.answer != answer10){
                                                console.log(" ")
                                                console.log("I'm guessing it's  Donald Trump") 
                                                console.log(" ")
                                                break
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }else if(odpowiedz.index = 1 && odpowiedz.answer === answer1) {
            if(odpowiedz.index = 2 && odpowiedz.answer != answer2){
                if (odpowiedz.index = 3 && odpowiedz.answer != answer3){
                    if (odpowiedz.index = 4 && odpowiedz.answer === answer4){
                        if (odpowiedz.index = 5 && odpowiedz.answer === answer5){
                            if (odpowiedz.index = 6 && odpowiedz.answer != answer6){
                                if (odpowiedz.index = 7 && odpowiedz.answer != answer7){
                                    if (odpowiedz.index = 8 && odpowiedz.answer === answer8){
                                        if (odpowiedz.index = 9 && odpowiedz.answer != answer9){
                                            if (odpowiedz.index = 10 && odpowiedz.answer === answer10){
                                                console.log(" ")
                                                console.log("I'm guessing it's Mr. Bean") 
                                                console.log(" ")
                                                break
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }else if(odpowiedz.index = 1 && odpowiedz.answer != answer1) {
            if (odpowiedz.index = 2 && odpowiedz.answer === answer2){
                if (odpowiedz.index = 3 && odpowiedz.answer != answer3){
                    if (odpowiedz.index = 4 && odpowiedz.answer != answer4){
                        if (odpowiedz.index = 5 && odpowiedz.answer != answer5){
                            if (odpowiedz.index = 6 && odpowiedz.answer === answer6){
                                if (odpowiedz.index = 7 && odpowiedz.answer === answer7){
                                    if (odpowiedz.index = 8 && odpowiedz.answer != answer8){
                                        if (odpowiedz.index = 9 && odpowiedz.answer === answer9){
                                            if (odpowiedz.index = 10 && odpowiedz.answer != answer10){
                                                console.log(" ")
                                                console.log("I'm guessing it's Beyonce")
                                                console.log(" ")
                                                break
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        console.log(" ")
        console.log("I don't know this celebrity. Try to use different answers")
        console.log(" ")
        break
    }
}