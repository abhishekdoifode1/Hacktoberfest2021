AOS.init();
let hill = document.getElementById('hills')
let road = document.getElementById('floor')
let text = document.getElementById('text')

window.addEventListener('scroll' ,function(){
    var val = window.scrollY
    hill.style.top = -val * 0.5 + 'px'
    road.style.top = -val * 0.5 + 'px'
    text.style.top = val *0.15 + 'px'
})
