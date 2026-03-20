from tkinter import messagebox
from datetime import datetime
from tkinter import messagebox

def validate_dob(dob):
    try:
        datetime.strptime(dob, "%d/%m/%Y")
        return True
    except:
        messagebox.showerror(
            "Invalid DOB",
            "Please enter DOB in format: DD/MM/YYYY"
        )
        return False

def validate_data(data):
    name, address, dob, dept, x_per, xii_per, gender = data

    if not all(data):
        messagebox.showerror("Error", "All fields are required")
        return False

    try:
        if not (0 <= float(x_per) <= 100):
            raise ValueError
        if not (0 <= float(xii_per) <= 100):
            raise ValueError
    except:
        messagebox.showerror("Error", "Percentage must be between 0 and 100")
        return False

    return True


def show_success():
    messagebox.showinfo("Success", "Data saved successfully!")