// * Exercise 1
// console.log('Hello World')

// * Exercise 2
// Changes the Background colour of articles by adding a class to them
function changeAllArticleColors(){
    const articles = document.querySelectorAll("#products article")

    for(let article of articles){
        article.classList.add("sale");
    }
}

// * Exercise 3
// Prints to the console when a button is pressed
function attachBuyEvents(){
    const buttons = document.querySelectorAll("#products button");
    
    for(let button of buttons){
        button.addEventListener('click',function(e) { 
            console.log("BUY!")
            console.log(e.currentTarget)})
    }
}

// * Exercise 4
//
function attachBuyEvents2(){
const buttons = document.querySelectorAll("#products button");
    
    for(let button of buttons){
        button.addEventListener('click',function(e) { 
            let parent = e.currentTarget.parentElement;
            parent.classList.
            console.log(e.currentTarget.parentElement);
        })
    }
}

attachBuyEvents2();