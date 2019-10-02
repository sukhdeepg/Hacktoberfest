//implement sleep function using promises
"use strict"

function sleep(ms) {
  return new Promise((resolve) => {
    setTimeout(resolve, ms);
  });
}

(async ()=>{
    console.log("sleep well");
    await sleep(5000);
    console.log("happy coding!");
})();
