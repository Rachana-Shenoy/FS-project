import csv
#fields of record and the file where records are stored
employee_fields = ['empID', 'name', 'age', 'email', 'phone','gender']
employee_fileSystem = 'temp.txt'
def display_menu():
    print("--------------------------------------")
    print(" Welcome to Employee Management System for HR Department")
    print("---------------------------------------")
    print("1. Add New Employee")
    print("2. View Employees")
    print("3. Search Employee")
    print("4. Update Employee")
    print("5. Delete Employee")
    print("6. Quit")

#add new employee
def add_employee():
    print("-------------------------")
    print("Add Employee Information")
    print("-------------------------")
    global employee_fields
    global employee_fileSystem

    employee_data = []
    for field in employee_fields:
        value = input("Enter " + field + ": ")
        employee_data.append(value)

    with open(employee_fileSystem, "a", encoding="utf-8") as f:
        writer = csv.writer(f)
        writer.writerows([employee_data])

    print("Record saved successfully")
    input("Press any key to continue")
    return

#get a list of all records in the file
def view_employees():
    global employee_fields
    global employee_fileSystem

    print("--- Employee Records ---")

    with open(employee_fileSystem, "r", encoding="utf-8") as f:
        reader = csv.reader(f)
        for x in employee_fields:
            print(x, end='\t   |')
        print("\n------------------------------------------------------------------------------------")

        for row in reader:
            for item in row:
                print(item, end="\t |")
            print("\n")

    input("Press any key to continue")

#search a specific employee by his/her emp Id
def search_employee():
    global employee_fields
    global employee_fileSystem

    print("--- Search Employee ---")
    roll = input("Enter emp Id to search: ")
    with open(employee_fileSystem, "r", encoding="utf-8") as f:
        reader = csv.reader(f)
        for row in reader:
            if len(row) > 0:
                if roll == row[0]:
                    print("----- Employee Found -----")
                    print("EmpId: ", row[0])
                    print("Name: ", row[1])
                    print("Age: ", row[2])
                    print("Email: ", row[3])
                    print("Phone: ", row[4])
                    print("Gender: ", row[5])
                    break
        else:
            print("Emp Id not found in the file")
    input("Press any key to continue")

#modify employee details
def update_employee():
    global employee_fields
    global employee_fileSystem

    print("--- Update Employee ---")
    roll = input("Enter emp Id to update: ")
    index_employee = None
    updated_data = []
    with open(employee_fileSystem, "r", encoding="utf-8") as f:
        reader = csv.reader(f)
        counter = 0
        for row in reader:
            if len(row) > 0:
                if roll == row[0]:
                    index_employee = counter
                    print("Employee Found: at index ",index_employee)
                    employee_data = []
                    for field in employee_fields:
                        value = input("Enter " + field + ": ")
                        employee_data.append(value)
                    updated_data.append(employee_data)
                else:
                    updated_data.append(row)
                counter += 1


    # Check if the record is found or not
    if index_employee is not None:
        with open(employee_fileSystem, "w", encoding="utf-8") as f:
            writer = csv.writer(f)
            writer.writerows(updated_data)
    else:
        print("Emp Id not found in the file")

    input("Press any key to continue")

#delete an employee record from the file
def delete_employee():
    global employee_fields
    global employee_fileSystem

    print("--- Delete Employee ---")
    roll = input("Enter emp Id to delete: ")
    employee_found = False
    updated_data = []
    with open(employee_fileSystem, "r", encoding="utf-8") as f:
        reader = csv.reader(f)
        counter = 0
        for row in reader:
            if len(row) > 0:
                if roll != row[0]:
                    updated_data.append(row)
                    counter += 1
                else:
                    employee_found = True

    if employee_found is True:
        with open(employee_fileSystem, "w", encoding="utf-8") as f:
            writer = csv.writer(f)
            writer.writerows(updated_data)
        print("Emp Id ", roll, "deleted successfully")
    else:
        print("Emp Id not found in the file")

    input("Press any key to continue")

while True:
    display_menu()

    choice = input("Enter your choice: ")
    if choice == '1':
        add_employee()
    elif choice == '2':
        view_employees()
    elif choice == '3':
        search_employee()
    elif choice == '4':
        update_employee()
    elif choice == '5':
        delete_employee()
    else:
        break
