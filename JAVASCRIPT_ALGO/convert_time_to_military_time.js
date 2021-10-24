function getMilitaryTime(time) {
    let inputVal = time;

    let getPm = inputVal.split(" ")

    let timeUnite = getPm[getPm.length - 1]

    if(timeUnite == "PM") {
        let val = +inputVal.split(":")[0]
        let hour = val + 12;
        let minute = inputVal.split(":")[1]
        let minuteVal = +minute.split(" ")[0]
        let finalAnser = `${hour}:${minuteVal} ${timeUnite}`
        console.log(finalAnser)
    }

    if(timeUnite = "AM") {
        let hour = inputVal.split(":")[0]
        let minute = inputVal.split(":")[1].split(" ")[0]
    
        if(hour == 12) {
            let finalHour = '00'
            let finalMinute = minute
            let finalTime = `${finalHour}:${finalMinute} AM`
            console.log(finalTime)
        }
    }



}

getMilitaryTime("12:15 AM")

