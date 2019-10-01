//implement sleep function using promises
"use strict"

function sleep(seconds){
    return new Promise((resolve)=>{
        setTimeout(()=>{
            resolve(true);
        }, 5000);
    });
};

(async ()=>{
    console.log("sleep well");
    await sleep(5);
    console.log("happy coding!");
})();