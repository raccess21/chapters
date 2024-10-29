#generate bill
def bill(cust_data):
    if cust_data['room_code'] == 'D':
        TarrifPerDay = 2500             #for deluxe rooms
        #discount rate [gold, diamond, platinum] for deluxe rooms
        discountDeluxe = [5, 15, 25]
    
    else:
        TarrifPerDay = 4200             #for deluxe rooms
        #discount rate [gold, diamond, platinum] for super deluxe rooms
        discountDeluxe = discountSupDeluxe = [10, 20, 30]
    
    BillAmount = TarrifPerDay * cust_data["room_num"] * cust_data["days_num"]
    return TarrifPerDay - ((TarrifPerDay * (discountDeluxe[int(cust_data["mem_code"]) - 1]) ) / 100)
    

def display(cust_data):
    for key in cust_data.keys():
        print(key, cust_data[key])


#Force user to input from a list of specified values
def get_val(prompt, allowed = []):
    while True:
        data = input(prompt).upper()
        if allowed.count(data) > 0:
            return data
        else:
            print("Wrong choice. Please enter again")


#Force user to input positive integer
def get_num(prompt):
    while True:
        try:
            return int(input(prompt))
        except ValueError:
            print("Please enter correct value.")


#input customer data
def get_cust_data():
    name = input("Enter your name: ")
    mem_code = get_val("Enter your membership code(1/2/3): ", ["1", "2", "3"])
    room_code = get_val("Enter your room code(D/S): ", ["D", "S"])
    room_num = get_num("Enter number of rooms: ")
    days_num = get_num("Enter number of days: ")
    cust_data = {'name':name, 'mem_code':mem_code, 'room_code':room_code, 'room_num':room_num, 'days_num':days_num}
    print("Bill is", bill(cust_data))


def main():
    get_cust_data()


if __name__ == "__main__":
    main()