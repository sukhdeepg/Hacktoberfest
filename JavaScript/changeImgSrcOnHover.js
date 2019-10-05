// This is my favorite code snippet because I am new to coding 
// and this is one of the first cool things I've learned how to do.

var picChange = document.querySelector('img');
picChange.onmouseout = function() {
	this.src = 'photo1.jpg';
};
picChange.onmouseover = function() {
	this.src = 'photo2.jpg';
};
