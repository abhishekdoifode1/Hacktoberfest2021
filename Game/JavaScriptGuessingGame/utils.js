var fs = require('fs-extra');

class Question {
    constructor(index, contents, answer) {
        this.index = index;
        this.contents = contents;
        this.answer = 'true';
    }

    getId() {
        return this.index
        
    }

    getContent() {
        return this.contents
    }

}

class answers {
    constructor(answer) {
        this.answer = answer;
    }

    getAnswear() {
        return this.answer
        
    }

}

function readDb(path) {
    fs.ensureFileSync(path);
    let table = fs.readJsonSync(path, { throws: false });
    if (table === null) {
        return [];
    }
    return table;
}

function saveToDb(path, table) {
    fs.writeJsonSync(path, table);
}
    
function generateNewQuestion(index ,contents, answer) {
    let odp = new Question(index, contents, answer);
    return odp;

}

function answerQuestions(answer) {
    let pyt = new answers(answer);
    return pyt;

}

function checkIfTrue(answer) {
    if (answer !== 'true')
        return false;
    return true;
}

function checkIfGoodId(id) {
    if (id !== 1)
        return false;
    return true;
}

function getCurrentQuestionId(ques) {
    let queIds = [];
    for (let index = 0; index < ques.length; index++) {
        const que = ques[index];
        queIds.push(que.index);
    }
    return queIds;
}

function getCurrentQuestionContent(ques) {
    let queCons = [];
    for (let index = 0; index < ques.length; index++) {
        const que = ques[index];
        queCons.push(que.contents);
    }
    return queCons;
}

// function modifyQuestion(index, content, answer) {
//     if (!checkIfGoodId(content.getCurrentQuestionContent())) {
//         console.log('You can only modify questions with id: 1');
//         return undefined;
//     }

//     const changedContent = newQuestion /  content.getContent();
    
//     return new Question(index, changedContent, answer);
// }


module.exports = { readDb,saveToDb, Question, answers,generateNewQuestion, checkIfGoodId,getCurrentQuestionContent,checkIfTrue, answerQuestions, getCurrentQuestionId} // to pozwala uzywać tych metod w innych plikach