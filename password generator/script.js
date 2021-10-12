const result=document.getElementById('result');
const resultlen=document.getElementById('length');
const resultlow=document.getElementById('lowercase');
const resultupp=document.getElementById('uppercase');
const resultnum=document.getElementById('number');
const resultsym=document.getElementById('symbol');
const clipboard=document.getElementById('clipboard');
const generate=document.getElementById('generate');
const randomFunc={
    lower: randomlower,
    upper: randomupper,
    number: randomnumber,
    symbol: randomsymbol
};

generate.addEventListener('click',()=>{
    const lenval= +resultlen.value;
    const lowval=resultlow.checked;
    const uppval=resultupp.checked;
    const numval=resultnum.checked;
    const symval=resultsym.checked;
    result.innerText=generatePassword(uppval,lowval,numval,symval,lenval);
});

//copy to clipboard
clipboard.addEventListener('click',()=>{
    const textarea=document.createElement('textarea');
    const password = result.innerText;
    if(!password){
        return;
    }
    textarea.value=password;
    document.body.appendChild(textarea);
    textarea.select();
    document.execCommand("copy");
    textarea.remove();
    alert("password copied");
})

//generate password function
function generatePassword(upper,lower,number,symbol,length){
    let genpass="";
    const typescount=upper+lower+number+symbol;
    const typesArr=[{upper},{lower},{number},{symbol}].filter(item=>Object.values(item)[0]);
    console.log(typesArr);
    if(typescount==0){
        return '';
    }
    for(i=0;i<length;i+=typescount){
        typesArr.forEach(type=>{
            console.log(type)
            const funcname=Object.keys(type)[0];
            console.log(funcname);
            genpass+=randomFunc[funcname]();
        })
    }
    console.log(genpass)
    const finalpassword=genpass.slice(0, length);
    return finalpassword;
}
//generator functions
function randomlower(){
    return String.fromCharCode(Math.floor(Math.random()*26 + 97));
}
function randomupper(){
    return String.fromCharCode(Math.floor(Math.random()*26 + 65));
}
function randomnumber(){
    return String.fromCharCode(Math.floor(Math.random()*10 + 48));
}
function randomsymbol(){
    const symbol='@?!#$%^&*()'
    return symbol[Math.floor(Math.random()* symbol.length)];
}