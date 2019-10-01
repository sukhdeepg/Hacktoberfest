//This a favorite of mine because it was first attempt at a countdown timer

var isUserAnswering = false;
var qPageTitle = createElement('h1');
//sets the timer functions
var time;
var timeID;
var currentTime;
var numCorrect;

//create the timer functions
function timeGame() {
    //set the time to minus
    if (!isUserAnswering) {
        //sets the timer to add the count function
        timeID = setInterval(count, 1000);
        isUserAnswering = true;
    }

}

function reset() {
    //sets the time back to 330 seconds
    time = 5.5 * 60;
    qPageTitle.textContent = '05:30';
}

function count() {
    //set the decrement
    time--;
    if (time === 0) {
        //clear the interval
        clearInterval(timeID);
        endGame();
    }
    //sets time to the current time
    currentTime = timeConverter(time);
    //puts the timer at the top of the page
    qPageTitle.textContent = currentTime;
}

//based off the stopwatch class activity
function timeConverter(timeStamp) {
    //converts the time into something readable
    var minutes = Math.floor(timeStamp / 60);
    var seconds = timeStamp - (minutes * 60);

    if (seconds < 10) {
        seconds = "0" + seconds;
    }

    if (minutes === 0) {
        minutes = "00";
    } else if (minutes < 10) {
        minutes = "0" + minutes;
    }

    return minutes + ":" + seconds;
}

//functions to prevent multiple appends
function questionReset() {
    var questionRemove = questionContainer.clear();
    return questionRemove;
}

function resultsReset() {
    var resultsRemove = resultsDiv.clear();
    return resultsRemove;
}

function noTimeReset() {
    var noTimeRemove = $('#sub-wrapper-no-time').clear();
    return noTimeRemove;
}

//ends the game when user runs out of time.
function endGame() {
    noTimeReset();
    console.log('this is working');
    //sets the views sets the title
    var noTimeTitle = createElement('h1');
    noTimeTitle.textContent = 'Oh No! You ran out of time!! Want to try again?';
}