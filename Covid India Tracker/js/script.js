const hamburger=document.getElementById("hamburger");
const navUl=document.getElementById("nav-ul");
hamburger.addEventListener("click",()=>{
    navUl.classList.toggle("show");
});

$(document).ready(function(){
    var url='https://data.covid19india.org/v4/min/data.min.json'

    $.getJSON(url,function(data){
        var total_confirmed, state, total_deceased, total_recovered, total_deaths, vaccinated_1, vaccinated_2
        console.log(data)
        total_confirmed = data.TT.total.confirmed
        total_deaths = data.TT.total.deceased
        total_recovered = data.TT.total.recovered
        total_vaccinated_1 = data.TT.total.vaccinated1
        total_vaccinated_2 = data.TT.total.vaccinated2

        $('#total_confirmed').text(total_confirmed)
        $('#total_deaths').text(total_deaths)
        $('#total_recovered').text(total_recovered)
        $('#total_vaccinated_1').text(total_vaccinated_1)
        $('#total_vaccinated_2').text(total_vaccinated_2)


        var states = []
        var confirmed = []
        var recovered = []
        var deaths = []
        var vaccinated_1 = []
        var vaccinated_2 = []

        $.each(data, function(key, value){
            states.push(key)
            confirmed.push(value.total.confirmed)
            recovered.push(value.total.recovered)
            deaths.push(value.total.deceased)
            vaccinated_1.push(value.total.vaccinated1)
            vaccinated_2.push(value.total.vaccinated2)
        })

        // Delete specific state
        states.splice(33,1)
        confirmed.splice(33,1)
        recovered.splice(33,1)
        deaths.splice(33,1)
        vaccinated_1.splice(33,1)
        vaccinated_2.splice(33,1)

        const jsonObj = [];
            for(let i = 0; i < states.length; i++){
               jsonObj.push({
                  states: states[i],
                  confirmed: confirmed[i],
                  recovered: recovered[i],
                  deaths: deaths[i],
                  vaccinated_1: vaccinated_1[i],
                  vaccinated_2: vaccinated_2[i]
               });
        };
        
        function buildTable(data){
            var table = document.getElementById('table_body')
            for (var i=0;i<data.length;i++){ 
                row = `<tr>
                <td>${data[i].states}</td>
                <td>${data[i].confirmed}</td>
                <td>${data[i].recovered}</td>
                <td>${data[i].deaths}</td>
                <td>${data[i].vaccinated_1}</td>
                <td>${data[i].vaccinated_2}</td>
            </tr>`
            table.innerHTML += row
            }
        }
        buildTable(jsonObj)
        var myChart = document.getElementById('myChart').getContext('2d');

        var chart = new Chart(myChart, {
            type:'bar',
            data:{
                labels:states,
                datasets: [
                    {
                        label: 'Total Confirmed',
                        data: confirmed,
                        backgroundColor: 'red',
                        minBarLength: 100,
                        hoverBorderWidth: 20,
                    },
                    {
                        label: 'Total Recovered',
                        data: recovered,
                        backgroundColor: 'blue',
                        minBarLength: 100,
                    },
                    {
                        label: 'Total Deaths',
                        data: deaths,
                        backgroundColor: 'green',
                        minBarLength: 100,
                    },
                    {
                        label: 'Single Vaccinated',
                        data: vaccinated_1,
                        backgroundColor: 'orange',
                        minBarLength: 100,
                    },
                    {
                        label: 'Double Vaccinated',
                        data: vaccinated_2,
                        backgroundColor: 'purple',
                        minBarLength: 100,
                    }
                ]
            }
        });
    })
})

