var expenseList = 0;
function cal() {

    var budget = document.getElementById("bgt").value;
    var balance = budget - expenseList;

    document.getElementById("bugetval").innerText = budget;
    document.getElementById("expenseval").innerText = expenseList;
    document.getElementById("balance").innerText = balance;
  
}

function addExpense() {
    var title = document.getElementById("title").value;
    var expense = document.getElementById("xpense").value;
    expenseList = expenseList + parseInt(expense);

    var data = '<tr>'+
        '<td>'+
         title +
        '</td>'+
        '<td class="expenseList">'+
         expense +
        '</td>'+
    '</tr>';

    $("tbody").append(data);

}
