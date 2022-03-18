//function func() {

//}

WorkerScript.onMessage = function(message) {
    if(message.run === true) {
        for(var a=0;a<2000;a++) {
            console.log(a)
            //setTimeout(function(){}, 1000);
        }
    }
    WorkerScript.sendMessage({run : false});
}

//function sleep(ms){
//    return new Promise(resolve   => setTimeout(resolve, ms));
//}
