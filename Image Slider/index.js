const slides = document.querySelectorAll(".slides img");
let slideindex = 0;
let intervalid = null;

//initializeslider();
document.addEventListener("DOMContentLoaded",initializeslider);
function initializeslider(){

    if (slides.length > 0){
        slides[slideindex].classList.add("displayslide");
        intervalid = setInterval(nextslide,5000);
    }
    slides[slideindex].classList.add("displayslide");
    intervalid = setInterval(nextslide,5000)
}
function showslide(index){
    if (index>= slides.length){
        slideindex = 0;
    }else if(index<0){
        slideindex = slides.length-1;
    }
    slides.forEach(slide => {
        slide.classList.remove("displayslide");
    });
    slides[slideindex].classList.add("displayslide");
}
function prevslide(){
clearInterval(intervalid);
slideindex--;
showslide(slideindex);
}
function nextslide(){
    slideindex++;
    showslide(slideindex);
}