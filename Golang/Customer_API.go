package main

import "fmt"

type customer struct {
	id    string
	first string
	last  string
	email string
	phone string
}

var customer_list []customer

func (c customer) create() {

	customer_list = append(customer_list, c)
}

func delete(id string) {

	for i, v := range customer_list {
		if v.id == id {
			customer_list = append(customer_list[:i], customer_list[i+1:]...) //removing ith customer
			break
		}
	}
}
func (c customer) update(id, first, last, email, phone string) {
	for i, v := range customer_list {
		if v == c {
			customer_list[i].id = id
			customer_list[i].first = first
			customer_list[i].last = last
			customer_list[i].email = email
			customer_list[i].phone = phone
		}
	}
}
func printCustomers() {
	for _, v := range customer_list {
		fmt.Printf("Customer id: %v\n", v.id)
		fmt.Printf("Customer first: %v\n", v.first)
		fmt.Printf("Customer last: %v\n", v.last)
		fmt.Printf("Customer email: %v\n", v.email)
		fmt.Printf("Customer phone: %v\n\n", v.phone)

	}
}

func main() {
	var _a string
	_t := true
	for _t == true {
		fmt.Println("Enter C to create")
		fmt.Println("Enter U to Update")
		fmt.Println("Enter D to Delete")
		fmt.Println("Enter P to list customers")
		fmt.Println("Enter Q to Quit")
		fmt.Print("Enter character: ")
		fmt.Scanln(&_a)

		var _c1 customer
		switch _a {
		case "C":
			{
				fmt.Print("Enter customer id: ")
				fmt.Scanln(&_c1.id)
				fmt.Print("Enter customer first name: ")
				fmt.Scanln(&_c1.first)
				fmt.Print("Enter customer last name: ")
				fmt.Scanln(&_c1.last)
				fmt.Print("Enter customer email: ")
				fmt.Scanln(&_c1.email)
				fmt.Print("Enter customer phone: ")
				fmt.Scanln(&_c1.phone)
				_c1.create()
				fmt.Println("------------------------------------")

			}
		case "U":
			{
				fmt.Print("Enter updated customer id: ")
				fmt.Scanln(&_c1.id)
				fmt.Print("Enter updated customer first name: ")
				fmt.Scanln(&_c1.first)
				fmt.Print("Enter updated customer last name: ")
				fmt.Scanln(&_c1.last)
				fmt.Print("Enter updated customer email: ")
				fmt.Scanln(&_c1.email)
				fmt.Print("Enter updated customer phone: ")
				fmt.Scanln(&_c1.phone)
				fmt.Println("------------------------------------")

			}
		case "D":
			{
				var _id string
				fmt.Print("Deletion: enter customer id ")
				fmt.Scanln(&_id)
				delete(_id)
				fmt.Println("------------------------------------")

			}
		case "P":
			{
				printCustomers()
				fmt.Println("------------------------------------")

			}
		case "Q":
			{
				_t = false
				fmt.Println("------------------------------------")

			}
		default:
			{
				fmt.Println("INCORRECT")
				fmt.Println("------------------------------------")

			}
		}

	}
}
